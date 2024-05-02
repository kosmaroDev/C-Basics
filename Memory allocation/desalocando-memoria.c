#include <stdio.h>
#include <stdlib.h>


// Para desalocar um vetor:
void desaloca_vetor(int **vetor){
	free(*vetor);
	*vetor = NULL;}

// Para desalocar uma matriz:
void desaloca_matriz(int ***matriz, int const ROWS){
	for (int i = 0; i < ROWS; i++) {
		free(*matriz[i]);
		*matriz[i] = NULL;
	}
	free(*matriz);
	*matriz = NULL;}

// Para desalocar um tensor 3D:
void desaloca_tensor_3D(int ****tensor_3D, int const SLICES, int const ROWS){
    // TODO
}

int* vetor(const int ITENS){
	
	int *vetor = NULL;
	int count = 0;

	vetor = (int*) calloc(ITENS, sizeof(int));

	for(int i = 0; i < ITENS; i++){
		vetor[i] = ++count;
		printf("vetor[%d] = %d\n", i, vetor[i]);
	}

	return vetor;}

int** matriz(const int ROWS, const int COLS){
	
	int **matriz = NULL;
	int count = 0;

	matriz = (int**) calloc(ROWS, sizeof(int *));


	for(int i = 0; i < ROWS; i++) {

		matriz[i] = (int*) calloc(COLS, sizeof(int));

		for(int j = 0; j < COLS; j++) {

			matriz[i][j] = ++count;
			printf("matriz[%d][%d] = %d\n", i, j, matriz[i][j]);
		}
	}

	
	return matriz;}

int*** tensor_3D(const int SLICES, const int ROWS, const int COLS){
	
	int ***tensor_3D = NULL;
	int count = 0;

	tensor_3D = (int***) calloc(SLICES, sizeof(int**));

	for (int i = 0; i < SLICES; i++) {

		tensor_3D[i] = (int**) calloc(ROWS, sizeof(int*));
		
		for (int j = 0; j < ROWS; j++) {

			tensor_3D[i][j] = (int*) calloc(COLS, sizeof(int));

			for (int k = 0; k < COLS; k++) {

				tensor_3D[i][j][k] =  ++count;
				printf("tensor_3D[%d][%d][%d] = %d\n", i, j, k, tensor_3D[i][j][k]);

			}
		}
	}

	printf("\n%p\n", &tensor_3D);
	
	return tensor_3D;}

int main() {

	int ITENS;
	int ROWS, COLS;
	int _SLICES, _ROWS, _COLS;

	puts("Qtd. itens no Vetor?");
	scanf("%d", &ITENS);
	puts("Qtd. linhas na Matrix?");
	scanf("%d", &ROWS);
	puts("Qtd. colunas na Matrix?");
	scanf("%d", &COLS);
	puts("Qtd. fatias no Tensor 3D?");
	scanf("%d", &_SLICES);
	puts("Qtd. linhas no Tensor 3D?");
	scanf("%d", &_ROWS);
	puts("Qtd. colunas no Tensor 3D?");
	scanf("%d", &_COLS);

	puts("****************************************\nVetor:\n");
	int *v = vetor(ITENS);
	puts("\n****************************************\nMatriz:\n");
	int **m = matriz(ROWS, COLS);
	puts("\n****************************************\nTensor 3D:\n");
	int ***t = tensor_3D(_SLICES, _ROWS, _COLS);

	desaloca_vetor(&v);
	if (v == NULL) {
		puts("\nVetor desalocado com sucesso!");
	}

	desaloca_matriz(&m, ROWS);
	if (m == NULL) {
		puts("\nMatriz desalocada com sucesso!");
	}
/*
	desaloca_tensor_3D(&t, _SLICES, _ROWS);
	if (t == NULL) {
		puts("\nTensor 3D desalocado com sucesso!");
	}
*/

	printf("\n%p\n", *t);

	return 0;
}