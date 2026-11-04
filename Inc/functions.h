/* AM32, Alka. */
#pragma once
#include "main.h"
#include "riscv-csr.h"
#include "riscv-irq.h"

static inline uint32_t irq_save(void) {
    const uint32_t state = (uint32_t)csr_read_mstatus() & MSTATUS_MIE_BIT_MASK;
    riscv_irq_global_disable();
    return state;
}

static inline void irq_restore(uint32_t state) {
    if (state) {
        riscv_irq_global_enable();
    }
}

uint32_t getAbsDif(int number1, int number2);
void delayMicros(uint32_t micros);
void delayMillis(uint32_t millis);
long map(long x, long in_min, long in_max, long out_min, long out_max);
