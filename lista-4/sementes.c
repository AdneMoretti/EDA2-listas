#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define key(A) (A.N)
#define EXCH(A, B){Item t=B; B=A; A=t;}
#define CMPEXCH(A, B){if(LESS2(B, A)) EXCH(A, B)}
// Macro para verificar se o N e igual, se for, verifica o S
#define LESS(A, B) (A.N==B.N ? A.S < B.S : A.N < B.N) 
// Macro para verificar se o S e igual, se for, verifica o N
#define LESS2(A, B) (A.S == B.S ? A.N < B.N : A.S <= B.S)
typedef struct Item 
{
    long long int S;
    int N;
}Item;
int quick(Item *v, int l, int r)
{
    Item c = v[r];
    int j = l;
    for (int k = l; k < r; k++)
        if (LESS(v[k], c))
        {
            EXCH(v[k], v[j]);
            j++;
        }
    EXCH(v[j], v[r]);
    return j;
}
int separa(Item *v, int l, int r){
    Item c = v[r];
    int j = l;
    for (int k = l; k < r; k++)
        if (LESS2(v[k], c))
        {
            EXCH(v[k], v[j]);
            j++;
        }
    EXCH(v[j], v[r]);
    return j;
}
void quicksort(Item *v, int l, int r){
    if(r-l<=32) return;
    CMPEXCH(v[(l+r)/2], v[r])
        CMPEXCH(v[l], v[(l+r)/2])
            CMPEXCH(v[r], v[(l+r)/2])
    int j=quick(v, l, r);
    quicksort(v, l, j-1);
    quicksort(v, j+1, r);
}
void insertionsort(Item *v, int l, int r)
{
    for (int i=l+1, j; i<=r; i++)
    {
        Item c = v[i];
        for (j = i; j > 0 && LESS2(c, v[j - 1]); j--)
            v[j] = v[j - 1];
        v[j] = c;
    }
}
void quicksort1(Item *v, int l, int r){
    quicksort(v, l, r);
    insertionsort(v, l, r);
}
void quickselect(Item *v, int l, int r, int n){
    CMPEXCH(v[(l+r)/2], v[r])
        CMPEXCH(v[l], v[(l+r)/2])
            CMPEXCH(v[r], v[(l+r)/2])
    int j=quick(v, l, r);
    if(j==n) return;
    if(j>n) quickselect(v, l, j-1, n);
    if(j<n) quickselect(v, j+1, r, n);
}

void imprimetopn(Item *v, int l, int r, int n){
    quickselect(v, l, r, l+n-1);
    quicksort1(v, l, l+n-1);
    for(int i=l;i<=l+n-1;i++){
        printf("%lld %d\n", v[i].S, v[i].N);
    }
}
Item sementes[10000001];
int main(void){
    int n, i=0;
    scanf("%d", &n);
    while(scanf("%lld %d", &sementes[i].S, &sementes[i].N) !=EOF) i++;
    // for(int j=0;j<=i-1;j++){
    //     printf("%d %d\n", sementes[j].S, sementes[j].N);
    // }
    imprimetopn(sementes, 0, i-1, n); 

}