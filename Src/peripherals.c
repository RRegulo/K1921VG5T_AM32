/*
 * peripherals.c — K1921VG5T (NIIET RISC-V, SCR4), 96 MHz PLL from 16 MHz HSE
 *
 * Timer allocation:
 *   TMR0 — Servo PWM input capture on PA14 (TMR0_IO)
 *   TMR1 — commutation timer (COM_TIMER, "up" mode, IRQ at COUNT == PERIOD)
 *   TMR2 — zero-cross interval timer (INTERVAL_TIMER, free running)
 *   TMR3 — free running us-delay time base (DELAY_TIMER)
 *   mtimer (RISC-V machine timer) — 20 kHz control loop tick
 *
 * Every APB/AHB block is clock-gated and held in reset after power-up
 * (UM_K1921VG5T 6.4, p.31): each init below opens CGCFGxxx + RSTDISxxx for
 * the block it uses. The bootloader only enables GPIOA.
 *
 *  Created on: Sep. 26, 2020
 *      Author: Alka
 *      Ported to K1921VG5T, 2026
 */

// PERIPHERAL SETUP
#include "peripherals.h"

#include "ADC.h"
#include "common.h"
#include "functions.h"
#include "targets.h"
#if VG5T_CACHE || VG5T_IRQ_NO_FP
#include "arch.h"
#include "csr.h"
#endif

/* TMR is clocked by SYSCLK; interval/com time is kept in 0.5 us units
 * like on K19XXVK035 (/(CPU_FREQUENCY_MHZ/2)). */
#define TIMER_TICKS_PER_HALFUS (CPU_FREQUENCY_MHZ / 2)

volatile uint32_t vg5t_pwm_prd_last = 0xFFFFFFFFu;
volatile uint32_t vg5t_pwm_cmp_last = 0xFFFFFFFFu;

#if VG5T_CACHE
/* Exact MPU region sequence from the working VG5T vg5tCacheInit(). */
#define VG5T_MPU_SEL  (SCR_CSR_MPU_BASE + 0)
#define VG5T_MPU_CTRL (SCR_CSR_MPU_BASE + 1)
#define VG5T_MPU_ADDR (SCR_CSR_MPU_BASE + 2)
#define VG5T_MPU_MASK (SCR_CSR_MPU_BASE + 3)
#define VG5T_CACHE_GLBL 0xbd4

static void vg5tMpuRegion(uint32_t entry, uint32_t addr, uint32_t size, uint32_t ctrl)
{
    write_csr(VG5T_MPU_SEL, entry);
    write_csr(VG5T_MPU_CTRL, 0);
    write_csr(VG5T_MPU_ADDR, addr >> 2);
    write_csr(VG5T_MPU_MASK, (~(size - 1u)) >> 2);
    write_csr(VG5T_MPU_CTRL, ctrl);
}

void vg5tCacheInit(void)
{
    write_csr(VG5T_CACHE_GLBL, 0xC);
    __asm__ volatile("fence.i" ::: "memory");
    while (read_csr(VG5T_CACHE_GLBL) & 0xC) {
    }
#if VG5T_MEM_MARGIN
    SIU->RAMCTRL = (3 << SIU_RAMCTRL_RM_Pos) | SIU_RAMCTRL_RMEN_Msk;
    SIU->TCMCTRL = (3 << SIU_TCMCTRL_RM_Pos) | SIU_TCMCTRL_RMEN_Msk;
    SIU->CRAMCTRL = (3 << SIU_CRAMCTRL_RM_Pos) | SIU_CRAMCTRL_RMEN_Msk;
#endif
    write_csr(VG5T_CACHE_GLBL, 0x3);

    vg5tMpuRegion(1, 0x00000000u, 0x100000u, 0x7Fu);
    vg5tMpuRegion(2, 0x20000000u, 0x40000u, 0x7Fu);
    vg5tMpuRegion(3, 0xF0000000u, 0x8000u, 0x2007Fu);
    vg5tMpuRegion(5, 0x40000000u, 0x2000000u, 0x1007Fu);
    vg5tMpuRegion(6, 0x50000000u, 0x2000000u, 0x1007Fu);
    vg5tMpuRegion(7, 0xFE000000u, 0x2000000u, 0x1007Fu);
    __asm__ volatile("fence.i" ::: "memory");
    write_csr(VG5T_MPU_SEL, 0);
    write_csr(VG5T_MPU_CTRL, 0);
}
#endif

