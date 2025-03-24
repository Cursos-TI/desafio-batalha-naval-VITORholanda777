#include <stdio.h>

#define TAM 10
#define NAVIO 3

void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void posicionarNavio(int tabuleiro[TAM][TAM], int linha, int coluna, int deslocLinha, int deslocColuna) {
    for (int i = 0; i < NAVIO; i++) 
        tabuleiro[linha + i * deslocLinha][coluna + i * deslocColuna] = 3;
}

int main() {
    int tabuleiro[TAM][TAM] = {0}; // Tabuleiro inicial com água (0)

    // Posicionando os navios diretamente
    posicionarNavio(tabuleiro, 2, 0, 0, 1); // Horizontal
    posicionarNavio(tabuleiro, 4, 3, 1, 0); // Vertical
    posicionarNavio(tabuleiro, 6, 5, 1, 1); // Diagonal principal
    posicionarNavio(tabuleiro, 8, 7, 1, -1); // Diagonal anti-principal

    printf("Tabuleiro final:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
