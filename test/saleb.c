#include <stdio.h>
#include <stdlib.h>
#include "../include/abb.h"


//bonus por utilizar heap na fila
NO *raiz_insert = NULL;
NO *raiz = NULL;



int main()
{
    int tam = 7;
    int vetor_de_id[] = {1, 2, 3, 4, 5, 6, 7};

    arvore(raiz, raiz_insert, vetor_de_id, 0, tam - 1);
    printf("Pos Ordem:\n");
    pos_ordem(raiz);
    printf("\n\n");
    printf("In Ordem:\n");
    in_ordem(raiz);
    printf("\n\n");
    printf("Pre Ordem:\n");
    pre_ordem(raiz);

    return 0;
};