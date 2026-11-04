#include "ADC.h"
#include "common.h"
#include "functions.h"
#include "targets.h"

volatile uint16_t adc_voltage;
extern uint16_t ADC_raw_volts;

void ADC_DMA_Callback(void) { ADC_raw_volts = adc_voltage; }

void ADCInit(void) {
    RCU->CGCFGAHB_bit.ADCEN = 1;
    RCU->RSTDISAHB_bit.ADCEN = 1;
    RCU->ADCCFG_bit.CLKSEL = RCU_ADCCFG_CLKSEL_PLLCLK;
    RCU->ADCCFG_bit.DIVN = 1;
    RCU->ADCCFG_bit.DIVEN = 1;
    RCU->ADCCFG_bit.CLKEN = 1;
    RCU->ADCCFG_bit.RSTDIS = 1;
    ADC->ACTL_bit.SELRES = 3;
    ADC->ACTL_bit.CALEN = 1;
    ADC->ACTL_bit.DISLVL = 0;
    ADC->ACTL_bit.ADCENLDO = 1;
    ADC->ACTL_bit.ADCEN = 1;
    delayMicros(50);
    ADC->ACTL_bit.ADCSTART = 1;
    ADC->EMUX_bit.EM0 = ADC_EMUX_EM0_PWM0A;
    ADC->SEQ[0].SCCTL_bit.ICNT = 0;
    ADC->SEQ[0].SRQCTL_bit.RQMAX = 0;
    ADC->SEQ[0].SRQSEL_bit.RQ0 = 0;
    ADC->SEQEN_bit.SEQEN0 = 1;
    ADC->IM_bit.SEQIM0 = 1;
    PLIC_IntEnable(Plic_Mach_Target, IsrVect_IRQ_ADC_SEQ0);
}
