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

void busca_dfs(GRAFO *gr, int num, int visitados[])
{
    visitados[num] = 1;

    printf("vertice %d visitado\n", num);

    ADJACENCIA *ad = gr->vert[num].lda;

    while(ad)
    {
        if(visitados[ad->vertice] == 0)
        {
            busca_dfs(gr, ad->vertice, visitados);
        }
        ad = ad->prox;
    }
    printf("A busca terminou no vertice %d", num);
}

FILA* criarFila() {
    FILA* fila = (FILA*)malloc(sizeof(FILA));
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

int filaVazia(FILA* fila) {
    return (fila->inicio == NULL);
}

void enfileirar(FILA* fila, int vertice) {
    NO* novoNo = (NO*)malloc(sizeof(NO));
    novoNo->vertice = vertice;
    novoNo->prox = NULL;
    if (filaVazia(fila)) {
        fila->inicio = novoNo;
        fila->fim = novoNo;
    } else {
        fila->fim->prox = novoNo;
        fila->fim = novoNo;
    }
}

int desenfileirar(FILA* fila) {
    if (filaVazia(fila)) {
        printf("Erro: Fila vazia!\n");
        return -1;
    } else {
        NO* noRemovido = fila->inicio;
        int vertice = noRemovido->vertice;
        fila->inicio = fila->inicio->prox;
        if (fila->inicio == NULL)
            fila->fim = NULL;
        free(noRemovido);
        return vertice;
    }
}

GRAFO* criarGrafo(int numVertices, int numArestas) {
    int i;
    GRAFO* grafo = (GRAFO*)malloc(sizeof(GRAFO));
    grafo->num_de_vertices = numVertices;
    grafo->num_de_arestas = numArestas;
    grafo->vert = (VERTICE*)malloc(numVertices * sizeof(VERTICE));
    for (i = 0; i < numVertices; i++)
        grafo->vert[i].lda = NULL;
    return grafo;
}

void inserirAresta(GRAFO* grafo, int origem, int destino, int peso) {
    ADJACENCIA* novaAresta = (ADJACENCIA*)malloc(sizeof(ADJACENCIA));
    novaAresta->vertice = destino;
    novaAresta->peso = peso;
    novaAresta->prox = grafo->vert[origem].lda;
    grafo->vert[origem].lda = novaAresta;
}

void BFS(GRAFO* grafo, int verticeInicial) {
    FILA* fila = criarFila();
    int* visitado = (int*)calloc(grafo->num_de_vertices, sizeof(int));

    visitado[verticeInicial] = 1;
    enfileirar(fila, verticeInicial);

    printf("Busca em Largura (BFS): ");

    while (!filaVazia(fila)) {
        int verticeAtual = desenfileirar(fila);
        printf("%d ", verticeAtual);

        ADJACENCIA* adj = grafo->vert[verticeAtual].lda;
        while (adj != NULL) {
            int verticeAdjacente = adj->vertice;
            if (!visitado[verticeAdjacente]) {
                visitado[verticeAdjacente] = 1;
                enfileirar(fila, verticeAdjacente);
            }
            adj = adj->prox;
        }
    }

    printf("\n");
    free(fila);
    free(visitado);
}
