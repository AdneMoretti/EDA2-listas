#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXCH(A, B){item t=B; B=A; A=t;}
#define CMPEXCH(A, B){if(LESS(B, A)) EXCH(A, B)}
#define LESS(A, B) (A.qtd==B.qtd ? A.asc < B.asc : A.qtd < B.qtd) 

struct Item{
    int asc;
    int qtd;
}typedef item;

int separa(item *v, int l, int r){
    item c = v[r];
    int i=l;
    for(int j=l;j<r;j++){
        if (LESS(v[j], c))
        {
            EXCH(v[j], v[i]);
            i++;
        }
    }
    EXCH(v[i], v[r])
    return i;
}
void quicksort(item *v, int l, int r){
    if(r-l<=32) return;
    CMPEXCH(v[(l+r)/2], v[r])
        CMPEXCH(v[l], v[(l+r)/2])
            CMPEXCH(v[r], v[(l+r)/2])
    int j=separa(v, l, r);
    quicksort(v, l, j-1);
    quicksort(v, j+1, r);
}

void insertionsort(item *v, int l, int r)
{
    for (int i=l+1, j; i<=r; i++)
    {
        item c = v[i];
        for (j = i; j > 0 && LESS(c, v[j - 1]); j--)
            v[j] = v[j - 1];
        v[j] = c;
    }
}

void quicksort1(item *v, int l, int r){
    quicksort(v, l, r);
    insertionsort(v, l, r);
}
//Funcao que adiciona um no vetor no indice do numero lido, 
//se for maior que a variavel maior, a variavel passa a ter o seu valor

void insere_hash(int *ht, int entrada, int *maior, int *menor){
    ht[entrada]++;
    if(entrada>*maior){
        *maior=entrada;
    }
    if(entrada<*menor){
        *menor=entrada;
    }
}
int main(){
    char c[1010];
    while(scanf(" %s", c)!=EOF){
        int maior=33, menor=130;
        int ht[130];
        item v[130];
        memset(ht, 0, 130*sizeof(int));
        for(int i=0;c[i]!= '\0';i++){
            insere_hash(ht, c[i], &maior, &menor);
        }
        int k=0;
        for(int i=menor;i<=maior;i++){
            if(ht[i]!=0){
                v[k].qtd = ht[i];
                v[k].asc = i;
                k++;
            }
        }
        quicksort1(v, 0, k-1);
        for(int i=0;i < k;i++){
            printf("%d %d\n", v[i].asc, v[i].qtd);
        }
        printf("\n");
    }
    return 0;
}
