// 1) Escreva os valores das variáveis para cada instrução do programa abaixo. Qual a saída do programa?

#include <stdio.h>

int main(int argc, char const *argv[]){
	
	int a, b;
	int* p1;
	int* p2;

	a = 4;
	b = 3; 
	p1 = &a;
	p2 = p1;

	*p2 = *p1 + 3; // -> a = 7
	b = b * (*p1); // -> b = 21
	(*p2)++;       // -> a = 8
	p1 = &b;

	printf("%d %d\n", *p1, *p2); // 21 8
	printf("%d %d\n", a, b);     // 8 21

	return 0;
}