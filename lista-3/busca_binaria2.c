#include <stdio.h>
#include <stdlib.h>

void merge(int *vetor, int l, int m, int r, int *vetor2){
    int *c = malloc(sizeof(int)*(r-l+1));
    int *c2 = malloc(sizeof(int)*(r-l+1));
    int k=0, i=l, j=m+1;

    while(i<=m && j<=r){
        if(vetor[i]<=vetor[j]){
            c2[k]=i;
            c[k++]=vetor[i++];
        }
        else{
            c2[k]=j;
            c[k++]=vetor[j++];
        }
    }
    while(i<=m){
        c2[k]=i;
        c[k++]=vetor[i++];
    }
    while(j<=r){
        c2[k]=j;
        c[k++]=vetor[j++];
    }
    k=0;
    for(int i=l;i<=r;i++){
        vetor2[i] = c2[k];
        vetor[i]=c[k++];
    }
    free(c);
    free(c2);
}
void mergesort(int *vetor, int l, int r, int *vetor2){
    if(l>=r) return;
    int m = (l+r)/2;
    mergesort(vetor, l, m, vetor2);
    mergesort(vetor, m+1, r, vetor2);
    merge(vetor, l, m, r, vetor2);
}

int busca_binaria(int *vetor, int l, int r, int num){     
    int meio=(l+r)/2;
    if(num==vetor[meio]) return meio;
    if(l>=r){
        return -1;
    }
    if(num<vetor[meio]) busca_binaria(vetor, l, meio, num);  
    else busca_binaria(vetor, meio+1, r, num);                                            
}
int main(void){
    int M, N, num;
    scanf("%d %d", &N, &M);
    int *vetor=malloc(sizeof(int)*N);
    int *vetor2 = malloc(sizeof(int)*N);
    for(int i=0;i<N;i++){
        scanf("%d", &num);
        vetor[i]=num;
    }
    mergesort(vetor, 0, N-1, vetor2);

    for(int i=0;i<M;i++){
        scanf("%d", &num); 
        int retorno = busca_binaria(vetor, 0, N-1, num);
        // if(retorno!=-1) printf("%d", vetor2[retorno]);
        // else printf("-1"); 
        // printf("%d",busca_binaria(vetor, 0, N-1, num));  
        // printf("\n");
    }
    for(int i=0;i<N;i++){
        printf("%d", vetor[i]);
    }
    for(int i=0;i<N;i++){
        printf("%d", vetor2[i]);
    }
}