// author : bini
// compiled using Linux GCC and SDL libgraph and lm flags
// to compile in terminal : gcc mw.c -lgraph -lm 


#include "stdio.h"
#include "stdlib.h"
#include "graphics.h"
#include "math.h"

#define pi M_PI 

//  xc and yc are centers
// x and y are spoke ka array
int xc=100,yc=100,x[100],y[100];


int main(){
	int gd = DETECT , gm ;
	int a,i, n,r=40;
	double rotate_angle = 0 , t = 0; 
	
	// inputs
	printf("Enter radius and spokes\n");
	scanf("%d %d",&r,&n);
	
	// initialization graphs
	initgraph(&gd,&gm,"");
	setcolor(3);

	a = xc + r;

	while(!kbhit()){



		while(a<=630){ // so as to ensure that the wheel doesnt run out of the page
			t = pi*rotate_angle / 180;
			cleardevice();
			circle(xc,yc,r);

			// use polar coordinates to rotate.. !! 
			for(i=0;i<n;i++,rotate_angle+=360/n){
				// now moving of wheel takes place in two steps;;;
				// rotation and translation
				// note: only the center of mass of any circular body will undergo translation motion
				// whereas the boundary of the body will undergo rotation motion.
				// we are first finding the angle by which each spoke rotaotes and the we rotate the spoke
				t = pi*rotate_angle/180; 
				x[i] = xc+ r*cos(t);
				y[i] = yc + r*sin(t);
				line(xc,yc,x[i],y[i]);
			}
			rotate_angle+=2; // for next frame ,, ... 
			xc+=2; // translating the center of circle
			a=xc+r; 
			delay(20);	
		}	
		// xc = 100 ; a = xc+r; // uncomment this line if u wanna continous rotation
	}
	getchar();
	closegraph();





}