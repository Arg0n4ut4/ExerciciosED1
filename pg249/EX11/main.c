#include <stdio.h>

#define ALUNOS 8
#define DISCIPLINAS 5

int main(void) {
    int idade[ALUNOS];
    int codigo[DISCIPLINAS];
    int provas[ALUNOS][DISCIPLINAS];
    int i, j;

    // Leitura das idades dos alunos
    printf("Digite a idade dos %d alunos:\n", ALUNOS);
    for (i = 0; i < ALUNOS; i++) {
        printf("Aluno %d: ", i + 1);
        scanf("%d", &idade[i]);
    }

    // Leitura dos codigos das disciplinas
    printf("\nDigite os codigos das %d disciplinas:\n", DISCIPLINAS);
    for (j = 0; j < DISCIPLINAS; j++) {
        printf("Disciplina %d: ", j + 1);
        scanf("%d", &codigo[j]);
    }

    // Leitura da matriz de provas
    printf("\nDigite a quantidade de provas feitas por cada aluno em cada disciplina:\n");
    for (i = 0; i < ALUNOS; i++) {
        printf("\nAluno %d:\n", i + 1);
        for (j = 0; j < DISCIPLINAS; j++) {
            printf("  Disciplina %d (codigo %d): ", j + 1, codigo[j]);
            scanf("%d", &provas[i][j]);
        }
    }

    // Impressao do relatorio
    printf("\nRELATORIO DE PROVAS POR ALUNO\n");
    printf("Aluno  Idade ");
    for (j = 0; j < DISCIPLINAS; j++) {
        printf("D%d ", codigo[j]);
    }
    printf("\n---------------------------------\n");

    for (i = 0; i < ALUNOS; i++) {
        printf("%5d %6d ", i + 1, idade[i]);
        for (j = 0; j < DISCIPLINAS; j++) {
            printf("%2d ", provas[i][j]);
        }
        printf("\n");
    }

    return 0;
}
