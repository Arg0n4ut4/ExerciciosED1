#include <stdio.h>

#define MESES 12
#define SEMANAS 4

int main(void) {
    double vendas[MESES][SEMANAS];
    const char *nomeMes[MESES] = {
        "Janeiro", "Fevereiro", "Marco", "Abril",
        "Maio", "Junho", "Julho", "Agosto",
        "Setembro", "Outubro", "Novembro", "Dezembro"
    };

    // Leitura dos dados: vendas por mes (linha) e semana (coluna)
    printf("Entrada das vendas por mes e semana (use ponto como separador decimal)\n");
    for (int i = 0; i < MESES; i++) {
        printf("\n--- %s ---\n", nomeMes[i]);
        for (int j = 0; j < SEMANAS; j++) {
            double valor;
            while (1) {
                printf("Venda da semana %d: ", j + 1);
                if (scanf("%lf", &valor) != 1) {
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF) {}
                    printf("Entrada invalida. Digite um numero valido.\n");
                    continue;
                }
                if (valor < 0.0) {
                    printf("Valor nao pode ser negativo. Digite novamente.\n");
                    continue;
                }
                vendas[i][j] = valor;
                break;
            }
        }
    }

    // 1) Total vendido em cada mes (soma da linha), mostrando nome do mes
    double totalAno = 0.0;
    double totalPorMes[MESES];
    for (int i = 0; i < MESES; i++) {
        double soma = 0.0;
        for (int j = 0; j < SEMANAS; j++) soma += vendas[i][j];
        totalPorMes[i] = soma;
        totalAno += soma;
    }

    // 2) Total vendido em cada semana durante todo o ano (soma por coluna)
    double totalPorSemana[SEMANAS] = {0.0};
    for (int j = 0; j < SEMANAS; j++) {
        double soma = 0.0;
        for (int i = 0; i < MESES; i++) soma += vendas[i][j];
        totalPorSemana[j] = soma;
    }

    // Impressao do relatorio
    printf("\n\nRELATORIO DE VENDAS\n");
    printf("Total por mes:\n");
    printf("%-10s %15s\n", "Mes", "Total_vendido");
    printf("---------------------------------\n");
    for (int i = 0; i < MESES; i++) {
        printf("%-10s %15.2f\n", nomeMes[i], totalPorMes[i]);
    }

    printf("\nTotal por semana no ano:\n");
    for (int j = 0; j < SEMANAS; j++) {
        printf("Semana %d: %.2f\n", j + 1, totalPorSemana[j]);
    }

    printf("\nTotal vendido no ano: %.2f\n", totalAno);

    return 0;
}
