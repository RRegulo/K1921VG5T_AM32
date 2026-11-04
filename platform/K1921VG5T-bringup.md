# K1921VG5T bring-up — что и почему (решённые и заапрувленные вопросы)

Журнал проблем и решений при заведении K1921VG5T (NIIET RISC-V, ядро Syntacore
SCR4) в этом дереве: бутлоадер `esc-bootloader`, приложение `esc-firmware`,
конфигуратор `am32-configurator` и тулзы. Дополняет
`esc-bootloader/firmware/sdk-patches.md` (патчи SDK) и
`esc-firmware/firmware/VG5T_PORT_REPORT.md` (порт приложения).

Источники: ТГ-чат НИИЭТ (`dependencies/ChatExport_2026-09-22`), рабочие
референсы `rabidrabbit/k1921vg7t_simple` и модульный `niiet/riscv_cmake_sdk`
(пример `examples/bootloader`), апстрим-репы `niiet/k1921vg5t_sdk` /
`k1921vg7t_sdk`.

---

## 1. Раскладка flash / 4 КБ бутлоадера

- Приложение линкуется с `0x1000` (`k1921vg5t_app.ld`, добавлен в SDK), т.е.
  первые 4 КБ — бутлоадер. `esc_sectors.ld` задаёт `.app_start 0x1000`,
  `.eeprom 0xF000`, `.device_type = ADDR(.eeprom)-32 = 0xEFE0`,
  `.calibration 0xF800`, `_flash_rw_offset 0x08000000`.
- В `esc-bootloader/firmware/vg5t/esc.ld` стоит ASSERT, что образ бутлоадера
  (включая LMA-копии `.data`/`.sdata` после `__etext`) не заходит за
  `_app_start_addr`. Сейчас бутлоадер **влезает** (Release ≈ 3.3 КБ,
  Debug ≈ 4.0 КБ).
- **`-Og` Debug-сборка** исторически переполняла 4 КБ на ~70 Б; лечили
  `-falign-functions/jumps/loops=1`. В итоге лимит временно отключён и костыли
  убраны (см. §3), Debug собирается и работает.

## 2. Flash fetch-buffer: `FBEN` + `CFLUSH` + `LAT` (главный фикс)

В `niietsdk/vg5t/Device/K1921VG5T/source/system_k1921vg5t.c` сток НИИЭТ в
ветке PLL писал только латентность:
```c
FLASH->CTRL_bit.LAT = 2;
//cache_enable(1,0);
```
Рабочий референс VG7T (`vg7t_simple/libbaremetal/src/libc/runtime.c`) делает
больше — **сбрасывает и включает fetch-буфер** и считает латентность:
```c
FLASH->CTRL_bit.FBFLUSH = 1;  FLASH->CTRL;
FLASH->CTRL = ((g_systemclock / 35000000u) << FLASH_CTRL_LAT_Pos)
            | FLASH_CTRL_FBEN_Msk;
```
Приведено к тому же виду:
```c
FLASH->CTRL_bit.CFLUSH = 1;  (void)FLASH->CTRL;
FLASH->CTRL = (2u << FLASH_CTRL_LAT_Pos) | FLASH_CTRL_FBEN_Msk;
```
Латентность `= ceil(fclk/35 МГц)`: 96 МГц → 2 (совпадает с `LATENCY_100MHz=2`
из `k1921vg7t.h`). **Последствие:** раз `FBEN` включён, перед передачей
управления приложению нужно сбрасывать fetch-буфер (см. §6).

## 3. Флаги компиляции (`dependencies/cmake/riscv/K1921VG5T.cmake`)

| Флаг | Почему |
|---|---|
| `-march=rv32imafc_zicsr_zifencei` | `misa=0x40101125` → A C F I M U; `c` экономит ~25–30 % кода |
| `-mabi=ilp32f` | у чипа FPU только одинарной точности (flen=4); `ilp32d` ломал GDB (`flen 8 vs 4`) |
| `-fstrict-volatile-bitfields` | весь plib5t — `volatile`-битфилды регистров; как в рабочих сборках НИИЭТ |
| `-fno-strict-aliasing` | пуннинг буферов бутлоадера; как у НИИЭТ |
| `-Os` + `-flto` + `--gc-sections` (+ link `-ffunction/-fdata-sections`) | уложить бутлоадер в 4 КБ; без per-function секций в link LTRANS даёт один `.text` и gc не работает (ROM раздувался до ~7.3 КБ) |

