// implementation of n point bezier curve
#include "stdio.h"
#include "stdlib.h"
#include "graphics.h"
#include "math.h"

#define plot(x,y) putpixel(x,y,3);

int x_coordinates[10],y_coordinates[10];



double factorial(int x){
	if ( x==0 || x==1){
		return 1;
	}else{
		return x*factorial(x-1);
	}
}




void bezier(int n){
	
	int counter;
	double alpha;
	double step_size;
	double x_out,y_out;
	double n_factorial = factorial(n);
	
	for(step_size=0.0;step_size<1.0;step_size+=0.003){
		x_out=0;y_out=0;
		for(counter=0 ;counter<=n;counter++){
			alpha = n_factorial/(factorial(counter)*factorial(n-counter));
			x_out += x_coordinates[counter]*pow(step_size,counter)*pow(1-step_size,n-counter)*alpha;
			y_out += y_coordinates[counter]*pow(step_size,counter)*pow(1-step_size,n-counter)*alpha;
		}
		plot(x_out,y_out);
	}

	
	

}


int main(){

	int gd = DETECT , gm ;
	int n=0,i;
	printf("Enter numbner of points\n");
	scanf("%d",&n);
	printf("Enter pair of coordinates seperated by a space\n");
	for(i=0;i<n;i++){
		// printf("Enter pair %d\n", i);
		scanf("%d %d" , &x_coordinates[i],&y_coordinates[i]);
	}	

	initgraph(&gd,&gm,"");

	bezier(n-1);

	getchar();
	closegraph();

	return 0;
}


