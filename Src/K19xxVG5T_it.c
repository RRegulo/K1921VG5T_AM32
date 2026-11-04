/* AM32 interrupt handlers for K1921VG5T. */
#include "main.h"
#include "common.h"
#include "comparator.h"
#include "functions.h"
#include "peripherals.h"
#include "csr.h"
#include "arch.h"

extern void PeriodElapsedCallback(void);
extern void tenKhzRoutine(void);
extern void interruptRoutine(void);
extern volatile uint16_t adc_voltage;

void PlicIrqSetup(void) {
    PLIC_SetThreshold(Plic_Mach_Target, 0);

    // commutation timer TMR1
    PLIC_SetIrqHandler(Plic_Mach_Target, IsrVect_IRQ_TMR1, COM_TIMER_IRQHandler);
    PLIC_SetMode(IsrVect_IRQ_TMR1, PLIC_IRQMODE_HILEVEL);
    PLIC_SetPriority(IsrVect_IRQ_TMR1, 7);

    // BEMF comparator inputs on GPIOB
    PLIC_SetIrqHandler(Plic_Mach_Target, IsrVect_IRQ_GPIOB, GPIOB_IRQHandler);
    PLIC_SetMode(IsrVect_IRQ_GPIOB, PLIC_IRQMODE_HILEVEL);
    PLIC_SetPriority(IsrVect_IRQ_GPIOB, 6);

    // ADC sequencer 0
    PLIC_SetIrqHandler(Plic_Mach_Target, IsrVect_IRQ_ADC_SEQ0, ADC_SEQ0_IRQHandler);
    PLIC_SetMode(IsrVect_IRQ_ADC_SEQ0, PLIC_IRQMODE_HILEVEL);
    PLIC_SetPriority(IsrVect_IRQ_ADC_SEQ0, 4);
}

__RAMFUNC void MTIMER_IRQHandler(void) {
    mtimerRearm(); // MTIMECMP write also drops the MTI request

    /* Let PLIC interrupts (commutation, BEMF, PWM input) preempt the long
     * 20 kHz routine. A nested trap overwrites mepc/mstatus.MPIE/MPP, so they
     * are saved here and restored before returning to irq_entry's mret.
     * MTI itself stays masked to avoid re-entering this handler. */
    uint32_t saved_mepc = read_csr(mepc);
    uint32_t saved_mstatus = read_csr(mstatus);
    clear_csr(mie, MIE_MTIMER);
    set_csr(mstatus, MSTATUS_MIE);
    tenKhzRoutine();
    clear_csr(mstatus, MSTATUS_MIE);
    write_csr(mepc, saved_mepc);
    write_csr(mstatus, saved_mstatus);
    set_csr(mie, MIE_MTIMER);
}

__RAMFUNC void COM_TIMER_IRQHandler(void) {
    COM_TIMER->IM_bit.TMR = 0; // one-shot: re-armed by setAndEnableComInt()
    COM_TIMER->IC = TMR_IC_TMR_Msk;
    PeriodElapsedCallback();
}
__RAMFUNC void GPIOB_IRQHandler() {
    if (step == 1 || step == 4) { // c floating
        if (GPIOB->INTSTATUS_bit.PIN6) {
            GPIOB->INTSTATUS = 0xFFFFFFFF;
            if (COMPARATOR_REGISTER->INTENSET_bit.PIN6) {
                interruptRoutine();
            }
            return;
        }
    } else if (step == 2 || step == 5) { // a floating
        if (GPIOB->INTSTATUS_bit.PIN4) {
            GPIOB->INTSTATUS = 0xFFFFFFFF;
            if (COMPARATOR_REGISTER->INTENSET_bit.PIN4) {
                interruptRoutine();
            }
            return;
        }
    } else if (step == 3 || step == 6) { // b floating
        if (GPIOB->INTSTATUS_bit.PIN5) {
            GPIOB->INTSTATUS = 0xFFFFFFFF;
            if (COMPARATOR_REGISTER->INTENSET_bit.PIN5) {
                interruptRoutine();
            }
            return;
        }
    }
    /* flag of a pin that is not the floating phase of the current step
     * (step changed between edge and IRQ): drop it, otherwise the level
     * triggered PLIC line would re-enter this handler forever */
    GPIOB->INTSTATUS = 0xFFFFFFFF;
}

void ADC_SEQ0_IRQHandler(void) {
    ADC_SEQ_ITStatusClear(ADC_SEQ_Num_0);
    adc_voltage = ADC_SEQ_GetFIFOData(ADC_SEQ_Num_0);
}
