#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct info{
    int numero;
    char comando[15];
}info;

// #define KEY(A)(A.numero)
// #define LESS(A, B)(KEY(A)<KEY(B))
// #define EXCH(A, B){int t=B; B=A; A=t;}
// #define CMPEXCH(A, B){if(LESS(B, A)) EXCH(A, B);}

void busca_binaria(info *v, info *v2, int qtdelem1, int valor){
    int esq = -1;
    int dir = qtdelem1;

    while (esq < dir - 1)
    {
        int meio = (dir + esq) / 2;
        if(v[meio].numero < valor)
            esq = meio;
        else
            dir = meio;
    }
    if(valor == v[dir].numero)
    {
        printf("%s\n",v[dir].comando);
    }
    else if(valor != v[dir].numero){
        printf("undefined\n");
    }
}

void merge(info *v, int l, int m, int r)
{
  info *v2=malloc(sizeof(info)*(r-l+1));
  int i=l,j=m+1,k=0;

  while(i<=m && j<=r)
  {
    if((v[i].numero<=v[j].numero))
      v2[k++]=v[i++];
    else
      v2[k++]=v[j++];
  }

  while(i<=m)
      v2[k++]=v[i++];
  while(j<=r)
      v2[k++]=v[j++];


  k=0;
  for(i=l;i<=r;i++)
    v[i]=v2[k++];
  free(v2);
}

void mergesort(info *V,int l, int r)
{
  if (l>= r) return;
  int meio=(l+r)/2;
  mergesort(V,l,meio);
  mergesort(V,meio+1,r);
  merge(V,l,meio,r);
}
int main(void){
    int n, count=0, num;
    scanf("%d", &n);
    char retorno[16];
    info *list = malloc(sizeof(info)*n);
    info *list2 = malloc(sizeof(info)*n);
    for(int i=0;i<n;i++){
        scanf("%d %s", &list[count].numero, list[count].comando);
        count++;
    }
    mergesort(list, 0, count-1);
    while(scanf("%d", &num) != EOF){
        busca_binaria(list, list2, count, num);
    }
}