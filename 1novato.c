#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define MAR_AZUL 0
#define NAVIO 3

int main() {
    // Matriz 10x10 representando o tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = MAR_AZUL;
        }
    }

    // Vetores representando navios
    int navio_horizontal[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int navio_vertical[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};

    // Coordenadas iniciais (definidas manualmente)
    int linha_horizontal = 2;
    int coluna_horizontal = 4;

    int linha_vertical = 5;
    int coluna_vertical = 7;

    // Validação de limites e sobreposição
    int pode_colocar_horizontal = 1;
    int pode_colocar_vertical = 1;

    // Verifica se o navio horizontal cabe no tabuleiro
    if (coluna_horizontal + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        pode_colocar_horizontal = 0;
    }

    // Verifica se o navio vertical cabe no tabuleiro
    if (linha_vertical + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        pode_colocar_vertical = 0;
    }

    // Verifica se há sobreposição nas posições desejadas
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha_horizontal][coluna_horizontal + i] == NAVIO) {
            pode_colocar_horizontal = 0;
        }
        if (tabuleiro[linha_vertical + i][coluna_vertical] == NAVIO) {
            pode_colocar_vertical = 0;
        }
    }

    // Posiciona navio horizontal, se possível
    if (pode_colocar_horizontal) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha_horizontal][coluna_horizontal + i] = navio_horizontal[i];
        }
    }

    // Posiciona navio vertical, se possível
    if (pode_colocar_vertical) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha_vertical + i][coluna_vertical] = navio_vertical[i];
        }
    }

    // Exibe o tabuleiro
    printf("Tabuleiro Batalha Naval:\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
