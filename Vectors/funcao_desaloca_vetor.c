#include <stdio.h>
#include <stdlib.h>

void desaloca_vetor(int **vec_ref){
	free(*vec_ref);
	*vec_ref = NULL;
}

int main(){
	
	int *vh = (int *) calloc(5, sizeof(int));
	
	printf("&vh = %p, vh = %p\n\n", &vh, vh);

	for(int i = 0; i < 5; i++){
		printf("&vh[%d] = %p, vh[%d] = %d\n", i, &vh[i], i, vh[i]);
	}
	puts("");

	puts("==> ANTES DA FUNÇÃO desaloca_vetor(vh_mal): ");
	printf("&vh = %p, vh = %p\n", &vh, vh);
	desaloca_vetor(&vh);
	puts("==> DEPOIS DA FUNÇÃO desaloca_vetor(vh): ");
	printf("&vh = %p, vh = %p", &vh, vh);

	return 0;
}