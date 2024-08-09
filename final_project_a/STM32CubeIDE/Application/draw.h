#include <stdint.h>
#include "stm32f4xx_hal.h"
#include <stdio.h>
#include <math.h>

void clear_display(void);
void set_background(uint16_t color);
void draw_pixel(int x, int y, uint16_t color);
void draw_line(int x0, int y0, int x1, int y1, uint16_t color);
void circle(int xc, int yc, int x, int y, uint16_t color);
void draw_circle(int xc, int yc, int r, uint16_t color);
void draw_rectangle(int x0, int y0, int x1, int y1, uint16_t color);
void fill_rectangle(int x0, int y0, int x1, int y1, uint16_t color);
void fill_circle(int x_c,int y_c,int r,uint16_t color);
void draw_triangle(int x_a,int y_a,int x_b,int y_b,int x_c,int y_c,uint16_t color);
