// only for drawing lines in this
#include "stdio.h"
#include "math.h"
#include "graphics.h"

#ifndef COL
#define COL 3
#endif

# define plot(x,y) putpixel(x,y,COL)



// funtion to draw dda line

void dda_line(int x0,int y0,int x1,int y1){
	float m = (y1-y0)*1.0/(x1-x0);
	float  y_sub,x_sub,x,y;
	if ( m < 1  ){
		y = y0;
		for (x=x0;x<=x1;x++,y+=m){
			x_sub = (int)(x);
			y_sub = (int)(y);
			putpixel(x_sub,y_sub,COL);
		}
	}else{
		x = x0;
		for(y=y0;y<=y1;y++,x+=(1/m)){
			x_sub = (int)(x);
			y_sub = (int)(y);
			putpixel(x_sub,y_sub,COL);
		}
	}
}


// function for bresenhams line algo
void bresenhams_line(int x0,int y0,int x1,int y1){
	int dx = x1-x0;
	int dy = y1-y0;
	int D  = 2*dy - dx;
	int y=y0,x;
	putpixel(x0,y0,COL);
	for(x=x0;x<x1;x++){
		if (D > 0){
			y++;
			putpixel(x,y,COL);
			D+=(2*dy - 2*dx);

		}else{
			plot(x,y);
			D+=2*dy;
		}
	}

}