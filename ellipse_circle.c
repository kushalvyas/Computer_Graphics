// code to rotate a circle about the boundary of an ellipse

#include "stdio.h"
#include "stdlib.h"
#include "graphics.h"
#include "math.h"

#define pi M_PI

int main(){

	int gd = DETECT , gm;
	int xc = 250;
	int yc = 250;
	int r=10;
	int a = 90,b=60;
	initgraph(&gd,&gm,"");
	setbkcolor(0);
	ellipse(250,250,0,360,90,60);

	for (int i = 0; i < 360; ++i){
		float t = (pi*i)/180.0;
		int x = xc + (a+r)*cos(t);
		int y = yc + (b+r)*sin(t);
		ellipse(250,250,0,360,90,60);
		circle(x,y,r);
		delay(20);
		cleardevice();
	}

	

	getchar();
	closegraph();
	return 0;
}