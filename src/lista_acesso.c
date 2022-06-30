#include "../include/lista_acesso.h"

void add_lista_de_acesso(char *nome, char *cpf, char *senha, char *cargo_de_acesso)
{

    acess *novo = malloc(sizeof(acess));
    novo->nome = nome;
    novo->cpf = cpf;
    novo->senha = senha;
    novo->cargo_de_acesso = cargo_de_acesso;
    novo->prox = NULL;

    if (inicio == NULL)
    { // lista vazia
        inicio = novo;
        fim = novo;
        tam++;
    }
    else
    { // fim
        fim->prox = novo;
        fim = novo;
        tam++;
    }
}

void carrega_dado_lista_de_permicao()
{
    add_lista_de_acesso("billy", "1111", "1", "secretario");
    add_lista_de_acesso("tatiane", "2222", "2", "secretario");
    add_lista_de_acesso("pedro", "3333", "3", "secretario");
    add_lista_de_acesso("roberto", "4444", "4", "transportador");
    add_lista_de_acesso("naruto", "5555", "5", "transportador");
}

int verificar_acesso(char *cpf, char *senha){
    if((strcmp(fim->cpf, cpf) == 0) && (strcmp(fim->senha, senha) == 0)){
        return 1;
    }

    acess *aux = inicio;

    for(int i = 0; i < tam - 1; i++){
        if((strcmp(aux->cpf, cpf) == 0) && (strcmp(aux->senha, senha) == 0)){
            return 1;
        }
        aux = aux->prox;
    }
    return 0;
}