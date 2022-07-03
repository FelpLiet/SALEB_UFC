#pragma once

#include <stdlib.h>
#include <stdio.h>

typedef struct list {
  int id;
  char *nome;

  struct list *prox;
}list;

list *inicio;
list *fim;
int ids;

void preenche_vec(int vetor_de_id[], int tam_vec);

void add_list(int id, char *nome);

void imprimir(list *fim,list *aux);