#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"

GRAFO *criarGrafo(int v)
{
    GRAFO *g = malloc(sizeof(GRAFO));

    g->num_de_vertices = v;
    g->num_de_arestas = 0;
    g->vert = malloc(v * sizeof(VERTICE));

    for (int i = 0; i < v; i++)
        g->vert[i].lda = NULL;

    return g;
}

ADJACENCIA *criarAdjacencia(int v, int peso)
{
    ADJACENCIA *temp = malloc(sizeof(ADJACENCIA));

    temp->vertice = v;
    temp->peso = peso;
    temp->prox = NULL;

    return (temp);
}

int criarAresta(GRAFO *gr, int vertice_inicial, int vertice_final, int p)
{
    if(!gr)
        return (0);
    if((vertice_final < 0) || (vertice_final > gr->num_de_vertices))
        return (0);
    if((vertice_inicial < 0) || (vertice_inicial > gr->num_de_vertices))
        return (0);

    vertice_final--;
    vertice_inicial--;

    ADJACENCIA *novaAdj = criarAdjacencia(vertice_final, p);
    novaAdj->prox = gr->vert[vertice_inicial].lda;
    gr->vert[vertice_inicial].lda = novaAdj;
    gr->num_de_arestas++;

    return(1);
}

void imprimirGrafo(GRAFO *gr)
{
    printf("\n\t Num. de vertices: %d", gr->num_de_vertices);
    printf("\n\t Num. de arestas: %d\n\n", gr->num_de_arestas);

    for (int i = 0; i < gr->num_de_vertices; i++)
    {
        printf("Vertice %d: -> ", i+1);
        ADJACENCIA *ad = gr->vert[i].lda;
        while(ad)
        {
            printf("v%d(%d) -> ", ad->vertice+1, ad->peso);
            ad = ad->prox;
        }

        printf("\n");
    }
}
