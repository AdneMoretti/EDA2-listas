#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define key(A) (A.N)
#define key2(A) (A.N)
#define LESS(A, B) (key(A)<key(B))
#define EXCH(A, B){Item t=B; B=A; A=t;}
#define CMPEXCH(A, B){if(LESS(B, A)) EXCH(A, B)}

typedef struct Item 
{
    int pagina;
    int num[100000];
}Item;

int quick(Item *v, int l, int r){
    Item c = v[r];
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
void merge(Item *v, int l, int m, int r)
{
  Item *v2=malloc(sizeof(Item)*(r-l+1));
  int i=l,j=m+1,k=0;

  while(i<=m && j<=r)
  {
    if((v[i].S<=v[j].S))
      v2[k++]=v[i++];
    else
      v2[k++]=v[j++];
  }

  while(i<=m)
      v2[k++]=v[i++];
  while(j<=r)
      v2[k++]=v[j++];


  k=0;
  for(i=l;i<=r;i++){
    v[i]=v2[k++];
  }
  free(v2);
}

void mergesort(Item *V,int l, int r)
{
  if (l>= r) return;
  int meio=(l+r)/2;
  mergesort(V,l,meio);
  mergesort(V,meio+1,r);
  merge(V,l,meio,r);
}
void quickselect(Item *v, int l, int r, int n){
    int j=quick(v, l, r);
    if(j==n) return;
    if(j>n) quickselect(v, l, j-1, n);
    if(j<n) quickselect(v, j+1, r, n);
}

void imprimetopn(Item *v, int l, int r, int n){
    quickselect(v, l, r, l+n-1);
    mergesort(v, l, l+n-1);
    for(int i=l;i<=l+n-1;i++){
        printf("%d %d\n", v[i].S, v[i].N);
    }
}
Item elementos[10000000];
int main(void){
    int N, P, X;
    scanf("%d %d %d", &N, &P, &X);
    for(i=0;i<N;i++){
        scanf("%d", &elementos[i]);
    }
    int iniciop=X*P;
    int fimp=

}