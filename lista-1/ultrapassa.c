#include <stdio.h>
#include <stdlib.h>

void fumn(int *v, int umn, int tam){
    if(tam==0) return;
    int soma=0, i=0;
    while(soma<umn && i<tam){
        soma+=v[i++];
    }
    fumn(&v[i], umn, tam-i);
    if(soma>umn){
        printf("%d\n", v[i-1]);
    }
}
int main(void){
    int *v = malloc(4);
    int aux, tam=0;
    int umn;
    while(scanf("%d", &aux)==1 && aux!=0){
        tam++;
        v = realloc(v, sizeof(int)* tam);
        v[tam-1] = aux;
    }
    scanf("%d", &umn);
    fumn(v, umn, tam);
}
