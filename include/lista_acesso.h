#pragma once 

#include "abb_encomendas.h"

typedef  struct acess {
    char* nome;
    char* cpf;
    char* senha;
    char* cargo_de_acesso;
    struct acess* prox;
}acess;

acess * inicio_acess = NULL;
acess * fim_acess = NULL;
int tam_acess = 0;


int verificar_acesso(char *cpf, char *senha);

void carrega_dado_lista_de_permicao();
