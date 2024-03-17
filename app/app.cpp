/**
 ******************************************************************************
 * @author: Nark
 * @date:   06/02/2024
 ******************************************************************************
**/
#include "app.h"

void main_app() {

    /* system tick init */
    systick_init();

    /* io init */
    io_init();

    /* view render init */
    ssd1283a_init();
    ssd1283a_clear_screen(BLACK);

    /* screen idle */
    screen_idle_init();

    while(1) {
        screen_idle_handler();
    }
}


