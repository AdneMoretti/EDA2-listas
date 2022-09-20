#include <stdio.h>
#include <stdlib.h>
#define less(a, b)(a>b)
#define exch(a, b){int t=a;a=b;b=t;}
#define CMPEXCH(A, B){if(less(B, A)) exch(A, B)}

struct pq_st{
    int *pq;
    int *qp;
    int N;
}typedef pq_st;

void pq_init(int max_n, struct pq_st *Pq){
    Pq->pq = malloc(sizeof(int)*(max_n+1));
    Pq->qp = malloc(sizeof(int)*(max_n+1));
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
    Pq->qp[Pq->N]=Pq->N;
    fixup(Pq->pq, Pq->N);
    fixup(Pq->qp, Pq->N);
}
int Pqdelmax(struct pq_st *Pq, int k){
    exch(Pq->pq[k], Pq->pq[(Pq->N)]);
    fixDown(Pq->pq, k, --Pq->N);
    return Pq->pq[Pq->N+1];
}

int main(){
    pq_st Pq;
    int operacao, nota;
    int num;
    while(scanf("%d %d", &operacao, &num)==2 && operacao!=0 && nota!=0){
        pq_init(1000001, &Pq);
        for(int i=0;i<num-1;i++){
            scanf(" %d", &nota);
            Pqinsert(&Pq, nota);
        }
        for(int i=num-1;i<operacao;i++){
            scanf(" %d", &nota);
            Pqinsert(&Pq, nota);
            printf("%d%c", Pq.pq[1], " \n"[i == operacao-1]);
            Pqdelmax(&Pq, Pq.qp[i-num+1]);
        }
        // int *v = malloc(sizeof(int)* num);
        // for(int i=0;i<num;i++){
        //     scanf("%d", v[i]);
        // }
    }


    return 0;
}