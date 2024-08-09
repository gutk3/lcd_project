#include <stdint.h>
#include "stm32f4xx_hal.h"
#include <stdio.h>
#include <math.h>
#include "string.h"
#include "../../STM32CubeIDE/Application/comand.h"
#include "../../STM32CubeIDE/Application/draw.h"

extern char buffer[64];

uint16_t color;

int x, y, x_c, y_c, r, y_0, x_0, x_1, y_1, x_2, y_2, width;


void read_command(void){

	if(buffer[0]!='\0'){

			if (strncmp(buffer, "clear_display", strlen("clear_display")) == 0) {
			          	clear_display();
			          	memset(buffer, '\0', 64);
			       };
			if (strncmp(buffer, "set_background", strlen("set_background")) == 0) {
						color=0x0000;
						sscanf(buffer,"set_background(%X)", &color);
					    set_background(color);
					    memset(buffer, '\0', 64);
				       };
			if (strncmp(buffer, "draw_pixel", strlen("draw_pixel")) == 0){

						draw_pixel(x,y,color);
						memset(buffer, '\0', 64);
			};
			if(strncmp(buffer, "draw_line", strlen("draw_line"))==0){

				sscanf(buffer,"draw_line(%d,%d,%d,%d,%X)", &x_0,&y_0,&x_1,&y_1,&color);
				draw_line(x_0,y_0,x_1,y_1,color);
				memset(buffer, '\0', 64);
			};
			if(strncmp(buffer, "draw_circle", strlen("draw_circle"))==0){

				sscanf(buffer,"draw_circle(%d,%d,%d,%X)", &x_c,&y_c,&r,&color);
				draw_circle(x_c,y_c,r,color);
				memset(buffer, '\0', 64);
			};
			if(strncmp(buffer, "fill_circle", strlen("fill_circle"))==0){

				sscanf(buffer,"fill_circle(%d,%d,%d,%X)", &x_c,&y_c,&r,&color);
				fill_circle(x_c,y_c,r,color);
				memset(buffer, '\0', 64);
			};
			if(strncmp(buffer, "draw_rectangle", strlen("draw_rectangle"))==0){

				sscanf(buffer,"draw_rectangle(%d,%d,%d,%d,%X)", &x_0,&y_0,&x_1,&y_1,&color);
				draw_rectangle(x_0,y_0,x_1,y_1,color);
				memset(buffer, '\0', 64);
			};
			if(strncmp(buffer, "fill_rectangle", strlen("fil_rectangle"))==0){

				sscanf(buffer,"fill_rectangle(%d,%d,%d,%d,%X)", &x_0,&y_0,&x_1,&y_1,&color);
				fill_rectangle(x_0,y_0,x_1,y_1,color);
				memset(buffer, '\0', 64);
			};
			if(strncmp(buffer, "draw_triangle", strlen("draw_triangle"))==0){

				sscanf(buffer,"draw_triangle(%d,%d,%d,%d,%d,%d,%X)", &x_0,&y_0,&x_1,&y_1,&x_2,&y_2,&color);
				draw_triangle(x_0,y_0,x_1,y_1,x_2,y_2,color);
				memset(buffer, '\0', 64);
			};
	   };
};
