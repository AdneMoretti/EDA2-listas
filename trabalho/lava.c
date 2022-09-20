#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


typedef struct node *no;
#define INT_MAX 2147483647

struct node
{
    int dado;
    no prox;
    int c;
};

typedef struct
{
    int v, w, peso;
} Edge;

typedef struct
{
    no *g;
    int V, E;
} *Graph;

typedef struct{
    int x, y;
} coordenada;

int calcula_hash(int x, int y){
    int h = x + y*y;
    return h;
}

Edge EDGE(int v, int w, int c){
    Edge EDGE;
    EDGE.v = v;
    EDGE.w = w;
    EDGE.peso = c;
    return EDGE;
};
void menor_caminho(Graph G, int s, int *pa, int *dist){
    bool mature[1000];
    for(int v = 0; v < G->V; v++){
        pa[v]=-1; mature[v]=false; dist[v]=INT_MAX;
    }
    pa[s] = 1; dist[s]=0;
    while(true){
        int min = INT_MAX;
        int y;
        for(int z = 0; z < G->V; z++){
            if(mature[z]) continue;
            if(dist[z] < min){
                min = dist[z];
                y = z;
            }
        }
        if(min == INT_MAX) break;
        for(no a = G->g[y]; a!=NULL; a=a->prox){
            if(mature[a->dado]) continue;
            if(dist[y] + a->c < dist[a->dado]){
                dist[a->dado] = dist[y] + a->c;
                pa[a->dado] = y;
            }
        }
        mature[y] = true;
    }
}

// void menor_caminho(Graph G, int s, int *pa, int *dst){
//     bool mature[G->V];
//     for(int v=0;v<G->V; v++){
//         pa[v]=-1, mature[v]=false, dst[v]=INT_MAX;
//     }
//     pa[s]=s; dst[s]=0;
//     while(true){
//         int min=INT_MAX;
//         int y;
//         for(int z=0;z<G->V;z++){
//             if(mature[z]) continue;
//             if(dst[z]<min)
//                 min = dst[z], y=z;
//         }
//         if(min==INT_MAX) break;
//         for(no a = G->g[y]; a!=NULL; a=a->prox){
//             if(mature[a->dado]) continue;
//             if(dst[y]+a->c<dst[a->dado]){
//                 dst[a->dado]=dst[y]+a->c;
//                 pa[a->dado]=y;
//             }
//         }
//         mature[y]=true;
//     }
// }

Graph init_graph(int v){
    Graph G = malloc(sizeof(G));
    G->V = v; 
    G->E=0;
    G->g=malloc(v*sizeof(no));
    for(int i=0; i<v;i++){
        G->g[i] = NULL;
    }
    return G;
}

no new(int v, no next, int peso){
    // no x = malloc(sizeof*x);
    no x = next;
    x->dado = v; 
    x->prox = next;
    x->c = peso;
    return x;
}

void insert_graph(Graph G, Edge e){
    int v=e.v, w=e.w, c=e.peso;
    G->g[v] = new(w, G->g[v], c);
    G->g[w] = new(v, G->g[w], c);
    G->E++;
}

int main(){
    int N,M,S,T,B;
    scanf("%d %d", &N, &M);
    Graph PONTES = init_graph(N+2);
    int *pa = malloc(sizeof(int)*N+2);
	int *dist = malloc(sizeof(int)*N+2);

    for(int i = 0; i<M; i++){
        scanf("%d %d %d", &S, &T, &B);
        insert_graph(PONTES, EDGE(S, T, B));
    }

    menor_caminho(PONTES, 0, pa, dist);
    printf("%d\n", dist[N+1]);

    // int passo, n;
    // scanf("%d %d", &passo, &n);
    // Graph g = init_graph(n+2);
    // coordenada *coord = malloc(sizeof(coordenada)*n);
    // scanf("%d %d", &coord[0].x, &coord[0].y);
    // scanf("%d %d", &coord[1].x, &coord[1].y);
    // for(int i=2;i<n;i++){
    //     scanf("%d %d", &coord[i].x, &coord[i].y);
    // }
    // Edge e;
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){
    //         int dx = coord[i].x - coord[j].x;
    //         int dy = coord[i].y - coord[j].y;
    //         int d = sqrt((dx*dx)+dy*dy);
    //         if(d<=passo){            
    //             int v= calcula_hash(coord[i].x,coord[i].y);
    //             int w = calcula_hash(coord[j].x,coord[j].y);
    //             int peso = d;
    //             insert_graph(g, EDGE(v, w,peso));           
    //         }
    //     }
    // }
    // int *pa = malloc(sizeof(int)*n+2);
    // int *dst = malloc(sizeof(int)*n+2);
    // int h = calcula_hash(coord[0].x, coord[0].y);
    // menor_caminho(g, h, pa, dst);
    // h = calcula_hash(coord[1].x, coord[1].y);
    // printf("%d", dst[h]);
    // return 0;
}