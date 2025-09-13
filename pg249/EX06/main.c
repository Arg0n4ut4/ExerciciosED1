#include <stdio.h>

#define LINHAS 20
#define COLUNAS 10

int main(void) {
    int matriz[LINHAS][COLUNAS];
    int somaColuna[COLUNAS] = {0};
    int i, j;

    // Entrada dos elementos da matriz
    printf("Digite os elementos da matriz %dx%d:\n", LINHAS, COLUNAS);
    for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
            somaColuna[j] += matriz[i][j];
        }
    }

    // Multiplicacao de cada elemento pela soma da sua coluna
    printf("\nMatriz resultante (cada elemento multiplicado pela soma da coluna):\n");
    for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
            int resultado = matriz[i][j] * somaColuna[j];
            printf("%8d ", resultado);
        }
        printf("\n");
    }

    printf("\nSoma de cada coluna:\n");
    for (j = 0; j < COLUNAS; j++) {
        printf("Coluna %d: %d\n", j, somaColuna[j]);
    }

    return 0;
}
