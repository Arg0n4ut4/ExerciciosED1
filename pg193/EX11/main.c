#include <stdio.h>

#define TAM 10

int main(void) {
    int numeros[TAM];
    int pares[TAM], impares[TAM];
    int qtdPares = 0, qtdImpares = 0;

    // Entrada de dados
    for (int i = 0; i < TAM; i++) {
        printf("Digite o %d numero inteiro: ", i + 1);
        scanf("%d", &numeros[i]);

        if (numeros[i] % 2 == 0) {
            pares[qtdPares] = numeros[i];
            qtdPares++;
        } else {
            impares[qtdImpares] = numeros[i];
            qtdImpares++;
        }
    }

    // Saída: pares
    printf("\nVetor de numeros pares (%d): ", qtdPares);
    if (qtdPares == 0) {
        printf("nenhum");
    } else {
        for (int i = 0; i < qtdPares; i++) {
            printf("%d ", pares[i]);
        }
    }

    // Saída: ímpares
    printf("\nVetor de numeros impares (%d): ", qtdImpares);
    if (qtdImpares == 0) {
        printf("nenhum");
    } else {
        for (int i = 0; i < qtdImpares; i++) {
            printf("%d ", impares[i]);
        }
    }

    printf("\n");
    return 0;
}
