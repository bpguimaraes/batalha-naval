#include <stdio.h>
#include <stdlib.h>

#define TAM_TAB 10
#define TAM_HAB 5

// Função para inicializar o tabuleiro
void inicializarTabuleiro(int tabuleiro[TAM_TAB][TAM_TAB]) {
    for (int i = 0; i < TAM_TAB; i++)
        for (int j = 0; j < TAM_TAB; j++)
            tabuleiro[i][j] = 0;
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM_TAB][TAM_TAB]) {
    for (int i = 0; i < TAM_TAB; i++) {
        for (int j = 0; j < TAM_TAB; j++) {
            if (tabuleiro[i][j] == 3)
                printf("N ");
            else if (tabuleiro[i][j] == 5)
                printf("H ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

// Função para posicionar navios
void posicionarNavio(int tabuleiro[TAM_TAB][TAM_TAB], int linha, int coluna, char direcao) {
    for (int i = 0; i < 3; i++) {
        if (direcao == 'H')  // Horizontal
            tabuleiro[linha][coluna + i] = 3;
        else if (direcao == 'V')  // Vertical
            tabuleiro[linha + i][coluna] = 3;
        else if (direcao == 'D')  // Diagonal principal
            tabuleiro[linha + i][coluna + i] = 3;
        else if (direcao == 'A')  // Diagonal secundária
            tabuleiro[linha + i][coluna - i] = 3;
    }
}

// Função para criar matriz cone
void criarCone(int habilidade[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++)
        for (int j = 0; j < TAM_HAB; j++)
            habilidade[i][j] = (i >= j && i + j >= TAM_HAB - 1) ? 1 : 0;
}

// Função para criar cruz
void criarCruz(int habilidade[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++)
        for (int j = 0; j < TAM_HAB; j++)
            habilidade[i][j] = (i == TAM_HAB / 2 || j == TAM_HAB / 2) ? 1 : 0;
}

// Função para criar octaedro (losango)
void criarOctaedro(int habilidade[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - TAM_HAB / 2) + abs(j - TAM_HAB / 2) <= TAM_HAB / 2)
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

// Sobrepõe a habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAM_TAB][TAM_TAB], int habilidade[TAM_HAB][TAM_HAB], int centroLinha, int centroColuna) {
    int offset = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int tabLinha = centroLinha - offset + i;
            int tabColuna = centroColuna - offset + j;

            if (tabLinha >= 0 && tabLinha < TAM_TAB && tabColuna >= 0 && tabColuna < TAM_TAB) {
                if (habilidade[i][j] == 1 && tabuleiro[tabLinha][tabColuna] != 3) {
                    tabuleiro[tabLinha][tabColuna] = 5;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM_TAB][TAM_TAB];
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    inicializarTabuleiro(tabuleiro);

    // Posicionando navios: dois normais e dois diagonais
    posicionarNavio(tabuleiro, 0, 0, 'H'); // Horizontal
    posicionarNavio(tabuleiro, 5, 0, 'V'); // Vertical
    posicionarNavio(tabuleiro, 0, 5, 'D'); // Diagonal principal
    posicionarNavio(tabuleiro, 2, 8, 'A'); // Diagonal secundária

    // Criando habilidades
    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // Aplicando habilidades
    aplicarHabilidade(tabuleiro, cone, 2, 2);       // Cone em (2,2)
    aplicarHabilidade(tabuleiro, cruz, 5, 5);       // Cruz em (5,5)
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);   // Octaedro em (7,7)

    // Exibindo o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}