// header for drawing ellipses
#include "graphics.h"
#include "stdio.h"
#include "math.h"

#ifndef COL
#define COL 3
#endif

#define plot(x,y) putpixel(x,y,COL);

void put_points(int xc,int yc,int x , int y){
	plot(xc+x,yc+y);
	plot(xc-x,yc+y);
	plot(xc+x,yc-y);
	plot(xc-x,yc-y);
}

void midpoint_ellipse(int rx , int ry , int xc, int yc){

	float rxSq = rx * rx;
	float rySq = ry * ry;
	float x = 0, y = ry, p;
	float px = 0, py = 2 * rxSq * y;

	// drawing region 1
	put_points(	xc,yc,x,y);

	//Region 1
	p = rySq - (rxSq * ry) + (0.25 * rxSq);
	while (px < py){
		x++;
		px = px + 2 * rySq;
		if (p < 0)
			p = p + rySq + px;
		else{
			y--;
			py = py - 2 * rxSq;
			p = p + rySq + px - py;
		}
		put_points(xc, yc, x, y);
		
	}
	 //Region 2
	p = rySq*(x+0.5)*(x+0.5) + rxSq*(y-1)*(y-1) - rxSq*rySq;
	while (y > 0){
		y--;
		py = py - 2 * rxSq;
		if (p > 0)
			p = p + rxSq - py;
		else{
			x++;
			px = px + 2 * rySq;
			p = p + rxSq - py + px;
		}
		put_points(xc, yc, x, y);
		
		}

}