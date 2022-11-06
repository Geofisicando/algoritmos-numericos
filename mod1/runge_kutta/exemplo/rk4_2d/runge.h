#ifndef _RUNGE_H_
#define _RUNGE_H_

void runge_kutta_step(float (*f)(float,float,float),
			float (*g)(float,float,float),
			float *x,
			float *y,
			float *z,
			float h)
{
	float k1, k2, k3, k4;
	float l1, l2, l3, l4;
	float h2=h/2.;
	float x0=*x, y0=*y, z0=*z;

	k1 = h*(*f)(x0,y0,z0);
	l1 = h*(*g)(x0,y0,z0);
	k2 = h*(*f)(x0+h2,y0+k1/2.,z0+l1/2.);
	l2 = h*(*g)(x0+h2,y0+k1/2.,z0+l1/2.);
	k3 = h*(*f)(x0+h2,y0+k2/2.,z0+l2/2.);
	l3 = h*(*g)(x0+h2,y0+k2/2.,z0+l2/2.);
	k4 = h*(*f)(x0+h,y0+k3,z0+l3);
	l4 = h*(*g)(x0+h,y0+k3,z0+l3);

	*x = x0+h;
	*y = y0+(k1+2*k2+2*k3+k4)/6.;
	*z = z0+(l1+2*l2+2*l3+l4)/6.;
}

#endif
