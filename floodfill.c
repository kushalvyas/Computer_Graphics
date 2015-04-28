// to implement flood fill algorithm

#include"stdio.h"
#include"stdlib.h"
#include"graphics.h"
#include"math.h"
void ffill(int x,int y,int fill,int old)
{
	int current;
	current=getpixel(x,y);
	if(current==old)
	{
		putpixel(x,y,fill);
		ffill(x+1,y,fill,old);
		ffill(x-1,y,fill,old);
		ffill(x,y+1,fill,old);
		ffill(x,y-1,fill,old);
		ffill(x+1,y+1,fill,old);
		ffill(x-1,y+1,fill,old);
		ffill(x+1,y-1,fill,old);
		ffill(x-1,y-1,fill,old);
	}
}
void main()
{
	int gd=DETECT,gm,i,x,y;
	initgraph(&gd,&gm,"");
	setbkcolor(0);
	setcolor(8);
	rectangle(100,100,150,150);
	ffill(125,125,7,0);
	getchar();
	closegraph();
}
