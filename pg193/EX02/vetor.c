#include <stdio.h>
#include "vetor.h"

// Função para preencher o vetor com inteiros informados pelo usuário
void preencherVetor(int v[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Digite o %d numero inteiro: ", i + 1);
        scanf("%d", &v[i]);
    }
}

// Mostra números múltiplos de 2
void mostrarMultiplosDe2(const int v[], int tamanho) {
    printf("\nMultiplos de 2: ");
    for (int i = 0; i < tamanho; i++) {
        if (v[i] % 2 == 0) {
            printf("%d ", v[i]);
        }
    }
    printf("\n");
}

// Mostra números múltiplos de 3
void mostrarMultiplosDe3(const int v[], int tamanho) {
    printf("\nMultiplos de 3: ");
    for (int i = 0; i < tamanho; i++) {
        if (v[i] % 3 == 0) {
            printf("%d ", v[i]);
        }
    }
    printf("\n");
}

// Mostra números múltiplos de 2 e 3 ao mesmo tempo (x6)
void mostrarMultiplosDe2e3(const int v[], int tamanho) {
    printf("\nMultiplos de 2 e 3: ");
    for (int i = 0; i < tamanho; i++) {
        if (v[i] % 2 == 0 && v[i] % 3 == 0) {
            printf("%d ", v[i]);
        }
    }
    printf("\n");
}
