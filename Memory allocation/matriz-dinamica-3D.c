#include <stdio.h>
#include <stdlib.h>

int main() {

	const int ROWS = 3;
	const int COLS = 3;
	const int SLICES = 3;
	int count = 0;

	int ***m = NULL;

	m = (int***) calloc(SLICES, sizeof(int**));

	printf("&m = %p, m = %p\n\n", &m, m);

	for (int i = 0; i < SLICES; i++) {

		m[i] = (int**) calloc(ROWS, sizeof(int*));
		printf("&m[%d] = %p, m[%d] = %p\n", i, &m[i], i, m[i]);

		for (int j = 0; j < ROWS; j++) {

			m[i][j] = (int*) calloc(COLS, sizeof(int));
			printf("&m[%d][%d] = %p, m[%d][%d] = %p\n", i, j, &m[i][j], i, j, m[i][j]);

			for (int k = 0; k < COLS; k++) {

				m[i][j][k] =  ++count; // Para começar do 1.
				printf("&m[%d][%d][%d] = %p, m[%d][%d][%d] = %d\n", i, j, k, &m[i][j][k], i, j, k, m[i][j][k]);

			}
			puts("");
		}
		puts("");
	}


	return 0;
}