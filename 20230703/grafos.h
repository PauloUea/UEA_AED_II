#ifndef GRAFOS_H_INCLUDED
#define GRAFOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct adjacencia{

    int vertice;
    int peso;
    struct adjacencia *prox;
}ADJACENCIA;

typedef struct vertice{

    ADJACENCIA *lda;
}VERTICE;

typedef struct grafo{

    int num_de_vertices;
    int num_de_arestas;
    VERTICE *vert;
}GRAFO;

GRAFO *criarGrafo(int v);
ADJACENCIA *criarListaAdjacencia(int v, int peso);
int criarAresta(GRAFO *gr, int vertice_inicial, int vertice_final, int p);


#endif // GRAFOS_H_INCLUDED
