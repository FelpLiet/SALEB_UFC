#pragma once 

#include "abb_encomendas.h"

typedef  struct acess {
    char* nome;
    char* cpf;
    char* senha;
    char* cargo_de_acesso;
    struct acess* prox;
}acess;

acess * inicio_acess;
acess * fim_acess;
int tam_acess;


int verificar_acesso_secretario(char *cpf, char *senha);

int verificar_acesso_transportador(char *cpf, char *senha);

char* busca_nome_acesso(char * cpf);

void carrega_dado_lista_de_permicao();
