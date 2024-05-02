#include <stdio.h>
#include <string.h>

struct Aluno_1 {
    char nome[64];
    int idade;
};

struct Aluno_2 {
    char nome[64];
    int idade;
} AlunoAnonimo1;

struct {
    char nome[64];
    int idade;
} AlunoAnonimo2;

typedef struct _aluno {
    char nome[64];
    int idade;
} Aluno;

void imprime_aluno_1(struct Aluno_1 aluno){
    printf("Nome: %s\n", aluno.nome);
    printf("Idade:%d\n", aluno.idade);
}
void imprime_aluno_2(struct Aluno_2 aluno){
    printf("Nome: %s\n", aluno.nome);
    printf("Idade:%d\n", aluno.idade);
}
void imprime_aluno(Aluno aluno){
    printf("Nome: %s\n", aluno.nome);
    printf("Idade:%d\n", aluno.idade);
}

int main(){

    // Todos os jeitos de declaração e inicialização das variáveis podem ser aplicadas à todas as formas
    // com excessão da forma anonima, o exemplo da forma anonima é a única forma de acessar.

    // Forma 1
    struct Aluno_1 aluno_1;
    strcpy(aluno_1.nome, "aluno1");
    aluno_1.idade = 10;

    // Forma 2
    strcpy(AlunoAnonimo1.nome, "AlunoAnonimo1");
    AlunoAnonimo1.idade = 26;

    // Forma 3
    strcpy(AlunoAnonimo2.nome, "AlunoAnonimo2");
    AlunoAnonimo2.idade = 25;

    // Fomra 4
    Aluno aluno = { .nome = "aluno", .idade = 20};

    imprime_aluno_1(aluno_1);
    imprime_aluno_2(AlunoAnonimo1);
    printf("Nome: %s\nIdade: %d\n", AlunoAnonimo2.nome, AlunoAnonimo2.idade);
    imprime_aluno(aluno);

    return 0;
}
