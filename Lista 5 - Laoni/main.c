1#include <stdio.h>
#include <stdlib.h>

int main()
{
    int qtde_linhas = 0;
    FILE *db;

    //adicionando mais alunos ao arquivo
    adicionar_aluno(&db);

    //numero de linhas no arquivo
    qtde_linhas = conta_linhas(&db);

    gerar_relatorio(&db, qtde_linhas);

    return 0;
}
