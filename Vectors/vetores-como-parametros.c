#include <stdio.h>
#include <stdlib.h>

void scalar_sum_on_elements(int *vec_ref, int size, int scalar){
	for(int i = 0; i < size; i++){
		vec_ref[i] += scalar;
	}
}

void print_vector(const int *vec_ref, int size){
	for(int i = 0; i < size; i++){
		printf("&v[%d] = %p, v[%d] = %d\n", i, &vec_ref[i], i, vec_ref[i]);
	}
	puts("");
}

int main(){
	
	puts("### STATIC VECTOR");
	int vs[5] = {0, 10, 20, 30, 40};

	print_vector(vs, 5);
	scalar_sum_on_elements(vs, 5, 9);
	print_vector(vs, 5);

	puts("### DYNAMIC VECTOR\n");
	int *vh = (int *) calloc(5, sizeof(int));

	for(int i = 0; i < 5; i++){
		vh[i] = i * 100;
	}

	print_vector(vh, 5);
	scalar_sum_on_elements(vh, 5, 9);
	print_vector(vh, 5);

	free(vh);
	vh = NULL;

	return 0;
}