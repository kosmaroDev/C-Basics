#include <stdio.h>
#include <stdlib.h>

int main(){

	float z = 2.5;
	float* fp;

	fp = &z;

	printf("z     = %f\n", z);
	printf("*&z   = %f\n", *&z);
	printf("*fp   = %f\n", *fp);
	printf("**&fp = %f\n\n", **&fp);

	return 0;
}