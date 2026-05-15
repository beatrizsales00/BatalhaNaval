#include <stdio.h>

#define N 10

// =========================
// Função para imprimir o tabuleiro
// =========================
void imprimirTabuleiro(int tabuleiro[N][N]) {
    printf("  ");
    for (int c = 0; c < N; c++) printf("%d ", c);
    printf("\n");

    for (int l = 0; l < N; l++) {
        printf("%d ", l);
        for (int c = 0; c < N; c++)
            printf("%d ", tabuleiro[l][c]);
        printf("\n");
    }
}

// =========================
// Funções para habilidades
// =========================

// Cone 3x5, centralizado automaticamente
void aplicarCone(int tabuleiro[N][N], int centroL, int centroC){
    int cone[3][5] = {
        {0,0,1,0,0},
        {0,1,1,1,0},
        {1,1,1,1,1}
    };
    for(int i=0;i<3;i++)
        for(int j=0;j<5;j++){
            int x = centroL - 1 + i;
            int y = centroC - 2 + j;
            if(x>=0 && x<N && y>=0 && y<N)
                tabuleiro[x][y] = cone[i][j];
        }
}

// Cruz 3x5, centralizada automaticamente
void aplicarCruz(int tabuleiro[N][N], int centroL, int centroC){
    int cruz[3][5] = {
        {0,0,3,0,0},
        {3,3,3,3,3},
        {0,0,3,0,0}
    };
    for(int i=0;i<3;i++)
        for(int j=0;j<5;j++){
            int x = centroL - 1 + i;
            int y = centroC - 2 + j;
            if(x>=0 && x<N && y>=0 && y<N)
                tabuleiro[x][y] = cruz[i][j];
        }
}

// Octaedro 3x5, centralizado automaticamente
void aplicarOctaedro(int tabuleiro[N][N], int centroL, int centroC){
    int octa[3][5] = {
        {0,0,2,0,0},
        {0,2,2,2,0},
        {0,0,2,0,0}
    };
    for(int i=0;i<3;i++)
        for(int j=0;j<5;j++){
            int x = centroL - 1 + i;
            int y = centroC - 2 + j;
            if(x>=0 && x<N && y>=0 && y<N)
                tabuleiro[x][y] = octa[i][j];
        }
}

int main(){
    int tabuleiro[N][N] = {0};

    // =========================
    // Define os pontos centrais de cada habilidade
    // =========================
    int centroConeL=2, centroConeC=5;
    int centroCruzL=7, centroCruzC=3;
    int centroOctaL=5, centroOctaC=5;

    // =========================
    // Aplicando habilidades
    // =========================
    aplicarCone(tabuleiro, centroConeL, centroConeC);
    aplicarCruz(tabuleiro, centroCruzL, centroCruzC);
    aplicarOctaedro(tabuleiro, centroOctaL, centroOctaC);

    // =========================
    // Imprime tabuleiro final
    // =========================
    imprimirTabuleiro(tabuleiro);

    return 0;
}