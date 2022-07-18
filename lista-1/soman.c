#include <stdio.h> 


int main(){
    int N, A, soma=0;
    scanf("%d", &N);
    for (int i=0;i<N;i++){
        scanf("%d", &A);
        soma += A;
    }
    printf("%d\n", soma);
}