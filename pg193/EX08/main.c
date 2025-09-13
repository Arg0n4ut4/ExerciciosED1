#include <stdio.h>

#define N 7
#define MAX_NOME 50

int main(void) {
    char nomes[N][MAX_NOME];
    double medias[N];
    int i;

    /* Entrada de nomes e medias */
    for (i = 0; i < N; i++) {
        printf("Digite o nome do aluno %d: ", i + 1);
        scanf(" %[^\n]", nomes[i]);

        printf("Digite a media final de %s: ", nomes[i]);
        while (scanf("%lf", &medias[i]) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            printf("Entrada invalida. Digite a media novamente para %s: ", nomes[i]);
        }
    }

    /* Encontrar maior media e verificar empates */
    double maior = medias[0];
    for (i = 1; i < N; i++) {
        if (medias[i] > maior) maior = medias[i];
    }

    int cont = 0;
    int idxMaior = -1;
    for (i = 0; i < N; i++) {
        if (medias[i] == maior) {
            cont++;
            idxMaior = i;
        }
    }

    if (cont == 1) {
        printf("\nAluno com maior media (desconsiderar empates): %s (%.2lf)\n", nomes[idxMaior], maior);
    } else {
        printf("\nMaior media empatada entre %d alunos. Desconsiderar empates.\n", cont);
    }

    /* Para cada aluno com media < 7, mostrar quanto precisa no exame */
    printf("\nAlunos com media < 7 e quanto precisam no exame para serem aprovados (media exame >= 5):\n");
    int algum = 0;
    for (i = 0; i < N; i++) {
        if (medias[i] < 7.0) {
            algum = 1;
            double necessario = 10.0 - medias[i];
            if (necessario <= 0.0) {
                printf("%s: precisa de 0.00 no exame (ja alcança media >= 5)\n", nomes[i]);
            } else if (necessario > 10.0) {
                printf("%s: impossivel atingir aprovacao no exame (necessita %.2lf > 10.00)\n", nomes[i], necessario);
            } else {
                printf("%s: precisa de %.2lf no exame\n", nomes[i], necessario);
            }
        }
    }
    if (!algum) {
        printf("Todos os alunos estao aprovados (media >= 7), nenhum precisa de exame.\n");
    }

    return 0;
}
