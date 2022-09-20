#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//declara o vetor da tabela hash com tamanho 1000001, ja que e o maior elemento a ser lido e
//inicia as variaveis maior e maior cor como 0
int ht[101];

//Funcao que adiciona um no vetor no indice do numero lido, 
//se for maior que a variavel maior, a variavel passa a ter o seu valor
void insere_hash(int entrada, int *maior, int *maior_cor){
    ht[entrada]+=1;
    if(ht[entrada]>*maior){
        *maior=ht[entrada];
        *maior_cor=entrada;
    }
    if(ht[entrada]==*maior){
        if(entrada>*maior_cor){
            *maior_cor=entrada;
        }
    }
}
int main(void){
    int n, valor;
    int maior=0;
    int maior_cor=0;
    memset(ht, 0, 101*sizeof(int));
    scanf("%d", &n);
    for(int i=0; i < n; i++){
        int entrada;
        scanf("%d", &entrada);
        insere_hash(entrada, &maior, &maior_cor);
    }
    printf("%d\n", maior_cor);
}
