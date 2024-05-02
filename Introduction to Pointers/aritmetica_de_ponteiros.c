#include <stdio.h>

int main(){
	
	int v[5] = {0, 1, 2, 3, 4};

	int a = 00;
	int b = 11;
	int c = 22;
	int d = 33;
	int e = 44;

	int *pa = &a;
	
	puts("Mostrando a ideia com array:\n");

	for(int i = 0; i < 5; i++){

		printf("Índice: %d, %dº elemento:\n", i, i+1);
		printf("&v[%d] = %p, &(v + %d) = %p, (v + %d) = %p\n", i, &v[i], i, &v + i, i, (v + i));
		printf("v[%d] = %d, *&v[%d] = %d, *(v + %d) = %d\n\n", i, v[i], i, *&v[i], i, *(v + i));
	}

	puts("\nAgora usando aritmetica de ponteiros para acessar outras variáveis usando um ponteiro conhecido.\n");

	printf("pa + 0 = %p, &a = %p, a = %d\n", pa, &a, a);
	printf("pa + 1 = %p, &b = %p, b = %d\n", pa+1, &b, b);
	printf("pa + 2 = %p, &c = %p, c = %d\n", pa+2, &c, c);
	printf("pa + 3 = %p, &d = %p, d = %d\n", pa+3, &d, d);
	printf("pa + 4 = %p, &e = %p, e = %d\n", pa+4, &e, e);

	return 0;
}