#include <stdio.h>
#include <stdlib.h>

int main()
{
    char Sim_ou_nao;

    printf("� mam�fero? Digite 'Sim' ou 'Nao'\n");
    scanf("%s", &Sim_ou_nao);

    if(Sim_ou_nao == "Sim"){
        printf("� quadr�pede?");
        scanf("%s", &Sim_ou_nao);
        if(Sim_ou_nao == 'Sim'){
            printf("� carn�voro?");
            scanf("%s", &Sim_ou_nao);
            if(Sim_ou_nao == 'Sim')
                printf("O animal � um le�o");
            else printf("� um cavalo");
        }else{
            printf("� b�pede?");
            scanf("%s", &Sim_ou_nao);
            if(Sim_ou_nao == 'Sim'){
                printf("� on�voro?");
                scanf("%s", &Sim_ou_nao);
                if(Sim_ou_nao == 'Sim')
                    printf("O animal � um homem");
                else printf("� um macaco");
            }else{
                printf("� voador?");
                scanf("%s", &Sim_ou_nao);
                if(Sim_ou_nao == 'Sim')
                    printf("O animal � um morcego?");
                else printf("O animal � uma baleia");
            }
        }
    }
}
