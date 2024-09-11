// livro.c
#include "livro.h"
#include "estrutura.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Adiciona um Livro
char* adicionar_livro(Biblioteca *biblioteca, Livro livro) {
    if (biblioteca->total_livros >= biblioteca->capacidade) {
        expandir_biblioteca(biblioteca);
    }
    for (int i = 0; i < biblioteca->total_livros; i++) {
        if (strcmp(biblioteca->livros[i].isbn, livro.isbn) == 0) {
            return "Erro: Livro com ISBN já existe.";
        }
    }
    biblioteca->livros[biblioteca->total_livros] = livro;
    biblioteca->total_livros++;
    return "Livro adicionado com sucesso.";
}

// Busca um Livro
char* buscar_livro(Biblioteca *biblioteca, const char* chave, const char* valor, char* resultado) {
    for (int i = 0; i < biblioteca->total_livros; i++) {
        Livro livro = biblioteca->livros[i];
        if ((strcmp(chave, "titulo") == 0 && strstr(livro.titulo, valor)) ||
            (strcmp(chave, "autor") == 0 && strstr(livro.autor, valor)) ||
            (strcmp(chave, "isbn") == 0 && strcmp(livro.isbn, valor) == 0)) {
            sprintf(resultado, "Título: %s\nAutor: %s\nISBN: %s\nAno de Publicação: %s\nStatus: %s\n",
                    livro.titulo, livro.autor, livro.isbn, livro.ano_publicacao, livro.disponivel ? "Disponível" : "Emprestado");
            return resultado;
        }
    }
    return "Nenhum livro encontrado.";
}

// Empresta um Livro
char* emprestar_livro(Biblioteca *biblioteca, const char* isbn) {
    for (int i = 0; i < biblioteca->total_livros; i++) {
        if (strcmp(biblioteca->livros[i].isbn, isbn) == 0) {
            if (!biblioteca->livros[i].disponivel) {
                return "Erro: Livro não está disponível.";
            }
            biblioteca->livros[i].disponivel = false;
            return "Livro emprestado com sucesso.";
        }
    }
    return "Erro: Livro não encontrado.";
}

// Devolve um Livro
char* devolver_livro(Biblioteca *biblioteca, const char* isbn) {
    for (int i = 0; i < biblioteca->total_livros; i++) {
        if (strcmp(biblioteca->livros[i].isbn, isbn) == 0) {
            if (biblioteca->livros[i].disponivel) {
                return "Erro: Livro já está disponível.";
            }
            biblioteca->livros[i].disponivel = true;
            return "Livro devolvido com sucesso.";
        }
    }
    return "Erro: Livro não encontrado.";
}