/* open clock gate + release reset of an APB block (UM 6.4, table 6.4) */
#define APB_ENABLE(name)                                                                           \
    do {                                                                                           \
        RCU->CGCFGAPB_bit.name = 1;                                                                \
        RCU->RSTDISAPB_bit.name = 1;                                                               \
    } while (0)

void setPrescalerPWM(uint16_t presc){
  if(presc == 0) {
    PWM0->TBCTL_bit.CLKDIV = PWM_TBCTL_CLKDIV_Div2;        //12 KHz
    PWM1->TBCTL_bit.CLKDIV = PWM_TBCTL_CLKDIV_Div2;        //12 KHz
    PWM2->TBCTL_bit.CLKDIV = PWM_TBCTL_CLKDIV_Div2;        //12 KHz
    PWM0->TBCTL_bit.HSPCLKDIV = PWM_TBCTL_HSPCLKDIV_Div1; //48 KHz
    PWM1->TBCTL_bit.HSPCLKDIV = PWM_TBCTL_HSPCLKDIV_Div1; //48 KHz
    PWM2->TBCTL_bit.HSPCLKDIV = PWM_TBCTL_HSPCLKDIV_Div1; //48 KHz
  }
  if(presc == 10) {
    PWM0->TBCTL_bit.HSPCLKDIV = PWM_TBCTL_HSPCLKDIV_Div10;
    PWM1->TBCTL_bit.HSPCLKDIV = PWM_TBCTL_HSPCLKDIV_Div10;
    PWM2->TBCTL_bit.HSPCLKDIV = PWM_TBCTL_HSPCLKDIV_Div10;
  }
  else if(presc == 20) {
    PWM0->TBCTL_bit.CLKDIV = PWM_TBCTL_CLKDIV_Div2;
    PWM1->TBCTL_bit.CLKDIV = PWM_TBCTL_CLKDIV_Div2;
    PWM2->TBCTL_bit.CLKDIV = PWM_TBCTL_CLKDIV_Div2;
    PWM0->TBCTL_bit.HSPCLKDIV = PWM_TBCTL_HSPCLKDIV_Div10;
    PWM1->TBCTL_bit.HSPCLKDIV = PWM_TBCTL_HSPCLKDIV_Div10;
    PWM2->TBCTL_bit.HSPCLKDIV = PWM_TBCTL_HSPCLKDIV_Div10;
  }
  else if(presc == 25) {
    PWM0->TBCTL_bit.CLKDIV = PWM_TBCTL_CLKDIV_Div2;
    PWM1->TBCTL_bit.CLKDIV = PWM_TBCTL_CLKDIV_Div2;
    PWM2->TBCTL_bit.CLKDIV = PWM_TBCTL_CLKDIV_Div2;
    PWM0->TBCTL_bit.HSPCLKDIV = PWM_TBCTL_HSPCLKDIV_Div12;
    PWM1->TBCTL_bit.HSPCLKDIV = PWM_TBCTL_HSPCLKDIV_Div12;
    PWM2->TBCTL_bit.HSPCLKDIV = PWM_TBCTL_HSPCLKDIV_Div12;
  }
  else if(presc == 30) {
    PWM0->TBCTL_bit.CLKDIV = PWM_TBCTL_CLKDIV_Div2;
    PWM1->TBCTL_bit.CLKDIV = PWM_TBCTL_CLKDIV_Div2;
    PWM2->TBCTL_bit.CLKDIV = PWM_TBCTL_CLKDIV_Div2;
    PWM0->TBCTL_bit.HSPCLKDIV = PWM_TBCTL_HSPCLKDIV_Div14;
    PWM1->TBCTL_bit.HSPCLKDIV = PWM_TBCTL_HSPCLKDIV_Div14;
    PWM2->TBCTL_bit.HSPCLKDIV = PWM_TBCTL_HSPCLKDIV_Div14;
  }
  else if(presc == 40) {
    PWM0->TBCTL_bit.CLKDIV = PWM_TBCTL_CLKDIV_Div4;
    PWM1->TBCTL_bit.CLKDIV = PWM_TBCTL_CLKDIV_Div4;
    PWM2->TBCTL_bit.CLKDIV = PWM_TBCTL_CLKDIV_Div4;
    PWM0->TBCTL_bit.HSPCLKDIV = PWM_TBCTL_HSPCLKDIV_Div10;
    PWM1->TBCTL_bit.HSPCLKDIV = PWM_TBCTL_HSPCLKDIV_Div10;
    PWM2->TBCTL_bit.HSPCLKDIV = PWM_TBCTL_HSPCLKDIV_Div10;
  }
  else if(presc == 50) {
    PWM0->TBCTL_bit.CLKDIV = PWM_TBCTL_CLKDIV_Div4;
    PWM1->TBCTL_bit.CLKDIV = PWM_TBCTL_CLKDIV_Div4;
    PWM2->TBCTL_bit.CLKDIV = PWM_TBCTL_CLKDIV_Div4;
    PWM0->TBCTL_bit.HSPCLKDIV = PWM_TBCTL_HSPCLKDIV_Div12;
    PWM1->TBCTL_bit.HSPCLKDIV = PWM_TBCTL_HSPCLKDIV_Div12;
    PWM2->TBCTL_bit.HSPCLKDIV = PWM_TBCTL_HSPCLKDIV_Div12;
  }
  else if(presc == 55) {
    PWM0->TBCTL_bit.CLKDIV = PWM_TBCTL_CLKDIV_Div4;
    PWM1->TBCTL_bit.CLKDIV = PWM_TBCTL_CLKDIV_Div4;
    PWM2->TBCTL_bit.CLKDIV = PWM_TBCTL_CLKDIV_Div4;
    PWM0->TBCTL_bit.HSPCLKDIV = PWM_TBCTL_HSPCLKDIV_Div14;
    PWM1->TBCTL_bit.HSPCLKDIV = PWM_TBCTL_HSPCLKDIV_Div14;
    PWM2->TBCTL_bit.HSPCLKDIV = PWM_TBCTL_HSPCLKDIV_Div14;
  }
  else if(presc == 60) {
    PWM0->TBCTL_bit.CLKDIV = PWM_TBCTL_CLKDIV_Div8;
    PWM1->TBCTL_bit.CLKDIV = PWM_TBCTL_CLKDIV_Div8;
    PWM2->TBCTL_bit.CLKDIV = PWM_TBCTL_CLKDIV_Div8;
    PWM0->TBCTL_bit.HSPCLKDIV = PWM_TBCTL_HSPCLKDIV_Div8;
    PWM1->TBCTL_bit.HSPCLKDIV = PWM_TBCTL_HSPCLKDIV_Div8;
    PWM2->TBCTL_bit.HSPCLKDIV = PWM_TBCTL_HSPCLKDIV_Div8;
  }
  else if(presc == 70) {
    PWM0->TBCTL_bit.CLKDIV = PWM_TBCTL_CLKDIV_Div8;
    PWM1->TBCTL_bit.CLKDIV = PWM_TBCTL_CLKDIV_Div8;
    PWM2->TBCTL_bit.CLKDIV = PWM_TBCTL_CLKDIV_Div8;
    PWM0->TBCTL_bit.HSPCLKDIV = PWM_TBCTL_HSPCLKDIV_Div10;
    PWM1->TBCTL_bit.HSPCLKDIV = PWM_TBCTL_HSPCLKDIV_Div10;
    PWM2->TBCTL_bit.HSPCLKDIV = PWM_TBCTL_HSPCLKDIV_Div10;
  }
  else if(presc == 80) {
    PWM0->TBCTL_bit.CLKDIV = PWM_TBCTL_CLKDIV_Div8;
    PWM1->TBCTL_bit.CLKDIV = PWM_TBCTL_CLKDIV_Div8;
    PWM2->TBCTL_bit.CLKDIV = PWM_TBCTL_CLKDIV_Div8;
    PWM0->TBCTL_bit.HSPCLKDIV = PWM_TBCTL_HSPCLKDIV_Div12;
    PWM1->TBCTL_bit.HSPCLKDIV = PWM_TBCTL_HSPCLKDIV_Div12;
    PWM2->TBCTL_bit.HSPCLKDIV = PWM_TBCTL_HSPCLKDIV_Div12;
  }
  else if(presc == 90) {
    PWM0->TBCTL_bit.CLKDIV = PWM_TBCTL_CLKDIV_Div8;
    PWM1->TBCTL_bit.CLKDIV = PWM_TBCTL_CLKDIV_Div8;
    PWM2->TBCTL_bit.CLKDIV = PWM_TBCTL_CLKDIV_Div8;
    PWM0->TBCTL_bit.HSPCLKDIV = PWM_TBCTL_HSPCLKDIV_Div14;
    PWM1->TBCTL_bit.HSPCLKDIV = PWM_TBCTL_HSPCLKDIV_Div14;
    PWM2->TBCTL_bit.HSPCLKDIV = PWM_TBCTL_HSPCLKDIV_Div14;
  }
}


