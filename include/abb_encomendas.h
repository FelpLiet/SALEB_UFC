#pragma once

typedef struct no_encomenda
{
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

	struct no_encomenda *dir;
	struct no_encomenda *esq;
}no_encomenda;

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fila_pedidos.h"
#include "lista_acesso.h"
#include "lista.h"
typedef struct NO {
  int id;
  char *nome;

  struct NO *esq;
  struct NO *dir;
} NO;


// no_encomenda *raiz_insert;
// no_encomenda *raiz;
// int tamp_temp;
no_encomenda *return_raiz_insert();

no_encomenda *return_raiz();

// busca pelo vertice
no_encomenda *buscaRecursiva(no_encomenda *no, int id);

// insere um vertice na arvore
no_encomenda *insere_na_arvore(no_encomenda *no, int id);

void arvore(no_encomenda *raiz_insert, int vetor_de_id[], int inicio, int fim);

void copia_no(no_encomenda *origem, no_encomenda *dentino);

void apaga_abb(no_encomenda *aux);

void pos_ordem(no_encomenda *aux);

void in_ordem(no_encomenda *aux);

void pre_ordem(no_encomenda *aux);