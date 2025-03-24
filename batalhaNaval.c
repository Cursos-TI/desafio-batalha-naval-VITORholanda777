#include <stdio.h>

#define TAMANHO 10 // Tamanho do tabuleiro
#define NAVIO_TAMANHO 3 // Tamanho dos navios

void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0; // 0 representa água
        }
    }
}

int posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int horizontal) {
    if (horizontal) {
        if (coluna + NAVIO_TAMANHO > TAMANHO) return 0; // Fora dos limites
        for (int i = 0; i < NAVIO_TAMANHO; i++) {
            if (tabuleiro[linha][coluna + i] != 0) return 0; // Sobreposição
        }
        for (int i = 0; i < NAVIO_TAMANHO; i++) {
            tabuleiro[linha][coluna + i] = 3;
            printf("Navio horizontal posicionado em: (%d, %d)\n", linha, coluna + i);
        }
    } else {
        if (linha + NAVIO_TAMANHO > TAMANHO) return 0; // Fora dos limites
        for (int i = 0; i < NAVIO_TAMANHO; i++) {
            if (tabuleiro[linha + i][coluna] != 0) return 0; // Sobreposição
        }
        for (int i = 0; i < NAVIO_TAMANHO; i++) {
            tabuleiro[linha + i][coluna] = 3;
            printf("Navio vertical posicionado em: (%d, %d)\n", linha + i, coluna);
        }
    }
    return 1; // Posicionado com sucesso
}

void imprimirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);

    // Coordenadas pré-definidas para os navios (podem ser ajustadas)
    if (!posicionarNavio(tabuleiro, 2, 2, 1)) {
        printf("Falha ao posicionar navio horizontal!\n");
    }
    if (!posicionarNavio(tabuleiro, 5, 5, 0)) {
        printf("Falha ao posicionar navio vertical!\n");
    }
    
    imprimirTabuleiro(tabuleiro);
    return 0;
}
