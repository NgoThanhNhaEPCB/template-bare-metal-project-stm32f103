/**
 ******************************************************************************
 * @author: Nark
 * @date:   06/02/2024
 ******************************************************************************
**/
#ifndef __SYSTEM_IRQ_H__
#define __SYSTEM_IRQ_H__

#include "app.h"

#ifdef __cplusplus
 extern "C" {
#endif 

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"

void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SVC_Handler(void);
void DebugMon_Handler(void);
void PendSV_Handler(void);
void system_tick_handler(void);

#ifdef __cplusplus
}
#endif

#endif /* __SYSTEM_IRQ_H__ */

