#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"

int main()
{

    GRAFO *meuGrafo = criarGrafo(4);

    int vet[4];

    criarAresta(meuGrafo, 0, 2, 14);
    criarAresta(meuGrafo, 0, 3, 10);
    criarAresta(meuGrafo, 1, 3, 11);
    criarAresta(meuGrafo, 2, 1, 15);
    criarAresta(meuGrafo, 3, 2, 12);

    imprimirGrafo(meuGrafo);

    busca_dfs(meuGrafo, 0, vet);

    printf("\n");

    BFS(meuGrafo, 0);

    printf("\n");

    dijkstra(meuGrafo, 1);

    return 0;
}
