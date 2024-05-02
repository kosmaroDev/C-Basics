#include <stdio.h>
#include <string.h>

struct Aluno_1 {
    char nome[64];
    int idade;
};

struct Aluno_2 {
    char nome[64];
    int idade;
} joao;

struct {
    char nome[64];
    int idade;
} edla;

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
    // com excessão da forma anoima, o exemplo da forma anonima é a única forma de acessar.

    // Forma 1
    struct Aluno_1 aluno_1;
    strcpy(aluno_1.nome, "aluno1");
    aluno_1.idade = 10;

    // Forma 2
    strcpy(joao.nome, "joao");
    joao.idade = 26;

    // Forma 3
    strcpy(edla.nome, "edla");
    edla.idade = 25;

    // Fomra 4
    Aluno aluno = { .nome = "aluno", .idade = 20};

    imprime_aluno_1(aluno_1);
    imprime_aluno_2(joao);
    printf("Nome: %s\nIdade: %d\n", edla.nome, edla.idade);
    imprime_aluno(aluno);

    return 0;
}
