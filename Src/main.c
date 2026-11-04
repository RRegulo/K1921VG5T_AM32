/* AM32, Alka. PWM-only port for K1921VG5T. */
#include "main.h"
#include "ADC.h"
#include "IO.h"
#include "common.h"
#include "comparator.h"
#include "eeprom.h"
#include "settings.h"
#include "functions.h"
#include "peripherals.h"
#include "phaseouts.h"
#include "signal.h"
#include "sounds.h"
#include "targets.h"
#include <assert.h>
#include <stdint.h>
#include <string.h>

void zcfoundroutine(void);

EEprom_t eepromBuffer;
volatile uint32_t polling_mode_changeover;
volatile uint8_t ramp_divider;
volatile uint8_t max_ramp_startup = RAMP_SPEED_STARTUP;
volatile uint8_t max_ramp_low_rpm = RAMP_SPEED_LOW_RPM;
volatile uint8_t max_ramp_high_rpm = RAMP_SPEED_HIGH_RPM;
uint16_t prop_brake_duty_cycle = 0;
uint16_t ledcounter = 0;
uint16_t ramp_count;

uint16_t one_khz_loop_counter = 0;

uint8_t temp_advance;
uint16_t motor_kv = 2000;
uint8_t dead_time_override = DEAD_TIME;
uint8_t auto_advance_level;
volatile uint8_t zero_throttle_brake_active;
uint8_t brake_countdown;
uint16_t servo_low_threshold = 1100;  // anything below this point considered 0
uint16_t servo_high_threshold = 1900; // anything above this point considered 2000 (max)
uint16_t servo_neutral = 1500;
uint8_t servo_dead_band = 100;
char LOW_VOLTAGE_CUTOFF = 0;         // Turn Low Voltage CUTOFF on or off
uint16_t low_cell_volt_cutoff = 330; // 3.3volts per cell
volatile uint8_t temp_comp_pwm;

uint16_t armed_timeout_count;
uint16_t reverse_speed_threshold = 1500;
uint8_t desync_happened = 0;

char low_rpm_throttle_limit = 0;

uint16_t low_voltage_count = 0;

uint16_t VOLTAGE_DIVIDER = TARGET_VOLTAGE_DIVIDER; // 100k upper and 10k lower resistor in divider
uint16_t battery_voltage; // scale in volts * 10.  1260 is a battery voltage of 12.60
char cell_count = 0;

volatile uint16_t tenkhzcounter = 0;

uint16_t min_startup_duty = 120;
char bemf_timeout = 10;

uint8_t max_duty_cycle_change = 2;

uint16_t last_duty_cycle = 0;
volatile uint16_t duty_cycle_setpoint = 0;

typedef enum { GPIO_PIN_RESET = 0U, GPIO_PIN_SET } GPIO_PinState;

uint16_t startup_max_duty_cycle = 200;
uint16_t minimum_duty_cycle = DEAD_TIME;

uint16_t maximum_duty_cycle_limit = 2000;
uint16_t stall_protect_minimum_duty = DEAD_TIME;
volatile char desync_check = 0;

uint16_t tim1_arr = TIM1_AUTORELOAD;       // current auto reset value
uint16_t TIMER1_MAX_ARR = TIM1_AUTORELOAD; // maximum auto reset register value
uint16_t duty_cycle_maximum = 2000;
uint16_t low_rpm_level = 20;  // thousand erpm used to set range for throttle resrictions
uint16_t high_rpm_level = 70; //
uint16_t throttle_max_at_low_rpm = 400;
uint16_t throttle_max_at_high_rpm = 2000;

uint16_t commutation_intervals[6] = {0};
volatile uint32_t average_interval = 0;
uint32_t last_average_interval;
volatile int e_com_time;

uint16_t ADC_raw_volts;
volatile uint8_t PROCESS_ADC_FLAG = 0;
char prop_brake_active = 0;

volatile char old_routine = 1;
volatile uint16_t adjusted_input = 0;

volatile uint8_t bemf_timeout_happened = 0;
uint8_t filter_level = 5;
volatile uint8_t running = 0;
uint16_t advance = 0;

volatile char rising = 1;

uint32_t deadTime = DEAD_TIME;

