#include <stdio.h>
#include <stdlib.h>


static int qp[100005];
static int pq[100005];
static int N;
int *vetor;
void fixDown(int *pq, int k, int N);
void fixUp(int *pq, int k);
#define less(a, b)(vetor[a]>vetor[b])
struct pq_st{
    int *pq;
    int *qp;
    int N;
}typedef pq_st;

void pq_init(){
    N=0;

}

void exch(int i, int j){
    int t;
    t = qp[i];
    qp[i]=qp[j];
    qp[j]=t;
    pq[qp[i]]=i;
    pq[qp[j]]=j;    
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
void Pqinsert(int k){
    qp[k]=++N;
    pq[N]=k;
    fixup(pq, N);
}
void Pqchange(int k){
    fixup(pq, qp[k]);
    fixDown(pq, qp[k], N);
}
int Pqdelmin(){
    exch(pq[1], pq[N]);
    fixDown(pq, 1, N-1);
    return pq[N--];
}
void solve(int n, int k, int *v){

    // printf("%d", pq[1]); 
    int antiga=0;
    int proximo=k;
    vetor=v;
    pq_init();
    for(int i=0;i<k;i++){
        Pqinsert(i);
    }
    while(proximo<=n){
        if(proximo==n){
            printf("%d", vetor[pq[1]]);
        }
        else printf("%d ", vetor[pq[1]]);
        v[antiga]=0;
        Pqchange(antiga);
        Pqdelmin();
        antiga++;
        // Pqinsert(proximo);
        Pqinsert(proximo);
        proximo++;
    
    }
    printf("\n");
}
int main(){
    int v[1000005];
    int n, k;
    while(scanf("%d %d", &n, &k)==2 && n!=0 && k!=0){
        for(int i=0;i<n;i++){
            scanf("%d", &v[i]);
        }
        solve(n, k, v);
    }
    

    return 0;
}