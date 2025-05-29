#include <stdio.h>

// Constantes para o tamanho do tabuleiro e dos navios
#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

int main() {
    // Declaração do tabuleiro 10x10 e inicialização com 0 (água)
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};

    // Definindo as coordenadas iniciais dos navios (linha, coluna)
    // Navio Horizontal começando na linha 2, coluna 4
    int linhaH = 2;
    int colunaH = 4;

    // Navio Vertical começando na linha 5, coluna 7
    int linhaV = 5;
    int colunaV = 7;

    // Validação dos limites para o navio horizontal
    if (colunaH + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: Navio horizontal fora dos limites!\n");
        return 1;
    }

    // Validação dos limites para o navio vertical
    if (linhaV + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: Navio vertical fora dos limites!\n");
        return 1;
    }

    // Verificando se há sobreposição antes de posicionar os navios
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linhaH][colunaH + i] == 3 || tabuleiro[linhaV + i][colunaV] == 3) {
            printf("Erro: Sobreposição de navios detectada!\n");
            return 1;
        }
    }

    // Posicionando o navio horizontal no tabuleiro
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaH][colunaH + i] = 3;
    }

    // Posicionando o navio vertical no tabuleiro
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaV + i][colunaV] = 3;
    }

    // Impressão do tabuleiro
    printf("Tabuleiro:\n\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
