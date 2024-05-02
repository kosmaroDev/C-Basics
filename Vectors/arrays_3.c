#include <stdio.h>

int main(){

	int v[3] = {1, 2, 3};

	printf("v = %p,  &v = %p, &v[0] = %p\n", v, &v, &v[0]);

	return 0;
}