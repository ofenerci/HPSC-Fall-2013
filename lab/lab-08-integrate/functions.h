#include <math.h>


double func_a(const double x){
	const double y = x-10;
	return 0.25*y*y*y + 0.75*y*y - 1.5*y + 8.0;
}

double func_b(const double x){
	return 10000.0*exp(-1.0*x)/x;
}

double func_c(const double x){
	return sin(x)*x;
}

double func_d(const double x){
	const double y = x-7.5;
	return y/sqrt(1+y*y) + 2.0;
}