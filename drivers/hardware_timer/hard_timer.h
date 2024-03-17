/**
 ******************************************************************************
 * @author: Nark
 * @date:   06/02/2024
 ******************************************************************************
**/
#ifndef __HARD_TIMER_H__
#define __HARD_TIMER_H__

/* system drivers */
#include "stm32f10x.h"
#include "stm32f10x_common_peripheral_includes.h"

extern volatile uint32_t system_tick_count;
extern void systick_init(void);
extern void delay_ms(uint32_t milliseconds);

#endif /* __HARD_TIMER_H__ */