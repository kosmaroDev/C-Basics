#include <stdio.h>
#include <stdlib.h>

void desaloca_vetor_double(double *v[]){
	free(*v);
	*v = NULL;
}

void aloca_vetor_double_referencia(double *ref, const int SIZE){

	double *vetor_double = (double *) calloc(SIZE, sizeof(double));

	for(int i = 0;  i < SIZE; i++){
		vetor_double[i] = i * 1.3;
		//printf("&vetor[%d] = %p, vetor[%d] = %0.2f\n", i, &vetor_double[i], i, vetor_double[i]);
	}

	ref = vetor_double;
}

double *aloca_vetor_double(const int SIZE){
	
	double *vetor_double = (double *) calloc(SIZE, sizeof(double));

	for(int i = 0;  i < SIZE; i++){
		vetor_double[i] = i * 1.2;
	}

	return vetor_double;
}

void imprime_vetor_double(double *vetor, int size){
	for(int i = 0; i < size; i++){
		printf("&vetor[%d] = %p, vetor[%d] = %0.2f\n", i, &vetor[i], i, vetor[i]);
	}
}

int main(){
		
	const int SIZE = 10;

	puts("Função que aloca vetor double e retorne:\n");
	double *vetor_double_alocado = aloca_vetor_double(SIZE);
	imprime_vetor_double(vetor_double_alocado, SIZE);
	puts("==> ANTES DA DESALOCAÇÃO: ");
	printf("&v = %p, v = %p\n", &vetor_double_alocado, vetor_double_alocado);
	desaloca_vetor_double(&vetor_double_alocado);
	puts("==> APÓS DESALOCAÇÃO: ");
	printf("&v = %p, v = %p\n", &vetor_double_alocado, vetor_double_alocado);

	// ==========================================================================

	puts("\nFunção que aloca vetor double e retorne por referência:\n");
	double *ref;
	aloca_vetor_double_referencia(ref, SIZE);
	imprime_vetor_double(ref, SIZE);
	puts("==> ANTES DA DESALOCAÇÃO: ");
	printf("&v = %p, v = %p\n", &ref, ref);
	desaloca_vetor_double(&ref);
	puts("==> APÓS DESALOCAÇÃO: ");
	printf("&v = %p, v = %p\n", &ref, ref);
	return 0;
}