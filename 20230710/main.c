#include <stdio.h>
#include <stdbool.h>
#define MAX_VERTICES 100
// Estrutura para representar um grafo
struct Graph {
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
};
// Função para inicializar um grafo
void initializeGraph(struct Graph* graph, int numVertices) {
    graph->numVertices = numVertices;
    int i, j;
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
}
// Função para adicionar uma aresta ao grafo
void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}
// Função para imprimir o ciclo hamiltoniano encontrado
void printHamiltonianCycle(int path[], int numVertices) {
    printf("Ciclo Hamiltoniano encontrado: ");
    for (int i = 0; i < numVertices; i++) {
        printf("%d ", path[i]);
    }
    printf("%d\n", path[0]); // Imprimir o primeiro vértice novamente para fechar o ciclo
}
// Função para verificar se o vértice v pode ser adicionado ao caminho atual
bool isSafe(struct Graph* graph, int v, int path[], int pos) {
    if (graph->adjMatrix[path[pos - 1]][v] == 0) { // Verificar se há uma aresta entre o vértice anterior e v
        return false;
    }
    for (int i = 0; i < pos; i++) {
        if (path[i] == v) { // Verificar se o vértice já foi visitado anteriormente
            return false;
        }
    }
    return true;
}
// Função auxiliar recursiva para encontrar o ciclo hamiltoniano
bool hamiltonianCycleUtil(struct Graph* graph, int path[], int pos) {
    if (pos == graph->numVertices) {
        if (graph->adjMatrix[path[pos - 1]][path[0]] == 1) { // Verificar se há uma aresta entre o último vértice e o primeiro
            return true; // Um ciclo hamiltoniano foi encontrado
        } else {
            return false;
        }
    }
    for (int v = 1; v < graph->numVertices; v++) {
        if (isSafe(graph, v, path, pos)) {
            path[pos] = v;
            if (hamiltonianCycleUtil(graph, path, pos + 1) == true) {
                return true;
            }
            path[pos] = -1; // Retroceder
        }
    }
    return false;
}
// Função principal para encontrar um ciclo hamiltoniano no grafo
void findHamiltonianCycle(struct Graph* graph) {
    int path[MAX_VERTICES];
    for (int i = 0; i < graph->numVertices; i++) {
        path[i] = -1; // Inicializar o caminho com -1 (representando que o vértice ainda não foi visitado)
    }
    path[0] = 0; // Começar pelo primeiro vértice
    if (hamiltonianCycleUtil(graph, path, 1) == false) {
        printf("O grafo não possui um ciclo hamiltoniano.\n");
    } else {
        printHamiltonianCycle(path, graph->numVertices);
    }
}
int main() {
    struct Graph graph;
    int numVertices, numEdges, src, dest;

    printf("Digite o número de vértices no grafo: ");
    scanf("%d", &numVertices);

    printf("Digite o número de arestas no grafo: ");
    scanf("%d", &numEdges);

    initializeGraph(&graph, numVertices);

    printf("Digite as arestas no formato (vértice1 vértice2):\n");
    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(&graph, src, dest);
    }

    findHamiltonianCycle(&graph);

    return 0;
}
