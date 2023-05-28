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


void merge(int array[], int inicial, int medio, int final)
{

    int i, j, k;
    int m1 = medio - inicial + 1;
    int m2 = final - medio;

    int MetadeEsquerda[m1];
    int MetadeDireita[m2];

    for(i=0;i < m1; i++)
    {      
        MetadeEsquerda[i] = array[inicial + i];
       
        movs++;
    }

    for(j=0;j < m2;j++)
    {
        
        movs++;
        MetadeDireita[j] = array[medio + 1 + j];
        
    }

    i = 0;
    j = 0;
    k = inicial;

    while (i < m1 && j < m2)
    {
        comps++;
        if(MetadeEsquerda[i] <= MetadeDireita[j])
        {
            
            movs++;
            array[k] = MetadeEsquerda[i];
            i++;
        }
        else
        {
           
            movs++;
            array[k] = MetadeDireita[j];
            j++;
        }
        k++;

    }
    while (i < m1)
    {
       
        movs++;
        array[k] = MetadeEsquerda[i];
        i++;
        k++;
    }
    while (j < m2 )
    {
    
        array[k] = MetadeDireita[j];
        
        movs++;
        
        j++;
        k++;
    }
}

void mergeSort(int array[], int inicio, int fim)
{
    if(inicio < fim)
    {
        int medio = inicio + (fim - inicio)/2;
        mergeSort(array, inicio, medio);
        mergeSort(array, medio+1, fim);
        merge(array, inicio, medio, fim);
    }
   
    
}

int main()
{
    printf("Vetores a ordenar:  \n");
    int vet[MAX] = {19, 1, 15, 20, 9, 16, 12, 10, 2, 5, 3, 8, 4, 13, 7, 11, 6, 14, 17, 18};
    int asc[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int des[MAX] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    imprimir(vet);
    imprimir(asc);
    imprimir(des);

    printf("Desordenado:\n");
    mergeSort(vet, 0, MAX);
    printf("%d comparacoes e %d movimentacoes\n", comps, movs);
    comps = 0;
    movs = 0;
    printf("Saida:\t");
    imprimir(vet);

    printf("Ascendente:\n");
    mergeSort(asc, 0, MAX-1);
    printf("%d comparacoes e %d movimentacoes\n", comps, movs);
    comps = 0;
    movs = 0;
    printf("Saida:\t");
    imprimir(asc);

    printf("Descendente:\n");
    mergeSort(des, 0, MAX-1);
    printf("%d comparacoes e %d movimentacoes\n", comps, movs);
    comps = 0;
    movs = 0;
    printf("Saida:\t");
    imprimir(des);
    

    return 0;
}


