/**
 ******************************************************************************
 * @author: Nark
 * @date:   06/02/2024
 ******************************************************************************
**/

#ifndef __SSD1283A_H__
#define __SSD1283A_H__

/* system drivers */
#include "stm32f10x.h"
#include "stm32f10x_common_peripheral_includes.h"

/* user drivers */
#include "hard_timer.h"
#include "io_cfg.h"
#include "soft_spi.h"

#define LCD_X_SIZE	        130
#define LCD_Y_SIZE	        130

#define USE_HORIZONTAL  	0

#if USE_HORIZONTAL
#define X_MAX_PIXEL	        LCD_Y_SIZE
#define Y_MAX_PIXEL	        LCD_X_SIZE
#else
#define X_MAX_PIXEL	        LCD_X_SIZE
#define Y_MAX_PIXEL	        LCD_Y_SIZE
#endif
#define RED  		        0xf800   
#define GREEN		        0x07e0   
#define BLUE 		        0x001f   
#define SBLUE 	            0x251F   
#define WHITE		        0xffff   
#define BLACK		        0x0000  
#define YELLOW              0xFFE0   
#define GRAY0               0xEF7D   
#define GRAY1               0x8410   
#define GRAY2               0x4208  

extern void ssd1283a_init();
extern void ssd1283a_set_cursor(uint16_t x, uint16_t y);
extern void ssd1283a_set_region(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1);
extern void ssd1283a_draw_pixel(uint16_t x, uint16_t y, uint16_t color);
extern void ssd1283a_clear_screen(uint16_t color);
extern void ssd1283a_draw_bitmap(uint16_t x0, uint16_t y0, uint16_t w, uint16_t h, uint8_t* image);
extern void ssd1283a_draw_circle(int16_t x0, int16_t y0, int16_t r, uint16_t color);

#endif /* __SSD1283A_H__ */
