#pragma once
#include "abb_encomendas.h"
#include "lista_acesso.h"

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



void add_lista_pedidos(no_encomenda *pedido, char *cpf);

void remover_da_fila_de_prioridade();

void ver_prioridade();
