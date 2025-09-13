#include <stdio.h>

#define LIN 6
#define COL 3

int main(void) {
    int matriz[LIN][COL];
    int i, j;

    int maior, menor;
    int linMaior = 0, colMaior = 0;
    int linMenor = 0, colMenor = 0;

    printf("Digite os elementos da matriz %dx%d:\n", LIN, COL);
    for (i = 0; i < LIN; i++) {
        for (j = 0; j < COL; j++) {
            printf("Elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);

            if (i == 0 && j == 0) {
                // inicializa com o primeiro elemento
                maior = menor = matriz[i][j];
            } else {
                if (matriz[i][j] > maior) {
                    maior = matriz[i][j];
                    linMaior = i;
                    colMaior = j;
                }
                if (matriz[i][j] < menor) {
                    menor = matriz[i][j];
                    linMenor = i;
                    colMenor = j;
                }
            }
        }
    }

    printf("\nMaior elemento: %d (linha %d, coluna %d)\n", maior, linMaior + 1, colMaior + 1);
    printf("Menor elemento: %d (linha %d, coluna %d)\n", menor, linMenor + 1, colMenor + 1);

    return 0;
}
