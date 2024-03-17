/**
 ******************************************************************************
 * @author: Nark
 * @date:   06/02/2024
 ******************************************************************************
**/
#ifndef __SOFT_SPI_H__
#define __SOFT_SPI_H__

/* system drivers */
#include "stm32f10x.h"
#include "stm32f10x_common_peripheral_includes.h"

/* user drivers */
#include "hard_timer.h"
#include "io_cfg.h"

extern void soft_spi_write_byte(uint8_t _data);

#endif /* __SOFT_SPI_H__ */