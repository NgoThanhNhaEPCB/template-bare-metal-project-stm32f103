/**
 ******************************************************************************
 * @author: Nark
 * @date:   06/02/2024
 ******************************************************************************
**/
#include "task_polling.h"

void led_life_polling() {
    static uint8_t led_life_state = 0;
    static uint16_t period_led_life_polling_ms = 0;
    if (period_led_life_polling_ms == PERIOD_LED_LIFE_POLLING){
        if (led_life_state == 0) {
            led_life_write_low();
            led_life_state = 1;
            period_led_life_polling_ms = 0;
        }
        else if (led_life_state == 1){
            led_life_write_high();
            led_life_state = 0;
            period_led_life_polling_ms = 0;
        }
    }
    period_led_life_polling_ms++;
}

void task_polling_1ms() {
    led_life_polling();
}

void task_polling_10ms() {

}