volatile char forward = 1;
uint16_t gate_drive_offset = DEAD_TIME;

uint8_t stuckcounter = 0;
uint16_t k_erpm;
uint16_t e_rpm; // electrical revolution /100 so,  123 is 12300 erpm

uint16_t adjusted_duty_cycle;

uint8_t bad_count = 0;

uint8_t bad_count_threshold = CPU_FREQUENCY_MHZ / 24;

volatile char armed = 0;
volatile uint16_t zero_input_count = 0;

volatile uint16_t input = 0;
volatile uint16_t newinput = 0;
volatile char inputSet = 0;
volatile uint32_t zero_crosses;

volatile uint8_t zcfound = 0;

volatile uint8_t bemfcounter;
uint8_t min_bemf_counts_up = TARGET_MIN_BEMF_COUNTS;
uint8_t min_bemf_counts_down = TARGET_MIN_BEMF_COUNTS;

uint16_t lastzctime;
uint16_t thiszctime;

volatile uint16_t duty_cycle = 0;
volatile char step = 1;
volatile uint32_t commutation_interval = 12500;
uint16_t waitTime = 0;
volatile uint16_t signaltimeout = 0;

void loadEEpromSettings() {

    eepromBuffer = factory_settings;

    if (eepromBuffer.dir_reversed > 1) {
        eepromBuffer.dir_reversed = 0;
    }

    if (eepromBuffer.comp_pwm > 1) {
        eepromBuffer.comp_pwm = 0;
    }
    if (eepromBuffer.stuck_rotor_protection > 1) {
        eepromBuffer.stuck_rotor_protection = 0;
    }
    if (eepromBuffer.auto_advance > 1) {
        eepromBuffer.auto_advance = 0;
    }

    temp_comp_pwm = eepromBuffer.comp_pwm;
    if (eepromBuffer.advance_level > 42 ||
        (eepromBuffer.advance_level < 10 && eepromBuffer.advance_level > 3)) {
        temp_advance = 16;
    }
    if (eepromBuffer.advance_level < 4) { // old format needs to be converted to 0-32 range
        temp_advance = (eepromBuffer.advance_level << 3);
        eepromBuffer.advance_level = temp_advance + 10;
    }
    if (eepromBuffer.advance_level < 43 &&
        eepromBuffer.advance_level > 9) { // new format subtract 10 from advance
        temp_advance = eepromBuffer.advance_level - 10;
    }

    if (eepromBuffer.pwm_frequency < 145 && eepromBuffer.pwm_frequency > 7) {
        int divider = eepromBuffer.pwm_frequency * 100 / 6;
        TIMER1_MAX_ARR = TIM1_AUTORELOAD * 400 / divider;
        SET_AUTO_RELOAD_PWM(TIMER1_MAX_ARR);
    } else {
        tim1_arr = TIM1_AUTORELOAD;
        SET_AUTO_RELOAD_PWM(tim1_arr);
    }
    if (eepromBuffer.minimum_duty_cycle < 51 && eepromBuffer.minimum_duty_cycle > 0) {
        minimum_duty_cycle = eepromBuffer.minimum_duty_cycle * 10;
    } else {
        minimum_duty_cycle = 0;
    }
    if (eepromBuffer.maximum_duty_cycle == 0 || eepromBuffer.maximum_duty_cycle > 100) {
        maximum_duty_cycle_limit = 2000;
    } else {
        maximum_duty_cycle_limit = (uint16_t)eepromBuffer.maximum_duty_cycle * 20; // 100% -> 2000
        if (maximum_duty_cycle_limit < minimum_duty_cycle) {
            maximum_duty_cycle_limit = minimum_duty_cycle;
        }
    }
    if (eepromBuffer.startup_power < 151 && eepromBuffer.startup_power > 49) {
        min_startup_duty = minimum_duty_cycle + eepromBuffer.startup_power;
    } else {
        min_startup_duty = minimum_duty_cycle;
    }
    startup_max_duty_cycle = minimum_duty_cycle + 400;

    motor_kv = (eepromBuffer.motor_kv * 40) + 20;

    if (eepromBuffer.motor_poles < 2 || eepromBuffer.motor_poles > 32) {
        eepromBuffer.motor_poles = 14;
    }

    servo_low_threshold =
        (eepromBuffer.servo.low_threshold * 2) + 750; // anything below this point considered 0
    servo_high_threshold = (eepromBuffer.servo.high_threshold * 2) +
                           1750; // anything above this point considered 2000 (max)
    servo_neutral = (eepromBuffer.servo.neutral) + 1374;
    servo_dead_band = eepromBuffer.servo.dead_band;
    if (eepromBuffer.max_ramp < 10) {
        ramp_divider = 9;
        max_ramp_startup = eepromBuffer.max_ramp;
        max_ramp_low_rpm = eepromBuffer.max_ramp;
        max_ramp_high_rpm = eepromBuffer.max_ramp;
    } else {
        ramp_divider = 0;
        if ((eepromBuffer.max_ramp / 10) < max_ramp_startup) {
            max_ramp_startup = eepromBuffer.max_ramp / 10;
        }
        if ((eepromBuffer.max_ramp / 10) < max_ramp_low_rpm) {
            max_ramp_low_rpm = eepromBuffer.max_ramp / 10;
        }
        if ((eepromBuffer.max_ramp / 10) < max_ramp_high_rpm) {
            max_ramp_high_rpm = eepromBuffer.max_ramp / 10;
        }
    }

    if (motor_kv < 300) {
        low_rpm_throttle_limit = 0;
    }
    low_rpm_level = motor_kv / 100 / (32 / eepromBuffer.motor_poles);
    high_rpm_level = motor_kv / 12 / (32 / eepromBuffer.motor_poles);
    reverse_speed_threshold = map(motor_kv, 300, 3000, 1000, 500);
    polling_mode_changeover = POLLING_MODE_THRESHOLD;
}
void getBemfState(void) {
    uint8_t current_state = 0;
    current_state = !getCompOutputLevel(); // polarity reversed
    if (rising) {
        if (current_state) {
            bemfcounter++;
        } else {
            bad_count++;
            if (bad_count > bad_count_threshold) {
                bemfcounter = 0;
            }
        }
    } else {
        if (!current_state) {
            bemfcounter++;
        } else {
            bad_count++;
            if (bad_count > bad_count_threshold) {
                bemfcounter = 0;
            }
        }
    }
}

