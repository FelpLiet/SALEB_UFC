#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct NO {
  int id;
  char *nome;

  struct NO *esq;
  struct NO *dir;
} NO;

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

no_encomenda *raiz_insert;
no_encomenda *raiz;
int tamp_temp;

// busca pelo vertice
no_encomenda *buscaRecursiva(no_encomenda *no, int id);

// insere um vertice na arvore
no_encomenda *insere_na_arvore(no_encomenda *no, int id);

no_encomenda *arvore(int vetor_de_id[], int inicio, int fim);

void apaga_abb(no_encomenda *aux);

void pos_ordem(no_encomenda *aux);

void in_ordem(no_encomenda *aux);

void pre_ordem(no_encomenda *aux);