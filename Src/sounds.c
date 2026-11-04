/*
 * sounds.c
 *
 * Original AM32 sound routines: Alka, 2020.
 * K1921VG5T port and reduced startup/arming tunes: Regulo, 2026.
 */
#include "sounds.h"
#include "common.h"
#include "eeprom.h"
#include "functions.h"
#include "peripherals.h"
#include "phaseouts.h"
#include "targets.h"

uint8_t beep_volume;

void setCaptureCompare(void);

void setVolume(uint8_t volume)
{
    if (volume > 11) {
		volume = 11;
	}
	beep_volume = volume * 2;           // volume variable from 0 - 11 equates to CCR value of 0-22
}

void setCaptureCompare()
{
    SET_DUTY_CYCLE_ALL(beep_volume); // volume of the beep, (duty cycle) don't go
                                     // above 25 out of 2000
}

void playStartupTune()
{
	__disable_irq();

    //uint8_t value = *(uint8_t*)(EEPROM_START_ADD + 48);
//    if (value != 0xFF) {
//		playBlueJayTune();
//    } else {
    SET_AUTO_RELOAD_PWM(TIM1_AUTORELOAD);
	setCaptureCompare();
	comStep(3);       // activate a pwm channel
    SET_PRESCALER_PWM(55); // frequency of beep
    delayMillis(200); // duration of beep
    //signaltimeout = 0;
    comStep(5);
    SET_PRESCALER_PWM(40); // next beep is higher frequency
    delayMillis(200);
    //signaltimeout = 0;
	comStep(6);
    SET_PRESCALER_PWM(25); // higher again..
    delayMillis(200);
	allOff();                // turn all channels low again
    SET_PRESCALER_PWM(0); // set prescaler back to 0.
	signaltimeout = 0;
	//}

    SET_AUTO_RELOAD_PWM(TIMER1_MAX_ARR);
	__enable_irq();
}

void playInputTune()
{
	__disable_irq();
    SET_AUTO_RELOAD_PWM(TIM1_AUTORELOAD);
    SET_PRESCALER_PWM(80);
	setCaptureCompare();
	comStep(3);
    signaltimeout = 0;
    delayMillis(100);
    SET_PRESCALER_PWM(70);
    delayMillis(100);
    //signaltimeout = 0;
    SET_PRESCALER_PWM(40);
    delayMillis(100);
	allOff();
    SET_PRESCALER_PWM(0);
	signaltimeout = 0;
    SET_AUTO_RELOAD_PWM(TIMER1_MAX_ARR);
	__enable_irq();
}
