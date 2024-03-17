/**
 ******************************************************************************
 * @author: Nark
 * @date:   06/02/2024
 ******************************************************************************
**/
#include "screen_idle.h"

ball_t ball[NUM_BALL_MAX];
uint16_t color_table[6] = {RED, GREEN, YELLOW, BLUE, SBLUE, WHITE};

void screen_idle_init() {
    for (uint8_t i = 0; i < NUM_BALL_MAX; i++) {
        ball[i].axis_x = 1;
        ball[i].axis_y = 1;
        ball[i].slope = (rand() % (31)) - 15;
        ball[i].radius = (rand() % (7)) + 6;
        ball[i].x = rand() % (130 - ball[i].radius);
        ball[i].y = rand() % (130 - ball[i].radius);
        ball[i].color = color_table[rand() % 6];
    }
}

void screen_idle_handler() {
    
    for (uint8_t i = 0; i < NUM_BALL_MAX; i++) {

        ssd1283a_draw_circle(ball[i].x, ball[i].y, ball[i].radius, BLACK);

        if( ball[i].axis_x > 0) {
            ball[i].x = ball[i].x + 2;
        }
        else{
            ball[i].x = ball[i].x - 2;
        }

        if (ball[i].axis_y > 0) {
            ball[i].y += 2 * atan(ball[i].slope);
        }
        else{
            ball[i].y -= 2 * atan(ball[i].slope);
        }

        if (ball[i].x > (130 - ball[i].radius) || ball[i].x < ball[i].radius) {
            ball[i].axis_x = - ball[i].axis_x;
            if (ball[i].x < ball[i].radius) {
                ball[i].x = ball[i].radius;
            }
        }

        if (ball[i].y > (130 - ball[i].radius) || ball[i].y < ball[i].radius ) {
            ball[i].axis_y = - ball[i].axis_y;
            if (ball[i].y < ball[i].radius) {
                ball[i].y = ball[i].radius;
        }
        }

        ssd1283a_draw_circle(ball[i].x, ball[i].y, ball[i].radius, ball[i].color);
        delay_ms(1); 
    }
}
