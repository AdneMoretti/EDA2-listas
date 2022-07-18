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
int main(void){
    int num, count=0, vetor[1000000];
    int novo;
    for(int i=0;i<8;i++){
        scanf("%d", &num);
        if(num!=0){
            for(int j=0;j<num;j++){
                scanf("%d", &novo);
                vetor[count++]=novo;
            }
        }
    }
    mergesort(vetor, 0, count-1);

    for(int i=0;i<count;i++){
        if(i!=count-1) printf("%d ", vetor[i]);
        else printf("%d\n", vetor[i]);
        
    }
}