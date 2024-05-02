#include <stdio.h>

int main(){
	int v[5] = {0, 1, 2, 3, 4};

	for(int i=0; i < 5; i++){
		printf("&v[%d] = %p, v[%d] = %d\n", i, &v[i], i, v[i]);
	}

	puts("Até aqui é o que esperamos.\n\nDaqui para baixo é espaço de memória invadido.");

	printf("&v[5] = %p, v[5] = %d\n", &v[5], v[5]);
	printf("&v[6] = %p, v[6] = %d\n", &v[6], v[6]);

	return 0;
}