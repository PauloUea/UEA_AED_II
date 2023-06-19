#include <stdio.h>
#define MAX 5

int calcular_num_permutacoes(int *arr)
{
    int n = MAX;
    int f = 1;

    for(int i = 1; i <= n; i++)
        f *= i;

    return f;
}

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void imprimir_vetor(int *arr)
{
    for (int i = 0; i < MAX; i++) {
        printf("%d ", arr[i]);
    }
}

void permutacao(int arr[], int inicio, int fim)
{
    if (inicio == fim) {

        imprimir_vetor(arr);
        printf("\n");
    }
    else {
        for (int i = inicio; i <= fim; i++) {
            trocar(&arr[inicio], &arr[i]);
            permutacao(arr, inicio + 1, fim);
            trocar(&arr[inicio], &arr[i]); // backtrack
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};

    printf("Permutacoes : \n");
    permutacao(arr, 0, MAX - 1);

     printf("Numero de permutacoes : %d\n", calcular_num_permutacoes(arr));

    return 0;
}
