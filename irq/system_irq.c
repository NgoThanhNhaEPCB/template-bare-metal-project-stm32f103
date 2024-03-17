/**
 ******************************************************************************
 * @author: Nark
 * @date:   06/02/2024
 ******************************************************************************
**/

#include "system_irq.h"

void NMI_Handler(void) {
  /* to do implementations */
}

void HardFault_Handler(void) {
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

void MemManage_Handler(void) {
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

void BusFault_Handler(void) {
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

void SVC_Handler(void) {
  /* to do implementations */
}

void DebugMon_Handler(void) {
  /* to do implementations */
}

void PendSV_Handler(void) {
  /* to do implementations */
}

void system_tick_handler(void){
  system_tick_count++;
  task_polling_1ms();
}
