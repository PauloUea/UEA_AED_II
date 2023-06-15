#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paciente.h"

int main()
{
    HEAP filadeprioridade;
    Paciente p1, p2, p3;

    strcpy(p1.nome, "Joao");
    strcpy(p1.tel, "(92)99296-2770");
    p1.grau = 3;
    p1.id = 1;

    strcpy(p2.nome, "Maria");
    strcpy(p2.tel, "(92)99194-4799");
    p2.grau = 4;
    p2.id = 2;

    strcpy(p3.nome, "Alberto");
    strcpy(p3.tel, "(92)98405-7045");
    p3.grau = 5;
    p3.id = 3;

    inicializar_heap(&filadeprioridade);

    inserir(&filadeprioridade, p1);
    inserir(&filadeprioridade, p2);
    inserir(&filadeprioridade, p3);

    atender_paciente(&filadeprioridade);
    imprimir_heap(&filadeprioridade);

    return 0;
}
