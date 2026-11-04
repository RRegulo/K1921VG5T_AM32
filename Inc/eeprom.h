#pragma once

#include "main.h"

/* Поля отключённых функций оставлены только для совместимости раскладки. */
#define EEPROM_VERSION 4

typedef union EEprom_u {
    struct {
        uint8_t no_polling_start;   // 0
        uint8_t eeprom_version;     // 1
        uint8_t bootloader_version; // 2 (owned by the bootloader — do not reuse!)
        struct {
            uint8_t major; // 3
            uint8_t minor; // 4
        } version;
        uint8_t max_ramp;                  // 5 0.1% per ms to 25% per ms
        uint8_t minimum_duty_cycle;        // 6  0.2% to 51 percent
        uint8_t disable_stick_calibration; // 7
        uint8_t absolute_voltage_cutoff;   // 8  voltage level 1 to 100 in 0.5v increments
        uint8_t current_P;                 // 9  0-255
        uint8_t current_I;                 // 10 0-255
        uint8_t current_D;                 // 11 0-255
        uint8_t active_brake_power;        // 12  1-5 percent duty cycle
        uint8_t brake_on_zero_throttle;    // 13  0=off 1=coast 2=motor brake
                                           // 3-9=delayed brake (2+x seconds)
        uint8_t drive_by_rpm;              // 14 0=off 1=on rpm speed control
        uint8_t maximum_rpm;               // 15 max rpm speed control / 200
        uint8_t minimum_rpm;               // 16 min rpm speed control / 200
        uint8_t dir_reversed;              // 17
        uint8_t bi_direction;              // 18
        uint8_t use_sine_start;            // 19
        uint8_t comp_pwm;                  // 20
        uint8_t variable_pwm;              // 21
        uint8_t stuck_rotor_protection;    // 22
        uint8_t advance_level;             // 23
        uint8_t pwm_frequency;             // 24
        uint8_t startup_power;             // 25
        uint8_t motor_kv;                  // 26
        uint8_t motor_poles;               // 27
        uint8_t brake_on_stop;             // 28
        uint8_t stall_protection;          // 29
        uint8_t beep_volume;               // 30
        uint8_t telemetry_on_interval;     // 31
        struct {
            uint8_t low_threshold;  // 32
            uint8_t high_threshold; // 33
            uint8_t neutral;        // 34
            uint8_t dead_band;      // 35
        } servo;
        uint8_t low_voltage_cut_off;  // 36
        uint8_t low_cell_volt_cutoff; // 37
        uint8_t rc_car_reverse;       // 38
        uint8_t current_offset;       // 39 idle current offset (0xFF = not calibrated)
        uint8_t sine_mode_changeover_thottle_level; // 40
        uint8_t drag_brake_strength;                // 41
        uint8_t driving_brake_strength;             // 42
        struct {
            uint8_t temperature; // 43
            uint8_t current;     // 44
        } limits;
        uint8_t sine_mode_power; // 45
        uint8_t input_type;      // 46
        uint8_t auto_advance;    // 47
        // Maximum throttle as a % of full duty (1..100); 0 or 0xFF (blank) => 100%.
        // The stick still spans the whole range: full stick maps to this limit.
        uint8_t maximum_duty_cycle; // 48
        // Demagnetization compensation: 0=off 1=low 2=high (blank/invalid => off)
        uint8_t demag_comp; // 49
        uint8_t tune[126];  // 50-175 (configurator melody; built-in startup and armed tones are used)
        struct {
            uint8_t can_node;              // 176
            uint8_t esc_index;             // 177
            uint8_t require_arming;        // 178
            uint8_t telem_rate;            // 179
            uint8_t require_zero_throttle; // 180
            uint8_t filter_hz;             // 181
            uint8_t debug_rate;            // 182
            uint8_t term_enable;           // 183
            uint8_t reserved[8];           // 184-191
        } can;
    };
    uint8_t buffer[192];
} EEprom_t;

extern EEprom_t eepromBuffer;
