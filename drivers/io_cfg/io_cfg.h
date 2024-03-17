/**
 ******************************************************************************
 * @author: Nark
 * @date:   06/02/2024
 ******************************************************************************
**/
#ifndef __IO_CFG_H__
#define __IO_CFG_H__

/* system drivers */
#include "stm32f10x_common_peripheral_includes.h"

/*-----------------------------------------------------------------*/
/*                       led life io pin map                       */
/*-----------------------------------------------------------------*/
#define LED_LIFE_IO_PORT                (GPIOC)
#define LED_LIFE_IO_PIN                 (GPIO_Pin_13)
#define LED_LIFE_IO_CLOCK               (RCC_APB2Periph_GPIOC)

/*-----------------------------------------------------------------*/
/*                       ssd1283a io pin map                       */
/*-----------------------------------------------------------------*/
#define SOFT_SPI_MOSI_IO_PORT           (GPIOA)
#define SOFT_SPI_MOSI_IO_PIN            (GPIO_Pin_4)
#define SOFT_SPI_MOSI_IO_CLOCK          (RCC_APB2Periph_GPIOA)

#define SOFT_SPI_SCK_IO_PORT            (GPIOA)
#define SOFT_SPI_SCK_IO_PIN             (GPIO_Pin_5)
#define SOFT_SPI_SCK_IO_CLOCK           (RCC_APB2Periph_GPIOA)

#define SOFT_SPI_CS_IO_PORT             (GPIOA)
#define SOFT_SPI_CS_IO_PIN              (GPIO_Pin_7)
#define SOFT_SPI_CS_IO_CLOCK            (RCC_APB2Periph_GPIOA)

#define SSD1283A_RST_IO_PORT            (GPIOA)
#define SSD1283A_RST_IO_PIN             (GPIO_Pin_2)
#define SSD1283A_RST_IO_CLOCK           (RCC_APB2Periph_GPIOA)

#define SSD1283A_DC_IO_PORT             (GPIOA)
#define SSD1283A_DC_IO_PIN              (GPIO_Pin_3)
#define SSD1283A_DC_IO_CLOCK            (RCC_APB2Periph_GPIOA)

#ifdef __cplusplus
 extern "C" {
#endif 

/*-----------------------------------------------------------------*/
/*                        led life fuctions                        */
/*-----------------------------------------------------------------*/
extern void led_life_init();
extern void led_life_write_low();
extern void led_life_write_high();

/*-----------------------------------------------------------------*/
/*                        ssd1283a fuctions                        */
/*-----------------------------------------------------------------*/
extern void soft_spi_mosi_write_pin_high();
extern void soft_spi_mosi_write_pin_low();

extern void soft_spi_sck_write_pin_high();
extern void soft_spi_sck_write_pin_low();

extern void soft_spi_cs_write_pin_high();
extern void soft_spi_cs_write_pin_low();

extern void ssd1283a_dc_write_pin_high();
extern void ssd1283a_dc_write_pin_low();

extern void ssd1283a_rst_write_pin_high();
extern void ssd1283a_rst_write_pin_low();

/* initialize io pins */
extern void io_init();

#ifdef __cplusplus
}
#endif

#endif /* __IO_CFG_H__ */