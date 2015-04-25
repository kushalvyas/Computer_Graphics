#include "stdio.h"
#include "stdlib.h"
#include "graphics.h"
#include "circles.h"

#ifndef COL
#define COL 3
#endif

#define plot(x,y) putpixel(x,y,COL)

int Xpath_points[1000];
int Ypath_points[1000];
int path_counter = 0;
void simple_arc(int tx,int ty,int r){
	int x,factor,y;
	for(x = -r ; x<=r; x++){
		factor = pow(r,2)- pow(x,2);
		y = sqrt(factor);
		// plots the locus of pendulum bob
		if( ((tx+x) < 480) && ((tx+x) > 160) && ((ty+y) < 180) && ((ty+y) > 100) ) {
			// plot(tx+x,ty+y);
			printf("%d\n", tx+x);
			Xpath_points[path_counter] = (tx+x);
			Ypath_points[path_counter] = (ty+y);
			path_counter++;
		}
		
	}

}


int main(){
	int gd = DETECT , gm;
	int suspend[2],i ;
	suspend[0] = 320;
	suspend[1] = 50;
	printf("Heres' the swinging pendulum\n");
	simple_arc(320,50,100);
	printf("%d\n", path_counter);
	
	// print to check whether locus of pendulum bob is obtained

	// for (i=0;i<path_counter;i++){
	// 	printf("%d %d\n",Xpath_points[i],Ypath_points[i] );
	// }
	
	// initialize graph
	initgraph(&gd,&gm,"");
	cleardevice();

	while(!kbhit()){

		// oscillation in anticlockwise
		for(i=0;i<path_counter;i++){
			line(suspend[0],suspend[1] , Xpath_points[i],Ypath_points[i] );	
			midpoint_circle(Xpath_points[i],Ypath_points[i],20);
			delay(15);
			cleardevice();
			
		}
		// oscillation in clockwise
		for(i=path_counter-1;i>=0;i--){
			line(suspend[0],suspend[1] , Xpath_points[i],Ypath_points[i] );	
			midpoint_circle(Xpath_points[i],Ypath_points[i],20);
			delay(15);
			cleardevice();
			
		}

	}


	getchar();
	closegraph();

	return 0;
}

