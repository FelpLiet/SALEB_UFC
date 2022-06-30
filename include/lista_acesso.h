#pragma once 

#include "abb_encomendas.h"

typedef  struct acess {
    char* nome;
    char* cpf;
    char* senha;
    char* cargo_de_acesso;
    struct acess* prox;
}acess;

acess * inicio = NULL;
acess * fim = NULL;
int tam = 0;


int verificar_acesso(char *cpf, char *senha);

void carrega_dado_lista_de_permicao();
