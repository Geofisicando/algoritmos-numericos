#include <stdio.h>
#include <math.h>
#include "runge.h"

//float funcao(float x, float y){return y;}

//float funcao(float x, float y){return y-x;}
//float solucao(float x, float y){return expf(x)+x+1;}

float funcao(float x, float y){return y*y+1;}
float solucao(float x, float y){return tanf(x);}

int main(void){
	
	const float inicial=0.0;
	const float final=1.0;
	const float h=0.1;
	const float x0=0.;
	const float y0=0.;
	int n, i;
	float x, y;

	x=x0;
	y=y0;

	printf("x=%f y=%f ys=%f\n",x,y,solucao(x,y));

	n=(final-inicial)/h;

	for(i=0;i<n;i++){
		y = runge_kutta_step(funcao,x,y,h);
		x += h;
		printf("x=%f y=%f ys=%f\n",x,y,solucao(x,y));
	}
}
