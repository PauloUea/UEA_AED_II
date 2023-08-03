#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Estrutura para representar um grafo direcionado usando representação de lista de adjacência
struct Grafo
{
    int V;     // Número de vértices
    int **adj; // Lista de Adjacência
};

// Função para criar um novo grafo
struct Grafo *criarGrafo(int v)
{
    struct Grafo *grafo = (struct Grafo *)malloc(sizeof(struct Grafo));
    grafo->V = v;
    grafo->adj = (int **)malloc(v * sizeof(int *));
    for (int i = 0; i < v; ++i)
    {
        grafo->adj[i] = (int *)malloc(v * sizeof(int));
        for (int j = 0; j < v; ++j)
            grafo->adj[i][j] = 0;
    }
    return grafo;
}

// Função para adicionar uma aresta ao grafo
void adicionarAresta(struct Grafo *grafo, int v, int w)
{
    grafo->adj[v][w] = 1;
}

// Uma função recursiva para realizar DFS começando do vértice v
void DFSUtil(struct Grafo *grafo, int v, bool *visitado)
{
    // Marca o nó atual como visitado e imprime-o
    visitado[v] = true;
    printf("%d ", v);

    // Recorre por todos os vértices adjacentes a este vértice
    for (int i = 0; i < grafo->V; ++i)
    {
        if (grafo->adj[v][i] == 1 && !visitado[i])
            DFSUtil(grafo, i, visitado);
    }
}

// Função que retorna o transposto deste grafo
struct Grafo *obterTransposto(struct Grafo *grafo)
{
    struct Grafo *grafoTransposto = criarGrafo(grafo->V);
    for (int v = 0; v < grafo->V; v++)
    {
        for (int i = 0; i < grafo->V; i++)
        {
            if (grafo->adj[v][i] == 1)
                adicionarAresta(grafoTransposto, i, v);
        }
    }
    return grafoTransposto;
}

// Uma função para preencher os vértices na pilha de acordo com os tempos de finalização
// A ordem em que os vértices são adicionados à pilha define a ordem de seus tempos de finalização.
void preencherOrdem(struct Grafo *grafo, int v, bool *visitado, int *pilha, int *indicePilha)
{
    // Marca o nó atual como visitado
    visitado[v] = true;

    // Recorre por todos os vértices adjacentes a este vértice
    for (int i = 0; i < grafo->V; i++)
    {
        if (grafo->adj[v][i] == 1 && !visitado[i])
            preencherOrdem(grafo, i, visitado, pilha, indicePilha);
    }

    // Todos os vértices alcançáveis a partir de v foram processados até agora, coloca v na pilha
    pilha[(*indicePilha)++] = v;
}

// A função principal que encontra e imprime todas as componentes fortemente conectadas
void imprimirSCCs(struct Grafo *grafo)
{
    int pilha[grafo->V];
    int indicePilha = 0;

    // Marca todos os vértices como não visitados (Para a primeira DFS)
    bool *visitado = (bool *)malloc(grafo->V * sizeof(bool));
    for (int i = 0; i < grafo->V; i++)
        visitado[i] = false;

    // Preenche os vértices na pilha de acordo com os tempos de finalização
    for (int i = 0; i < grafo->V; i++)
    {
        if (!visitado[i])
            preencherOrdem(grafo, i, visitado, pilha, &indicePilha);
    }

    // Cria um grafo transposto
    struct Grafo *grafoTransposto = obterTransposto(grafo);

    // Marca todos os vértices como não visitados (Para a segunda DFS)
    for (int i = 0; i < grafo->V; i++)
        visitado[i] = false;

    // Agora processa todos os vértices na ordem definida pela pilha
    while (indicePilha > 0)
    {
        // Retira um vértice da pilha
        int v = pilha[--indicePilha];

        // Imprime a componente fortemente conectada do vértice retirado
        if (!visitado[v])
        {
            DFSUtil(grafoTransposto, v, visitado);
            printf("\n");
        }
    }
}

// Função principal
int main()
{
    // Cria um grafo conforme o diagrama acima
    struct Grafo *g = criarGrafo(5);
    adicionarAresta(g, 1, 0);
    adicionarAresta(g, 0, 2);
    adicionarAresta(g, 2, 1);
    adicionarAresta(g, 0, 3);
    adicionarAresta(g, 3, 4);

    printf("As seguintes componentes fortemente conectadas foram encontradas no grafo dado:\n");
    imprimirSCCs(g);

    return 0;
}