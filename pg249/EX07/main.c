#include <stdio.h>

#define M_LIN 4
#define M_COL 6
#define N_LIN 6
#define N_COL 4

int main(void) {
    int M[M_LIN][M_COL];
    int N[N_LIN][N_COL];
    int i, j, k;

    // Leitura da matriz M
    printf("Digite os elementos da matriz M (4x6):\n");
    for (i = 0; i < M_LIN; i++) {
        for (j = 0; j < M_COL; j++) {
            printf("M[%d][%d]: ", i, j);
            scanf("%d", &M[i][j]);
        }
    }

    // Leitura da matriz N
    printf("\nDigite os elementos da matriz N (6x4):\n");
    for (i = 0; i < N_LIN; i++) {
        for (j = 0; j < N_COL; j++) {
            printf("N[%d][%d]: ", i, j);
            scanf("%d", &N[i][j]);
        }
    }

    printf("\nResultado da soma das linhas de M com colunas de N:\n");
    for (i = 0; i < M_LIN; i++) {
        for (j = 0; j < N_COL; j++) {
            int soma = 0;
            for (k = 0; k < M_COL; k++) {
                soma += M[i][k] + N[k][j];
            }
            printf("%8d ", soma);
        }
        printf("\n");
    }

    return 0;
}
