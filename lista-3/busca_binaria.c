#include <stdio.h>
#include <stdlib.h>

void busca_binaria(int *vetor, int l, int r, int num){     
    int meio=(l+r)/2;
    if(l>=r){
        if(vetor[meio]>=num){
            printf("%d", meio);
            return;
        }
        else{
            printf("%d", meio+1);
            return;
        }
    }
    if(num<=vetor[meio]) busca_binaria(vetor, l, meio, num);    
    else busca_binaria(vetor, meio+1, r, num);                                            
}
int main(void){
    int M, N, num;
    scanf("%d %d", &N, &M);
    int *vetor=malloc(sizeof(int)*N);
    for(int i=0;i<N;i++){
        scanf("%d", &num);
        vetor[i]=num;
    }
    for(int i=0;i<M;i++){
        scanf("%d", &num);
        busca_binaria(vetor, 0, N-1, num);
        printf("\n");
    }
}