#include <stdio.h>

#define LIN 3
#define COL 8

int main(void) {
    int A[LIN][COL], B[LIN][COL];
    int soma[LIN][COL], diferenca[LIN][COL];
    int i, j;

    // Entrada da matriz A
    printf("Digite os elementos da matriz A (3x8):\n");
    for (i = 0; i < LIN; i++) {
        for (j = 0; j < COL; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    // Entrada da matriz B
    printf("\nDigite os elementos da matriz B (3x8):\n");
    for (i = 0; i < LIN; i++) {
        for (j = 0; j < COL; j++) {
            printf("B[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    // Calculo da soma e da diferenca
    for (i = 0; i < LIN; i++) {
        for (j = 0; j < COL; j++) {
            soma[i][j] = A[i][j] + B[i][j];
            diferenca[i][j] = A[i][j] - B[i][j];
        }
    }

    // Impressao da soma
    printf("\nMatriz soma (A + B):\n");
    for (i = 0; i < LIN; i++) {
        for (j = 0; j < COL; j++) {
            printf("%6d ", soma[i][j]);
        }
        printf("\n");
    }

    // Impressao da diferenca
    printf("\nMatriz diferenca (A - B):\n");
    for (i = 0; i < LIN; i++) {
        for (j = 0; j < COL; j++) {
            printf("%6d ", diferenca[i][j]);
        }
        printf("\n");
    }

    return 0;
}
