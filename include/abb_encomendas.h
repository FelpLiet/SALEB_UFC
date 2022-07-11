#pragma once

typedef struct no_encomenda
{
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

	struct no_encomenda *dir;
	struct no_encomenda *esq;
}no_encomenda;

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fila_pedidos.h"
#include "lista_acesso.h"
#include "lista.h"

void null_raiz();

no_encomenda *return_raiz_insert();

no_encomenda *return_raiz();

no_encomenda *buscaRecursiva(no_encomenda *no, int id);

no_encomenda *insere_na_arvore(no_encomenda *no, int id);

no_encomenda *abb_remove(no_encomenda *r, int v);

void arvore(no_encomenda *raiz_insert, int vetor_de_id[], int inicio, int fim);

void copia_no(no_encomenda *origem, no_encomenda *dentino);

void apaga_abb(no_encomenda *aux);

void pos_ordem(no_encomenda *aux);

void in_ordem(no_encomenda *aux);

void pre_ordem(no_encomenda *aux);