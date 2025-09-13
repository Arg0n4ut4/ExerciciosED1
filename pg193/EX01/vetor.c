#include <stdio.h>
#include "vetor.h"

// Função para preencher o vetor com inteiros informados pelo usuário
void preencherVetor(int v[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Digite o %d numero inteiro: ", i + 1);
        scanf("%d", &v[i]);
    }
}

// Mostra todos os números pares e a quantidade
void mostrarPares(const int v[], int tamanho) {
    int count = 0;
    printf("\nNumeros pares: ");
    for (int i = 0; i < tamanho; i++) {
        if (v[i] % 2 == 0) {
            printf("%d ", v[i]);
            count++;
        }
    }
    printf("\nQuantidade de pares: %d\n", count);
}

// Mostra todos os números ímpares e a quantidade
void mostrarImpares(const int v[], int tamanho) {
    int count = 0;
    printf("\nNumeros ímpares: ");
    for (int i = 0; i < tamanho; i++) {
        if (v[i] % 2 != 0) {
            printf("%d ", v[i]);
            count++;
        }
    }
    printf("\nQuantidade de impares: %d\n", count);
}
