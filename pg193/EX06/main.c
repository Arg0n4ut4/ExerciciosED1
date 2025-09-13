#include <stdio.h>

#define NUM_VENDEDORES 10
#define MAX_NOME 50

int main(void) {
    char nomes[NUM_VENDEDORES][MAX_NOME];
    double vendas[NUM_VENDEDORES];
    double comissaoPercent[NUM_VENDEDORES];
    double comissaoValor[NUM_VENDEDORES];
    double totalVendas = 0.0;
    double maior = 0.0, menor = 0.0;
    int i, indiceMaior = 0, indiceMenor = 0;

    // Entrada de dados
    for (i = 0; i < NUM_VENDEDORES; i++) {
        printf("Digite o nome do vendedor %d: ", i + 1);
        scanf(" %[^\n]", nomes[i]); // lê até a quebra de linha

        printf("Digite o total de vendas de %s: ", nomes[i]);
        scanf("%lf", &vendas[i]);

        printf("Digite o percentual de comissao de %s (ex: 5 para 5%%): ", nomes[i]);
        scanf("%lf", &comissaoPercent[i]);
    }

    // Calculo das comissoes
    for (i = 0; i < NUM_VENDEDORES; i++) {
        comissaoValor[i] = vendas[i] * comissaoPercent[i] / 100.0;
        totalVendas += vendas[i];

        if (i == 0 || comissaoValor[i] > maior) {
            maior = comissaoValor[i];
            indiceMaior = i;
        }

        if (i == 0 || comissaoValor[i] < menor) {
            menor = comissaoValor[i];
            indiceMenor = i;
        }
    }

    // Relatorio
    printf("\n=== Relatorio de comissoes ===\n");
    printf("Vendedor\tComissao a receber\n");
    for (i = 0; i < NUM_VENDEDORES; i++) {
        printf("%s\t\t%.2lf\n", nomes[i], comissaoValor[i]);
    }

    printf("\nTotal de vendas da loja: %.2lf\n", totalVendas);
    printf("Maior comissao: %.2lf (%s)\n", maior, nomes[indiceMaior]);
    printf("Menor comissao: %.2lf (%s)\n", menor, nomes[indiceMenor]);

    return 0;
}
