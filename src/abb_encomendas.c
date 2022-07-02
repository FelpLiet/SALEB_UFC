#include "../include/abb_encomendas.h"

int tamp_temp = 0;


no_encomenda *insere_na_arvore(no_encomenda *no, int id) {

  list *aux = inicio; //add a a struct lista

  if (no == NULL){

    no = (no_encomenda *) malloc(sizeof(no_encomenda));

    no->id = id;

    if(aux->id < id){

      while (aux->id < id){

        aux = aux->prox;

      }  

    }

    no->nome_aluno = aux->nome_aluno;

    no->esq = NULL;

    no->dir = NULL;

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



//busca o valor para depois chamar : incere_na_arvore

void arvore(no_encomenda *raiz, no_encomenda *raiz_insert, int vetor_de_id[], int inicio, int fim) {

  if (inicio <= fim) {

    int meio = (inicio + fim) / 2;

    raiz_insert = insere_na_arvore(raiz_insert, vetor_de_id[meio]);

    if(raiz == NULL){

      raiz = raiz_insert;

    }



    arvore(raiz, raiz_insert, vetor_de_id, inicio, meio - 1);

    arvore(raiz, raiz_insert, vetor_de_id, meio + 1, fim);

  }

}



//remove da arvore

no_encomenda *abb_remove(no_encomenda *r, int v){

  if(r == NULL){

    return NULL;

  }else if(r->id > v){

    r->esq = abb_remove(r->esq, v);

  }else if(r->id < v){

    r->dir = abb_remove(r->dir, v);

  }else{

    if(r->esq == NULL && r->dir == NULL){
      free(r);

      r = NULL;

    }else if(r->esq == NULL){

      no_encomenda *t = r;

      r = r->esq;

    }else{

      no_encomenda *f = r->esq;

      while(f->dir != NULL){

        f = f->dir;

      }

      r->id = f->id;
      r->nome_aluno = f->nome_aluno;

      f->id = v;

      r->esq = abb_remove(r->esq, v);

    }

  }

  return r;

}

void in_ordem(no_encomenda *aux){

    if(aux == NULL){
      printf("Vazio!");
      return;
    }

    if(aux->esq != NULL){

        in_ordem(aux->esq);

    }

    printf("ID: ");

    printf("%d\t", aux->id);

    printf("Nome: ");

    printf("%s\n", aux->nome_aluno);

    if(aux->dir != NULL){

        in_ordem(aux->dir);

    }

}