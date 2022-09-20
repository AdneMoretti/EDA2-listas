#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GRAPH_WEIGHT_T int
#define GRAPH_WEIGHT_SUM(a, b) (a + b)
#define GRAPH_WEIGHT_LESS(a, b) (a < b)
#define GRAPH_WEIGHT_INF 2147483647

typedef struct
{
    unsigned from, to;
    GRAPH_WEIGHT_T weight;
} Edge;

typedef struct
{
    GRAPH_WEIGHT_T **edges;
    unsigned V, E;
} Graph;

Graph G_init(unsigned numberOfVertices)
{
    Graph g = {.V = numberOfVertices, .E = 0};
    g.edges = malloc(sizeof(GRAPH_WEIGHT_T *) * g.V);
    for (unsigned i = 0; i < g.V; i++)
    {
        g.edges[i] = malloc(sizeof(GRAPH_WEIGHT_T) * g.V);
        for (unsigned j = 0; j < g.V; j++)
            g.edges[i][j] = GRAPH_WEIGHT_INF;
    }
    return g;
}

void G_free(Graph g)
{
    for (unsigned i = 0; i < g.V; i++)
        free(g.edges[i]);
    free(g.edges);
}

void G_insert(Graph *g, Edge e)
{
    if (e.from > g->V || e.to > g->V)
        return;

    g->E += (g->edges[e.from][e.to] == GRAPH_WEIGHT_INF);
    g->edges[e.from][e.to] = e.weight;
}

int G_numberOfEdges(Graph g)
{
    return g.E;
}

int G_numberOfVertices(Graph g)
{
    return g.V;
}

void G_components(Graph g, int start, int components[])
{
    if (components[start] < 0)
        components[start] = start;
    for (unsigned i = 0; i < g.V; i++)
        if (g.edges[start][i] != GRAPH_WEIGHT_INF && components[i] < 0)
        {
            int mn = ((int)i < components[start] ? (int)i : components[start]);
            components[start] = mn;
            components[i] = mn;
            G_components(g, i, components);
        }
}

void search(Graph g, int transitive[][2001])
{
    for (unsigned i = 0; i < g.V; i++)
    {
        for (unsigned j = 0; j < g.V; j++)
            transitive[i][j] = g.edges[i][j] != GRAPH_WEIGHT_INF;
        transitive[i][i] = 1;
    }

    for (unsigned i = 0; i < g.V; i++)
        for (unsigned j = 0; j < g.V; j++)
            if (transitive[j][i] == 1)
                for (unsigned k = 0; k < g.V; k++)
                    if (transitive[i][k] == 1)
                        transitive[j][k] = 1;
}

int tr[2001][2001];


int main()
{
    int N, M, V, W, P;
    while(scanf(" %d %d", &N, &M)==2 && N!=0){
    Grafo g = G_init(N);
    Edge e;
    for (int i = 0; i < M; i++)
    {
        scanf(" %d %d %d", &e.v, &e.w, &P);
        e.v--, e.w--;
        G_insert(&g, e);
        if (P == 2)
            G_insert(&g, e);
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            tr[i][j] = 0;

    search(g, tr);

    int t = 1;
    for (int i = 0; i < N && t; i++)
        for (int j = 0; j < N && t; j++)
            if (!tr[i][j])
                t = 0;

    printf("%d\n", t);

    }       
    return 0;
}