void commutate() {
    if (forward == 1) {
        step++;
        if (step > 6) {
            step = 1;
            desync_check = 1;
        }
        rising = step % 2;
    } else {
        step--;
        if (step < 1) {
            step = 6;
            desync_check = 1;
        }
        rising = !(step % 2);
    }
    const uint32_t irq_state = irq_save();
    if (!prop_brake_active) {
        comStep(step);
    }
    irq_restore(irq_state);
    changeCompInput();
    bemfcounter = 0;
    zcfound = 0;
    commutation_intervals[step - 1] = commutation_interval; // just used to calulate average
}

__RAMFUNC void PeriodElapsedCallback() {
    DISABLE_COM_TIMER_INT(); // disable interrupt
    commutate();
    commutation_interval = ((commutation_interval) + ((lastzctime + thiszctime) >> 1)) >> 1;
    advance =
        (commutation_interval * (eepromBuffer.auto_advance ? auto_advance_level : temp_advance)) >>
        6;
    waitTime = (commutation_interval >> 1) - advance;
    if (!old_routine) {
        enableCompInterrupts(); // enable comp interrupt
    }
    if (zero_crosses < 10000) {
        zero_crosses++;
    }
}

__RAMFUNC void interruptRoutine() {
    const char expect = rising;
    for (int i = 0; i < filter_level; i++) {
        if (getCompOutputLevel() == expect) {
            return;
        }
    }
    const uint32_t irq_state = irq_save();
    maskPhaseInterrupts();
    lastzctime = thiszctime;
    thiszctime = INTERVAL_TIMER_COUNT;
    SET_INTERVAL_TIMER_COUNT(0);
    SET_AND_ENABLE_COM_INT(waitTime + 1); // enable COM_TIMER interrupt
    irq_restore(irq_state);
}

