#pragma once

#include <stdlib.h>
#include <stdio.h>

typedef struct NO
{
	int id;

	struct NO *esq;
	struct NO *dir;
} NO;

typedef struct no_encomenda
{
	int id;
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
no_encomenda *buscaRecursiva(no_encomenda *no, int id);

// insere um vertice na arvore
no_encomenda *insere_na_arvore(no_encomenda *no, int id);

no_encomenda *arvore(no_encomenda *raiz, no_encomenda *raiz_insert, int vetor_de_id[], int inicio, int fim);

void in_ordem(no_encomenda *aux);