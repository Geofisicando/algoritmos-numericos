#include <stdio.h>
#include <math.h>
#include "runge.h"

float f(float x, float y, float z){return z;}
float g(float x, float y, float z){return y+x;}
float solucao(float x){return expf(x)-expf(-x)-x;}

int main(void){

	const float inicial=0.0;
	const float final=1.0;
	const float h=0.1;
	const float x0=0.;
	const float y0=0.;
	const float z0=1.;
	int n, i;
	float x, y, z;

	x=x0;
	y=y0;
	z=z0;

	printf("x=%f z=%f y=%f ys=%f\n",x,z,y,solucao(x));

	n=(final-inicial)/h;

	for(i=0;i<n;i++){
		runge_kutta_step(f,g,&x,&y,&z,h);
		printf("x=%f z=%f y=%f ys=%f\n",x,z,y,
				solucao(x));
	}
}
