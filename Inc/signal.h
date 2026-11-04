#pragma once

/*
 * IO.h
 *
 *  Created on: Sep. 26, 2020
 *      Author: Alka
 */

#include "main.h"

extern volatile char inputSet;

extern uint16_t ADC_raw_volts;
extern uint16_t servo_low_threshold;  // anything below this point considered 0
extern uint16_t servo_high_threshold; // anything above this point considered 2000 (max)
extern uint16_t servo_neutral;
extern uint8_t servo_dead_band;

void computeServoInput(uint32_t pulse_ticks);