void initCorePeripherals(void) {
    PlicIrqSetup();
    ALL_GPIO_Init(); // gpio clock
    UN_TIM0_Init();  // PWM input capture timer
    PWM_TIM1_Init(); // 6 channels PWM
    ZC_TIM2_Init();  // zero cross timer
    ALL_COMP_Init(); // ALL comparer
    COM_TIM1_Init(); //
    MX_TIM16_Init(); // delay time base (needed by ADCInit)
    TENKHz_SysTick_Init();
}

void resetInputCaptureTimer() { IC_TIMER_REGISTER->COUNT = 0; }

void enableCorePeripherals() {
    COM_TIMER->IM_bit.TMR = 0;
    TMR_SetMode(COM_TIMER, TMR_Mode_Capcom_Up);

    ADCInit();
}

#define COMP_PINS_MSK (GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6)

void ALL_COMP_Init(void) {
    // BEMF comparator inputs PB4 (A), PB5 (B), PB6 (C) — GPIO edge interrupts.
    // PULLMODE is 1 bit per pin on VG5T (UM A.5, SVD), pull-up like on vk035.
    GPIOB->PULLMODE |= COMP_PINS_MSK;
    GPIOB->INTENCLR = COMP_PINS_MSK;
    GPIOB->INTTYPESET = COMP_PINS_MSK; // edge
    // single edge only: with INTEDGESET the polarity (INTPOL) is ignored and
    // every edge interrupts (UM 13.4) — changeCompInput() selects the edge.
    GPIOB->INTEDGECLR = COMP_PINS_MSK;
    GPIOB->INTSTATUS = COMP_PINS_MSK; // clear stale flags

    PLIC_IntEnable(Plic_Mach_Target, IsrVect_IRQ_GPIOB);
}

