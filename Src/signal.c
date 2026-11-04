/* Servo PWM mapping from AM32, Alka. */
#include "signal.h"
#include "IO.h"
#include "common.h"
#include "functions.h"
#include "targets.h"

int max_servo_deviation = 250;
int servorawinput;

void computeServoInput(uint32_t pulse_ticks) {
    const uint32_t diffValue = pulse_ticks / CPU_FREQUENCY_MHZ;
    if (diffValue > 800U && diffValue < 2200U) {
        signaltimeout = 0;
        servorawinput = map(diffValue, servo_low_threshold, servo_high_threshold, 47, 2047);
        if (servorawinput <= 48) {
            servorawinput = 0;
        }
        if (servorawinput - newinput > max_servo_deviation) {
            newinput += max_servo_deviation;
        } else if (newinput - servorawinput > max_servo_deviation) {
            newinput -= max_servo_deviation;
        } else {
            newinput = servorawinput;
        }
        if (newinput == 0) {
            ++zero_input_count;
        } else {
            zero_input_count = 0;
        }
    } else {
        zero_input_count = 0;
    }
}
