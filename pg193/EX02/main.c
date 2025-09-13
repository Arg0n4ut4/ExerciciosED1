#include <stdio.h>
#include "vetor.h"

int main(void) {
    int numeros[TAM];

    preencherVetor(numeros, TAM);

    mostrarMultiplosDe2(numeros, TAM);
    mostrarMultiplosDe3(numeros, TAM);
    mostrarMultiplosDe2e3(numeros, TAM);

    return 0;
}
