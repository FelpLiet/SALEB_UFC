#pragma once

#include <stdlib.h>
#include <stdio.h>

typedef struct NO {
  int id;
  char *nome;

  struct NO *esq;
  struct NO *dir;
} NO;

typedef struct no_encomenda
{
	char *nome_aluno;
	int matricula_aluno;
	char *tiulo_livro;
	char *resumo_livo;
	char *campus_livro;
	char *campus_aluno;
	char *responsavel_encomenda;
	char *responsavel_trasporte;
	int prioridade;

	struct encomenda *dir;
	struct encomenda *esq;
}no_encomenda;

// busca pelo vertice
NO *buscaRecursiva(NO *no, int id);

// insere um vertice na arvore
NO *insere_na_arvore(NO *no, int id);

NO *arvore(NO *raiz, NO *raiz_insert, int vetor_de_id[], int inicio, int fim);

void pos_ordem(NO *aux);

void in_ordem(NO *aux);

void pre_ordem(NO *aux);