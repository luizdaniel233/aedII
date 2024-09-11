// estrutura.c
#include "livro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para inicializar a biblioteca
void inicializa_biblioteca(Biblioteca *biblioteca) {
    biblioteca->capacidade = 10;
    biblioteca->livros = malloc(biblioteca->capacidade * sizeof(Livro));
    biblioteca->total_livros = 0;
}

// Função para expandir a capacidade da biblioteca
void expandir_biblioteca(Biblioteca *biblioteca) {
    biblioteca->capacidade *= 2;
    biblioteca->livros = realloc(biblioteca->livros, biblioteca->capacidade * sizeof(Livro));
}
