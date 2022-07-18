#include <stdio.h>
#include <stdlib.h>

struct item{
    int I;
    char C;
    int P;
}typedef item;

void merge(item *vetor, int l, int m, int r){
    item *c = malloc(sizeof(item)*(r-l+1));
    int k=0, i=l, j=m+1;

    while(i<=m && j<=r){
        if(vetor[i].I>=vetor[j].I){
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

int main(){
    char entrada[100001];
    int i=0;
    int k=0;
    item v[100000];
    scanf(" %s", &entrada[i]);
    while(entrada[i]!='\0'){
        char c = entrada[i];
        v[k].C= entrada[i];
        v[k].P= i;
        int soma=1;
        int p=i;
        while(entrada[i+1]==c){
            soma++; 
            i++;
        }
        i++;
        v[k++].I=soma;
    }
    mergesort(v, 0, k-1);
    for(i=0;i<k;i++){
        printf("%d %c %d", v[i].I, v[i].C, v[i].P);
        printf("\n");
    }
}