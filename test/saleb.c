#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

void pos_ordem(NO *aux){
    
    if(aux->esq != NULL){
        pos_ordem(aux->esq);
    }
    if(aux->dir != NULL){
        pos_ordem(aux->dir);
    }
    printf("ID: ");
    printf("%d\t", aux->id);
}
void in_ordem(NO *aux){
    
    if(aux->esq != NULL){
        in_ordem(aux->esq);
    }
    printf("ID: ");
    printf("%d", aux->id);
    printf("\t");
    if(aux->dir != NULL){
        in_ordem(aux->dir);
    }
}
void pre_ordem(NO *aux){
    printf("ID: ");
    printf("%d", aux->id);
    printf("\t");
    if(aux->esq != NULL){
        pre_ordem(aux->esq);
    }
    if(aux->dir != NULL){
        pre_ordem(aux->dir);
    }
}

int main() {
  int tam = 7;
  int vetor_de_id[] = {1, 2, 3, 4, 5, 6, 7};

  arvore(raiz_insert,vetor_de_id,0,tam-1);
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