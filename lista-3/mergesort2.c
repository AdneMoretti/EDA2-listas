#include <stdio.h>
#include <stdlib.h>


void merge(int *v, int l, int meio, int r){
    int *c = malloc(sizeof(int)* (r-l+1));
    int i=l;
    int j=meio+1;
    int k=0;
    while(i<=meio && j<=r){
        if(v[i]<=v[j]){
            c[k++]=v[i++];
        }
        else{
            c[k++]=v[j++];
        }
    }
    while(i<=meio){
        c[k++]=v[i++];
    }
    while(j<=r){
        c[k++]=v[j++];
    }
    k=0;
    for(i=l;i<=r;i++){
        v[i]=c[k++];
    }
    free(c);
}
void mergesort(int *v, int l, int r){
    if(l>=r) return;
    int meio = (l+r)/2;
    mergesort(v, l, meio);
    mergesort(v, meio+1, r);
    merge(v, l, meio, r);
}
int main(void){
    int numero, count=0;
    int v[100000];
    while(scanf("%d", &numero)!=EOF){
        count++;
        v[count-1] = numero;
    }
    mergesort(v, 0, count-1);
    for(int i=0;i<count;i++){
        if(i!=count-1) printf("%d ", v[i]);
        else printf("%d\n", v[i]);
    }

}