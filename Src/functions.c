/*
 * functions.c
 *
 *  Created on: Sep. 26, 2020
 *      Author: Alka
 */

#include "functions.h"
#include "peripherals.h"
#include "targets.h"

long map(long x, long in_min, long in_max, long out_min, long out_max) {
    if (x >= in_max)
        return out_max;
    if (x <= in_min)
        return out_min;
    if (in_min > in_max)
        return map(x, in_max, in_min, out_max, out_min);
    if (out_min == out_max)
        return out_min;
    const long in_mid = (in_min + in_max) >> 1;
    const long out_mid = (out_min + out_max) >> 1;
    if (in_min == in_mid)
        return out_mid;
    if (x <= in_mid)
        return map(x, in_min, in_mid, out_min, out_mid);
    else
        return map(x, in_mid + 1, in_max, out_mid, out_max);
}

uint32_t getAbsDif(int number1, int number2) {
    int result = number1 - number2;
    if (result < 0) {
        result = -result;
    }
    return (uint32_t)result;
}

/*
  delay by microseconds, max 65535
 */
void delayMicros(uint32_t micros) {
    /* TMR3 free-running 0..FFFF_FFFF at SYSCLK (96 ticks per us), started in
     * MX_TIM16_Init(). Wrap-safe elapsed-time compare: "up" mode resets COUNT
     * the same clock it reaches PERIOD, so polling for COUNT == PERIOD can miss. */
    const uint32_t start = DELAY_TIMER->COUNT;
    const uint32_t ticks = micros * CPU_FREQUENCY_MHZ;
    while ((uint32_t)(DELAY_TIMER->COUNT - start) < ticks) {
    }
}

/*
  delay in millis, convenience wrapper around delayMicros
 */
void delayMillis(uint32_t millis) {
    while (millis-- > 0) {
#ifndef VG5T_DEBUG_NO_RESET
        RELOAD_WATCHDOG_COUNTER();
#endif
        delayMicros(1000UL);
    }
}
