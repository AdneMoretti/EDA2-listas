#include <stdio.h>
#include <stdlib.h>

#define LESS(A, B)(A<B)
#define EXCH(A, B){int t=B; B=A; A=t;}
#define CMPEXCH(A, B){if(LESS(B, A)) EXCH(A, B);}

int quick(int *v, int l, int r){
    int c = v[r];
    int i=l-1, j=r;
    for(;;){
        while(LESS(v[++i], c));
        while(LESS(c, v[--j])) if(i==j) break;
        if(i>=j) break;
        EXCH(v[i], v[j]);
    }
    EXCH(v[i], v[r]);
    return i;
}
void quicksort(int *v, int l, int r){
    if(l>=r) return;
    int j=quick(v, l, r);
    quicksort(v, l, j-1);
    quicksort(v, j+1, r);
}
int main(void){
    int num;
    scanf("%d", &num);
    int *vetor=malloc(sizeof(int)*num);
    for(int i=0;i<num;i++){
        scanf("%d", &vetor[i]);
    }
    quicksort(vetor, 0, num-1);
    for(int i=0;i<num;i++){
        printf("%d", vetor[i]);
        if(i==num-1)  printf("\n");
        else printf(" ");
    }
}