void startMotor() {
    if (running == 0) {
        commutate();
        commutation_interval = 10000;
        SET_INTERVAL_TIMER_COUNT(5000);
        running = 1;
    }
    enableCompInterrupts();
}

void setInput() {
    adjusted_input = newinput;
    if ((bemf_timeout_happened > bemf_timeout) && eepromBuffer.stuck_rotor_protection) {
        /* A COM callback between masking the comparator and disabling its timer
         * can re-enable the comparator and undo this stop. */
        const uint32_t irq_state = irq_save();
        maskPhaseInterrupts();
        DISABLE_COM_TIMER_INT(); // a queued commutation would power the bridge again
        COM_TIMER_CLEAR_PENDING();
        allOff();
        input = 0;
        running = 0;
        duty_cycle_setpoint = 0;
        SET_DUTY_CYCLE_ALL(0);
        bemf_timeout_happened = 102;
        irq_restore(irq_state);
        return;
    } else {
        input = adjusted_input;
    }
    if (armed) {
        if (input >= 47) {
            if (running == 0) {
                allOff();
                if (!old_routine) {
                    startMotor();
                }
                running = 1;
                last_duty_cycle = min_startup_duty;
            }

            duty_cycle_setpoint =
                map(input, 47, 2047, minimum_duty_cycle, maximum_duty_cycle_limit);
            prop_brake_active = 0;
        }

        if (input < 47) {
            if (eepromBuffer.brake_on_zero_throttle == 0) {
                duty_cycle_setpoint = 0;
            }
            if (!eepromBuffer.comp_pwm) {
                duty_cycle_setpoint = 0;
                if (!running) {
                    old_routine = 1;
                    zero_crosses = 0;
                    if (eepromBuffer.brake_on_stop) {
                        fullBrake();
                    } else {
                        if (!prop_brake_active) {
                            allOff();
                        }
                    }
                }
            } else {
                if (!running) {

                    old_routine = 1;
                    zero_crosses = 0;
                    bad_count = 0;
                    if (eepromBuffer.brake_on_stop > 0) {

                        if (eepromBuffer.brake_on_stop == 1) {
                            prop_brake_duty_cycle = eepromBuffer.drag_brake_strength * 200;
                            if (prop_brake_duty_cycle >= (1999)) {
                                fullBrake();
                            } else {
                                proportionalBrake();
                                prop_brake_active = 1;
                            }
                        }

                    } else {
                        allOff();
                    }
                    duty_cycle_setpoint = 0;
                }
            }
        }
        if (!prop_brake_active) {
            if (input >= 47 && (zero_crosses < 30U)) {
                if (duty_cycle_setpoint < min_startup_duty) {
                    duty_cycle_setpoint = min_startup_duty;
                }
                if (duty_cycle_setpoint > startup_max_duty_cycle) {
                    duty_cycle_setpoint = startup_max_duty_cycle;
                }
            }

            if (duty_cycle_setpoint > duty_cycle_maximum) {
                duty_cycle_setpoint = duty_cycle_maximum;
            }
        }
    }
}

