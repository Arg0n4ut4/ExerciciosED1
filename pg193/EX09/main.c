#include <stdio.h>

#define N 10
#define MAX_NOME 60

int main(void) {
    char nomes[N][MAX_NOME];
    int codigos[N];
    double precos[N];

    /* Leitura dos dados */
    printf("Entrada de dados dos %d produtos\n", N);
    for (int i = 0; i < N; i++) {
        printf("\nProduto %d\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", nomes[i]);
        printf("Codigo (inteiro): ");
        while (scanf("%d", &codigos[i]) != 1) {
            int c; while ((c = getchar()) != '\n' && c != EOF) {}
            printf("Entrada invalida. Digite o codigo (inteiro): ");
        }
        printf("Preco (use ponto como separador decimal, ex: 1234.56): ");
        while (scanf("%lf", &precos[i]) != 1) {
            int c; while ((c = getchar()) != '\n' && c != EOF) {}
            printf("Entrada invalida. Digite o preco novamente: ");
        }
    }

    /* Cabecalho do relatorio */
    printf("\n\nRELATORIO DE PRODUTOS COM AUMENTO\n");
    printf("%-30s %8s %12s %14s\n", "Nome", "Codigo", "Preco", "Novo_preco");
    printf("-------------------------------------------------------------------------------\n");

    int houve = 0;
    for (int i = 0; i < N; i++) {
        int codigoPar = (codigos[i] % 2 == 0);
        int precoMaior1000 = (precos[i] > 1000.00);
        double novoPreco = precos[i];
        double aumento = 0.0;

        if (codigoPar && precoMaior1000) {
            aumento = 0.20; /* 20% */
        } else if (codigoPar) {
            aumento = 0.15; /* 15% */
        } else if (precoMaior1000) {
            aumento = 0.10; /* 10% */
        } else {
            aumento = 0.0;
        }

        if (aumento > 0.0) {
            novoPreco = precos[i] * (1.0 + aumento);
            printf("%-30s %8d %12.2f %14.2f\n", nomes[i], codigos[i], precos[i], novoPreco);
            houve = 1;
        }
    }

    if (!houve) {
        printf("Nenhum produto atende aos criterios de aumento.\n");
    }

    return 0;
}
