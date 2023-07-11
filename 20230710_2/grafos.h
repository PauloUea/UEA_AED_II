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

typedef struct no{
    int vertice;
    struct no* prox;
} NO;

typedef struct fila{
    NO* inicio;
    NO* fim;
} FILA;

GRAFO *criarGrafo(int v);
ADJACENCIA *criarListaAdjacencia(int v, int peso);
int criarAresta(GRAFO *gr, int vertice_inicial, int vertice_final, int p);
void busca_dfs(GRAFO *gr, int num, int visitados[]);
FILA* criarFila();
int filaVazia(FILA* fila);
void enfileirar(FILA* fila, int vertice);
int desenfileirar(FILA* fila);
GRAFO* criarGrafo(int numVertices, int numArestas);
void inserirAresta(GRAFO* grafo, int origem, int destino, int peso);
void BFS(GRAFO* grafo, int verticeInicial);


#endif // GRAFOS_H_INCLUDED
