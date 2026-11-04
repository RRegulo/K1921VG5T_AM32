#include "settings.h"
#include "targets.h"
#include "common.h"

/* Defaults copied from ../am32-configurator/utils/defaultEscConfig.ts.
 * input_type is fixed to PWM because this reduced image has no protocol detector. */
const EEprom_t factory_settings __attribute__((section(".settings"), used)) = {
    .no_polling_start = 1,
    .eeprom_version = EEPROM_VERSION,
    .bootloader_version = 0xFF,
    .version = {FIRMWARE_VERSION_MAJOR, FIRMWARE_VERSION_MINOR},
    .max_ramp = 16,
    .minimum_duty_cycle = 2,
    .disable_stick_calibration = 0,
    .absolute_voltage_cutoff = 0,
    .current_P = 100,
    .current_I = 0,
    .current_D = 50,
    .active_brake_power = 2,
    .brake_on_zero_throttle = 0,
    .drive_by_rpm = 0,
    .maximum_rpm = 50,
    .minimum_rpm = 5,
    .dir_reversed = 0,
    .bi_direction = 0,
    .use_sine_start = 0,
    .comp_pwm = 1,
    .variable_pwm = 0,
    .stuck_rotor_protection = 0,
    .advance_level = 26,
    .pwm_frequency = 24,
    .startup_power = 100,
    .motor_kv = 55,
    .motor_poles = 14,
    .brake_on_stop = 0,
    .stall_protection = 0,
    .beep_volume = 5,
    .telemetry_on_interval = 0,
    .servo = {128, 128, 128, 50},
    .low_voltage_cut_off = 0,
    .low_cell_volt_cutoff = 50,
    .rc_car_reverse = 0,
    .current_offset = 0xFF,
    .sine_mode_changeover_thottle_level = 15,
    .drag_brake_strength = 10,
    .driving_brake_strength = 10,
    .limits = {.temperature = 0, .current = 0},
    .sine_mode_power = 6,
    .input_type = SERVO_IN,
    .auto_advance = 0,
    .maximum_duty_cycle = 100,
    .demag_comp = 0};

_Static_assert(sizeof(EEprom_t) == 192, "AM32 settings layout changed");