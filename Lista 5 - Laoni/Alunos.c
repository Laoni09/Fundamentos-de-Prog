#include <stdio.h>
#include <stdlib.h>
#include "Alunos.h"

void adicionar_aluno(FILE *db){
    char cond;
    db = fopen("database.txt", "a");

    if (db == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    struct Aluno aluno1;

    while(1){
        printf("Deseja adicionar mais algum aluno? [s/n]");
        scanf("%c", &cond);

        if(cond == 's'){
            printf("Digite o nome do aluno:\n");
            scanf("%s", &aluno1.primeiro_nome);
            fprintf(db, "%s ", aluno1.primeiro_nome);

            printf("Nota P1:\n");
            scanf("%f", &aluno1.notap1);
            fprintf(db, "%.2f ", aluno1.notap1);

            printf("Nota P2:\n");
            scanf("%f", &aluno1.notap2);
            fprintf(db, "%.2f ", aluno1.notap2);

            printf("Nota LISTAS:\n");
            scanf("%f", &aluno1.lista);
            fprintf(db, "%.2f ", aluno1.lista);

            printf("Nota APS:\n");
            scanf("%f", &aluno1.aps);
            fprintf(db, "%.2f\n", aluno1.aps);
        }if(cond == 'n') break;
    }
    fclose(db);
}

int conta_linhas(FILE *db){
    int qtde_linhas = 0;
    db = fopen("database.txt", "r");
    char content_line;
    while((content_line = fgetc(db)) != EOF){
        if (content_line == '\n'){
            qtde_linhas++;
        }
    }
    fclose(db);
    return qtde_linhas;
}

void gerar_relatorio(FILE *db, int qtde_linhas){
    int i = 0, j = 0, posicao;
    char content_line, caractere;
    char cond = 'n';

    struct Aluno *alunos = malloc(qtde_linhas * sizeof(struct Aluno));

    if (alunos == NULL) {
        printf("Erro ao alocar memória.\n");
    return 1;
    }

    db = fopen("database.txt", "r");

    i = 0;
    while(fscanf(db, "%s %f %f %f %f", alunos[i].primeiro_nome, &alunos[i].notap1, &alunos[i].notap2, &alunos[i].lista, &alunos[i].aps) != EOF)
        i++;

    float media_aluno;
    for(i = 0; i < qtde_linhas; i++){
        media_aluno = 0.0;
        printf("%s ", alunos[i].primeiro_nome);
        media_aluno = ((0.35*alunos[i].notap1 + 0.35*alunos[i].notap2 + 0.1*alunos[i].lista + 0.2*alunos[i].aps)/(0.35 + 0.35 + 0.1 + 0.2));
        if(media_aluno >= 6.0) printf("condicao: aprovado");
        if(media_aluno < 6.0 && media_aluno >= 4.0) printf("condicao: recuperacao");
        if(media_aluno < 4.0) printf("condicao: reprovado");
        printf("\n");
    }
    free(alunos);
    fclose(db);
}