__RAMFUNC void tenKhzRoutine() { // 20khz as of 2.00 to be renamed
    duty_cycle = duty_cycle_setpoint;
    tenkhzcounter++;
    ledcounter++;
    ramp_count++;
    one_khz_loop_counter++;
    if (!armed) {
        if (cell_count == 0) {
            if (inputSet) {
                if (adjusted_input == 0) {
                    armed_timeout_count++;
                    if (armed_timeout_count > LOOP_FREQUENCY_HZ) { // one second
                        if (zero_input_count > 30) {
                            armed = 1;
                            playInputTune();
                            if ((cell_count == 0) && eepromBuffer.low_voltage_cut_off == 1) {
                                cell_count = battery_voltage / 370;
                            }

                        } else {
                            inputSet = 0;
                            armed_timeout_count = 0;
                        }
                    }
                } else {
                    armed_timeout_count = 0;
                }
            }
        }
    }

    if (old_routine && running) {
        maskPhaseInterrupts();
        getBemfState();
        if (!zcfound) {
            if (rising) {
                if (bemfcounter > min_bemf_counts_up) {
                    zcfound = 1;
                    zcfoundroutine();
                }
            } else {
                if (bemfcounter > min_bemf_counts_down) {
                    zcfound = 1;
                    zcfoundroutine();
                }
            }
        }
    }
    if (one_khz_loop_counter > PID_LOOP_DIVIDER) { // 1khz PID loop
        PROCESS_ADC_FLAG = 1;                      // set flag to do new adc read at lower priority
        one_khz_loop_counter = 0;
    }
    if (ramp_count > ramp_divider) {
        ramp_count = 0;
        if (zero_crosses < 150 || last_duty_cycle < 150) {
            max_duty_cycle_change = max_ramp_startup;
        } else {
            if (average_interval > 500) {
                max_duty_cycle_change = max_ramp_low_rpm;
            } else {
                max_duty_cycle_change = max_ramp_high_rpm;
            }
        }

        if ((duty_cycle - last_duty_cycle) > max_duty_cycle_change) {
            duty_cycle = last_duty_cycle + max_duty_cycle_change;
        }
        if ((last_duty_cycle - duty_cycle) > max_duty_cycle_change) {
            duty_cycle = last_duty_cycle - max_duty_cycle_change;
        }
    } else {
        duty_cycle = last_duty_cycle;
    }
#define DUTY_LIMIT_99 1970
    uint16_t duty_to_set = duty_cycle;
    if (duty_cycle > DUTY_LIMIT_99) {
        duty_to_set = DUTY_LIMIT_99;
    }
    if ((armed && running) && input > 47) {
        if (zero_throttle_brake_active) {
            zero_throttle_brake_active = 0;
            temp_comp_pwm = eepromBuffer.comp_pwm;
        } else {
            adjusted_duty_cycle = ((duty_to_set * tim1_arr) / 2000) + 1;
        }
    } else {
        if (running && input < 47) {                        // brake on zero throttle behavior while
            if (eepromBuffer.brake_on_zero_throttle == 1) { // coast on 0 throttle
                temp_comp_pwm = 0;                          // tracks rpm until stopped
                zero_throttle_brake_active = 1;
            }
            if (eepromBuffer.brake_on_zero_throttle == 2) { // motor brake on 0 throttle
                temp_comp_pwm = 1;                          // tracks rpm until stopped
                zero_throttle_brake_active = 1;
            }
            if ((eepromBuffer.brake_on_zero_throttle > 2) &&
                (eepromBuffer.brake_on_zero_throttle <
                 10)) { // brake on 0 throttle after 2 + x seconds
                if (zero_throttle_brake_active == 0) {
                    brake_countdown = eepromBuffer.brake_on_zero_throttle -
                                      2; // brake countdown decremented in 20khz routine
                    tenkhzcounter = LOOP_FREQUENCY_HZ;
                }
                if ((brake_countdown == 0) && (zero_throttle_brake_active == 1)) {
                    zero_crosses = 0; // after countdown forces the brake on stop behavior
                    running = 0;      // stops tracking rpm
                }
                zero_throttle_brake_active = 1;
            }
            adjusted_duty_cycle = ((duty_cycle * tim1_arr) / 2000);
        } else { // input less than 47 and not running, normal brake on stop
            if (prop_brake_active) {
                adjusted_duty_cycle = tim1_arr - ((prop_brake_duty_cycle * tim1_arr) / 2000);
            } else {
                if ((eepromBuffer.brake_on_stop == 2) && armed) { // require arming for active brake
                    comStep(2);
                    adjusted_duty_cycle =
                        DEAD_TIME + ((eepromBuffer.active_brake_power * tim1_arr) / 2000) * 10;
                } else {
                    adjusted_duty_cycle = ((duty_cycle * tim1_arr) / 2000);
                }
            }
        }
    }
    last_duty_cycle = duty_cycle;
    SET_AUTO_RELOAD_PWM(tim1_arr);
    SET_DUTY_CYCLE_ALL(adjusted_duty_cycle);

    signaltimeout++;
}

