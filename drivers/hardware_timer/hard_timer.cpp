/**
 ******************************************************************************
 * @author: Nark
 * @date:   06/02/2024
 ******************************************************************************
**/
#include "hard_timer.h"

volatile uint32_t system_tick_count = 0;

void systick_init(void) {
    SystemCoreClockUpdate();
    if (SysTick_Config(SystemCoreClock / 1000)) { 
        while (1);
    }
    SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk;
}

void delay_ms(uint32_t milliseconds) {
    uint32_t start_tick = system_tick_count;

    while ((system_tick_count - start_tick) < milliseconds);
}
