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
void inserirAresta(GRAFO* grafo, int origem, int destino, int peso);
void BFS(GRAFO* grafo, int verticeInicial);
int procura_no(float d[], int v[], int verts);
void dijkstra(GRAFO *gr, int no);
void imprimir_int(int *vet, int num);
void imprimir_float(float *vet, int num);
void imprimirGrafo(GRAFO *gr);


#endif // GRAFOS_H_INCLUDED
