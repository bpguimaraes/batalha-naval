#include <stdio.h>

#define TAMANHO 10
#define TAM_NAVIO 3
#define AGUA 0
#define NAVIO 3

// Função para verificar se pode posicionar o navio
int pode_posicionar(int tabuleiro[TAMANHO][TAMANHO], int linha[], int coluna[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (linha[i] < 0 || linha[i] >= TAMANHO || coluna[i] < 0 || coluna[i] >= TAMANHO) {
            return 0; // Fora do tabuleiro
        }
        if (tabuleiro[linha[i]][coluna[i]] != AGUA) {
            return 0; // Já ocupado
        }
    }
    return 1; // Posições válidas
}

// Função para posicionar o navio
void posicionar_navio(int tabuleiro[TAMANHO][TAMANHO], int linha[], int coluna[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        tabuleiro[linha[i]][coluna[i]] = NAVIO;
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];

    // Inicializa tabuleiro com água (0)
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Coordenadas dos navios (cada um com 3 posições)
    int linha1[] = {1, 1, 1}; // Horizontal
    int coluna1[] = {2, 3, 4};

    int linha2[] = {5, 6, 7}; // Vertical
    int coluna2[] = {6, 6, 6};

    int linha3[] = {0, 1, 2}; // Diagonal principal (↘)
    int coluna3[] = {0, 1, 2};

    int linha4[] = {0, 1, 2}; // Diagonal secundária (↙)
    int coluna4[] = {9, 8, 7};

    // Valida e posiciona os navios
    if (pode_posicionar(tabuleiro, linha1, coluna1, TAM_NAVIO)) {
        posicionar_navio(tabuleiro, linha1, coluna1, TAM_NAVIO);
    }

    if (pode_posicionar(tabuleiro, linha2, coluna2, TAM_NAVIO)) {
        posicionar_navio(tabuleiro, linha2, coluna2, TAM_NAVIO);
    }

    if (pode_posicionar(tabuleiro, linha3, coluna3, TAM_NAVIO)) {
        posicionar_navio(tabuleiro, linha3, coluna3, TAM_NAVIO);
    }

    if (pode_posicionar(tabuleiro, linha4, coluna4, TAM_NAVIO)) {
        posicionar_navio(tabuleiro, linha4, coluna4, TAM_NAVIO);
    }

    // Exibe o tabuleiro
    printf("Tabuleiro Batalha Naval (0 = Água, 3 = Navio):\n\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
