#include <stdio.h>
#include <stdlib.h>

void merge(int *vetor, int l, int m, int r){
    int *c = malloc(sizeof(int)*(r-l+1));
    int k=0, i=l, j=m+1;

    while(i<=m && j<=r){
        if(vetor[i]<=vetor[j]){
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
void mergesort(int *vetor, int l, int r){
    if(l>=r) return;
    int m = (l+r)/2;
    mergesort(vetor, l, m);
    mergesort(vetor, m+1, r);
    merge(vetor, l, m, r);
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
    int N, num;
    scanf("%d", &N);
    int *vetor=malloc(sizeof(int)*N);
    for(int i=0;i<N;i++){
        scanf("%d", &num);
        vetor[i]=num;
    }
    mergesort(vetor, 0, N-1);


    while(scanf("%d", &num)!=EOF){
        int retorno = busca_binaria(vetor, 0, N-1, num);
        if(retorno!=-1) printf("sim");
        else printf("nao"); 
        printf("\n");
    }
}