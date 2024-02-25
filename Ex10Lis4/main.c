#include <stdio.h>
#include <stdlib.h>

int main()
{
    char Sim_ou_nao;

    printf("É mamífero? Digite 'Sim' ou 'Nao'\n");
    scanf("%s", &Sim_ou_nao);

    if(Sim_ou_nao == "Sim"){
        printf("É quadrúpede?");
        scanf("%s", &Sim_ou_nao);
        if(Sim_ou_nao == 'Sim'){
            printf("É carnívoro?");
            scanf("%s", &Sim_ou_nao);
            if(Sim_ou_nao == 'Sim')
                printf("O animal é um leão");
            else printf("É um cavalo");
        }else{
            printf("É bípede?");
            scanf("%s", &Sim_ou_nao);
            if(Sim_ou_nao == 'Sim'){
                printf("É onívoro?");
                scanf("%s", &Sim_ou_nao);
                if(Sim_ou_nao == 'Sim')
                    printf("O animal é um homem");
                else printf("É um macaco");
            }else{
                printf("É voador?");
                scanf("%s", &Sim_ou_nao);
                if(Sim_ou_nao == 'Sim')
                    printf("O animal é um morcego?");
                else printf("O animal é uma baleia");
            }
        }
    }
}
