// to plot a chessboard

#include "stdio.h"
#include "stdlib.h"
#include "graphics.h"



void dda_line(int x0,int y0,int x1,int y1 , int COL){
	float m = (y1-y0)*1.0/(x1-x0);
	float  y_sub,x_sub,x,y;
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


int main(){

	int gd = DETECT , gm;
	int square = 8;
	int board_length,square_size;
	int i,j,k,COL;
	int originX = 100, originY = 100;
	int x=originX , y=originY;

	printf("Enter the length of board\n");
	scanf("%d",&board_length);
	square_size = board_length/8;

	initgraph(&gd,&gm,"");
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){

			if((i+j)%2 == 0){
				COL = BLACK;
			}else{
				COL = WHITE;
			}
			for(k=0;k<square_size;k++){
				dda_line(x,y,x,y+square_size,COL);
				x++;
			}


		}
		y+=square_size;
		x = originX;
		


	}
	
	getchar();
	closegraph();

	return 0;
}