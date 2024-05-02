#include <stdio.h>

int altera_valor(const int* z1){

	puts("Tentando alterar:");
	printf("z1 = %p, *z1 = %d.\n\n", z1, *z1);

// Repare que não irá compilar se a linha abaixo não estiver comentada ou apagada.
//	*z1 += 1;

	return *z1;
}

void troca(int* x, int* y, const int* z){
	int aux = *x;
	*x = *y;
	*y = aux;

	altera_valor(z);
}

int main(){

	int a = 10;
	int b = 20;
	int c = 30;

	puts("Antes:");
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	printf("c = %d\n\n", c);

	troca(&a, &b, &c);

	puts("Depois:");
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	printf("c = %d\n", c);

	return 0;
}