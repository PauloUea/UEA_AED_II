#ifndef GRAFOMA_H_INCLUDED
#define GRAFOMA_H_INCLUDED

typedef struct grafo{

    int vertices;
    int arestas;
    int **adj;
}GRAFO;

GRAFO *inicializar_grafo(int v);
int criar_aresta(GRAFO *gr, int vi, int vf);
int excluir_aresta(GRAFO *gr, int vi, int vf);

#endif // GRAFOMA_H_INCLUDED
