#include <stdio.h>

#define TAM 15

int main(void) {
    int vetor[TAM];
    int i;
    int encontrou = 0;

    printf("Digite %d numeros inteiros:\n", TAM);
    for (i = 0; i < TAM; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("\nVerificando valores iguais a 30...\n");
    for (i = 0; i < TAM; i++) {
        if (vetor[i] == 30) {
            printf("Encontrado 30 na posicao %d\n", i);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhum valor igual a 30 foi encontrado.\n");
    }

    return 0;
}