## 4. Кэши (L1 I/D) — по умолчанию выключены

- `cache_enable()` в `plic.c` **не вызывается** (в `system_k1921vg5t.c`
  закомментирован `//cache_enable(1,0)`), `PLF_CACHE_CFG` не определён →
  кэши выключены, `cache_flush` в стартапе вырезан.
- Включение (референс VG7T, `mpu_enable()`): `SCR_CSR_CACHE_GLBL(0xBD4)=0xC`
  → `fence.i` → ждать → `0x3`; MPU-регионы flash/RAM/TCM как cacheable;
  `SIU->RAMCTRL/TCMCTRL/CRAMCTRL = (3<<RM)|RMEN` (макс. скорость).
- Если включать — обязательно выравнивание секций/буферов по кэш-линии
  (`CL_SIZE=16`) и флаш данных перед чтением, изменённых DMA/периферией.
- Вывод: **«кэш ОЗУ» не был причиной проблем** — он просто выключен.

## 5. Обработчик исключений (trap)

- Штатный `trap_handler` (`plic.c`) на **любое исключение** уходит в
  `while(1)` — «ни одного байта наружу» без внешних признаков.
- Добавлен захват в глобалы `trap_mcause/trap_mepc/trap_mtval` (адреса в RAM
  видны в отладчике). `mcause & 0x1F`: 0=instr-misalign, 1=instr-access,
  2=illegal, 3=breakpoint, 4=load-misalign, 5=load-access, 6=store-misalign,
  7=store-access, 11=ecall.
- Этим подтвердили, что Debug-сборка раньше **падала в trap**; после правок
  (§2, §3) trap ушёл.

## 6. Переход бутлоадер → приложение (`firmware/vg5t/bootloader.c`)

Было (неполно):
```c
clear_csr(mstatus, MSTATUS_MIE);
write_csr(mie, 0);
app_reset();            // прыжок на _app_start_addr (0x1000)
```
Эталон НИИЭТ (`protocol_do_jump` в `riscv_cmake_sdk`, `boot_jump_to_app` в
DFU-примере) делает ещё `csrw mip, zero`, `fence`, **`fence.i`** (и в DFU —
проверку валидности `sp/pc`). Приведено к:
```c
clear_csr(mstatus, MSTATUS_MIE);
write_csr(mie, 0);
asm volatile("csrw mip, zero" ::: "memory");
FLASH->CTRL_bit.CFLUSH = 1;  (void)FLASH->CTRL;   // сброс fetch-буфера (FBEN!)
fence();
ifence();
app_reset();
```
Приложение (`esc-firmware`) линкуется тем же SDK-стартапом: его `_start`
(`.text.startup`) на `0x1000` сам инициализирует `mstatus/sp/gp/mtvec`,
копирует `.data/.sdata`, чистит `.bss` и вызывает `main()` — поэтому
установка `sp/mtvec` из «векторной таблицы» не требуется.
**Внимание:** вызовы `jumpToMainApp()` сейчас раскомментированы в `main.c`
(фазы `checkForSignal` и защита по `invalid_command`).

## 7. Отладка: OpenOCD work-area (перекрытие RAM) и CHIPID

- `target/k1921vg5t.cfg` (НИИЭТ, клонируется devcontainer-ом) задаёт
  `-work-area-phys 0x20000000 -work-area-size 0x4000 -work-area-backup 0` —
  это **вся 16 КБ RAM**, ровно где `.data/.bss/rxBuffer` (0x20000000…) и стек
  (0x20003800…). На больших чтениях отладчик затирает переменные прошивки
  (`address`, `cmd`, `rxBuffer`) → отвал/мусор, и «перетёртый address» → `C1`.
  Исправление — локальный `esc-bootloader/.vscode/vg5t-workarea-fix.cfg`:
  `K1921VG5T.cpu configure -work-area-phys 0x20000800 -work-area-size 0x2000 …`
  + щедрые таймауты; подключается в `launch.json` после `target/k1921vg5t.cfg`.
- Предсобранный `openocd-niiet` ожидает CHIPID `0x4e4c400`, реальный кремний
  даёт `0x4e4c300` — два `cmp` в бинаре патчатся в `.devcontainer/Dockerfile`
  (`81 fa 00 c4 e4 04` → `81 fa 00 c3 e4 04`), иначе `flash probe` падает.
