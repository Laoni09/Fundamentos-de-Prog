#include <stdio.h>
#include <stdlib.h>
//11
void prova_ponteiro(int *vetor){
    printf("Na função: %d bits\n", sizeof(vetor));
}

//8
void multiplica_matrizes(){
    int linha;
    int coluna;
    int i;
    int somaprod;
    int mat1[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int mat2[3][3]={{1,0,0},{0,1,0},{0,0,1}};
    int mat3[3][3];
    int M1L=3, M1C=3, M2L=3, M2C=3;
    for(linha=0; linha<M1L; linha++)
        for(coluna=0; coluna<M2C; coluna++){
            somaprod=0;
            for(i=0; i<M1L; i++) somaprod += mat1[linha][i]*mat2[i][coluna];
            mat3[linha][coluna]=somaprod;
        }
    for(linha=0; linha<M1L; linha++){
        for(coluna=0; coluna<M2C; coluna++)
            printf("%d ", mat3[linha][coluna]);
        printf("\n");
    }
}

//7
int capitalize(char *str){
    int tam = 0;
    while(str[tam] != '\0'){
        str[tam] = str[tam] + 'A' - 'a';
        tam++;
    }
}

//5
int busca_troca(char *str, const char busca, const char troca){
    int i = 0, qtde = 0;
    while(str[i] != '\0'){
        if(str[i] == busca){
            str[i] = troca;
            qtde++;
        }
        i++;
    }
    return qtde;
}

void sort_X(int opr, int *X){
    int i = 0, j = 0, elemento = 0;
    if(opr == 1){
        for(i = 0; i < 5; i++){
            for(j = 0; j < 5; j++){
                elemento = X[j];
                if(X[i] < X[j]){
                    X[j] = X[i];
                    X[i] = elemento;
                }
            }
        }
        for(i = 0; i < 5; i++)
            printf("%d", X[i]);
    }
    if(opr == 2){
        for(i = 0; i < 5; i++){
            for(j = 0; j < 5; j++){
                elemento = X[j];
                if(X[i] > X[j]){
                    X[j] = X[i];
                    X[i] = elemento;
                }
            }
        }
        for(i = 0; i < 5; i++)
            printf("%d", X[i]);
    }
}

int intersec(int *X, int *Y, int *Z){
    int i = 0, j = 0, k = 0, contador = 0, condicao = 0;
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            if(X[i] == Y[j]){
                condicao = 0;
                for(contador = 0; contador <= k; contador++){
                    if(X[i] == Z[contador])
                        condicao = 1;
                }
                if(condicao != 1){
                    Z[k] = X[i];
                    k++;
                }
            }
        }
    }
    return k;
}

int minha_strlen(const char *string){
    int tam = 0;
    while(string[tam] != '\0'){
        tam++;
    }
    return tam;
}

int main()
{
    int vetor[4] = {1, 3, 4, 5};
    prova_ponteiro(&vetor);
    printf("Na main: %d bits", sizeof(vetor));
}
