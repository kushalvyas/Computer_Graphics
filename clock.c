// implementing a sample clock using graphics.h
#include "stdio.h"
#include "stdlib.h"
#include "graphics.h"
#include "math.h"


#define pi M_PI


int main(){
	int gd = DETECT , gm ;
	int sec , minute , hour ;
	int len_sec = 70,len_minute = 60 , len_hour =40;
	float t;
	int r = 80,xc=250,yc=250;
	
	// initializing seconds hand
	int xs = xc + len_sec*cos(pi*1/180.0);
	int ys = yc + len_sec*sin(pi*1/180.0);
	// initialiazing minutes hand
	int xm = xc + len_minute*cos(pi*1/180.0);
	int ym = yc + len_minute*sin(pi*1/180.0);
	// initializing hour hand
	int xh = xc + len_hour*cos(pi*1/180.0);
	int yh = yc + len_hour*sin(pi*1/180.0);
	

	initgraph(&gd,&gm,"");


	// initializing the clock
	circle(xc,yc,r);
	line(xc,yc,xs,ys);
	line(xc,yc,xm,ym);
	line(xc,yc,xh,yh);

	getchar();
	int rotate_angle_for_minute = 0;
	int rotate_angle_for_hour = 0;

	// i denotes degrees of rotation 
	for (int i = 0; i < 1000; i++){
		// for loop keeps count for second

		circle(xc,yc,r);

		// calculation for seconds hand
		xs = xc + len_sec*cos(pi*i/180.0);
		ys = yc + len_sec*sin(pi*i/180.0);


		// calculating minute hand
		// one min has 60 seconds
		// so the second hand needs to move 360 degrees for minutes hand to move
		if(i%360 == 0){
			xm = xc + len_minute*cos(pi*rotate_angle_for_minute/180.0);
			ym = yc + len_minute*sin(pi*rotate_angle_for_minute/180.0);
			rotate_angle_for_minute++;
		}

		// calculation for hours hand
		// simnilarly for hours
		if(i%(360*360) == 0){
			xh = xc + len_hour*cos(pi*rotate_angle_for_hour/180.0);
			yh = yc + len_hour*sin(pi*rotate_angle_for_hour/180.0);
			rotate_angle_for_hour++;
			
		}

		// plotting
		line(xc,yc,xs,ys);
		line(xc,yc,xm,ym);
		line(xc,yc,xh,yh);
		delay(50);
		cleardevice();
	


	}

	getchar();
	closegraph();
	return 0;
}