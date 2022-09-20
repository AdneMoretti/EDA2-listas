#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int v, w;
} Edge;

typedef struct
{
    int **aresta;
    int V, E;
} Grafo;

Grafo G_init(int numRuas)
{
    Grafo graf;
    graf.V = numRuas;
    graf.E = 0; 
    graf.aresta = malloc(sizeof(int *) * graf.V);
    for (int i = 0; i < graf.V; i++)
    {
        graf.aresta[i] = malloc(sizeof(int) * graf.V);
        for (int j = 0; j < graf.V; j++)
            graf.aresta[i][j] = -1;
    }
    return graf;
}


void G_insert(Grafo *g, Edge e)
{
    g->aresta[e.v][e.w] = 1;
}


void search(Grafo g, int pre[][2001])
{
    for (int i = 0; i < g.V; i++)
    {
        for (int j = 0; j < g.V; j++)
            pre[i][j] = g.aresta[i][j] != -1;
        pre[i][i] = 1;
    }

    for (int i = 0; i < g.V; i++)
        for (int j = 0; j < g.V; j++)
            if (pre[j][i] == 1)
                for (int k = 0; k < g.V; k++)
                    if (pre[i][k] == 1)
                        pre[j][k] = 1;
}

int pre[2001][2001];
void G_free(Grafo g)
{
    for (int i = 0; i < g.V; i++)
        free(g.aresta[i]);
    free(g.aresta);
}

int main()
{
    int N, M, V, W, P;
    while(scanf(" %d %d", &N, &M)==2 && N!=0){
        Grafo g = G_init(N);
        Edge e;

        for (int i = 0; i < M; i++)
        {
            scanf(" %d %d %d", &V, &W, &P);
            V--, W--;
            e.v = V;
            e.w = W;
            G_insert(&g, e);
            if (P == 2)
                e.v = W;
                e.w = V;
                G_insert(&g, e);
        }

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                pre[i][j] = 0;

        search(g, pre);
        G_free(g);

        int t = 1;
        for (int i = 0; i < N && t; i++)
            for (int j = 0; j < N && t; j++)
                if (!pre[i][j])
                    t = 0;

        printf("%d\n", t);

    }       
    return 0;
}
