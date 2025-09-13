#include <stdio.h>

#define TAM_LOGICA 15
#define TAM_LP 10

// Função que verifica se o numero ja existe no vetor
int existeNoVetor(int vetor[], int tamanho, int numero) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == numero) {
            return 1; // existe
        }
    }
    return 0; // nao existe
}

int main(void) {
    int logica[TAM_LOGICA];
    int lp[TAM_LP];
    int i, j;
    int encontrou = 0;
    int matricula;

    // Inserção do vetor de Lógica
    printf("Digite as matriculas dos alunos de Logica (%d alunos):\n", TAM_LOGICA);
    for (i = 0; i < TAM_LOGICA; ) {
        printf("Aluno %d: ", i + 1);
        scanf("%d", &matricula);

        if (existeNoVetor(logica, i, matricula)) {
            printf("Matricula ja inserida. Digite outra.\n");
        } else {
            logica[i] = matricula;
            i++; // só incrementa se a matrícula for válida
        }
    }

    // Inserção do vetor de Linguagem de Programação
    printf("\nDigite as matriculas dos alunos de Linguagem de Programacao (%d alunos):\n", TAM_LP);
    for (i = 0; i < TAM_LP; ) {
        printf("Aluno %d: ", i + 1);
        scanf("%d", &matricula);

        if (existeNoVetor(lp, i, matricula)) {
            printf("Matricula ja inserida. Digite outra.\n");
        } else {
            lp[i] = matricula;
            i++; // só incrementa se a matrícula for válida
        }
    }

    // Verificando interseção
    printf("\nAlunos que cursam Logica e Linguagem de Programacao simultaneamente:\n");
    for (i = 0; i < TAM_LOGICA; i++) {
        for (j = 0; j < TAM_LP; j++) {
            if (logica[i] == lp[j]) {
                printf("%d\n", logica[i]);
                encontrou = 1;
                break; // evita imprimir a mesma matrícula mais de uma vez
            }
        }
    }

    if (!encontrou) {
        printf("Nenhum aluno cursa as duas disciplinas simultaneamente.\n");
    }

    return 0;
}
