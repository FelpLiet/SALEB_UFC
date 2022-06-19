#include "../include/arvore.h"

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