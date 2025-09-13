#include <stdio.h>

#define LIN 3
#define COL 3

int main(void) {
    double matriz[LIN][COL];
    double resultado[LIN][COL];
    double escalar;
    int i, j;

    // Leitura da matriz
    printf("Digite os elementos da matriz 3x3 (reais):\n");
    for (i = 0; i < LIN; i++) {
        for (j = 0; j < COL; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%lf", &matriz[i][j]);
        }
    }

    // Leitura do escalar
    printf("\nDigite o numero a multiplicar a matriz: ");
    scanf("%lf", &escalar);

    // Multiplicacao elemento a elemento
    for (i = 0; i < LIN; i++) {
        for (j = 0; j < COL; j++) {
            resultado[i][j] = matriz[i][j] * escalar;
        }
    }

    // Impressao da matriz resultante
    printf("\nMatriz resultante:\n");
    for (i = 0; i < LIN; i++) {
        for (j = 0; j < COL; j++) {
            printf("%8.2lf ", resultado[i][j]);
        }
        printf("\n");
    }

    return 0;
}
