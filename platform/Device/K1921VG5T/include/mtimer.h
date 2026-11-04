#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>

/* SCR4 memory-mapped Mtimer (UM_K1921VG5T 10.1, table 10.56):
 *   +0x00 CONTROL, +0x04 DIVIDER, +0x08 MTIME(LO/HI), +0x10 MTIMECMP(LO/HI).
 * The block only answers inside an MPU region with MTYPE=3 ("CPU mapped
 * config", UM 10.5); its base is the core MMCFG window 0xE0000000 (the
 * upstream SiFive-CLINT addresses 0x02004000/0x0200BFF8 and plf.h's
 * 0xF0040000 both fault on silicon). Call mtimer_mpu_init() once before
 * touching any mtimer_* function. */
#define RISCV_MMCFG_BASE    (0xE0000000UL)
#define RISCV_MMCFG_SIZE    (0x01000000UL)
#define RISCV_MTIMER_BASE   (RISCV_MMCFG_BASE)
#define RISCV_MTIMER_CTRL_ADDR (RISCV_MTIMER_BASE + 0x00)
#define RISCV_MTIMER_DIV_ADDR  (RISCV_MTIMER_BASE + 0x04)
#define RISCV_MTIME_ADDR    (RISCV_MTIMER_BASE + 0x08)
#define RISCV_MTIMECMP_ADDR (RISCV_MTIMER_BASE + 0x10)
/* MPU entry used for the MMCFG window (entries 0..3 are used by cache_enable()) */
#define RISCV_MTIMER_MPU_ENTRY 4

#ifndef MTIME_FREQ_HZ
	#if defined SYSCLK_HSI
		#define MTIME_FREQ_HZ 1000000ULL
	#elif defined SYSCLK_HSE
		#define MTIME_FREQ_HZ HSECLK_VAL
	#else
		#define MTIME_FREQ_HZ 50000000ULL
	#endif
#endif

#define MTIMER_SECONDS_TO_CLOCKS(SEC)           \
    ((uint64_t)(((SEC)*(MTIME_FREQ_HZ))))

#define MTIMER_MSEC_TO_CLOCKS(MSEC)           \
    ((uint64_t)(((MSEC)*(MTIME_FREQ_HZ))/1000))

#define MTIMER_USEC_TO_CLOCKS(USEC)           \
    ((uint64_t)(((USEC)*(MTIME_FREQ_HZ))/1000000))

/** Set the raw time compare point in system timer clocks.
 * @param clock_offset Time relative to current mtime when 
 * @note The time range of the 64 bit timer is large enough not to consider a wrap around of mtime.
 * An interrupt will be generated at mtime + clock_offset.
 * See http://five-embeddev.com/riscv-isa-manual/latest/machine.html#machine-timer-registers-mtime-and-mtimecmp
 */
/** Map the Mtimer (MMCFG window) with an MTYPE=3 MPU entry; enable the
 * timer counting on the core clock without divider. */
void mtimer_mpu_init(void);

/** Set the absolute compare value (raw clocks). */
void mtimer_set_raw_time_cmp_abs(uint64_t mtimecmp);

void mtimer_set_raw_time_cmp(uint64_t clock_offset);

/** Read the raw time of the system timer in system timer clocks
 */
uint64_t mtimer_get_raw_time(void);

void sleep(uint32_t ms);
void usleep(uint32_t us);

#endif // #ifdef TIMER_H

