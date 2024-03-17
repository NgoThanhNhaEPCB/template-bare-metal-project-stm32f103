/**
 ******************************************************************************
 * @author: Nark
 * @date:   06/02/2024
 ******************************************************************************
**/

#ifndef __SCREEN_IDLE_H__
#define __SCREEN_IDLE_H__

#include "math.h"

/* system drivers */
#include "stm32f10x.h"
#include "stm32f10x_common_peripheral_includes.h"

/* user drivers */
#include "hard_timer.h"
#include "io_cfg.h"
#include "ssd1283a.h"

/* user tasks */
#include "task_polling.h"

#define NUM_BALL_MAX            (10)

typedef struct {
    int x, y, axis_x, axis_y, radius, slope, color;
} ball_t;

extern void screen_idle_init();
extern void screen_idle_handler();

#endif /* __SCREEN_IDLE_H__ */
