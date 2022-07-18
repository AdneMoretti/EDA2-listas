#include <stdio.h>

#define LESS(A, B)(A<B)
#define EXCH(A, B){int t=B; B=A; A=t;}
#define CMPEXCH(A, B){if(LESS(B, A)) EXCH(A, B);}

#include <stdio.h>

void insertionsort(int *v, int l, int r){
    for(int i=r;i>l; i--){
        CMPEXCH(v[i-1], v[i]);
    }
    for(int i = l+2; i<=r;i++){
        int j=i, aux=v[j];
        while(LESS(aux, v[j-1])){
            v[j]=v[j-1];
            j--;
        }
        v[j]=aux;
    }
    for(int i=0;i<=r;i++){
        printf("%d", v[i]);
        if(i==r)  printf("\n");
        else printf(" ");
    }
}
int main(void){
    int numero, count=0;
    int v[50001];
    while(scanf("%d", &numero)!=EOF){
        count++;
        v[count-1] = numero;
    }
    insertionsort(v, 0, count-1);
}