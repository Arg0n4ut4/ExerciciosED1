#include <stdio.h>

#define LIN 2
#define COL 4

int main(void) {
    int matriz[LIN][COL];
    int i, j;

    int qtdLinha[LIN] = {0};
    int somaPares = 0;
    int qtdPares = 0;

    // Entrada de dados
    printf("Digite os elementos da matriz %dx%d:\n", LIN, COL);
    for (i = 0; i < LIN; i++) {
        for (j = 0; j < COL; j++) {
            printf("Elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);

            // verifica intervalo
            if (matriz[i][j] >= 12 && matriz[i][j] <= 20) {
                qtdLinha[i]++;
            }

            // verifica par
            if (matriz[i][j] % 2 == 0) {
                somaPares += matriz[i][j];
                qtdPares++;
            }
        }
    }

    // Resultados
    printf("\nQuantidade de elementos entre 12 e 20 por linha:\n");
    for (i = 0; i < LIN; i++) {
        printf("Linha %d: %d\n", i + 1, qtdLinha[i]);
    }

    if (qtdPares > 0) {
        double media = (double)somaPares / qtdPares;
        printf("\nMedia dos elementos pares: %.2f\n", media);
    } else {
        printf("\nNao ha elementos pares na matriz.\n");
    }

    return 0;
}
