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
struct Item{
    int qnt;
    int *v;
}
int cnt;
void verifica_onde(){

}
void dfsr(int v, int w, int numcidades){
    cnt++;
    pre[w]=cnt;
    for(int i=0;i<numcidades;i++){
        if(grafo[w][i]!=0){
            if(pre[i]==-1) dfsr(w, i, numcidades);
        }
        
    }
}

int search(int local, int numcidades){
    for(int i=0;i<numcidades;i++) pre[i]=-1;
    int count=0, cnt=0;
    int maior=0, maior_i=0;
    for(int i=0;i<numcidades;i++){
        if(pre[i]==-1){
            dfsr(i, i, numcidades);
            Item *item;
            if(cnt>maior)
                maior = cnt;
                maior_i=i;
            if(cnt==maior){
                if(i==local) maior_i=i;
                else{
                    if(maior_i>i) maior_i=i;
                }
            }
            
            cnt=0;
            count++;
        }
    }
    return maior, maior_i;
}
int main(){
    int numcidades, local,v, w;
    scanf("%d %d", &numcidades, &local);
    while(scanf("%d %d", &v, &w)==2){
        grafo[v][w]=1;
        grafo[w][v]=1;
        grafo[w][w]=1;
        grafo[v][v]=1;
    }
    int maior, maior_i= search(local, numcidades);
    if(local==maior_i && maior==0){
        printf("Fique em casa");
    }
    else if(local==maior_i && maior!=0){
        printf("Bora pra estrada");
    }
    else if(local!=maior_i){
        printf("Vamos para %d", maior_i);
    }
    return 0;
}