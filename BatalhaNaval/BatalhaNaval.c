#include <stdio.h>

// =========================
// Função para imprimir o tabuleiro
// =========================
void imprimirTabuleiro(int tabuleiro[10][10]) {
    printf("   ");
    for (int c = 0; c < 10; c++) {
        printf("%c ", 'A' + c);
    }
    printf("\n");

    for (int l = 0; l < 10; l++) {
        printf("%d  ", l);
        for (int c = 0; c < 10; c++) {
            printf("%d ", tabuleiro[l][c]);
        }
        printf("\n");
    }
}

int main() {
    // =========================
    // Criando tabuleiro 10x10
    // =========================
    int tabuleiro[10][10] = {0}; // Inicializa tudo com 0 (água)

    // =========================
    // Definição de navios
    // =========================
    int tamanhoNavio = 3;

    // Navios horizontais/verticais
    int linhaH = 1, colunaH = 2; // horizontal
    int linhaV = 5, colunaV = 7; // vertical

    // Navios diagonais
    int linhaD1 = 0, colunaD1 = 0; // diagonal descendente
    int linhaD2 = 9, colunaD2 = 0; // diagonal ascendente

    // =========================
    // Função auxiliar para verificar se é possível posicionar
    // =========================
    int podePosicionar(int l, int c, int deltaL, int deltaC, int tamanho) {
        for (int i = 0; i < tamanho; i++) {
            int x = l + i * deltaL;
            int y = c + i * deltaC;
            if (x < 0 || x >= 10 || y < 0 || y >= 10) return 0; // fora do tabuleiro
            if (tabuleiro[x][y] != 0) return 0; // já ocupado
        }
        return 1;
    }

    // =========================
    // Posicionando navios horizontais
    // =========================
    if (colunaH + tamanhoNavio <= 10) {
        for (int i = 0; i < tamanhoNavio; i++) {
            tabuleiro[linhaH][colunaH + i] = 3;
        }
    }

    // =========================
    // Posicionando navios verticais
    // =========================
    if (linhaV + tamanhoNavio <= 10) {
        for (int i = 0; i < tamanhoNavio; i++) {
            tabuleiro[linhaV + i][colunaV] = 3;
        }
    }

    // =========================
    // Posicionando navio diagonal descendente (\)
    // =========================
    if (podePosicionar(linhaD1, colunaD1, 1, 1, tamanhoNavio)) {
        for (int i = 0; i < tamanhoNavio; i++) {
            tabuleiro[linhaD1 + i][colunaD1 + i] = 3;
        }
    }

    // =========================
    // Posicionando navio diagonal ascendente (/)
    // =========================
    if (podePosicionar(linhaD2, colunaD2, -1, 1, tamanhoNavio)) {
        for (int i = 0; i < tamanhoNavio; i++) {
            tabuleiro[linhaD2 - i][colunaD2 + i] = 3;
        }
    }

    // =========================
    // Exibindo o tabuleiro final
    // =========================
    imprimirTabuleiro(tabuleiro);

    return 0;
}