void MX_IWDG_Init(void) {
    /* The WDT clock is HSE 16 MHz. With LOAD = 3200000, the two-stage timeout
     * is 200 ms + 200 ms = 400 ms if RELOAD_WATCHDOG_COUNTER() is not called. */
    APB_ENABLE(WDTEN);
    RCU->WDTCFG_bit.CLKSEL = RCU_WDTCFG_CLKSEL_HSECLK;
    RCU->WDTCFG_bit.DIVEN = 0;
    RCU->WDTCFG_bit.CLKEN = 1;
    RCU->WDTCFG_bit.RSTDIS = 1;
    WDT->LOAD = 3200000;
    WDT->INTCLR = 1;
    WDT->CTRL_bit.RESEN = 1;
    WDT->CTRL_bit.INTEN = 1;
}

void PWM_TIM1_Init(void) // PWM
{
    APB_ENABLE(PWM0EN);
    APB_ENABLE(PWM1EN);
    APB_ENABLE(PWM2EN);

    // select AF1 (PWM0_A/B, PWM1_A/B, PWM2_A/B) and enable altfunc push-pull outputs
    GPIOA->ALTFUNCNUM_bit.PIN8 = 1;
    GPIOA->ALTFUNCNUM_bit.PIN9 = 1;
    GPIOA->ALTFUNCNUM_bit.PIN10 = 1;
    GPIOA->ALTFUNCNUM_bit.PIN11 = 1;
    GPIOA->ALTFUNCNUM_bit.PIN12 = 1;
    GPIOA->ALTFUNCNUM_bit.PIN13 = 1;

    PWM0->TBCTL_bit.CLKDIV = PWM_TBCTL_CLKDIV_Div2; // 48 MHz -> 24 KHz
    PWM0->TBCTL_bit.HSPCLKDIV = PWM_TBCTL_HSPCLKDIV_Div1;
    PWM1->TBCTL_bit.CLKDIV = PWM_TBCTL_CLKDIV_Div2; // 48 MHz -> 24 KHz
    PWM1->TBCTL_bit.HSPCLKDIV = PWM_TBCTL_HSPCLKDIV_Div1;
    PWM2->TBCTL_bit.CLKDIV = PWM_TBCTL_CLKDIV_Div2; // 48 MHz -> 24 KHz
    PWM2->TBCTL_bit.HSPCLKDIV = PWM_TBCTL_HSPCLKDIV_Div1;
    PWM0->ETPS_bit.SOCAPRD = 1;
    PWM0->ETSEL_bit.SOCAEN = 1;
    PWM0->ETSEL_bit.SOCASEL = PWM_ETSEL_INTSEL_CTREqZero;
    PWM0->TBPRD = TIM1_AUTORELOAD; // 24 KHz
    PWM0->AQCTLA_bit.PRD = PWM_AQCTLA_PRD_Set;
    PWM0->AQCTLA_bit.CAU = PWM_AQCTLA_CAU_Clear;
    PWM0->AQCTLB_bit.PRD = PWM_AQCTLB_PRD_Clear;
    PWM0->AQCTLB_bit.CBU = PWM_AQCTLB_CBU_Set;
    PWM1->TBPRD = TIM1_AUTORELOAD; // 24 KHz
    PWM1->AQCTLA_bit.PRD = PWM_AQCTLA_PRD_Set;
    PWM1->AQCTLA_bit.CAU = PWM_AQCTLA_CAU_Clear;
    PWM1->AQCTLB_bit.PRD = PWM_AQCTLB_PRD_Clear;
    PWM1->AQCTLB_bit.CBU = PWM_AQCTLB_CBU_Set;
    PWM2->TBPRD = TIM1_AUTORELOAD; // 24 KHz
    PWM2->AQCTLA_bit.PRD = PWM_AQCTLA_PRD_Set;
    PWM2->AQCTLA_bit.CAU = PWM_AQCTLA_CAU_Clear;
    PWM2->AQCTLB_bit.PRD = PWM_AQCTLB_PRD_Clear;
    PWM2->AQCTLB_bit.CBU = PWM_AQCTLB_CBU_Set;
    PWM0->DBRED = DEAD_TIME;
    PWM0->DBFED = DEAD_TIME;
    PWM0->DBCTL_bit.OUTMODE = 0x03;
    PWM0->DBCTL_bit.POLSEL = 0x02;
    PWM1->DBRED = DEAD_TIME;
    PWM1->DBFED = DEAD_TIME;
    PWM1->DBCTL_bit.OUTMODE = 0x03;
    PWM1->DBCTL_bit.POLSEL = 0x02;
    PWM2->DBRED = DEAD_TIME;
    PWM2->DBFED = DEAD_TIME;
    PWM2->DBCTL_bit.OUTMODE = 0x03;
    PWM2->DBCTL_bit.POLSEL = 0x02;
    PWM0->DBCTL_bit.INMODE = 0;
    PWM1->DBCTL_bit.INMODE = 0;
    PWM2->DBCTL_bit.INMODE = 0;

    // all six gates as driven-low GPIO outputs (FETs off) until comStep()/allOff()
    GPIOA->DATAOUTCLR =
        GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13;
    GPIOA->ALTFUNCCLR =
        GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13;
    GPIOA->OUTENSET =
        GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13;

    // one write enabling PWM0..2 starts all three counters in sync. OR-in:
    // TMR0EN was already set by UN_TIM0_Init() and must not be cleared.
    SIU->CNTEN |= SIU_CNTEN_PWM0EN_Msk | SIU_CNTEN_PWM1EN_Msk | SIU_CNTEN_PWM2EN_Msk;
}

