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

// =========================
// Função para validar posicionamento de navio
// =========================
int podePosicionar(int tabuleiro[10][10], int l, int c, int deltaL, int deltaC, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        int x = l + i * deltaL;
        int y = c + i * deltaC;
        if (x < 0 || x >= 10 || y < 0 || y >= 10) return 0; // fora do tabuleiro
        if (tabuleiro[x][y] != 0) return 0; // já ocupado
    }
    return 1;
}

// =========================
// Função para aplicar habilidade
// =========================
void aplicarHabilidade(int tabuleiro[10][10], int matriz[7][7], int origemL, int origemC) {
    int tam = 7; // tamanho da matriz da habilidade
    int meio = tam / 2;

    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            int l = origemL - meio + i;
            int c = origemC - meio + j;
            if (l >= 0 && l < 10 && c >= 0 && c < 10) { // dentro do tabuleiro
                if (matriz[i][j] == 1 && tabuleiro[l][c] == 0) {
                    tabuleiro[l][c] = 5; // marca área de efeito
                }
            }
        }
    }
}

int main() {
    // =========================
    // Criando tabuleiro 10x10
    // =========================
    int tabuleiro[10][10] = {0};

    int tamanhoNavio = 3;
    int linhaH = 1, colunaH = 2;
    int linhaV = 5, colunaV = 7;
    int linhaD1 = 0, colunaD1 = 0;
    int linhaD2 = 9, colunaD2 = 0;

    // =========================
    // Posicionando navios
    // =========================
    if (colunaH + tamanhoNavio <= 10)
        for (int i = 0; i < tamanhoNavio; i++)
            tabuleiro[linhaH][colunaH + i] = 3;

    if (linhaV + tamanhoNavio <= 10)
        for (int i = 0; i < tamanhoNavio; i++)
            tabuleiro[linhaV + i][colunaV] = 3;

    if (podePosicionar(tabuleiro, linhaD1, colunaD1, 1, 1, tamanhoNavio))
        for (int i = 0; i < tamanhoNavio; i++)
            tabuleiro[linhaD1 + i][colunaD1 + i] = 3;

    if (podePosicionar(tabuleiro, linhaD2, colunaD2, -1, 1, tamanhoNavio))
        for (int i = 0; i < tamanhoNavio; i++)
            tabuleiro[linhaD2 - i][colunaD2 + i] = 3;

    // =========================
    // Criando matrizes de habilidade (7x7)
    // =========================
    int cone[7][7] = {
        {0,0,0,1,0,0,0},
        {0,0,1,1,1,0,0},
        {0,1,1,1,1,1,0},
        {1,1,1,1,1,1,1},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0}
    };

    int cruz[7][7] = {
        {0,0,0,1,0,0,0},
        {0,0,0,1,0,0,0},
        {0,0,0,1,0,0,0},
        {1,1,1,1,1,1,1},
        {0,0,0,1,0,0,0},
        {0,0,0,1,0,0,0},
        {0,0,0,1,0,0,0}
    };

    int octaedro[7][7] = {
        {0,0,0,1,0,0,0},
        {0,0,1,1,1,0,0},
        {0,1,1,1,1,1,0},
        {1,1,1,1,1,1,1},
        {0,1,1,1,1,1,0},
        {0,0,1,1,1,0,0},
        {0,0,0,1,0,0,0}
    };

    // =========================
    // Aplicando habilidades
    // =========================
    aplicarHabilidade(tabuleiro, cone, 2, 5);     // origem L2,C5
    aplicarHabilidade(tabuleiro, cruz, 7, 3);     // origem L7,C3
    aplicarHabilidade(tabuleiro, octaedro, 5, 5);// origem L5,C5

    // =========================
    // Exibindo tabuleiro final
    // =========================
    imprimirTabuleiro(tabuleiro);

    return 0;
}