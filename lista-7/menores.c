#include <stdio.h>
#include <stdlib.h>
#define less(a, b)(a>b)
#define exch(a, b){int t=a;a=b;b=t;}
#define CMPEXCH(A, B){if(less(B, A)) exch(A, B)}

struct pq_st{
    int *pq;
    int N;
}typedef pq_st;

void pq_init(int max_n, struct pq_st *Pq){
    Pq->pq = malloc(sizeof(int)*(max_n+1));
    Pq->N=0;
}
void fixup(int  *v, int k){
    while(k>1 && less(v[k/2], v[k])){
        exch(v[k], v[k/2]);
        k=k/2;
    }
}
void fixDown(int *v, int k, int N){
    int j;
    while(2*k<=N){
        j=2*k;
        if(j<N && less(v[j], v[j+1]))j++;
        if(!less(v[k], v[j])) break;
        exch(v[k], v[j]);
        k=j;
    }
}
int Pqinsert(struct pq_st *Pq, int novo){
    Pq->pq[++Pq->N]=novo;
    fixup(Pq->pq, Pq->N);
}
int Pqdelmin(struct pq_st *Pq){
    exch(Pq->pq[1], Pq->pq[Pq->N]);
    fixDown(Pq->pq, 1, --Pq->N);
    return Pq->pq[Pq->N+1];
}

int main(){
    pq_st Pq;
    pq_init(10000000, &Pq);
    int operacao;
    int num;
    while(scanf("%d %d", &operacao, &num)==2){
        if(operacao==1){
            Pqinsert(&Pq, num);
        }
        else{
            int n=0;
            int tam=0;
            int v[100];
            while(tam<num){
                int topo = Pqdelmin(&Pq);
                if((tam==num-1)){
                    printf("%d", topo);
                }
                else{
                    printf("%d ", topo);
                }
                v[n++] = topo;
                tam++;
            }
            for(tam=0;tam<num;tam++){
                Pqinsert(&Pq, v[tam]);
            }
            printf("\n");

        }
    }


    return 0;
}