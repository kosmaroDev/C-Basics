#include <stdio.h>
#include <stdlib.h>

int main() {

	const int ROWS = 3;
	const int COLS = 3;
	int count = 1;

	int **m = NULL;

	m = (int**) calloc(ROWS, sizeof(int *));

	for(int i = 0; i < ROWS; i++){
		m[i] = (int*) calloc(COLS, sizeof(int));
	}

	printf("&m = %p, m = %p\n\n", &m, m);

	for(int i = 0; i < ROWS; i++) {
		printf("&m[%d] = %p, m[%d] = %p\n", i, &m[i], i, m[i]);
		for(int j = 0; j < COLS; j++) {
			m[i][j] = count++;
			printf("&m[%d][%d] = %p, m[%d][%d] = %d\n", i, j, &m[i][j], i, j, m[i][j]);
		}

		puts("");
	}
		return 0;
}