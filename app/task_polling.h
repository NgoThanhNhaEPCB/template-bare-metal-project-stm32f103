/**
 ******************************************************************************
 * @author: Nark
 * @date:   06/02/2024
 ******************************************************************************
**/
#ifndef __TASK_POLLING_H__
#define __TASK_POLLING_H__

/* system drivers */
#include "stm32f10x.h"
#include "stm32f10x_common_peripheral_includes.h"

/* user drivers */
#include "hard_timer.h"
#include "io_cfg.h"

#define PERIOD_LED_LIFE_POLLING         (500)

#ifdef __cplusplus
 extern "C" {
#endif 

extern void task_polling_1ms();

#ifdef __cplusplus
}
#endif


#endif /* __TASK_POLLING_H__ */