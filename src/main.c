#include <stdio.h>
#include <stdlib.h>

typedef struct NO {
  int id;

  struct NO* esq;
  struct NO* dir;
} NO;

NO *raiz_insert = NULL;
NO *raiz = NULL;
int tamp_temp = 0;

NO* buscaRecursiva(NO *no, int id) {
  if (no == NULL)
    return NULL;
  else if (no->id == id)
    return no;
  else if (no->id > id)
    return buscaRecursiva(no->esq, id);
  else
    return buscaRecursiva(no->dir, id);
}

NO *insere_na_arvore(NO *no, int id) {
  if (no == NULL){
    no = (NO *) malloc(sizeof(NO));
    no->id = id;
    no->esq = NULL;
    no->dir = NULL;
    tamp_temp++;
  }else if(id < (no->id)){
    no->esq = insere_na_arvore(no->esq, id);
  }else if(id > (no->id)){
    no->dir = insere_na_arvore(no->dir, id);
  }else{
    printf("Inserção inválida! "); // id já existe
    exit(1);
  }
  return no;
}

void arvore(NO *raiz_insert, int vetor_de_id[], int inicio, int fim) {
  if (inicio <= fim) {
    int meio = (inicio + fim) / 2;
    raiz_insert = insere_na_arvore(raiz_insert, vetor_de_id[meio]);
    if(raiz == NULL){
      raiz = raiz_insert;
    }

    arvore(raiz_insert, vetor_de_id, inicio, meio - 1);
    arvore(raiz_insert, vetor_de_id, meio + 1, fim);
  }
}

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