#include <stdio.h>

int main(){

	const int ROWS = 3;
	const int COLS = 3;
	int count = 1;

	int m[ROWS][COLS];

	printf("&m = %p, m = %p\n\n", &m, m);

	for(int i = 0; i < ROWS; i++){
		for(int j = 0; j < COLS; j++){
			m[i][j] = count++;
			printf("&m[%d][%d] = %p, m[%d][%d] = %d\n", i, j, &m[i][j], i, j, m[i][j]);
		}
		puts("");
	}

	return 0;
}