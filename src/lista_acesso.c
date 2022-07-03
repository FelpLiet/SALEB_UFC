#include "../include/lista_acesso.h"

acess * inicio_acess = NULL;
acess * fim_acess = NULL;
int tam_acess = 0;

void add_lista_de_acesso(char *nome, char *cpf, char *senha, char *cargo_de_acesso)
{

    acess *novo = malloc(sizeof(acess));
    novo->nome = nome;
    novo->cpf = cpf;
    novo->senha = senha;
    novo->cargo_de_acesso = cargo_de_acesso;
    novo->prox = NULL;

    if (inicio_acess == NULL)
    { // lista vazia
        inicio_acess = novo;
        fim_acess = novo;
        tam_acess++;
    }
    else
    { // fim_acess
        fim_acess->prox = novo;
        fim_acess = novo;
        tam_acess++;
    }
}

void carrega_dado_lista_de_permicao()
{
    add_lista_de_acesso("billy", "214.494", "12345", "secretario");
    add_lista_de_acesso("tatiane", "894.840", "12345", "secretario");
    add_lista_de_acesso("pedro", "631.660", "12345", "secretario");
    add_lista_de_acesso("roberto", "621.651", "12345", "transportador");
    add_lista_de_acesso("naruto", "161.081", "12345", "transportador");
    add_lista_de_acesso("osvaldo", "413.200", "12345", "transportador");
    add_lista_de_acesso("fracalina", "385.252", "12345", "transportador");
    add_lista_de_acesso("tanjiro", "464.396", "12345", "transportador");
}

int verificar_acesso_secretario(char *cpf, char *senha){
    if((strcmp(inicio_acess->cpf, cpf) == 0) && (strcmp(inicio_acess->senha, senha) == 0 && (strcmp(inicio_acess->cargo_de_acesso, "secretario") == 0))){
        return 1;
    }
    else if((strcmp(fim_acess->cpf, cpf) == 0) && (strcmp(fim_acess->senha, senha) == 0 && (strcmp(inicio_acess->cargo_de_acesso, "secretario") == 0))){
        return 1;
    }

    acess *aux = inicio_acess->prox;

    for(int i = 0; i < tam_acess - 2; i++){
        if((strcmp(aux->cpf, cpf) == 0) && (strcmp(aux->senha, senha) == 0) && (strcmp(inicio_acess->cargo_de_acesso, "secretario") == 0)){
            return 1;
        }
        aux = aux->prox;
    }
    return 0;
} 

int verificar_acesso_transportador(char *cpf, char *senha){
    if((strcmp(inicio_acess->cpf, cpf) == 0) && (strcmp(inicio_acess->senha, senha) == 0) && (strcmp(inicio_acess->cargo_de_acesso, "transportador") == 0)){
        return 1;
    }
    else if((strcmp(fim_acess->cpf, cpf) == 0) && (strcmp(fim_acess->senha, senha) == 0 && (strcmp(inicio_acess->cargo_de_acesso, "transportador") == 0))){
        return 1;
    }

    acess *aux = inicio_acess->prox;

    for(int i = 0; i < tam_acess - 2; i++){
        if((strcmp(aux->cpf, cpf) == 0) && (strcmp(aux->senha, senha) == 0) && (strcmp(inicio_acess->cargo_de_acesso, "transportador") == 0)){
            return 1;
        }
        aux = aux->prox;
    }
    return 0;
}


char* busca_nome_acesso(char * cpf){
    if((strcmp(inicio_acess->cpf, cpf) == 0)){
        return inicio_acess->nome;
    }
    else if((strcmp(fim_acess->cpf, cpf) == 0)){
        return fim_acess->nome;
    }

    acess *aux = inicio_acess->prox;

    for(int i = 0; i < tam_acess - 2; i++){
        if((strcmp(aux->cpf, cpf) == 0)){
            return aux->nome;
        }
        aux = aux->prox;
    }
    char nao_encontrado[] = "nome não definido";
    char * nao_encontrado_pont = nao_encontrado;
    return nao_encontrado_pont;
}