void zcfoundroutine() { // only used in polling mode, blocking routine.
    thiszctime = INTERVAL_TIMER_COUNT;
    SET_INTERVAL_TIMER_COUNT(0);
    commutation_interval = (thiszctime + (3 * commutation_interval)) / 4;
    advance = (temp_advance * commutation_interval) >> 6; //   7.5 degree increments
    waitTime = commutation_interval / 2 - advance;
    while ((INTERVAL_TIMER_COUNT) < (waitTime)) {
        if (zero_crosses < 5) {
            break;
        }
    }
    commutate();
    bemfcounter = 0;
    bad_count = 0;

    zero_crosses++;
    if (eepromBuffer.no_polling_start) {
        if (zero_crosses > 2) {
            old_routine = 0;
            enableCompInterrupts(); // enable interrupt
        }
    } else {

        if (commutation_interval < polling_mode_changeover) {
            old_routine = 0;
            enableCompInterrupts(); // enable interrupt
        }
    }
}

int main(void) {
#ifndef USE_BOOTLOADER
    SystemInit();
#if VG5T_CACHE
    vg5tCacheInit();
#endif
#endif
    SystemCoreClockUpdate();

    gate_drive_offset = deadTime;
    dead_time_override = deadTime;
    minimum_duty_cycle = deadTime;
    stall_protect_minimum_duty = deadTime;
    initCorePeripherals();
    enableCorePeripherals();

    loadEEpromSettings();
    setVolume(eepromBuffer.beep_volume > 11 ? 5 : eepromBuffer.beep_volume);

    inputSet = 1;
    pwmInputStart();
#ifndef VG5T_DEBUG_NO_RESET
    MX_IWDG_Init();
#endif
    riscv_irq_global_enable();
    PWM0->DBRED = dead_time_override;
    PWM0->DBFED = dead_time_override;
    PWM1->DBRED = dead_time_override;
    PWM1->DBFED = dead_time_override;
    PWM2->DBRED = dead_time_override;
    PWM2->DBFED = dead_time_override;

    if (eepromBuffer.dir_reversed == 1) {
        forward = 0;
    } else {
        forward = 1;
    }
    tim1_arr = TIMER1_MAX_ARR;
    playStartupTune();

    while (1) {
        pollPWMInput();
#ifndef VG5T_DEBUG_NO_RESET
        RELOAD_WATCHDOG_COUNTER();
#endif
        e_com_time =
            ((commutation_intervals[0] + commutation_intervals[1] + commutation_intervals[2] +
              commutation_intervals[3] + commutation_intervals[4] + commutation_intervals[5]) +
             4) >>
            1; // COMMUTATION INTERVAL IS 0.5US INCREMENTS
        if (zero_crosses < 5) {

            min_bemf_counts_up = TARGET_MIN_BEMF_COUNTS * 2;
            min_bemf_counts_down = TARGET_MIN_BEMF_COUNTS * 2;

        } else {
            min_bemf_counts_up = TARGET_MIN_BEMF_COUNTS;
            min_bemf_counts_down = TARGET_MIN_BEMF_COUNTS;
        }

        if (eepromBuffer.variable_pwm == 1) { // uses range defined by pwm frequency setting
            tim1_arr = map(commutation_interval, 96, 200, TIMER1_MAX_ARR / 2, TIMER1_MAX_ARR);
        }
        if (eepromBuffer.variable_pwm == 2) { // uses automatic range
            if (average_interval < 250 && average_interval > 100) {
                tim1_arr = average_interval * (CPU_FREQUENCY_MHZ / 9);
            }
            if (average_interval < 100 && average_interval > 0) {
                tim1_arr = 100 * (CPU_FREQUENCY_MHZ / 9);
            }
            if ((average_interval >= 250) || (average_interval == 0)) {
                tim1_arr = 250 * (CPU_FREQUENCY_MHZ / 9);
            }
        }
        if (signaltimeout > (LOOP_FREQUENCY_HZ >> 1)) { // half second timeout when armed;
            if (armed) {
                allOff();
                armed = 0;
                input = 0;
                inputSet = 0;
                zero_input_count = 0;
                SET_DUTY_CYCLE_ALL(0);
                resetInputCaptureTimer();
                NVIC_SystemReset();
            }
            if (signaltimeout > LOOP_FREQUENCY_HZ << 1) { // 2 second when not armed
                allOff();
                armed = 0;
                input = 0;
                inputSet = 0;
                zero_input_count = 0;
                SET_DUTY_CYCLE_ALL(0);
                resetInputCaptureTimer();
                NVIC_SystemReset();
            }
        }

        if (tenkhzcounter > LOOP_FREQUENCY_HZ) { // 1s sample interval
            tenkhzcounter = 0;
            if (brake_countdown > 0) {
                brake_countdown--;
            }
        }

        if ((zero_crosses > 1000) || (adjusted_input == 0)) {
            bemf_timeout_happened = 0;
        }
        if (zero_crosses > 100 && adjusted_input < 200) {
            bemf_timeout_happened = 0;
        }

        if (adjusted_input < 150) { // startup duty cycle should be low enough to not burn motor
            bemf_timeout = 100;
        } else {
            bemf_timeout = 10;
        }

        average_interval = e_com_time / 3;
        if ((desync_check && zero_crosses > 10)) {
            if (((getAbsDif(last_average_interval, average_interval) > average_interval >> 1) &&
                 (average_interval < 2000))) { // throttle resitricted before zc 20.
                zero_crosses = 0;
                desync_happened++;
                if (input > 47 || commutation_interval > 1000) {
                    running = 0;
                }
                old_routine = 1;
                last_duty_cycle = min_startup_duty / 2;
            }
            desync_check = 0;
            last_average_interval = average_interval;
        }

        if (PROCESS_ADC_FLAG == 1) { // ADC processing at 1 kHz

            ADC_DMA_Callback();
            ADC_SEQ_SwStartCmd();
            battery_voltage = (ADC_raw_volts * 3300U / 4095U * VOLTAGE_DIVIDER) / 100U;
            if (eepromBuffer.low_voltage_cut_off == 1) {
                if (battery_voltage < (cell_count * low_cell_volt_cutoff)) {
                    low_voltage_count++;
                } else {
                    if (!LOW_VOLTAGE_CUTOFF) { // if set low cutoff has happened, require
                        low_voltage_count = 0;
                    }
                }
            }
            if (eepromBuffer.low_voltage_cut_off == 2) { // absolute cut off
                if (battery_voltage < (eepromBuffer.absolute_voltage_cutoff * 50)) {
                    low_voltage_count++;
                } else {
                    if (!LOW_VOLTAGE_CUTOFF) {
                        low_voltage_count = 0;
                    }
                }
            }
            if (low_voltage_count > 10000) { // 10 second wait before cut-off for low voltage
                LOW_VOLTAGE_CUTOFF = 1;
                input = 0;
                allOff();
                maskPhaseInterrupts();
                running = 0;
                zero_input_count = 0;
                armed = 0;
            }

            PROCESS_ADC_FLAG = 0;
        }

        stuckcounter = 0;

        e_rpm = running * (600000 / e_com_time); // in tens of rpm
        k_erpm = e_rpm / 10; // ecom time is time for one electrical revolution in microseconds

        if (low_rpm_throttle_limit) { // some hardware doesn't need this, its on
            duty_cycle_maximum = map(k_erpm, low_rpm_level, high_rpm_level, throttle_max_at_low_rpm,
                                     throttle_max_at_high_rpm); // for more performance lower the
        } else {
            duty_cycle_maximum = 2000;
        }

        if (zero_crosses < 100 && commutation_interval > 500) {
            filter_level = 12;
        } else {
            filter_level = map(average_interval, 100, 500, 3, 12);
        }
        if (commutation_interval < 50) {
            filter_level = 2;
        }

        if (eepromBuffer.auto_advance) {
            auto_advance_level = map(duty_cycle, 100, 2000, 13, 23);
        }

        /**************** old routine*********************/
        if (INTERVAL_TIMER_COUNT > 45000) {
            zero_throttle_brake_active =
                0; // reset zero throttle brake on back emf timeout (rotation stop)
            if (running == 1) {
                temp_comp_pwm = eepromBuffer.comp_pwm;
                bemf_timeout_happened++;

                maskPhaseInterrupts();
                old_routine = 1;
                if (input < 48) {
                    running = 0;
                    commutation_interval = 5000;
                }
                zero_crosses = 0;
                zcfoundroutine();
            }
        }
    }
}
