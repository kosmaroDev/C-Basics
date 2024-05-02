#include <stdio.h>

int soma(int x, int y){

	int z = x + y;

	return z;
}

int subtracao(int x, int y){

	int z = x - y;

	return z;
}

void soma_e_subtracao(int x, int y, int* sum, int* sub){
	*sum = soma(x, y);
	*sub = subtracao(x, y);
}

int main(){

	int a = 10;
	int b = 20;
	int soma, subtracao;

	puts("Início do programa:");
	printf("&soma      = %p, soma      = %d\n", &soma, soma);
	printf("&subtracao = %p, subtracao = %d\n\n", &subtracao, subtracao);

	soma_e_subtracao(a, b, &soma, &subtracao);

	puts("Após soma_e_subtracao.");
	printf("&soma      = %p, soma      = %d\n", &soma, soma);
	printf("&subtracao = %p, subtracao = %d\n\n", &subtracao, subtracao);

	return 0;
}