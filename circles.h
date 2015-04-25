// header for drawing circles
#include "stdio.h"
#include "math.h"
#include "graphics.h"


#ifndef COL
#define COL 3
#endif

# define plot(x,y) putpixel(x,y,COL)


void multi_plot(int xc , int yc ,int x , int y){
	plot(xc+x,yc+y);
	plot(xc+y,yc+x);
	plot(xc-x,yc+y);
	plot(xc-y,yc+x);
	plot(xc-x,yc-y);
	plot(xc-y,yc-x);
	plot(xc+x,yc-y);
	plot(xc+y,yc-x);
}



void simple_circle(int tx,int ty,int r){
	int x,factor,y;
	for(x = -r ; x<=r; x++){
		factor = pow(r,2)- pow(x,2);
		y = sqrt(factor);
		plot(tx+x,ty+y);
		plot(tx+x,ty-y);
	}


}

void midpoint_circle(int xc, int yc,int r){
	int radiuserror = 1-r,y=r,x=0;
	while(x<y){
		x++;
		if(radiuserror < 0){
			radiuserror+= 2*x + 1; 
		}else{
			y--;
			radiuserror += 2*(x-y) + 1;
		}
		multi_plot(xc,yc,x,y);

	}

}

void bresenhams_circle(int xc , int yc,int r){
	int x =0,y=r;
	int p = 3-2*r;
	do{
		multi_plot(xc,yc,x,y);
		if(p<0){
			p = p + 4*x + 6;
		}else{
			p = p + 10 + 4*(x-y);
			y--;
		}
		x++;

	}while(x<y);

}
