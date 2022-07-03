#include "../include/abb_encomendas.h"

int tamp_temp = 0;


no_encomenda *buscaRecursiva(no_encomenda *no, int id)
{
  if (no == NULL)
    return NULL;
  else if (no->id == id)
    return no;
  else if (no->id > id)
    return buscaRecursiva(no->esq, id);
  else
    return buscaRecursiva(no->dir, id);
}

no_encomenda *insere_na_arvore(no_encomenda *no, int id)
{
  if (no == NULL)
  {
    no = (no_encomenda *)malloc(sizeof(no_encomenda));
    no->id = id;
    no->esq = NULL;
    no->dir = NULL;
    tamp_temp++;
  }
  else if (id < (no->id))
  {
    no->esq = insere_na_arvore(no->esq, id);
  }
  else if (id > (no->id))
  {
    no->dir = insere_na_arvore(no->dir, id);
  }
  else
  {
    printf("Inserção inválida! "); // id já existe
    exit(1);
  }
  return no;
}

no_encomenda *arvore(no_encomenda *raiz, no_encomenda *raiz_insert, int vetor_de_id[], int inicio, int fim)
{
  if (inicio <= fim)
  {
    int meio = (inicio + fim) / 2;
    raiz_insert = insere_na_arvore(raiz_insert, vetor_de_id[meio]);
    if (raiz == NULL)
    {
      raiz = raiz_insert;
    }

    arvore(raiz, raiz_insert, vetor_de_id, inicio, meio - 1);
    arvore(raiz, raiz_insert, vetor_de_id, meio + 1, fim);
  }
}

void apaga_abb(no_encomenda *aux)
{
	if (aux == NULL) {
		return;
	}

	apaga_abb(aux->esq);
	apaga_abb(aux->dir);

	free(aux);

	aux = NULL;
}

void pos_ordem(no_encomenda *aux){
    
    if(aux->esq != NULL){
        pos_ordem(aux->esq);
    }
    if(aux->dir != NULL){
        pos_ordem(aux->dir);
    }
    printf("ID: ");
    printf("%d\t", aux->id);
    printf("Nome: ");
    printf("%s\n", aux->nome_aluno);
}
void in_ordem(no_encomenda *aux)
{

    if (aux->esq != NULL)
    {
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
void pre_ordem(no_encomenda *aux)
{
    printf("ID: ");
    printf("%d\t", aux->id);
    printf("Nome: ");
    printf("%s\n", aux->nome_aluno);
    if(aux->esq != NULL){
        pre_ordem(aux->esq);
    }
    if(aux->dir != NULL){
        pre_ordem(aux->dir);
    }
}