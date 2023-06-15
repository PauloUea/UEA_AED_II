#ifndef PACIENTE_H_INCLUDED
#define PACIENTE_H_INCLUDED


#include <stdio.h>

#define MAX 100

struct paciente {
    char nome[50];
    char tel[13];
    int id;
    int grau;
};

typedef struct paciente Paciente;

typedef struct {
    Paciente valor[MAX];
    int num_elem;
} HEAP;

int tam_vetor(HEAP *heap);
void inicializar_heap(HEAP *heap);
void imprimir_paciente(Paciente pac);
void imprimir_heap(HEAP *heap);
Paciente max_prio(HEAP *heap);
void inserir(HEAP *heap, Paciente novo_paciente);
void heapify_up(HEAP *heap, int novo);
Paciente atender_paciente(HEAP *heap);
void heapify_down(HEAP *heap, int i);

#endif // PACIENTE_H_INCLUDED
