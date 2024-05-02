#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _livro {
    char titulo[64];
    unsigned int num_paginas;
    float preco;
} Livro;

Livro *create_livro(const char *titulo, const unsigned int num_paginas, const float preco){
    Livro *livro = (Livro *) calloc(1, sizeof(Livro));
    strcpy(livro->titulo, titulo);
    livro->num_paginas = num_paginas;
    livro->preco = preco;
    return livro;
}

void read_livro(Livro *livro){
    printf("Título: %s\nNúmero de páginas: %d\nPreço: R$ %.2f\n", livro->titulo, livro->num_paginas, livro->preco);
}

void update_livro(Livro *livro, const char *novo_titulo, const unsigned int novo_num_paginas, const float novo_preco){
    strcpy(livro->titulo, novo_titulo);
    livro->num_paginas = novo_num_paginas;
    livro->preco = novo_preco;
}

void delete_livro(Livro **livro_ref){
    free(*livro_ref);
    *livro_ref = NULL;
}

Livro *copy_livro(Livro *livro){
    Livro *copia = (Livro *) calloc(1, sizeof(Livro));
    strcpy(copia->titulo, livro->titulo);
    copia->num_paginas = livro->num_paginas;
    copia->preco = livro->preco;
    return copia;
}

typedef struct _aluno {
    char nome[64];
    int idade;
    Livro *livro_favorito;
} Aluno;

Aluno *create_aluno(const char *nome, const int idade, Livro *livro_favorito){
    Aluno *aluno = (Aluno *) calloc(1, sizeof(Aluno));
    strcpy(aluno->nome, nome);
    aluno->idade = idade;
    aluno->livro_favorito = copy_livro(livro_favorito);
    return aluno;
}

void read_aluno(Aluno *aluno){
    printf("Nome: %s\nIdade: %d\nLivro Favorito: %s\n", aluno->nome, aluno->idade, aluno->livro_favorito->titulo);
}

void update_aluno(Aluno *aluno, const char *novo_nome,
                  const int novo_idade, Livro *novo_livro_favorito){
    strcpy(aluno->nome, novo_nome);
    aluno->idade = novo_idade;
    aluno->livro_favorito = copy_livro(novo_livro_favorito);
}

void delete_aluno(Aluno **aluno_ref){
    Aluno *aluno = *aluno_ref;
    delete_livro(&aluno->livro_favorito);
    free(aluno);
    aluno = NULL;
}

int main(){
    Livro *senhor_dos_aneis_o_retorno_do_rei = create_livro("O Retorno do Rei", 431, (float) 44.9);
    read_livro(senhor_dos_aneis_o_retorno_do_rei);
    puts("");
    Aluno *aluno = create_aluno("João", 26, senhor_dos_aneis_o_retorno_do_rei);
    read_aluno(aluno);
    puts("");
    delete_livro(&senhor_dos_aneis_o_retorno_do_rei);
    read_aluno(aluno);
    return 0;
}