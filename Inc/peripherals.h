/* AM32 peripheral interface for K1921VG5T. */
#pragma once
#include "main.h"
#include "ADC.h"
#include "functions.h"
#include "targets.h"

#define INTERVAL_TIMER_COUNT (getintervaTimerCount())
#define RELOAD_WATCHDOG_COUNTER() (WDT->INTCLR = 1)
#define DISABLE_COM_TIMER_INT() (COM_TIMER->IM_bit.TMR = 0)
#define COM_TIMER_CLEAR_PENDING() (COM_TIMER->IC = TMR_IC_TMR_Msk)
#define SET_AND_ENABLE_COM_INT(time) (setAndEnableComInt(time))
#define SET_INTERVAL_TIMER_COUNT(time) (setintervaTimerCount(time))
#define SET_PRESCALER_PWM(value) (setPrescalerPWM(value))

extern volatile uint32_t vg5t_pwm_prd_last, vg5t_pwm_cmp_last;
static inline void vg5tSetAutoReloadPwm(uint32_t relval)
{
    if (relval != vg5t_pwm_prd_last) {
        const uint32_t irq = irq_save();
        PWM0->TBPRD = relval;
        PWM1->TBPRD = relval;
        PWM2->TBPRD = relval;
        vg5t_pwm_prd_last = relval;
        irq_restore(irq);
    }
}
static inline void vg5tSetDutyAllPwm(uint32_t newdc)
{
    if (newdc != vg5t_pwm_cmp_last) {
        const uint32_t irq = irq_save();
        const uint32_t cmpa = newdc << PWM_CMPA_CMPA_Pos;
        const uint32_t cmpb = newdc << PWM_CMPB_CMPB_Pos;
        PWM0->CMPA = cmpa;
        PWM0->CMPB = cmpb;
        PWM1->CMPA = cmpa;
        PWM1->CMPB = cmpb;
        PWM2->CMPA = cmpa;
        PWM2->CMPB = cmpb;
        vg5t_pwm_cmp_last = newdc;
        irq_restore(irq);
    }
}
#if VG5T_PWM_CACHE
#define SET_AUTO_RELOAD_PWM(value) vg5tSetAutoReloadPwm(value)
#define SET_DUTY_CYCLE_ALL(value) vg5tSetDutyAllPwm(value)
#else
#define SET_AUTO_RELOAD_PWM(value) (PWM0->TBPRD = value, PWM1->TBPRD = value, PWM2->TBPRD = value)
#define SET_DUTY_CYCLE_ALL(value)                                                                  \
    (PWM0->CMPA_bit.CMPA = value, PWM0->CMPB_bit.CMPB = value, PWM1->CMPA_bit.CMPA = value,        \
     PWM1->CMPB_bit.CMPB = value, PWM2->CMPA_bit.CMPA = value, PWM2->CMPB_bit.CMPB = value)
#endif

void initCorePeripherals(void);
#if VG5T_CACHE
void vg5tCacheInit(void);
#endif
void enableCorePeripherals(void);
void ALL_GPIO_Init(void);
void ALL_COMP_Init(void);
void PWM_TIM1_Init(void);
void ZC_TIM2_Init(void);
void COM_TIM1_Init(void);
void MX_IWDG_Init(void);
void MX_TIM16_Init(void);
void TENKHz_SysTick_Init(void);
void UN_TIM0_Init(void);
void resetInputCaptureTimer(void);
void setAndEnableComInt(uint16_t time);
void setPrescalerPWM(uint16_t presc);
uint16_t getintervaTimerCount(void);
void setintervaTimerCount(uint16_t time);
void mtimerRearm(void);
void PlicIrqSetup(void);
void MTIMER_IRQHandler(void);
void COM_TIMER_IRQHandler(void);
void GPIOB_IRQHandler(void);
void ADC_SEQ0_IRQHandler(void);
