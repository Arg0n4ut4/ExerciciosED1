#include <stdio.h>

#define N_ALUNOS 15
#define N_PROVAS 5
#define MAX_NOME 60

int main(void) {
    char nomes[N_ALUNOS][MAX_NOME];
    double notas[N_ALUNOS][N_PROVAS];
    double medias[N_ALUNOS];
    int i, j;

    /* Leitura dos nomes */
    printf("Entrada dos nomes dos %d alunos\n", N_ALUNOS);
    for (i = 0; i < N_ALUNOS; i++) {
        printf("Nome do aluno %d: ", i + 1);
        /* ler linha inteira, ignorando espacos iniciais */
        scanf(" %[^\n]", nomes[i]);
    }

    /* Leitura das notas */
    printf("\nEntrada das notas (0.0 a 10.0) - %d provas por aluno\n", N_PROVAS);
    for (i = 0; i < N_ALUNOS; i++) {
        printf("\nNotas de %s:\n", nomes[i]);
        for (j = 0; j < N_PROVAS; j++) {
            double temp;
            while (1) {
                printf("  Prova %d: ", j + 1);
                if (scanf("%lf", &temp) != 1) {
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF) {}
                    printf("  Entrada invalida. Digite um numero entre 0.0 e 10.0\n");
                    continue;
                }
                if (temp < 0.0 || temp > 10.0) {
                    printf("  Nota fora do intervalo. Digite um valor entre 0.0 e 10.0\n");
                    continue;
                }
                notas[i][j] = temp;
                break;
            }
        }
    }

    /* Calcula medias por aluno e media da classe */
    double somaMedias = 0.0;
    for (i = 0; i < N_ALUNOS; i++) {
        double soma = 0.0;
        for (j = 0; j < N_PROVAS; j++) soma += notas[i][j];
        medias[i] = soma / N_PROVAS;
        somaMedias += medias[i];
    }
    double mediaClasse = somaMedias / N_ALUNOS;

    /* Impressao do relatorio */
    printf("\n\nRELATORIO POR ALUNO\n");
    printf("%-30s %8s %12s\n", "Nome", "Media", "Situacao");
    printf("---------------------------------------------------------------\n");
    for (i = 0; i < N_ALUNOS; i++) {
        const char *situacao;
        if (medias[i] >= 7.0) situacao = "aprovado";
        else if (medias[i] >= 5.0) situacao = "exame";
        else situacao = "reprovado";

        printf("%-30s %8.2f %12s\n", nomes[i], medias[i], situacao);
    }

    printf("\nMedia da classe: %.2f\n", mediaClasse);

    return 0;
}