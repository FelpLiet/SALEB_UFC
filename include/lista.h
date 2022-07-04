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
	char *autor_livro;
	char *campus_livro;
	char *campus_aluno;
	char *responsavel_encomenda;
	char *responsavel_trasporte;
	int prioridade;

  struct list *prox;
}list;

void preenche_vec(int vetor_de_id[], int tam_vec);

void add_list(int id, char *nome, int matricula, char *titulo, char *autor);

void imprimir(list *aux);

void reconstroi_arvore(no_encomenda *teste);

list *return_inicio_list();
