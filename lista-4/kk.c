#include <stdio.h>
#include <stdlib.h>

typedef int Item;
#define LESS(A, B)(A<B)
#define EXCH(A, B){int t=B; B=A; A=t;}
#define CMPEXCH(A, B){if(LESS(B, A)) EXCH(A, B);}


int separa(int *v, int l, int r){
    int c = v[r];
    int i=l-1, j=r;
    for(;;){
        while(LESS(v[++i], c));
        while(LESS(c, v[--j])) if(i==j) break;
        if(i>=j) break;
        EXCH(v[i], v[j])
    }
    EXCH(v[i], v[r])
    return i;
}

void quicksort(int *v, int l, int r){
    if(l>=r) return;
    CMPEXCH(v[(l+r)/2], v[r])
        CMPEXCH(v[l], v[(l+r)/2])
            CMPEXCH(v[r], v[(l+r)/2])
    int j=separa(v, l, r);
    quicksort(v, l, j-1);
    quicksort(v, j+1, r);
}


int quickselect(Item *v, int l, int r, int n){
    int j = separa(v, l, r);
    if (j>n)
       return quickselect(v, l, j-1, n);
    else if (j<n)
       return quickselect(v, j+1, r, n);
    return j;
}

int main(){
    int num;
    int inicio, fim;
    int N, P, X;
    scanf("%d %d %d", &N, &P, &X) == 1;
    int r = N-1;
    Item *v = malloc(N*sizeof(Item));
    for(int i = 0; i < N; i++){
        scanf("%d", &v[i]);
    }

    inicio = X*P;
    fim = inicio + X;
    if(fim > r){
      fim = r;
    }
    quickselect(v, 0, r, inicio);
    quickselect(v, inicio+1, r, fim);
    quicksort(v, inicio, fim);
    int i=inicio;
    if(fim == r){
        while(i<=fim){
            printf("%d\n", v[i]);
            i++;
        }
    }
    else{
        while(i<fim){
            printf("%d\n", v[i]);
            i++;
        }
    }
    return 0;
}