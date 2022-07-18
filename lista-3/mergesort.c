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
    int numero, num, count=0;
    scanf("%d", &numero);
    int *v = malloc(sizeof(int)*numero);
    for(int i=0;i<numero;i++){
        scanf("%d", &num);
        v[count++] = num;
    }
    mergesort(v, 0, count-1);

    for(int i=0;i<count;i++){
        printf("%d", v[i]);
        if(i==count-1)  printf("\n");
        else printf(" ");
    }
}
