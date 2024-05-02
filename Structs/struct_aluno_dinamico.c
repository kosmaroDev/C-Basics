#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _aluno {
    char nome[64];
    int idade;
} Aluno;

void imprime_aluno_por_valor(Aluno aluno){
    printf("Nome: %s\n", aluno.nome);
    printf("Idade:%d\n", aluno.idade);
}

void imprime_aluno_por_referencia(Aluno *aluno_ref){
    printf("Nome: %s\n", aluno_ref->nome);
    printf("Idade:%d\n", aluno_ref->idade);
}

int main(){

    Aluno *aluno = (Aluno *) calloc(1, sizeof(Aluno));

    strcpy(aluno->nome, "Aluno");
    aluno->idade = 10;

    imprime_aluno_por_referencia(aluno);
    imprime_aluno_por_valor(*aluno);

    return 0;
}
