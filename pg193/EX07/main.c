#include <stdio.h>

#define TAM 10

int main(void) {
    double numeros[TAM];
    int i, qtdNegativos = 0;
    double somaPositivos = 0.0;

    // Entrada de dados
    for (i = 0; i < TAM; i++) {
        printf("Digite o %d numero real: ", i + 1);
        scanf("%lf", &numeros[i]);

        if (numeros[i] < 0) {
            qtdNegativos++;
        } else {
            somaPositivos += numeros[i];
        }
    }

    // Saída
    printf("\nQuantidade de numeros negativos: %d\n", qtdNegativos);
    printf("Soma dos numeros positivos: %.2lf\n", somaPositivos);

    return 0;
}