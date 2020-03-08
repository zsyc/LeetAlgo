#include <stdio.h>
#include <math.h>
#include <assert.h>
double mysqrt(double y){
	assert(y>=0);
	double x, start, end;
	if (y<1) start = 0.0;
	else if (y==1.0) return 1.0;
	else start = 1.0;
	end = y;
	while (start<end){
		x = start + (end-start)/2;
		if (fabs(x*x-y)<1e-3) return x;
		else if (x*x < y) start = x;
		else end = x;
	}
	return 0;
}

int main(void){
	double y;
	do{
		scanf("%lf",&y);
		printf("%lf\n", mysqrt(y));
	}
	while (y!=0.0);
	return 0;
}
