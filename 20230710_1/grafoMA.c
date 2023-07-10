#include <stdio.h>
#include <stdlib.h>
#include "grafoMA.h"

GRAFO *inicializar_grafo(int v)
{
    GRAFO *gr = malloc(sizeof(GRAFO));

    gr->vertices = v;
    gr->arestas = 0;

    gr->adj = malloc(sizeof(int*) * v);
    for(int i = 0;i < v;i++)
        gr->adj[i] = malloc(sizeof(int) * v);
    for(int i = 0;i < v;i++)
        for(int j = 0;j < v;j++)
            gr->adj[i][j] = 0;

    return gr;
}

int criar_aresta(GRAFO *gr, int vi, int vf)
{
    if(!gr) return(0);
    if((vf < 0) || (vf >= gr->vertices))
        return (0);
    if((vi < 0) || (vi >= gr->vertices))
        return (0);

    if(gr->adj[vi][vf] == 0)
    {
        gr->adj[vi][vf] = 1;
        gr->arestas++;
    }
    return 1;
}

int excluir_aresta(GRAFO *gr, int vi, int vf)
{
    if(!gr) return(0);
    if((vf < 0) || (vf >= gr->vertices))
        return (0);
    if((vi < 0) || (vi >= gr->vertices))
        return (0);

    if(gr->adj[vi][vf] == 1)
    {
        gr->adj[vi][vf] = 0;
        gr->arestas--;
    }
    return 1;
}

void imprimir_grafoMA(GRAFO *gr)
{
    for(int i = 0; i <gr->vertices; i++)
    {
        printf("\nvertice %d:", i);
        for(int j = 0; j < gr->vertices; j++)
        {
            printf(" %d", gr->adj[i][j]);
        }
    }
}

void imprimir_arestas(GRAFO *gr)
{
    for (int i = 0; i < gr->vertices;i++)
        for(int j = 0;j < gr->vertices;j++)
            if(gr->adj[i][j] == 1)
                printf(" <%d, %d>", i, j);

}
