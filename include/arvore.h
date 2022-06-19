#pragma once

typedef struct NO {
  int id;

  struct NO* esq;
  struct NO* dir;
} NO;

NO *raiz_insert = NULL;
NO *raiz = NULL;
int tamp_temp = 0;

#include <stdlib.h>
#include <stdio.h>

//busca pelo vertice
NO* buscaRecursiva(NO *no, int id);

//insere um vertice na arvore
NO *insere_na_arvore(NO *no, int id);

void arvore(NO *raiz_insert, int vetor_de_id[], int inicio, int fim);