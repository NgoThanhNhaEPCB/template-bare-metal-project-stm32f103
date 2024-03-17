/**
 ******************************************************************************
 * @author: Nark
 * @date:   06/02/2024
 ******************************************************************************
**/
#ifndef __APP_H__
#define __APP_H__

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
#include "screen_idle.h"


#ifdef __cplusplus
 extern "C" {
#endif 

extern void main_app();

#ifdef __cplusplus
}
#endif

#endif /* __APP_H__ */
