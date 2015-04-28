// code to rotate circle about circumference of a circle

#include "stdio.h"
#include "stdlib.h"
#include "graphics.h"
#include "math.h"

#define pi M_PI

int main(){

	int gd = DETECT , gm ;
	float R = 50 , r = 10 , xc = 250 , yc = 250 , t;
	initgraph(&gd,&gm,"");
	
	for(int i =0 ; i<360;i++){
		t = (pi * i) / 180.0 ;
		circle(xc,yc,R);
		int x = xc + (R+r)*cos(t);
		int y = yc + (R+r)*sin(t);
		circle(x+1,y+1,r);
		delay(20);
		cleardevice();

	}
	getchar();
	closegraph();

}