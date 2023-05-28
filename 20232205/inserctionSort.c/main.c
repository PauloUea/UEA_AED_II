#include<stdio.h>
#define MAX 20

void imprimir_vetor(int *vet)
{
    int i;
    for (i = 0; i < MAX; i++)
        printf("%d ", vet[i]);
        
    printf("\n");
}

void bubble_sort(int *vet)
{
    int i, j, aux;
    int comps =0, movs = 0;
    
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX-1; j++)
        {
            comps++;
            if(vet[j] > vet[j+1]) //comparações
            {
                aux =  vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;

                movs++;
            }
        }
        
    }

    printf("\n%d comparacoes e %d trocas\n", comps, movs);
    
}

void inserction_sort(int *vet)
{
    int i, j, tmp;
    int comps = 0, movs = 0;

    for(i = 0; i < MAX;i++)
    {
        tmp = vet[i];
        for(j=i-1;j >= 0 && tmp < vet[j];j--)
        {
            comps++;
            movs++;
            vet[j+1] = vet[j];
        }
        vet[j+1] = tmp;
        movs++;
    }
    printf("\n%d comparacoes e %d movimentacoes\n", comps, movs);
}

void selection_sort(int *vet)
{
    int i, j, min, aux;
    int comps = 0, movs = 0;

    for(i = 0;i < MAX; i++)
    {
        min = i;
        for (j = i+1; j < MAX; j++)       
        {
            comps++;
            if(vet[j] < vet[min]) 
                 min = j;
            
        }
        aux = vet[min];
        vet[min] = vet[i];
        vet[i] = aux;
        movs++;
    }
    printf("\n%d comparacoes e %d trocas\n", comps, movs);
}

int main()
{
    int opt = 0;
    int vet[MAX] = {19, 1, 15, 20, 9, 16, 12, 10, 2, 5, 3, 8, 4, 13, 7, 11, 6, 14, 17, 18};
    int asc[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int des[MAX] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};   

    printf("\t Vetores a ordenar: \n");
    imprimir_vetor(vet);
    imprimir_vetor(asc);
    imprimir_vetor(des);

    printf("Qual metodo de ordenacao voce deseja utilizar?\n\t1 - Bubble Sort\n\t2 - Inserction Sort\n\t3 - Selection Sort\n\n");

    scanf("%d", &opt);
    switch (opt)
    {
    case 1:
        printf("Desordenado:\t");
        bubble_sort(vet);
        printf("Ascendente:\t");
        bubble_sort(asc);
        printf("Descendente:\t");
        bubble_sort(des);
        
        break;

    case 2:
        printf("Desordenado:\t");
        inserction_sort(vet);
        printf("Ascendente:\t");
        inserction_sort(asc);
        printf("Descendente:\t");
        inserction_sort(des);
        break;

    case 3:
        printf("Desordenado:\t");
        selection_sort(vet);
        printf("Ascendente:\t");
        selection_sort(asc);
        printf("Descendente:\t");
        selection_sort(des);
        break;
    
    default:
        break;
    }

    printf("\nSaida\n");
    imprimir_vetor(vet);
    imprimir_vetor(asc);
    imprimir_vetor(des);
}