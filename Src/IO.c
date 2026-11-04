/* PWM-вход К1921ВГ5Т: PA14 / TMR0_IO. */
#include "IO.h"
#include "common.h"
#include "functions.h"
#include "targets.h"

static uint32_t rise;
static uint8_t have_rise;
void pwmInputStart(void) {
    TMR0->IC = TMR_IC_CAPCOM0_0_Msk;
}

static void pollCapture(void) {
    if (!TMR0->RIS_bit.CAPCOM0_0) {
        return;
    }
    const uint32_t captured = TMR0->CAPCOM[0].VAL0;
    TMR0->IC = TMR_IC_CAPCOM0_0_Msk;
    if (GPIO_ReadBit(INPUT_PIN_PORT, INPUT_PIN) == SET) {
        rise = captured;
        have_rise = 1;
    } else if (have_rise) {
        const uint32_t width = captured - rise;
        have_rise = 0;
        if (width > 800U * CPU_FREQUENCY_MHZ && width < 2200U * CPU_FREQUENCY_MHZ) {
            computeServoInput(width);
            inputSet = 1;
        }
    }
}

void pollPWMInput(void) {
    pollCapture();
    setInput();
}