void ZC_TIM2_Init(void) {
    // free-running zero-cross interval timer ("multiple" = 0..FFFF_FFFF)
    APB_ENABLE(TMR2EN);
    TMR_SetDivider(INTERVAL_TIMER, 0);
    INTERVAL_TIMER->COUNT = 0;
    TMR_SetMode(INTERVAL_TIMER, TMR_Mode_Multiple);
    SIU->CNTEN |= SIU_CNTEN_TMR2EN_Msk;
}

/* preset added into getintervaTimerCount() so that it returns the last
 * SET_INTERVAL_TIMER_COUNT() value immediately, like the vk035 down-counter */
static volatile uint32_t interval_preset_ticks = 0;

uint16_t getintervaTimerCount() {
    return (uint16_t)((INTERVAL_TIMER->COUNT + interval_preset_ticks) / TIMER_TICKS_PER_HALFUS);
}

void setintervaTimerCount(uint16_t intertime) {
    INTERVAL_TIMER->COUNT = 0;
    interval_preset_ticks = (uint32_t)intertime * TIMER_TICKS_PER_HALFUS;
}

void setAndEnableComInt(uint16_t time) {
    // "up" mode: TMR flag at COUNT == PERIOD, PERIOD + 1 ticks per cycle
    uint32_t period = (uint32_t)time * TIMER_TICKS_PER_HALFUS;
    COM_TIMER->COUNT = 0;
    COM_TIMER->PERIOD = (period > 1u) ? (period - 1u) : 1u;
    COM_TIMER->IC = TMR_IC_TMR_Msk;
    COM_TIMER->IM_bit.TMR = 1;
}

