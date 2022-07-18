#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define key(A) (A.jpn)
#define LESS(A, B) ((strcmp(key(A), key(B)))<0)
#define EXCH(A, B){Item t=B; B=A; A=t;}
#define CMPEXCH(A, B){if(LESS(B, A)) EXCH(A, B)}

typedef struct Item 
{
    char jpn[81];
    char ptbr[81];
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
void quicksort(Item *v, int l, int r){
    if(l>=r) return;
    CMPEXCH(v[(l+r)/2], v[r]);
        CMPEXCH(v[l], v[(l+r)/2]);
            CMPEXCH(v[r], v[(l+r)/2]);
    int j=quick(v, l, r);
    quicksort(v, l, j-1);
    quicksort(v, j+1, r);
}
int busca_binaria(Item *vetor, int l, int r, char *num){     
    int meio=(l+r)/2;
    if(strcmp(num,vetor[meio].jpn)==0) return meio;
    if(l>=r){
        return -1;
    }
    if(strcmp(num,vetor[meio].jpn)<0) busca_binaria(vetor, l, meio, num);  
    else busca_binaria(vetor, meio+1, r, num);                                            
}
Item dicionario[10000000];

void traduz(){
    int M, N;
    scanf("%d %d", &M, &N);
    for(int i=0;i<M;i++)
    {
        scanf(" %[^\n]", dicionario[i].jpn);
        scanf(" %[^\n]", dicionario[i].ptbr);
    }
    quicksort(dicionario, 0, M-1);
    for(int i=0;i<N;i++){
        char b[81], p;
        while(scanf(" %s%c", b, &p)==2){
            int j = busca_binaria(dicionario, 0, M-1, b);
            if(j<0) printf("%s", b);
            else printf("%s", dicionario[j].ptbr);
            printf("%c", p); if(p=='\n') break;
        }
    }
}

int main(void){
    int t;
    scanf("%d", &t);
    for(int i=0;i<t;i++){
        traduz();
        printf("\n");
    }

}