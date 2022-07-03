#pragma once

#include <stdlib.h>
#include <stdio.h>
#include "abb_encomendas.h"
#include "fila_pedidos.h"
#include "lista_acesso.h"

typedef struct list {
  int id;
	char *nome_aluno;
	int matricula_aluno;
	char *titulo_livro;
	char *resumo_livro;
	char *campus_livro;
	char *campus_aluno;
	char *responsavel_encomenda;
	char *responsavel_trasporte;
	int prioridade;

  struct list *prox;
}list;

// list *inicio;
// list *fim;
// int ids;

void preenche_vec(int vetor_de_id[], int tam_vec);

void add_list(int id, char *nome);

void imprimir(list *fim,list *aux);

void reconstroi_arvore(no_encomenda *teste);

