/**
 ******************************************************************************
 * @author: Nark
 * @date:   06/02/2024
 ******************************************************************************
**/

#include "ssd1283a.h"

void ssd1283a_write_index(uint8_t _command) {
   soft_spi_cs_write_pin_low();
   ssd1283a_dc_write_pin_low();
   soft_spi_write_byte(_command);
   soft_spi_cs_write_pin_high();
}

void ssd1283a_write_data(uint8_t _data) {
   soft_spi_cs_write_pin_low();
   ssd1283a_dc_write_pin_high();
   soft_spi_write_byte(_data);
   soft_spi_cs_write_pin_high();
}

void ssd1283a_write_data_16bit(uint16_t _data) {
   soft_spi_cs_write_pin_low();
   ssd1283a_dc_write_pin_high();
   soft_spi_write_byte(_data >> 8);
   soft_spi_write_byte(_data);
   soft_spi_cs_write_pin_high();
}

void ssd1283a_write_reg_16bit(uint8_t _index, uint16_t _data) {
    ssd1283a_write_index(_index);
    ssd1283a_write_data_16bit(_data);
}

void ssd1283a_reset() {
	ssd1283a_rst_write_pin_low();
	delay_ms(100);
	ssd1283a_rst_write_pin_high();
	delay_ms(50);
}

void ssd1283a_init() {	
    ssd1283a_reset();
    ssd1283a_write_reg_16bit(0x10,0x2F8E); /* power control 1 */
    ssd1283a_write_reg_16bit(0x11,0x000C); /* power control 2 */
    ssd1283a_write_reg_16bit(0x07,0x0021); /* display control */
    ssd1283a_write_reg_16bit(0x28,0x0006); /* vcom OTP */
    ssd1283a_write_reg_16bit(0x28,0x0005);
    ssd1283a_write_reg_16bit(0x27,0x057F); /* further bias current setting */
    ssd1283a_write_reg_16bit(0x29,0x89A1); /* vcom OTP */
    ssd1283a_write_reg_16bit(0x00,0x0001); /* OSC en */
    delay_ms(100);
    ssd1283a_write_reg_16bit(0x29,0x80B0); /* vcom OTP */
    delay_ms(30);
    ssd1283a_write_reg_16bit(0x29,0xFFFE); /* vcom OTP */
    ssd1283a_write_reg_16bit(0x07,0x0023); /* display control */
    delay_ms(30);
    ssd1283a_write_reg_16bit(0x07,0x0033); /* display control */
    #if USE_HORIZONTAL
    ssd1283a_write_reg_16bit(0x01,0x2283); /* driver output control, REV, TB=0, RL=1, RGB */
    ssd1283a_write_reg_16bit(0x03,0x6838); /* entry mode, 65K, ram, ID3 */
    #else
    ssd1283a_write_reg_16bit(0x01,0x2183); /* driver output control, REV, TB, RGB */
    ssd1283a_write_reg_16bit(0x03,0x6830); /* entry mode, 65K, ram, ID0 */
    #endif
    ssd1283a_write_reg_16bit(0x2F,0xFFFF); /* 2A ~ 2F, test */
    ssd1283a_write_reg_16bit(0x2C,0x8000);
    ssd1283a_write_reg_16bit(0x27,0x0570);
    ssd1283a_write_reg_16bit(0x02,0x0300); /* driving wave form control */
    ssd1283a_write_reg_16bit(0x0B,0x580C); /* frame cycle control */
    ssd1283a_write_reg_16bit(0x12,0x0609); /* power control 3 */
    ssd1283a_write_reg_16bit(0x13,0x3100); /* power control 4 */
}

void ssd1283a_set_cursor(uint16_t x, uint16_t y) {	
    #if USE_HORIZONTAL	
        ssd1283a_write_index(0x21);
        ssd1283a_write_data(x);
        ssd1283a_write_data(y + 2);	
    #else
        ssd1283a_write_index(0x21);
        ssd1283a_write_data(y + 2);
        ssd1283a_write_data(x + 2);	
    #endif
        ssd1283a_write_index(0x22);	
}

void ssd1283a_set_region(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1) {

    #if USE_HORIZONTAL
        ssd1283a_write_index(0x45);
        ssd1283a_write_data(x1);
        ssd1283a_write_data(x0);	
        
        ssd1283a_write_index(0x44);
        ssd1283a_write_data(y1 + 2);
        ssd1283a_write_data(y0 + 2);	
    #else
        ssd1283a_write_index(0x44);
        ssd1283a_write_data(x1 + 2);
        ssd1283a_write_data(x0 + 2);	
        
        ssd1283a_write_index(0x45);
        ssd1283a_write_data(y1 + 2);
        ssd1283a_write_data(y0 + 2);	
    #endif
        ssd1283a_set_cursor(x0, y0);
}

void ssd1283a_draw_pixel(uint16_t x, uint16_t y, uint16_t color) {
	ssd1283a_set_cursor(x, y);
	ssd1283a_write_data_16bit(color);
}

void ssd1283a_clear_screen(uint16_t color) {	
    unsigned int i, m;
    ssd1283a_set_region(0, 0, X_MAX_PIXEL - 1, Y_MAX_PIXEL - 1);
    soft_spi_cs_write_pin_low();
    ssd1283a_dc_write_pin_high();
    for(i = 0;i < X_MAX_PIXEL; i++){
        for(m = 0; m < Y_MAX_PIXEL; m++){	
            soft_spi_write_byte(color >> 8);
            soft_spi_write_byte(color);
        }
    }
    soft_spi_cs_write_pin_high(); 
}

void ssd1283a_draw_bitmap(uint16_t x0, uint16_t y0, uint16_t w, uint16_t h, uint8_t* image) {
    uint32_t cursor = 0;
    ssd1283a_set_region(x0, y0, x0 + w - 1, y0 + h - 1);
    for(uint16_t j = 0; j < w; j++){
        for(uint16_t i = 0; i < h; i++){
            ssd1283a_write_data(image[cursor]);
            ssd1283a_write_data(image[cursor + 1]);
            cursor = cursor + 2;
        }
    }
}

void ssd1283a_draw_circle(int16_t x0, int16_t y0, int16_t r, uint16_t color) {
  int16_t f = 1 - r;
  int16_t ddF_x = 1;
  int16_t ddF_y = -2 * r;
  int16_t x = 0;
  int16_t y = r;

  ssd1283a_draw_pixel(x0  , y0+r, color);
  ssd1283a_draw_pixel(x0  , y0-r, color);
  ssd1283a_draw_pixel(x0+r, y0  , color);
  ssd1283a_draw_pixel(x0-r, y0  , color);

  while (x<y) {
    if (f >= 0) {
      y--;
      ddF_y += 2;
      f += ddF_y;
    }
    x++;
    ddF_x += 2;
    f += ddF_x;
    ssd1283a_draw_pixel(x0 + x, y0 + y, color);
    ssd1283a_draw_pixel(x0 - x, y0 + y, color);
    ssd1283a_draw_pixel(x0 + x, y0 - y, color);
    ssd1283a_draw_pixel(x0 - x, y0 - y, color);
    ssd1283a_draw_pixel(x0 + y, y0 + x, color);
    ssd1283a_draw_pixel(x0 - y, y0 + x, color);
    ssd1283a_draw_pixel(x0 + y, y0 - x, color);
    ssd1283a_draw_pixel(x0 - y, y0 - x, color);
  }
}