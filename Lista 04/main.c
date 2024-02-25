#include <stdio.h>
#include <stdlib.h>

int main()
{
    char sequencia[20][50];
    printf("Digite 20 palavras de ate 50 letras ou um ponto (.) para finalizar a sequencia!\n");

    int i = 0;
    int cont = 0;
    int letras = 0;
    int tamanhoPalavra = 0;
    int condicao = 1;

    for(i = 0; i < 20 && condicao == 1; i++){
        scanf("%s", &sequencia[i]);
        if(sequencia[i][0] == '.')
            condicao = 0;
        for(letras = 0; sequencia[i][letras] != '\0'; letras++);
        if(letras > 50){
            printf("Digite uma palavra com ate 50 letras!\n");
            i--;
            tamanhoPalavra = 0;
        }else if(letras <= 50 && condicao == 1){
            tamanhoPalavra = 1;
            cont++;
            }

    }

    printf("Lista:\n");

    for(i = cont-1; i >= 0; i--){
        printf("%s\n", sequencia[i]);
    }


    return 0;
}
