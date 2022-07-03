#pragma once
#include "abb_encomendas.h"
#include "lista_acesso.h"

typedef struct fila_pedidos
{
	char *nome_aluno;
	int matricula_aluno;
	char *titulo_livro;
	char *resumo_livro;
	char *campus_livro;
	char *campus_aluno;
	char *responsavel_encomenda;
	char *responsavel_trasporte;
	int prioridade;

	struct fila_pedidos *prox;

} fila_pedidos;

void add_fila_pedidos(no_encomenda *pedido, char *cpf);

void remover_da_fila_de_prioridade();

void ver_prioridade();
