#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
// int hash(char s[30], int numcidades) {
//     int h = 0;
//     for (int i = 0; s[i] != '\0'; i++){
//         h = h + s[i]*(i+1);
//     }
//     h = h%5000;
// }
void dfsr(int v, int w, int numcidades){
    pre[w]=cnt++;
    // printf("%d", cnt);
    for(int i=0;i<=numcidades;i++){
        if(grafo[w][i]!=0){
            if(pre[i]==-1) dfsr(w, i, numcidades);
        }
        
    }
}

int search(int numcidades){
    for(int i=0;i<numcidades;i++) pre[i]=-1;
    int count=0, maior=0;
    cnt=0;
    for(int i=0;i<numcidades;i++){
        if(pre[i]==-1){
            dfsr(i, i, numcidades);
            if(cnt>=maior){
                maior=cnt;
            }
            cnt=0;
            count++;
        }
    }
    return maior;
}
int limpa_G(int c){
    for(int i=0;i<c;i++){
        for(int j=0;j<c;j++){
            grafo[i][j]=0;
        }
    }
}

int main(){
    int c, r;
    char v[31], w[31];
    int vh, wh;
    char ch[1];
    char vet_aux[5001][31];
    while(scanf("%d %d", &c, &r)==2){
        limpa_G(c);
        if(c==0 && r==0) break;
        for(int i=0;i<c;i++){
            scanf(" %s", vet_aux[i]);
            // vh = hash(v, c);
            // if(grafo[i][i]==1)
            grafo[i][i]=1;
            // vet_aux[i]=v;
            
        }
        for(int i=0;i<r;i++){
            scanf("%s %s", v, w);
            // vh = hash(v, c);
            // wh = hash(w, c);
            int x = -1, y = -1;
            for (int j = 0; j < c && (x == -1 || y == -1); j++)
            {
                if (x == -1 && strcmp(vet_aux[j], v) == 0)
                    x = j;
                else if (y == -1 && strcmp(vet_aux[j], w) == 0)
                    y = j;
            }
            grafo[x][y]=1;
            grafo[y][x]=1;
        }
        int count = search(c);
        printf("%d\n", count);
        // scanf("%c", ch);
    }
    return 0;
}