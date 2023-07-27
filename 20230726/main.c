#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aresta
{
    int src, dest, peso;
} Aresta;

typedef struct Grafo
{
    int V, E;
    Aresta *aresta;
} Grafo;

Grafo *criaGrafo(int V, int E)
{
    Grafo *grafo = malloc(sizeof(Grafo));
    grafo->V = V;
    grafo->E = E;
    grafo->aresta = malloc(sizeof(Aresta) * E);
    return grafo;
}

typedef struct conjunto
{
    int pai;
    int classificacao;
} conjunto;

int encontra(conjunto conjuntos[], int i)
{
    if (conjuntos[i].pai != i)
        conjuntos[i].pai = encontra(conjuntos, conjuntos[i].pai);
    return conjuntos[i].pai;
}

void uniao(conjunto conjuntos[], int x, int y)
{
    int raizX = encontra(conjuntos, x);
    int raizY = encontra(conjuntos, y);
    if (conjuntos[raizX].classificacao < conjuntos[raizY].classificacao)
        conjuntos[raizX].pai = raizY;
    else if (conjuntos[raizX].classificacao > conjuntos[raizY].classificacao)
        conjuntos[raizY].pai = raizX;
    else
    {
        conjuntos[raizY].pai = raizX;
        conjuntos[raizX].classificacao++;
    }
}

int minhaComp(const void *a, const void *b)
{
    Aresta *a1 = (Aresta *)a;
    Aresta *b1 = (Aresta *)b;
    return a1->peso > b1->peso;
}

void KruskalMST(Grafo *grafo)
{
    int V = grafo->V;
    Aresta resultado[V];
    qsort(grafo->aresta, grafo->E, sizeof(grafo->aresta[0]), minhaComp);
    conjunto *conjuntos = (conjunto *)malloc(V * sizeof(conjunto));

    for (int v = 0; v < V; ++v)
    {
        conjuntos[v].pai = v;
        conjuntos[v].classificacao = 0;
    }

    int e = 0;
    int i = 0;

    while (e < V - 1 && i < grafo->E)
    {
        Aresta prox_aresta = grafo->aresta[i++];
        int x = encontra(conjuntos, prox_aresta.src);
        int y = encontra(conjuntos, prox_aresta.dest);
        if (x != y)
        {
            resultado[e++] = prox_aresta;
            uniao(conjuntos, x, y);
        }
    }

    printf("Seguem as arestas na AGM construída\n");
    for (i = 0; i < e; ++i)
        printf("%d -- %d == %d\n", resultado[i].src, resultado[i].dest,
               resultado[i].peso);
    return;
}

int main()
{
    /* Definindo um grafo específico */
    int V = 4; // Número de vértices no grafo
    int E = 5; // Número de arestas no grafo
    Grafo *grafo = criaGrafo(V, E);

    // adiciona aresta 0-1
    grafo->aresta[0].src = 0;
    grafo->aresta[0].dest = 1;
    grafo->aresta[0].peso = 10;

    // adiciona aresta 0-2
    grafo->aresta[1].src = 0;
    grafo->aresta[1].dest = 2;
    grafo->aresta[1].peso = 6;

    // adiciona aresta 0-3
    grafo->aresta[2].src = 0;
    grafo->aresta[2].dest = 3;
    grafo->aresta[2].peso = 5;

    // adiciona aresta 1-3
    grafo->aresta[3].src = 1;
    grafo->aresta[3].dest = 3;
    grafo->aresta[3].peso = 15;

    // adiciona aresta 2-3
    grafo->aresta[4].src = 2;
    grafo->aresta[4].dest = 3;
    grafo->aresta[4].peso = 4;

    KruskalMST(grafo);

    return 0;
}