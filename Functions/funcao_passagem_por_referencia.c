#include <stdio.h>

int soma(int x1, int y1){

	printf("Entrou em soma passando x1 = %d e y1 = %d que são o conteúdo das variáveis 'x' e 'y'.\n", x1, y1);
	printf("&x1 = %p, x1 = %d\n", &x1, x1);
	printf("&y1 = %p, y1 = %d\n\n", &y1, y1);

	int z1 = x1 + y1;

	return z1;
}


int altera_valores(int* x, int* y){

	printf("Entrou em altera_valores com parametros *x = %p e *y = %p que apontam respectivamente para 'a' e 'b'.\n", x, y);
	printf("x = %p, *x = %d\n", x, *x);
	printf("y = %p, *y = %d\n\n", y, *y);

	*x += 3;
	*y *= 2;

	puts("Parametros alterados, ou seja, *x = *x + 3 e *y = *y * 2.\n");
	printf("x = %p, *x = %d\n", x, *x);
	printf("y = %p, *y = %d\n\n", y, *y);

	int z = soma(*x, *y);

	return z;
}


int main(){

	// repare nos valores e endereços de memória que serão printados.

	int a = 10;
	int b = 20;
	int c;

	puts("Início do Programa:\n");
	printf("&a = %p, a = %d\n", &a, a);
	printf("&b = %p, b = %d\n\n", &b, b);

	c = altera_valores(&a, &b); // -> 'x' recebe referencia de 'a' e 'y' recebe a referencia de 'b';

	puts("Após chamada da função altera_valores:\n");
	printf("&a = %p, a = %d\n", &a, a);
	printf("&b = %p, b = %d\n\n", &b, b);

	printf("%d + %d = %d\n", a, b, c); // pois a passagem foi por referencia, ou seja, os valores de 'a' e 'b' são alterados fora da função altera_valores.
	puts("Soma correta pois a passagem de parametros por referencia altera as variáveis fora da função\n.");

	return 0;
}