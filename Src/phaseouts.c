/*
 * phaseouts.c — K1921VG5T, phases on PA8..PA13 (PWM0/1/2 A+B)
 *
 *  Created on: Apr 22, 2020
 *      Author: Alka
 *      Modified by TempersLee June,21 2024
 *      Ported to K1921VG5T: the GPIO CLR registers (ALTFUNCCLR/DATAOUTCLR/
 *      OUTENCLR) are write-1-clear with a single VAL field, and alternate
 *      function outputs additionally require OUTENSET (UM 13.1, table 13.1).
 *      Phase mapping matches the working VG5T/VK035 target: A=PA12/13,
 *      B=PA10/11, C=PA8/9; comparator inputs A/B/C=PB4/PB5/PB6.
 */
#include "phaseouts.h"

#include "functions.h"
#include "targets.h"
#include "common.h"

extern char prop_brake_active;

/* PA12/PA13 = PWM2 (phase A), PA10/PA11 = PWM1 (phase B),
 * PA8/PA9 = PWM0 (phase C) */
#define PHASE_A_HIGH (1u << 12)
#define PHASE_A_LOW (1u << 13)
#define PHASE_B_HIGH (1u << 10)
#define PHASE_B_LOW (1u << 11)
#define PHASE_C_HIGH (1u << 8)
#define PHASE_C_LOW (1u << 9)

#define ALL_LOW (PHASE_A_LOW | PHASE_B_LOW | PHASE_C_LOW)
#define ALL_HIGH (PHASE_A_HIGH | PHASE_B_HIGH | PHASE_C_HIGH)

/* gate pin as plain GPIO output driven low (FET off) */
#define GATE_OFF(mask)                                                                             \
    do {                                                                                           \
        GPIOA->DATAOUTCLR = (mask);                                                                \
        GPIOA->ALTFUNCCLR = (mask);                                                                \
        GPIOA->OUTENSET = (mask);                                                                  \
    } while (0)
/* gate pin as plain GPIO output driven high (FET on) */
#define GATE_ON(mask)                                                                              \
    do {                                                                                           \
        GPIOA->DATAOUTSET = (mask);                                                                \
        GPIOA->ALTFUNCCLR = (mask);                                                                \
        GPIOA->OUTENSET = (mask);                                                                  \
    } while (0)
/* gate pin driven by the PWM alternate function (AF + OUTEN, table 13.1) */
#define GATE_PWM(mask)                                                                             \
    do {                                                                                           \
        GPIOA->OUTENSET = (mask);                                                                  \
        GPIOA->ALTFUNCSET = (mask);                                                                \
    } while (0)

/* Phase states, same semantics as mcu/k19xxvk035/Src/phaseouts.c:
 *   PWM   — high side PWM, low side complementary PWM (temp_comp_pwm) or off
 *   FLOAT — both gates actively driven low (never left Hi-Z: a floating
 *           driver input can turn a FET on)
 *   LOW   — high side off, low side on
 * The FET that has to turn off is always switched first. */

void proportionalBrake() {
    GATE_OFF(ALL_HIGH);
    GATE_PWM(ALL_LOW);
}

void phaseBPWM() {
    if (!temp_comp_pwm) { // for future
        GATE_OFF(PHASE_B_LOW);
    } else {
        GATE_PWM(PHASE_B_LOW);
    }
    GATE_PWM(PHASE_B_HIGH);
}

void phaseBFLOAT() {
    GATE_OFF(PHASE_B_LOW);
    GATE_OFF(PHASE_B_HIGH);
}

void phaseBLOW() {
    GATE_OFF(PHASE_B_HIGH);
    GATE_ON(PHASE_B_LOW);
}

//////////////////////////////PHASE 2//////////////////////////////////////////////////
void phaseAPWM() {
    if (!temp_comp_pwm) {
        GATE_OFF(PHASE_A_LOW);
    } else {
        GATE_PWM(PHASE_A_LOW);
    }
    GATE_PWM(PHASE_A_HIGH);
}

void phaseAFLOAT() {
    GATE_OFF(PHASE_A_LOW);
    GATE_OFF(PHASE_A_HIGH);
}

void phaseALOW() {
    GATE_OFF(PHASE_A_HIGH);
    GATE_ON(PHASE_A_LOW);
}

///////////////////////////////////////////////PHASE 3
////////////////////////////////////////////////////

void phaseCPWM() {
    if (!temp_comp_pwm) {
        GATE_OFF(PHASE_C_LOW);
    } else {
        GATE_PWM(PHASE_C_LOW);
    }
    GATE_PWM(PHASE_C_HIGH);
}

void phaseCFLOAT() {
    GATE_OFF(PHASE_C_LOW);
    GATE_OFF(PHASE_C_HIGH);
}

void phaseCLOW() {
    GATE_OFF(PHASE_C_HIGH);
    GATE_ON(PHASE_C_LOW);
}

void allOff() {
    phaseAFLOAT();
    phaseBFLOAT();
    phaseCFLOAT();
}

void comStep(int newStep) {
    switch (newStep) {
    case 1: // A-B
        phaseAPWM();
        phaseBLOW();
        phaseCFLOAT();
        break;

    case 2: // C-B
        phaseAFLOAT();
        phaseBLOW();
        phaseCPWM();
        break;

    case 3: // C-A
        phaseALOW();
        phaseBFLOAT();
        phaseCPWM();
        break;

    case 4: // B-A
        phaseALOW();
        phaseBPWM();
        phaseCFLOAT();
        break;

    case 5: // B-C
        phaseAFLOAT();
        phaseBPWM();
        phaseCLOW();
        break;

    case 6: // A-C
        phaseAPWM();
        phaseBFLOAT();
        phaseCLOW();
        break;
    }
}

void fullBrake() { // full braking shorting all low sides
    phaseALOW();
    phaseBLOW();
    phaseCLOW();
}