/* ---------------- 20 kHz control loop tick (RISC-V mtimer) ----------------- */
#define MTIMER_TICK_CLOCKS (MTIME_FREQ_HZ / LOOP_FREQUENCY_HZ)
static uint64_t mtimer_next_cmp;

/* called from MTIMER_IRQHandler: re-arm on an absolute grid (no drift from
 * handler latency), resync if we ever fell behind. Writing MTIMECMP clears MTI. */
void mtimerRearm(void) {
    uint64_t now = mtimer_get_raw_time();
    mtimer_next_cmp += MTIMER_TICK_CLOCKS;
    if ((int64_t)(mtimer_next_cmp - now) <= 0) {
        mtimer_next_cmp = now + MTIMER_TICK_CLOCKS;
    }
    mtimer_set_raw_time_cmp_abs(mtimer_next_cmp);
}

void TENKHz_SysTick_Init(void) {
    /* mtimer is only reachable through an MTYPE=3 MPU region on the core MMCFG
     * window 0xE0000000 (UM 10.1/10.5) — mtimer_mpu_init() maps it and lets it
     * count the 96 MHz core clock. */
    mtimer_mpu_init();
    riscv_irq_init();
#if VG5T_IRQ_NO_FP
    extern void vg5t_irq_entry(void);
    write_csr(mtvec, (uint32_t)vg5t_irq_entry);
#endif
    riscv_irq_set_handler(RISCV_IRQ_MTI, MTIMER_IRQHandler);
    // route external (PLIC) interrupts through the same trap entry
    riscv_irq_set_handler(RISCV_IRQ_MEI, PLIC_MachHandler);
    mtimer_next_cmp = mtimer_get_raw_time() + MTIMER_TICK_CLOCKS;
    mtimer_set_raw_time_cmp_abs(mtimer_next_cmp);
    riscv_irq_enable(RISCV_IRQ_MTI);
    riscv_irq_enable(RISCV_IRQ_MEI);
}

