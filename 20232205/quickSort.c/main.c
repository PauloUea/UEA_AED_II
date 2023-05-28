#include<stdio.h>
#define MAX 20

int comps = 0, movs = 0;

void imprimir(int vetor[])
{
    int i = 0;
    for(i = 0;i < MAX;i++)
        printf("%d ", vetor[i]);

    printf("\n");
}

int partition(int vet[], int inicial, int final)
{
    int tmp;
    int pivo = vet[final];

    int i = (inicial - 1);

    for (int j = inicial; j <= final-1;j++)
    {   
        comps++;
        if(vet[j] <= pivo)
        {
            i++;
            tmp = vet[i];
            vet[i] = vet[j];
            vet[j] = tmp;
            movs++;
        }

    }
    tmp = vet[i+1];
    vet[i+1] = vet[final];
    vet[final] = tmp;
    movs++;

    return(i+1);

}

void quicksort(int vet[], int inicial, int final)
{
    if(inicial < final)
    {
        int q = partition(vet, inicial, final);
        quicksort(vet, inicial, q-1);
        quicksort(vet, q+1, final);
    }
}

int main()
{
    int vet[MAX] = {19, 1, 15, 20, 9, 16, 12, 10, 2, 5, 3, 8, 4, 13, 7, 11, 6, 14, 17, 18};
    int asc[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int des[MAX] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    printf("Vetores a ordenar:  \n");
    imprimir(vet);
    imprimir(asc);
    imprimir(des);

    printf("\nDesordenado:\n");
    quicksort(vet, 0, MAX);
    printf("%d comparacoes e %d movimentacoes\n", comps, movs);
    comps = 0;
    movs = 0;
    printf("Saida:\t");
    imprimir(vet);

    printf("\nAscendente:\n");
    quicksort(asc, 0, MAX-1);
    printf("%d comparacoes e %d movimentacoes\n", comps, movs);
    comps = 0;
    movs = 0;
    printf("Saida:\t");
    imprimir(asc);

    printf("\nDescendente:\n");
    quicksort(des, 0, MAX-1);
    printf("%d comparacoes e %d movimentacoes\n", comps, movs);
    comps = 0;
    movs = 0;
    printf("Saida:\t");
    imprimir(des);

    return 0;

}