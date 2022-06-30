#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct NO {
  int id;

  struct NO* esq;
  struct NO* dir;
} NO;





//busca pelo vertice
NO* buscaRecursiva(NO *no, int id);

//insere um vertice na arvore
NO *insere_na_arvore(NO *no, int id);

NO *arvore( NO * raiz, NO *raiz_insert, int vetor_de_id[], int inicio, int fim);

void pos_ordem(NO *aux);

void in_ordem(NO *aux);

void pre_ordem(NO *aux);