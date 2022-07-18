#include <stdio.h>
#include <stdlib.h>


void insertionsort(int *v, int l, int r){
    int aux;
    for(int i=r; i>l; i--){
        if(v[i-1]>v[i]){
            aux = v[i];
            v[i] = v[i-1];
            v[i-1] = aux;
        }
    }
    for(int i = l+2; i<=r; i++){
        int j = i; int elemento = v[j];
        while(elemento < v[j-1]){
             v[j]=v[j-1];
             j--;
        }
        v[j]=elemento;
    }
}

int main(){
    int numero, cont =0;
    scanf("%d", &numero);
    int *v = malloc(sizeof(int)*numero);
    for(int i=0;i<numero;i++){
        scanf("%d", &v[i]);
    }
    insertionsort(v, 0, numero-1);
    for(int j = 0; j<numero; j++){
        if(v[j] != v[j+1]) cont++;
    }
    printf("%d\n", cont);
    return 0;
}
