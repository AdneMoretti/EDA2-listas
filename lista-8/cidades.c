#include <stdio.h>
#include <stdlib.h>
static int pre[5001];
int grafo[5001][5001];

// struct Edge{
//     int v;
//     int w;
// }typedef Edge;

// struct Grafo{
//     int **g;
//     int vertices;
// }typedef Grafo;
int cnt;
void dfsr(int v, int w, int numcidades){
    // pre[w]=cnt++;
    cnt++;
    for(int i=0;i<numcidades;i++){
        if(grafo[w][i]!=0){
            if(pre[i]==-1) dfsr(w, i, numcidades);
        }
        
    }
}

int search(int numcidades){
    for(int i=0;i<numcidades;i++) pre[i]=-1;
    int count=0, cnt=0;
    for(int i=0;i<numcidades;i++){
        if(pre[i]==-1){
            dfsr(i, i, numcidades);
            cnt=0;
            count++;
        }
    }
    return count;
}
int main(){
    int numcidades, v, w;
    scanf("%d", &numcidades);
    while(scanf("%d %d", &v, &w)==2){
        grafo[v][w]=1;
        grafo[w][v]=1;
        grafo[w][w]=1;
        grafo[v][v]=1;
    }
    int count = search(numcidades);
    for(int i=0;i<numcidades;i++) printf("%d", pre[i]);
    printf("%d\n", count);
    return 0;
}