- Если после плохой прошивки DTM не отвечает (`dtmcontrol is 0`) — сделать
  service-mode erase (удержание пина/кнопки), а не «дожимать» reset-командами.

## 8. EEPROM — кто владеет и что валидно

- EEPROM = 192 Б @ `0xF000` (`esc-firmware/firmware/inc/eeprom.h`, `EEprom_t`).
  Байт 1 `eeprom_version` (= `LAYOUT_REVISION` в конфигураторе), байт 2
  `bootloader_version` (владеет бутлоадер).
- Бутлоадер `update_EEPROM()` (при software-reset) читает 256 Б и штампует
  только `byte[2] = BOOTLOADER_VERSION_NUM`; остальное оставляет как есть.
- **Инициализирует EEPROM приложение**: `main.c` при несовпадении
  `FIRMWARE_VERSION_*`/`EEPROM_VERSION` пишет версии и `saveEEpromSettings()`;
  `loadEEpromSettings()` требует `eeprom_version ∈ [1,4]` и
  `bootloader_version ∈ [1,254]`, иначе morse-код ошибки + reset.
- Пока приложение не запускалось — EEPROM пустой (0xFF), конфигуратор читает
  невалидные поля. **Практика:** сначала прошить/запустить приложение, потом
  работать конфигуратором.

## 9. Тайминги бит-банга (наблюдение; НЕ меняли)

- Бит-банг ESC ≈ 53–54 мкс при 19200 (52.08 мкс) — на ~3–4 % медленнее
  (накладные `delayMicroseconds` + возможная частота ядра).
- В `sendString` есть лишний `delayMicroseconds(BITTIME)` после каждого байта
  (+~17 % ко времени ответа). Из-за этого **большое одиночное чтение** (184 Б
  EEPROM = 187 Б ответа, ~100+ мс) не укладывается в таймаут 4-way FC →
  `ACK_D_GENERAL_ERROR`.
- **Решено не трогать:** это вмешательство в общий код; без него всё работает,
  а большие чтения конфигуратор обходит постранично (см. §10).

## 10. Конфигуратор (`am32-configurator`)

- Подробный лог 4-way на страницу: TX/RX сырыми байтами, разбор
  `cmd/addr/paramCount/ack/csum` и причина отказа; в `serial.ts` — сырые куски
  и почему пакет не собран. Заодно исправлена путаница `logError`/`logWarning`
  в конструкторе `FourWay`.
- EEPROM читается **постранично** (`readChunked`, по 32 Б с логом) — обход
  падения большого чтения; read-back в `writeSettings` тоже постраничный.
- Из логов подтверждено: ESC на канале 1 (init target 0 → 0x0F, target 1 → OK);
  малое чтение (deviceId `GDG08A12SMV1` @0xEFE0) проходит, большое падало.

## 11. Периферия приложения (по `VG5T_PORT_REPORT.md`)

- Сигнальный пин = **PA14 = TMR0_IO** (у vk035 был другой) — DShot RX (CAPCOM +
  DMA) и GCR TX нативно на TMR0; TMR1 = коммутация, TMR2 = zero-cross, TMR3 =
  задержки; 20 кГц тик — на mtimer; PLIC вместо NVIC; `SIU->CNTEN` включает
  TMR/PWM; `FLASH_*` (plib5t) с гранулой 8 Б / страницей 1 КБ.
- Клок настраивает бутлоадер (`SystemInit`), приложение зовёт только
  `SystemCoreClockUpdate()`.

## 12. Тулзы / окружение

- Компилятор бутлоадера и приложения vg5t: NIIET/CloudBear `riscv32-unknown-elf`
  GCC 14.1.0 с multilib `rv32imafc_zicsr/ilp32f` (`/opt/riscv-gnu-toolchain`).
- WCH CH32V203: только официальный `riscv-none-embed-gcc` 8.2.0 (MounRiver) —
  generic GCC мискомпилит WCH fast-interrupt прологи. Нативный Linux-вариант
  ставится `dependencies/tools/risc/install-risc-toolchain-linux.sh`.
- OpenOCD: `openocd-niiet` (патч CHIPID) для vg5t, `openocd-k1921vk` для vk035,
  `openocd-wch` для v203. SVD: `K1921VG5T.svd`.
- Аппаратный референс, с которого брались рабочие паттерны: VG7T (то же ядро
  SCR4) — `rabidrabbit/k1921vg7t_simple`, `niiet/riscv_cmake_sdk`.
