#include <stdio.h>

#define LIN 3
#define COL 5

int main(void) {
    int matriz[LIN][COL];
    int i, j;
    int contador = 0;

    // Entrada dos dados
    printf("Digite os elementos da matriz %dx%d:\n", LIN, COL);
    for (i = 0; i < LIN; i++) {
        for (j = 0; j < COL; j++) {
            printf("Elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);

            if (matriz[i][j] >= 15 && matriz[i][j] <= 20) {
                contador++;
            }
        }
    }

    // Saída
    printf("\nQuantidade de elementos entre 15 e 20: %d\n", contador);

    return 0;
}
