#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "graphics.h"

#ifndef COLOR
#define COLOR 3
#endif

// using the DDA line algorithm :
void DDA(int x0,int y0,int x1,int y1){

	/*Logic for DDA:
	*When the slope is < 1, that is that the line is more steeper towards the 
	* x axis , implies that the x coordinate increaments quickly
	*When the slope is > 1 that is that the line is more steeper towards the y axis
	* , it implies that the y coordinates will increament more quickly.
	*/

	double y,x,x_sub,y_sub;
	double slope;
	slope = ((y1-y0)*1.0)/(x1-x0);
	if(slope < 1){
		y = y0;
		for(x=x0;x<x1;x++,y+=slope){
			x_sub = (int)x;
			y_sub = (int)y;
			putpixel(x,y,COLOR);
		}

	}else{
		x = x0;
		for(y=y0;y<=y1;y++,x+=(1.0/slope)){
			x_sub = (int)x;
			y_sub = (int)y;
			putpixel(x,y,COLOR);	
		}
	}
}



// driver function to test the program
int main(int argc, char const *argv[]){
	int gd = DETECT ,gm;
	int x0,y0,x1,y1;
	printf("Enter the start and end coordinates\n");
	scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
	initgraph(&gd,&gm,"");
	DDA(x0,y0,x1,y1);
	
	getchar();
	closegraph();
	return 0;
}