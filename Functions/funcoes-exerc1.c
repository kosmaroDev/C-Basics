// Mostre todos os passos (teste de mesa) do programa abaixo e identifique o que é impresso pelo programa.

#include <stdio.h>

void func(int* px, int* py){
	px = py; // 3
	*py = (*py) * (*px); // 4 , y  -> y²
	*px = (*px) + 2;     // 5 , y² -> y² + 2
}

int main(){

	int x, y; // 1
	scanf("%d %d", &x, &y); // 2

	func(&x, &y);

	printf("x = %d, y = %d\n", x, y); // x = x, y = y² + 2

	return 0;
}

// Imagine que &x = 5000, &y = 5004 e que as entradas tenha sido x = 2 e y = 3.

//#    x    px    *px    y    py    *py
//1    #    --     -     #    --     -
//2    2   5000    2     3   5004    3
//3    2   5004    3     3   5004    3
//4    2   5004    9     9   5004    9
//5    2   5004   11    11   5004   11

// Ou seja, o que será impresso é:

// x = x, y = y² + 2 -> x = 2, y = 11.