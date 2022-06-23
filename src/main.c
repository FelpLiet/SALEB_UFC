#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NO {
  int id;
  char *nome;

  struct NO *esq;
  struct NO *dir;
} NO;

typedef struct list {
  int id;
  char *nome;

  struct list *prox;
}list;

NO *raiz_insert = NULL;
NO *raiz = NULL;
int tamp_temp = 0;

list *inicio = NULL;
list *fim = NULL;
int tam_list = 0;

void add_list(int id, char *nome){
  list *novo = (list*)malloc(sizeof(list));
  novo->id = id;
  novo->nome = nome;
  novo->prox = NULL;
  if(inicio == NULL){
    inicio = novo;
    fim = novo;
  }else if(id <= inicio->id){
    novo->prox = inicio;
    inicio = novo;
  }else if(id >= fim->id){
    fim->prox = novo;
    fim = novo;
  }else{
    list *aux = inicio;
    while(aux->prox->id < novo->id){
      aux = aux->prox;
    }
    novo->prox = aux->prox;
    aux->prox = novo;
  }
}

void imprimir(list *aux){
  printf("%d ",aux->id);
  printf("%s", aux->nome);
  printf("\n");
  if(aux->id == fim->id){
    return;
  }else{
    imprimir(aux->prox);
  }
}

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
  list *aux = inicio;
  if (no == NULL){
    no = (NO *) malloc(sizeof(NO));
    no->id = id;
    if(aux->id < id){
      while (aux->id < id){
        aux = aux->prox;
      }  
    }
    no->nome = aux->nome;
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

NO *abb_remove(NO *r, int v){
  if(r == NULL){
    return NULL;
  }else if(r->id > v){
    r->esq = abb_remove(r->esq, v);
  }else if(r->id < v){
    r->dir = abb_remove(r->dir, v);
  }else{
    if(r->esq == NULL && r->dir == NULL){
      r = NULL;
    }else if(r->esq == NULL){
      NO *t = r;
      r = r->esq;
    }else{
      NO *f = r->esq;
      while(f->dir != NULL){
        f = f->dir;
      }
      r->id = f->id;
      f->id = v;
      r->esq = abb_remove(r->esq, v);
    }
  }
  return r;
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
    printf("Nome: ");
    printf("%s\n", aux->nome);
}
void in_ordem(NO *aux){
    
    if(aux->esq != NULL){
        in_ordem(aux->esq);
    }
    printf("ID: ");
    printf("%d\t", aux->id);
    printf("Nome: ");
    printf("%s\n", aux->nome);
    if(aux->dir != NULL){
        in_ordem(aux->dir);
    }
}
void pre_ordem(NO *aux){
    printf("ID: ");
    printf("%d\t", aux->id);
    printf("Nome: ");
    printf("%s\n", aux->nome);
    if(aux->esq != NULL){
        pre_ordem(aux->esq);
    }
    if(aux->dir != NULL){
        pre_ordem(aux->dir);
    }
}

void preenche_vec(int vetor_de_id[], int tam_vec){
  list *aux = inicio;

  for(int i = 0; i < tam_vec; i++){
    vetor_de_id[i] = aux->id;
    aux = aux->prox;
  }
}

int main() {

  add_list(2, "jovi");
  add_list(1, "pedro");
  add_list(4, "billy");
  add_list(3, "felp");
  add_list(5, "wes");
  imprimir(inicio);
  printf("\n\n");
  int tam_vec = fim->id;
  int vetor_de_id[tam_vec];
  preenche_vec(vetor_de_id, tam_vec);


  arvore(raiz_insert,vetor_de_id,0,tam_vec-1);
  printf("Pos Ordem:\n");
  pos_ordem(raiz);
  printf("\n\n");
  printf("In Ordem:\n");
  in_ordem(raiz);
  printf("\n\n");
  printf("Pre Ordem:\n");
  pre_ordem(raiz);

  abb_remove(raiz, 2);
  printf("\n\n");
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