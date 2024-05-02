#include <stdio.h>

int main(){
	int v[5];

	for(int i = 0; i < 5; i++){
		printf("&v[%d] = %p, v[%d] = %d\n", i, &v[i], i, v[i]);
	}

	for(int j = 0; j < 5; j++){
		scanf("%d", &v[j]);
	}

	for(int k = 0; k < 5; k++){
		printf("&v[%d] = %p, v[%d] = %d\n", k, &v[k], k, v[k]);
	}

	return 0;
}