#pragma once
#include "abb_encomendas.h"

typedef struct lista_pedidos
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

    struct lista_pedidos * prox;

}lista_pedidos;

lista_pedidos * inicio_pedido = NULL;
lista_pedidos * fim_pedido = NULL;
int tam_pedido = 0;

void add_lista_pedidos(no_encomenda *pedido);

void remover_da_fila_de_prioridade();

void ver_prioridade();
