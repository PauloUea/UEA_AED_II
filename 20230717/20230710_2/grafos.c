#include <stdio.h>
#include <stdlib.h>
#include<math.h>
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
        printf("Vertice %d: -> ", i);
        ADJACENCIA *ad = gr->vert[i].lda;
        while(ad)
        {
            printf("v%d(%d) -> ", ad->vertice, ad->peso);
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

    printf("\nBusca em Largura (BFS): ");

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

int procura_no(float d[], int v[], int verts)
{
    float min_dist = INFINITY;

    int min_no = -1;
    for (int i = 0; i<verts ;i++)
    {
        if(v[i] == 0 && min_dist > d[i])
        {
            min_dist = d[i];
            min_no = i;
        }
    }

    return min_no;
}

void dijkstra(GRAFO *gr, int no)
{
    float dist[gr->num_de_vertices];
    int visit[gr->num_de_vertices];
    int pred[gr->num_de_vertices];

    int no_trab;

    for(int i = 0; i<gr->num_de_vertices; i++)
    {
        dist[i] = INFINITY;
        visit[i] = 0;
    }
    dist[no] = 0;
    pred[no] = no;
    no_trab = procura_no(dist, visit, gr->num_de_vertices);

    while(no_trab != -1)
    {
        visit[no_trab] = 1;

        ADJACENCIA *ad = gr->vert[no_trab].lda;
        printf("%d", no_trab);

        while(ad)
        {
            if(visit[ad->vertice] == 0 && ((dist[no_trab] + ad->peso) < dist[ad->vertice]))
            {
                dist[ad->vertice] = dist[no_trab] + ad->peso;
                pred[ad->vertice] = no_trab;
            }
            ad = ad->prox;
        }
        no_trab = procura_no(dist, visit, gr->num_de_vertices);
    }

    imprimir_int(pred, gr->num_de_vertices);
    imprimir_float(dist, gr->num_de_vertices);
}

void imprimir_int(int *vet, int num)
{
    for(int i = 0; i < num; i++)
    {
        printf("%d ",vet[i]);
    }
    printf("\n");
}

void imprimir_float(float *vet, int num)
{
    for(int i = 0; i < num; i++)
    {
        printf("%.2f ",vet[i]);
    }
    printf("\n");
}
