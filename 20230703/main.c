#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"

int main()
{
    GRAFO *meuGrafo = criarGrafo(4);

    criarAresta(meuGrafo, 1, 2, 14);
    criarAresta(meuGrafo, 1, 3, 14);
    criarAresta(meuGrafo, 1, 4, 14);
    criarAresta(meuGrafo, 2, 4, 14);
    criarAresta(meuGrafo, 2, 3, 14);

    imprimirGrafo(meuGrafo);

    return 0;
}
