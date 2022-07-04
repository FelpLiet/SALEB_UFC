#pragma once 

#include "abb_encomendas.h"
#include "fila_pedidos.h"
#include "lista.h"

typedef  struct acess {
    char* nome;
    char* cpf;
    char* senha;
    char* cargo_de_acesso;
    struct acess* prox;
}acess;

int verificar_acesso_secretario(char *cpf, char *senha);

int verificar_acesso_transportador(char *cpf, char *senha);

char* busca_nome_acesso(char * cpf);

int lista_acesso_esta_vazia();

void carrega_dado_lista_de_permicao();
