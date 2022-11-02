#ifndef _RUNGE_H_
#define _RUNGE_H_

float runge_kutta_step(float (*funcao)(float,float),
			float x0,
			float y0,
			float h)
{
	float k1, k2, k3, k4;
	float y;
	float h2=h/2.;

	k1 = h*(*funcao)(x0,y0);
	k2 = h*(*funcao)(x0+h2,y0+k1/2.);
	k3 = h*(*funcao)(x0+h2,y0+k2/2.);
	k4 = h*(*funcao)(x0+h,y0+k3);

	y = y0+(k1+2*k2+2*k3+k4)/6.;

	return y;
}

#endif
