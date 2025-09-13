#include <stdio.h>
#include "vetor.h"

int main(void) {
    int numeros[TAM];

    preencherVetor(numeros, TAM);
    mostrarPares(numeros, TAM);
    mostrarImpares(numeros, TAM);

    return 0;
}
