#include <stdio.h>
#include <stdlib.h>

struct item{
    int index;
    int numero;
} typedef item;

void merge(item *vetor, int l, int m, int r){
    item *c = malloc(sizeof(item)*(r-l+1));
    int k=0, i=l, j=m+1;

    while(i<=m && j<=r){
        if(vetor[i].numero<=vetor[j].numero){
            c[k++]=vetor[i++];
        }
        else{
            c[k++]=vetor[j++];
        }
    }
    while(i<=m){
        c[k++]=vetor[i++];
    }
    while(j<=r){
        c[k++]=vetor[j++];
    }
    k=0;
    for(int i=l;i<=r;i++){
        vetor[i]=c[k++];
    }
    free(c);
}
void mergesort(item *vetor, int l, int r){
    if(l>=r) return;
    int m = (l+r)/2;
    mergesort(vetor, l, m);
    mergesort(vetor, m+1, r);
    merge(vetor, l, m, r);
}

int busca_binaria(item *vetor, int l, int r, int num){     
    int meio=(l+r)/2;
    if(num==vetor[meio].numero) return meio;
    if(l>=r){
        return -1;
    }
    if(num<vetor[meio].numero) busca_binaria(vetor, l, meio, num);  
    else busca_binaria(vetor, meio+1, r, num);                                            
}
int main(void){
    int M, N, num;
    scanf("%d %d", &N, &M);
    item *vetor=malloc(sizeof(item)*N);
    for(int i=0;i<N;i++){
        scanf("%d", &num);
        vetor[i].numero=num;
        vetor[i].index=i;
    }
    mergesort(vetor, 0, N-1);

    for(int i=0;i<M;i++){
        scanf("%d", &num); 
        int retorno = busca_binaria(vetor, 0, N-1, num);
        if(retorno!=-1) printf("%d", vetor[retorno].index);
        else printf("-1"); 
        // printf("%d",busca_binaria(vetor, 0, N-1, num));  
        printf("\n");
    }
}