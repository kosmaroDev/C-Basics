#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int messi = 10;
	int* jaiminho = &messi;
	int** sebastiao = &jaiminho;

	printf("&messi    = %p, messi      = %d\n", &messi, messi);
	printf("jaiminho  = %p, &jaiminho  = %p, *jaiminho  = %d\n", jaiminho, &jaiminho, *jaiminho);
	printf("sebastiao = %p, &sebastiao = %p, *sebastiao = %p, **sebastiao = %d\n\n", sebastiao, &sebastiao, *sebastiao, **sebastiao);

	**sebastiao = 99;

	printf("&messi    = %p, messi      = %d\n", &messi, messi);
	printf("jaiminho  = %p, &jaiminho  = %p, *jaiminho  = %d\n", jaiminho, &jaiminho, *jaiminho);
	printf("sebastiao = %p, &sebastiao = %p, *sebastiao = %p, **sebastiao = %d\n", sebastiao, &sebastiao, *sebastiao, **sebastiao);

	return 0;
}