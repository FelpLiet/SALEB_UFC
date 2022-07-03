#pragma once

#include <stdlib.h>
#include <stdio.h>

typedef struct list {
  int id;
  char *nome;

  struct list *prox;
}list;


void preenche_vec(list *inicio,int vetor_de_id[], int tam_vec);

void add_list(list *inicio, list *fim,int id, char *nome);

void preenche_vec(list *inicio, int vetor_de_id[], int tam_vec);

void imprimir(list *fim,list *aux);