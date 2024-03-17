/**
 ******************************************************************************
 * @author: Nark
 * @date:   06/02/2024
 ******************************************************************************
**/
#include "soft_spi.h"

void soft_spi_write_byte(uint8_t _data) {
    for (uint8_t i = 0; i < 8; i++) {
        if (_data & 0x80) {
            soft_spi_mosi_write_pin_high();
        } 
        else {
            soft_spi_mosi_write_pin_low();
        }
        soft_spi_sck_write_pin_high();
        _data = _data << 1;
        soft_spi_sck_write_pin_low();
    }
}
