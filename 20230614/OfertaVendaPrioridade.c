#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura Oferta
typedef struct {
    char nome[50];
    int preco;
} Oferta;

// Inicialização do heap e do tamanho do heap
Oferta heap[10000];
int tamanhoHeap = 0;

// Função de trocar
void trocar(Oferta *a, Oferta *b) {
    Oferta temp = *a;
    *a = *b;
    *b = temp;
}

// Função inserir_novo
void inserir_novo(Oferta oferta) {
    int i = tamanhoHeap++;
    while(i > 0) {
        int p = (i - 1) / 2;
        if(heap[p].preco >= oferta.preco) break;
        heap[i] = heap[p];
        i = p;
    }
    heap[i] = oferta;
}

// Função heapify
void heapify(int i) {
    Oferta oferta = heap[i];
    while(i * 2 + 1 < tamanhoHeap) {
        int a = i * 2 + 1;
        int b = i * 2 + 2;
        if(b < tamanhoHeap && heap[b].preco > heap[a].preco) a = b;
        if(heap[a].preco <= oferta.preco) break;
        heap[i] = heap[a];
        i = a;
    }
    heap[i] = oferta;
}

// Função remover_maximo
void remover_maximo() {
    Oferta melhorOferta = heap[0];
    heap[0] = heap[--tamanhoHeap];
    heapify(0);
    printf("%d %s\n", melhorOferta.preco, melhorOferta.nome);
}

// Função principal
int main() {
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        char evento[10];
        scanf("%s", evento);

        if(strcmp(evento, "OFERTA") == 0) {
            Oferta oferta;
            scanf("%s %d", oferta.nome, &oferta.preco);
            inserir_novo(oferta);
        } else if(strcmp(evento, "VENDA") == 0) {
            remover_maximo();
        }
    }

    return 0;
}
