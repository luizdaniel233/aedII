#include "livro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINHA 256

// Função para processar o arquivo de entrada e gerar o arquivo de saída
void processar_arquivo(const char* entrada, const char* saida, Biblioteca *biblioteca) {
    FILE *file_in = fopen(entrada, "r");
    FILE *file_out = fopen(saida, "a"); // Usando "a" para anexar ao arquivo de saída

    if (!file_in || !file_out) {
        perror("Erro ao abrir arquivo");
        return;
    }

    char linha[MAX_LINHA];
    while (fgets(linha, sizeof(linha), file_in)) {
        char comando[20];
        sscanf(linha, "%s", comando);

        if (strcmp(comando, "ADD") == 0) {
            Livro livro;
            sscanf(linha, "%*s %99[^;]; %99[^;]; %19[^;]; %4s", livro.titulo, livro.autor, livro.isbn, livro.ano_publicacao);
            livro.disponivel = true;
            fprintf(file_out, "%s\n", adicionar_livro(biblioteca, livro));
        } else if (strcmp(comando, "SEARCH") == 0) {
            char criterio[10], valor[100];
            sscanf(linha, "%*s %s %s", criterio, valor);
            char chave[10];
            if (criterio[0] == '-') {
                strcpy(chave, "titulo");
                strcpy(valor, criterio + 1);
            } else if (criterio[0] == '+') {
                strcpy(chave, "autor");
                strcpy(valor, criterio + 1);
            } else {
                strcpy(chave, "isbn");
                strcpy(valor, criterio);
            }
            char resultado[1024];
            fprintf(file_out, "%s\n", buscar_livro(biblioteca, chave, valor, resultado));
        } else if (strcmp(comando, "CHECK") == 0) {
            char operacao[10], isbn[20];
            sscanf(linha, "%*s %s %s", operacao, isbn);
            if (strcmp(operacao, "OUT") == 0) {
                fprintf(file_out, "%s\n", emprestar_livro(biblioteca, isbn));
            } else if (strcmp(operacao, "IN") == 0) {
                fprintf(file_out, "%s\n", devolver_livro(biblioteca, isbn));
            }
        } else if (strcmp(comando, "CHECK_OUT") == 0) {
            char isbn[20];
            sscanf(linha, "%*s %19[^;];", isbn);
            fprintf(file_out, "%s\n", emprestar_livro(biblioteca, isbn));
        } else if (strcmp(comando, "CHECK_IN") == 0) {
            char isbn[20];
            sscanf(linha, "%*s %19[^;];", isbn);
            fprintf(file_out, "%s\n", devolver_livro(biblioteca, isbn));
        } else if (strcmp(comando, "END") == 0) {
            break;
        } else {
            fprintf(file_out, "Comando desconhecido: %s\n", linha);
        }
    }

    fclose(file_in);
    fclose(file_out);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Uso: %s <arquivo_saida> <arquivo_entrada1> [<arquivo_entrada2> ...]\n", argv[0]);
        return 1;
    }

    const char* arquivo_saida = argv[1];

    Biblioteca biblioteca;
    inicializa_biblioteca(&biblioteca);

    for (int i = 2; i < argc; i++) {
        processar_arquivo(argv[i], arquivo_saida, &biblioteca);
    }

    free(biblioteca.livros); // Liberar memória
    return 0;
}
