#include <stdio.h>

int main(){
    int numero, soma=0;
    while(scanf("%d", &numero)!= EOF){
        soma+=1;
    }
    printf("%d\n", soma);
}