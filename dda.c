#include "stdio.h"
#include "graphics.h"
#include "stdlib.h"
#include "math.h"

#ifndef COL
#define COL 3
#endif

// DDA Algorithm plotting line function
void plotLine_using_DDA_algorithm(float m){
double  y0=50,x0=50,y1=100,x1=100,x,y;
int y_sub,x_sub;

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

// defining the main of DDA
int main(int argc, char const *argv[]){
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	printf("DDA Algorithm\n");
	plotLine_using_DDA_algorithm(1);
	getchar();
	closegraph();
	return 0;
}