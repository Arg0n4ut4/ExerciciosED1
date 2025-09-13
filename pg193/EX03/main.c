#include <stdio.h>
#include <string.h>
#include "estoque.h"

int main(void) {
    int estoque[TAM];
    int estoqueAntigo[TAM];

    // Inicializa estoque com entradas do usuario
    inicializarEstoque(estoque, TAM);

    // Copia para estoqueAntigo antes de processar pedidos
    memcpy(estoqueAntigo, estoque, sizeof(int) * TAM);

    // Processa pedidos (atualiza vetor 'estoque' quando pedido atendido)
    processarPedidos(estoque, TAM);


    // Imprime comparacao em ordem crescente de codigo 1..TAM
    imprimirComparacaoEstoque(estoque, estoqueAntigo, TAM);

    return 0;
}
