#include <stdio.h>
#include <stdlib.h>
static int pre[2001];
int grafo[2001][2001];
int num, num2;

void insere_arestas(int N){
    for(int i=0;i<N;i++){
        scanf("%d", &num);
        grafo[i][i]=1;
        for(int j=0;j<num;j++){
            scanf("%d", &num2);
            grafo[i][num2]=1;
        }
    }
}
int main(){
    int N, M, J;
    scanf("%d %d %d", &N, &M, &J);
    insere_arestas(N);
    for(int i=0;i<M;i++){
        scanf("%d", &num);
        for(int j=0;j<N;j++){
            if(grafo[num][j]==1){
                pre[j]=1;
            }
        }
    }
    for(int i=0;i<J;i++){
        scanf("%d", &num);
        if(pre[num]!=1) printf("Nao vou estar la\n");
        else printf("Eu vou estar la\n");
    }
    return 0;
}
