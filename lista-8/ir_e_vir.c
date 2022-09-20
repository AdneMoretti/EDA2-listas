#include <stdio.h>
#include <stdlib.h>
int cnt;
static int pre[5001];
int grafo[5001][5001];

void dfsr(int v, int w, int numcidades){
    pre[w]=cnt++;
    for(int i=0;i<=numcidades;i++){
        if(grafo[w][i]!=0){
            if(pre[i]==-1) dfsr(w, i, numcidades);
        }
        
    }
}

int search(int numcidades){
    for(int i=0;i<=numcidades;i++) pre[i]=-1;
    int count=0, maior=0;
    cnt=0;
    for(int i=0;i<=numcidades;i++){
        if(pre[i]==-1){
            dfsr(i, i, numcidades);
            count++;
        }
    }
    return count;
}

int main(){
    int N, M;
    int V, W, P;
    while(scanf("%d %d", &N, &M)==2){
        if(N==0 || M==0 ) break;
        for(int i=0;i<M;i++){
            scanf("%d %d %d", &V, &W, &P);
            if(P==1){
                grafo[V][V]=1;
                grafo[W][W]=1;
                grafo[V][W]=1;
            }
            else{
                grafo[V][V]=1;
                grafo[W][W]=1;
                grafo[V][W]=1;
                grafo[W][V]=1;
            }
        }
        
        int count = search(M);
        printf("%d", count);
    }

    return 0;
}