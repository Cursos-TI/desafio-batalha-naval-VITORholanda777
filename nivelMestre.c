#include <stdio.h>
#include <stdlib.h>

#define TAM 10
#define HAB 5

void iniciarTab(int tab[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tab[i][j] = (i >= 3 && i <= 4 && j >= 3 && j <= 4) ? 3 : 0;
}

void mostrarTab(int tab[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++)
            printf("%c ", tab[i][j] == 0 ? '~' : (tab[i][j] == 3 ? '#' : '@'));
        printf("\n");
    }
}

void criarHab(int hab[HAB][HAB], int tipo) {
    int c = HAB/2;
    for (int i = 0; i < HAB; i++)
        for (int j = 0; j < HAB; j++)
            hab[i][j] = (tipo == 0) ? (j >= c-i && j <= c+i && i >= c) :
                       (tipo == 1) ? (i == c || j == c) :
                       (abs(i-c) + abs(j-c) <= c);
}

void aplicarHab(int tab[TAM][TAM], int hab[HAB][HAB], int x, int y) {
    int c = HAB/2;
    for (int i = 0; i < HAB; i++)
        for (int j = 0; j < HAB; j++)
            if (hab[i][j] && x+i-c >= 0 && x+i-c < TAM && y+j-c >= 0 && y+j-c < TAM)
                tab[x+i-c][y+j-c] = 5;
}

int main() {
    int tab[TAM][TAM], hab[HAB][HAB];
    char *nomes[] = {"CONE", "CRUZ", "OCTAEDRO"};
    
    for (int t = 0; t < 3; t++) {
        iniciarTab(tab);
        criarHab(hab, t);
        aplicarHab(tab, hab, 5, 5);
        printf("\n%s:\n", nomes[t]);
        mostrarTab(tab);
    }
    
    return 0;
}