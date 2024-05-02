#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>

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

bool isEquals_livro(Livro livro1, Livro livro2){
    if(strcmp(livro1.titulo, livro2.titulo) != 0){
        return true;
    }
    return false;
}

int main(){

    const int num_livros = 3;

    Livro **livros = (Livro **) calloc(num_livros, sizeof(Livro*));

    livros[0] = create_livro("O Senhor dos Anéis - A Sociedade do Anel", 423, (float) 46.6);
    livros[1] = create_livro("O Senhor dos Anéis - As Duas Torres", 464, (float) 52.9);
    livros[2] = create_livro("O Senhor dos Anéis - O Retorno do Rei", 431, (float) 44.9);

    for (int i = 0; i < num_livros; i++) {
        read_livro(livros[i]);
    }

    for (int i = 0; i < num_livros; i++) {
        delete_livro(&livros[i]);
    }
    free(livros);
    livros = NULL;

    return 0;
}