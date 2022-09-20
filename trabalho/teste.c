#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>

typedef struct node *link;
static int count, aux[1000];

struct node{
    int v; 
    link prox;
    int c;
};

typedef struct{
    int v;
    int w;
    int peso;
} Edge;

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

typedef struct graph *Graph;

struct graph{
    int V;
    int E; 
    link *adj;
};

link NEW(int v, link prox, int c){
    link m = malloc(sizeof*m);
    m->v=v; 
    m->prox=prox; 
    m-> c = c;
    return m;
}

Graph GRAPHinit(int v){
    Graph G=malloc(sizeof(*G));
    G->V=v; G->E=0;
    G->adj=malloc(v*sizeof(link));
    for(int i=0; i<v;i++){
        G->adj[i] = NULL;
    }
    return G;
}

void GRAPHInsertE(Graph G, Edge e){
    int v = e.v;
    int w=e.w;
    int c = e.peso;
    G->adj[v] = NEW(w,G->adj[v],c);
    G->adj[w]= NEW(v,G->adj[w],c);
    G->E++;
}

//versao ingenua
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
        for(link a = G->adj[y]; a!=NULL; a=a->prox){
            if(mature[a->v]) continue;
            if(dist[y] + a->c < dist[a->v]){
                dist[a->v] = dist[y] + a->c;
                pa[a->v] = y;
            }
        }
        mature[y] = true;
    }
}


int main(){
    int passo, n;
    scanf("%d %d", &passo, &n);
    Graph g = GRAPHinit(n+2);
    coordenada *coord = malloc(sizeof(coordenada)*n);
    scanf("%d %d", &coord[0].x, &coord[0].y);
    scanf("%d %d", &coord[1].x, &coord[1].y);
    for(int i=2;i<n;i++){
        scanf("%d %d", &coord[i].x, &coord[i].y);
    }
    Edge e;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int dx = coord[i].x - coord[j].x;
            int dy = coord[i].y - coord[j].y;
            int d = sqrt((dx*dx)+dy*dy);
            if(d<=passo){            
                int v= calcula_hash(coord[i].x,coord[i].y);
                int w = calcula_hash(coord[j].x,coord[j].y);
                int peso = d;
                GRAPHInsertE(g, EDGE(v, w, peso));           
            }
        }
    }
    int *pa = malloc(sizeof(int)*n+2);
    int *dst = malloc(sizeof(int)*n+2);
    int h = calcula_hash(coord[0].x, coord[0].y);
    menor_caminho(g, h, pa, dst);
    h = calcula_hash(coord[1].x, coord[1].y);
    printf("%d", dst[h]);
    return 0;
}