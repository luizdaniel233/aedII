// livro.h
#ifndef LIVRO_H
#define LIVRO_H

#include <stdbool.h>

// Definição da estrutura Livro
typedef struct {
    char titulo[100];
    char autor[100];
    char isbn[20];
    char ano_publicacao[5];
    bool disponivel;
} Livro;

// Definição da estrutura Biblioteca
typedef struct {
    Livro *livros;
    int total_livros;
    int capacidade;
} Biblioteca;

// Funções para gerenciar livros
void inicializa_biblioteca(Biblioteca *biblioteca);
char* adicionar_livro(Biblioteca *biblioteca, Livro livro);
char* buscar_livro(Biblioteca *biblioteca, const char* chave, const char* valor, char* resultado);
char* emprestar_livro(Biblioteca *biblioteca, const char* isbn);
char* devolver_livro(Biblioteca *biblioteca, const char* isbn);

#endif
