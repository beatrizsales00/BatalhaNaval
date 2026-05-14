#include <stdio.h>

int main() {

    // =========================
    // Declaração do tabuleiro
    // =========================
    int tabuleiro[10][10];

    int linha, coluna;

    // =========================
    // Inicializando com água
    // =========================
    for (linha = 0; linha < 10; linha++) {
        for (coluna = 0; coluna < 10; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }

    // =========================
    // Configuração dos navios
    // =========================

    int tamanhoNavio = 3;

    // Navio horizontal
    int linhaHorizontal = 2;
    int colunaHorizontal = 4;

    // Navio vertical
    int linhaVertical = 5;
    int colunaVertical = 7;

    // =========================
    // Posicionando navio horizontal
    // =========================
    if (colunaHorizontal + tamanhoNavio <= 10) {

        for (coluna = 0; coluna < tamanhoNavio; coluna++) {

            tabuleiro[linhaHorizontal][colunaHorizontal + coluna] = 3;
        }
    }

    // =========================
    // Posicionando navio vertical
    // =========================
    if (linhaVertical + tamanhoNavio <= 10) {

        for (linha = 0; linha < tamanhoNavio; linha++) {

            if (tabuleiro[linhaVertical + linha][colunaVertical] == 0) {

                tabuleiro[linhaVertical + linha][colunaVertical] = 3;
            }
        }
    }

    // =========================
    // Exibindo letras das colunas
    // =========================
    printf("   ");

    for (coluna = 0; coluna < 10; coluna++) {
        printf("%c ", 'A' + coluna);
    }

    printf("\n");

    // =========================
    // Exibindo tabuleiro
    // =========================
    for (linha = 0; linha < 10; linha++) {

        // Número da linha
        printf("%d  ", linha);

        for (coluna = 0; coluna < 10; coluna++) {

            printf("%d ", tabuleiro[linha][coluna]);
        }

        printf("\n");
    }

    return 0;
}