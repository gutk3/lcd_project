#include <stdint.h>
#include "stm32f4xx_hal.h"
#include "../../STM32CubeIDE/Application/draw.h"
#include <stdio.h>
#include <math.h>



#define FB1_ADDR                               ((uint32_t)0xD0000000)
#define DISP_WIDTH        640
#define DISP_HEIGHT       480
#define FB_SIZE                         (DISP_WIDTH * DISP_HEIGHT * 2)
#define FB2_ADDR                        (FB1_ADDR + FB_SIZE)

void clear_display(void){


	for (uint32_t i = 0 ; i < DISP_WIDTH * DISP_HEIGHT; i++){
	  	  ((int16_t*)FB1_ADDR)[i] = 0x0000;


	}
};

void set_background(uint16_t color){


	for (uint32_t i = 0 ; i < DISP_WIDTH * DISP_HEIGHT; i++){
	  	  ((int16_t*)FB1_ADDR)[i] = color;

	}
};

void draw_pixel(int x,int y, uint16_t color){

	((int16_t*)FB1_ADDR)[x + y * DISP_WIDTH] = color;

};

void draw_line(int x0, int y0, int x1, int y1, uint16_t color){

	int disp_size = 640*480;

	int x_ch, y_ch;
	int x_step, y_step;
	x_ch = x1 - x0;
	y_ch = y1 - y0;
	if (y_ch < 0) { y_ch = -y_ch; y_step = -1; } else { y_step = 1; }
	if (x_ch < 0) { x_ch = -x_ch; x_step = -1; } else { x_step = 1; }
	y_ch <<= 1;
	x_ch <<= 1;
	if ((0 <= x0) && (x0 < disp_size) && (0 <= y0) && (y0 < disp_size))
		draw_pixel(x0,y0,color);
	if (x_ch > y_ch) {
		int cond = y_ch - (x_ch >> 1);
		while (x0 != x1) {
				x0 += x_step;
				if (cond >= 0) {
					y0 += y_step;
					cond -= x_ch;
				}
				cond += y_ch;
				if ((0 <= x0) && (x0 < disp_size) && (0 <= y0) && (y0 < disp_size))
					draw_pixel(x0,y0,color);
				}
			} else {
			int cond = x_ch - (y_ch >> 1);
	while (y0 != y1) {
	if (cond >= 0) {
		x0 += x_step;
		cond -= y_ch;
	}
		y0 += y_step;
		cond += x_ch;
		if ((0 <= x0) && (x0 < disp_size) && (0 <= y0) && (y0 < disp_size))
			draw_pixel(x0,y0,color);
		}
	}

};


void circle(int xc, int yc, int x, int y, uint16_t color){

    draw_pixel(xc+x, yc+y, color);
    draw_pixel(xc-x, yc+y, color);
    draw_pixel(xc+x, yc-y, color);
    draw_pixel(xc-x, yc-y, color);
    draw_pixel(xc+y, yc+x, color);
    draw_pixel(xc-y, yc+x, color);
    draw_pixel(xc+y, yc-x, color);
    draw_pixel(xc-y, yc-x, color);
};

void draw_circle(int xc, int yc, int r, uint16_t color){

	int x = 0, y = r;
    int b = 3 - 2 * r;
    circle(xc, yc, x, y, color);
    while (y >= x)
    {
    	x++;

        if (b > 0)
        {
            y--;
            b = b + 4 * (x - y) + 10;
        }
        else
            b = b + 4 * x + 6;
        circle(xc, yc, x, y, color);

    }
};

void draw_rectangle(int x0, int y0, int x1, int y1, uint16_t color){

	for(int i=y0;i<y1;i++)
		draw_pixel(x0,i,color);

	for(int i=y0;i<y1;i++)
		draw_pixel(x1,i,color);

	for(int i=x0;i<x1;i++)
		draw_pixel(i,y0,color);

	for(int i=x0;i<x1;i++)
		draw_pixel(i,y1,color);
};

void fill_rectangle(int x0, int y0, int x1, int y1, uint16_t color){

	for(int i=x0;i<x1;i++){
		for(int j=y0;j<y1;j++){
			draw_pixel(i,j,color);
		};
	};
};

void fill_circle(int x_c,int y_c,int r,uint16_t color){

	for(int i=x_c-r;i<x_c+r;i++){
		for(int j=y_c-r;j<y_c+r;j++){
			int dx = x_c - i;
			int dy = y_c - j;
			if ( (dx*dx + dy*dy) <= (r*r) )
			{
				draw_pixel(i,j,color);
			};
		};
	};
};

void draw_triangle(int x_a,int y_a,int x_b,int y_b,int x_c,int y_c,uint16_t color){

	draw_line(x_a,y_a,x_b,y_b,color);
	draw_line(x_b,y_b,x_c,y_c,color);
	draw_line(x_a,y_a,x_c,y_c,color);
};

