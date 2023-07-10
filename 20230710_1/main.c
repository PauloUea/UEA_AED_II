#include <stdio.h>
#include <stdlib.h>
#include "grafoMA.h"

int main()
{
    GRAFO *meuGrafo = inicializar_grafo(5);

    imprimir_grafoMA(meuGrafo);

    criar_aresta(meuGrafo, 1, 0);
    criar_aresta(meuGrafo, 1, 2);
    criar_aresta(meuGrafo, 2, 0);
    criar_aresta(meuGrafo, 2, 4);
    criar_aresta(meuGrafo, 3, 1);
    criar_aresta(meuGrafo, 4, 3);

    printf("\n\n");

    imprimir_grafoMA(meuGrafo);

    excluir_aresta(meuGrafo, 3, 1);

    printf("\n\n");

    imprimir_grafoMA(meuGrafo);
    printf("\n\n");
    printf("Arestas: "); imprimir_arestas(meuGrafo);


    return 0;
}
