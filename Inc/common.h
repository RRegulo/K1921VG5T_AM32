#pragma once
#include "eeprom.h"
#include "riscv-irq.h"

#define __RAMFUNC
#define __disable_irq() riscv_irq_global_disable()
#define __enable_irq() riscv_irq_global_enable()
#ifdef VG5T_DEBUG_NO_RESET
#define NVIC_SystemReset() (signaltimeout = 0)
#else
#define NVIC_SystemReset() (RCU->RSTSYS = 0xA55A0001UL)
#endif

extern EEprom_t eepromBuffer;
extern uint16_t TIMER1_MAX_ARR;
extern volatile uint16_t adjusted_input;
extern volatile uint16_t zero_input_count;
extern volatile uint16_t signaltimeout;
extern volatile uint16_t input;
extern volatile uint16_t newinput;
extern volatile char inputSet;
extern volatile char forward;
extern volatile uint8_t running;
extern volatile uint8_t temp_comp_pwm;
extern volatile uint32_t average_interval;

/* Значение поля input_type в раскладке параметров AM32. */
enum inputType { SERVO_IN = 2 };