void COM_TIM1_Init(void) {
    APB_ENABLE(TMR1EN);
    TMR_SetDivider(COM_TIMER, 0);
    COM_TIMER->IM = 0;
    COM_TIMER->COUNT = 0;
    COM_TIMER->PERIOD = 0xFFFFFFFF;
    TMR_SetMode(COM_TIMER, TMR_Mode_Stop);
    COM_TIMER->IC = TMR_IC_TMR_Msk | TMR_IC_CAPCOM0_0_Msk | TMR_IC_CAPCOM0_1_Msk;
    SIU->CNTEN |= SIU_CNTEN_TMR1EN_Msk;
    PLIC_IntEnable(Plic_Mach_Target, IsrVect_IRQ_TMR1);
}

void MX_TIM16_Init(void) {
    // free running time base for delayMicros() (functions.c)
    APB_ENABLE(TMR3EN);
    TMR_SetDivider(DELAY_TIMER, 0);
    DELAY_TIMER->COUNT = 0;
    TMR_SetMode(DELAY_TIMER, TMR_Mode_Multiple);
    SIU->CNTEN |= SIU_CNTEN_TMR3EN_Msk;
}

void ALL_GPIO_Init(void) {
    RCU->CGCFGAHB_bit.GPIOBEN = 1;
    RCU->RSTDISAHB_bit.GPIOBEN = 1;
    RCU->CGCFGAHB_bit.GPIOAEN = 1;
    RCU->RSTDISAHB_bit.GPIOAEN = 1;
}
void UN_TIM0_Init(void) {
    APB_ENABLE(TMR0EN);

    // PA14 -> AF1 = TMR0_IO, alternate function input
    GPIOA->ALTFUNCNUM_bit.PIN14 = 1;
    GPIOA->ALTFUNCSET = GPIO_Pin_14;
    GPIOA->OUTENCLR = GPIO_Pin_14;

    // capture source for TMR0 CCIA = external pin TMR0_IO (SIU->TMRMUX.TMR0CCIA = 0)
    SIU->TMRMUX_bit.TMR0CCIA = 0x0;

    // TMR0 free-running, CAPCOM in capture mode on both edges, output disabled
    TMR_SetMode(IC_TIMER_REGISTER, TMR_Mode_Stop);
    IC_TIMER_REGISTER->CTRL_bit.OUTEN = 0;
    TMR_SetDivider(IC_TIMER_REGISTER, 0);
    IC_TIMER_REGISTER->IM = 0;
    IC_TIMER_REGISTER->COUNT = 0;
    IC_TIMER_REGISTER->PERIOD = 0xFFFFFFFF;
    IC_TIMER_REGISTER->CAPCOM[0].CTRL_bit.OUTMODE = 0;
    IC_TIMER_REGISTER->CAPCOM[0].CTRL_bit.CAP = 1;     // capture mode
    IC_TIMER_REGISTER->CAPCOM[0].CTRL_bit.CCISEL = 0;  // CCIA
    IC_TIMER_REGISTER->CAPCOM[0].CTRL_bit.CAPMODE = 3; // both edges
    IC_TIMER_REGISTER->DMA_TXIM = 0;
    IC_TIMER_REGISTER->DMA_RXIM = 0;
    IC_TIMER_REGISTER->IC = TMR_IC_TMR_Msk | TMR_IC_CAPCOM0_0_Msk | TMR_IC_CAPCOM0_1_Msk;

    TMR_SetMode(IC_TIMER_REGISTER, TMR_Mode_Multiple);

    SIU->CNTEN |= SIU_CNTEN_TMR0EN_Msk;
}
