/*
 * comparator.c — BEMF comparator inputs on GPIOB (PB4=A, PB5=B, PB6=C)
 *
 * VG5T comparator interrupt path copied from the working target reference:
 * only the floating phase is enabled, stale flags are cleared, and edge
 * polarity is selected before enabling the input.
 */
#include "comparator.h"
#include "common.h"
#include "targets.h"

#define COMP_A_MASK GPIO_Pin_4
#define COMP_B_MASK GPIO_Pin_5
#define COMP_C_MASK GPIO_Pin_6

__RAMFUNC void setCompEdge(char r);

static uint32_t floatingCompMask(void)
{
    if (step == 1 || step == 4) {
        return COMP_C_MASK;
    }
    if (step == 2 || step == 5) {
        return COMP_A_MASK;
    }
    if (step == 3 || step == 6) {
        return COMP_B_MASK;
    }
    return 0;
}

__RAMFUNC uint8_t getCompOutputLevel(void)
{
    if (step == 1 || step == 4) {
        return SET == GPIO_ReadBit(COMPARATOR_REGISTER, PHASE_C_COMP_PIN);
    }
    if (step == 2 || step == 5) {
        return SET == GPIO_ReadBit(COMPARATOR_REGISTER, PHASE_A_COMP_PIN);
    }
    if (step == 3 || step == 6) {
        return SET == GPIO_ReadBit(COMPARATOR_REGISTER, PHASE_B_COMP_PIN);
    }
    return 0;
}

__RAMFUNC void maskPhaseInterrupts(void)
{
    COMPARATOR_REGISTER->INTENCLR = (COMP_A_MASK | COMP_B_MASK | COMP_C_MASK);
    COMPARATOR_REGISTER->INTSTATUS = (COMP_A_MASK | COMP_B_MASK | COMP_C_MASK);
}

__RAMFUNC void enableCompInterrupts(void)
{
    const uint32_t mask = floatingCompMask();
    COMPARATOR_REGISTER->INTSTATUS = mask;
    COMPARATOR_REGISTER->INTENSET = mask;
}

__RAMFUNC void changeCompInput(void)
{
    const uint32_t mask = floatingCompMask();
    COMPARATOR_REGISTER->INTENCLR = (COMP_A_MASK | COMP_B_MASK | COMP_C_MASK) & ~mask;
    setCompEdge(rising);
    COMPARATOR_REGISTER->INTSTATUS = mask;
    COMPARATOR_REGISTER->INTENSET = mask;
}

__RAMFUNC void setCompEdge(char r)
{
    if (r) {
        COMPARATOR_REGISTER->INTPOLCLR = (COMP_A_MASK | COMP_B_MASK | COMP_C_MASK);
    } else {
        COMPARATOR_REGISTER->INTPOLSET = (COMP_A_MASK | COMP_B_MASK | COMP_C_MASK);
    }
}
