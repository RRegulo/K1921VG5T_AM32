#pragma once
#include "main.h"
extern volatile char inputSet;

void pwmInputStart(void);
void pollPWMInput(void);
void setInput(void);
void computeServoInput(uint32_t pulse_ticks);
