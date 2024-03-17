/**
 ******************************************************************************
 * @author: Nark
 * @date:   06/02/2024
 ******************************************************************************
**/
#include "io_cfg.h"

/*-----------------------------------------------------------------*/
/*                        led life fuctions                        */
/*-----------------------------------------------------------------*/
void led_life_init() {
    GPIO_InitTypeDef    GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(LED_LIFE_IO_CLOCK, ENABLE);

	GPIO_InitStructure.GPIO_Pin = LED_LIFE_IO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(LED_LIFE_IO_PORT, &GPIO_InitStructure);
}

void led_life_write_low() {
	GPIO_ResetBits(LED_LIFE_IO_PORT, LED_LIFE_IO_PIN);
}

void led_life_write_high() {
	GPIO_SetBits(LED_LIFE_IO_PORT, LED_LIFE_IO_PIN);
}

/*-----------------------------------------------------------------*/
/*                        soft spi fuctions                        */
/*-----------------------------------------------------------------*/
void soft_spi_mosi_pin_init() {
    GPIO_InitTypeDef    GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(SOFT_SPI_MOSI_IO_CLOCK, ENABLE);

	GPIO_InitStructure.GPIO_Pin = SOFT_SPI_MOSI_IO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(SOFT_SPI_MOSI_IO_PORT, &GPIO_InitStructure);
}

void soft_spi_sck_pin_init() {
    GPIO_InitTypeDef    GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(SOFT_SPI_SCK_IO_CLOCK, ENABLE);

	GPIO_InitStructure.GPIO_Pin = SOFT_SPI_SCK_IO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(SOFT_SPI_SCK_IO_PORT, &GPIO_InitStructure);
}

void soft_spi_cs_pin_init() {
    GPIO_InitTypeDef    GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(SOFT_SPI_CS_IO_CLOCK, ENABLE);

	GPIO_InitStructure.GPIO_Pin = SOFT_SPI_CS_IO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(SOFT_SPI_CS_IO_PORT, &GPIO_InitStructure);
}

void ssd1283a_dc_pin_init() {
    GPIO_InitTypeDef    GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(SSD1283A_DC_IO_CLOCK, ENABLE);

	GPIO_InitStructure.GPIO_Pin = SSD1283A_DC_IO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(SSD1283A_DC_IO_PORT, &GPIO_InitStructure);
}

void ssd1283a_rst_pin_init() {
    GPIO_InitTypeDef    GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(SSD1283A_RST_IO_CLOCK, ENABLE);

	GPIO_InitStructure.GPIO_Pin = SSD1283A_RST_IO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(SSD1283A_RST_IO_PORT, &GPIO_InitStructure);
}

void soft_spi_mosi_write_pin_high() {
	GPIO_SetBits(SOFT_SPI_MOSI_IO_PORT, SOFT_SPI_MOSI_IO_PIN);
}

void soft_spi_mosi_write_pin_low() {
	GPIO_ResetBits(SOFT_SPI_MOSI_IO_PORT, SOFT_SPI_MOSI_IO_PIN);
}

void soft_spi_sck_write_pin_high() {
	GPIO_SetBits(SOFT_SPI_SCK_IO_PORT, SOFT_SPI_SCK_IO_PIN);
}

void soft_spi_sck_write_pin_low() {
	GPIO_ResetBits(SOFT_SPI_SCK_IO_PORT, SOFT_SPI_SCK_IO_PIN);
}

void soft_spi_cs_write_pin_high() {
	GPIO_SetBits(SOFT_SPI_CS_IO_PORT, SOFT_SPI_CS_IO_PIN);
}

void soft_spi_cs_write_pin_low() {
	GPIO_ResetBits(SOFT_SPI_CS_IO_PORT, SOFT_SPI_CS_IO_PIN);
}

void ssd1283a_dc_write_pin_high() {
	GPIO_SetBits(SSD1283A_DC_IO_PORT, SSD1283A_DC_IO_PIN);
}

void ssd1283a_dc_write_pin_low() {
	GPIO_ResetBits(SSD1283A_DC_IO_PORT, SSD1283A_DC_IO_PIN);
}

void ssd1283a_rst_write_pin_high() {
	GPIO_SetBits(SSD1283A_RST_IO_PORT, SSD1283A_RST_IO_PIN);
}

void ssd1283a_rst_write_pin_low() {
	GPIO_ResetBits(SSD1283A_RST_IO_PORT, SSD1283A_RST_IO_PIN);
}

void soft_spi_init() {
	soft_spi_mosi_pin_init();
	soft_spi_sck_pin_init();
	soft_spi_cs_pin_init();
	ssd1283a_dc_pin_init();
	ssd1283a_rst_pin_init();

	soft_spi_mosi_write_pin_low();
	soft_spi_sck_write_pin_low();
	soft_spi_cs_write_pin_high();
	ssd1283a_rst_write_pin_high();
}

/*-----------------------------------------------------------------*/
/*                           io initialize                         */
/*-----------------------------------------------------------------*/
void io_init() {
    led_life_init();
	soft_spi_init();
}

