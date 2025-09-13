#include <stdio.h>
#include "estoque.h"

static int leInteiroSeguro(int *valor) {
    if (scanf("%d", valor) != 1) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }
        return 0;
    }
    return 1;
}

// Preenche o vetor de estoques
void inicializarEstoque(int estoque[], int tamanho) {
    printf("Cadastro de estoque (produtos codificados de 1 a %d)\n", tamanho);
    for (int i = 0; i < tamanho; i++) {
        int q = -1;
        while (1) {
            printf("Informe a quantidade em estoque para o produto %d: ", i + 1);
            if (!leInteiroSeguro(&q)) {
                printf("Entrada invalida. Tente novamente.\n");
                continue;
            }
            if (q < 0) {
                printf("Quantidade nao pode ser negativa. Tente novamente.\n");
                continue;
            }
            break;
        }
        estoque[i] = q;
    }
}

// Processa pedidos ate que o codigo do cliente seja 0.
// Cada pedido recebe: codigoCliente, codigoProduto, quantidadeSolicitada.
void processarPedidos(int estoque[], int tamanho) {
    int codigoCliente;

    printf("\nInicio do processamento de pedidos (digite 0 como codigo do cliente para encerrar)\n");

    while (1) {
        printf("\nInforme o codigo do cliente (0 para encerrar): ");
        if (!leInteiroSeguro(&codigoCliente)) {
            printf("Entrada invalida. Tente novamente.\n");
            continue;
        }

        if (codigoCliente == 0) {
            break;
        }

        int codigoProduto;
        int quantidade;

        printf("Informe o codigo do produto desejado: ");
        if (!leInteiroSeguro(&codigoProduto)) {
            printf("Entrada invalida. Pedido ignorado.\n");
            continue;
        }

        printf("Informe a quantidade desejada: ");
        if (!leInteiroSeguro(&quantidade)) {
            printf("Entrada invalida. Pedido ignorado.\n");
            continue;
        }

        // valida codigo do produto: permitido 1..tamanho
        if (codigoProduto < 1 || codigoProduto > tamanho) {
            printf("Codigo inexistente\n");
            continue;
        }

        if (quantidade <= 0) {
            printf("Quantidade invalida. Pedido nao processado.\n");
            continue;
        }

        int idx = codigoProduto - 1;
        if (estoque[idx] < quantidade) {
            printf("Nao temos estoque suficiente dessa mercadoria.\n");
        } else {
            estoque[idx] -= quantidade; // atualiza somente se puder atender integralmente
            printf("Pedido atendido. Obrigado e volte sempre\n");
        }
    }
}

// Imprime tabela comparativa: Codigo | Estoque antigo | Estoque atual
// Em ordem crescente de codigo (1..TAM)
void imprimirComparacaoEstoque(const int estoque[], const int estoqueAntigo[], int tamanho) {
    printf("\nEstoque final (comparacao)\n");
    printf("Codigo\tEstoque_antigo\tEstoque_atual\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d\t%d\t\t%d\n", i + 1, estoqueAntigo[i], estoque[i]);
    }
}
