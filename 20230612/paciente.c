#include <stdio.h>
#include "paciente.h"

int tam_vetor(HEAP *heap)
{
    return heap->num_elem;
}

void inicializar_heap(HEAP *heap)
{
    heap->num_elem = 0;
}

void imprimir_paciente(Paciente pac)
{
    printf(" Ficha do Paciente n° %d: \nID: %d\nNome: %s\nPrioridade: %d\nTelefone: %s\n\n",pac.id, pac.id, pac.nome, pac.grau, pac.tel);
}

void imprimir_heap(HEAP *heap)
{
    for (int i = 0; i < heap->num_elem; i++)
        imprimir_paciente(heap->valor[i]);
}

Paciente max_prio(HEAP *heap)
{
    return heap->valor[0];
}

void inserir(HEAP *heap, Paciente novo_paciente)
{
    heap->num_elem++;
    heap->valor[heap->num_elem - 1] = novo_paciente;
    heapify_up(heap, heap->num_elem);
}

void heapify_up(HEAP *heap, int novo)
{
    int i = novo;
    Paciente aux;

    while (i >= 2 && heap->valor[(i / 2) - 1].grau < heap->valor[i - 1].grau)
    {
        aux = heap->valor[(i / 2) - 1];
        heap->valor[(i / 2) - 1] = heap->valor[i - 1];
        heap->valor[i - 1] = aux;
    }
}

Paciente atender_paciente(HEAP *heap)
{
    Paciente maximo = heap->valor[0];
    heap->valor[0] = heap->valor[heap->num_elem - 1];
    heap->num_elem--;
    heapify_down(heap, 1);

    return maximo;
}

void heapify_down(HEAP *heap, int i)
{
    int l = 2*i - 1;
    int r = 2*1;
    int m = i-1;

    Paciente temp;

    if(l < heap->num_elem - 1 && heap->valor[l].grau > heap->valor[m].grau)
        m = l;
    if(r < heap->num_elem - 1 && heap->valor[r].grau > heap->valor[m].grau)
        m = r;
    if(m != i - 1)
    {
        temp = heap->valor[i-1];
        heap->valor[i-1] = heap->valor[m];
        heap->valor[m] = temp;
    }

}
