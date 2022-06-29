#include <stdio.h>
#include <stdlib.h>
#include "../include/abb_encomendas.h"
#include "../include/lista_acesso.h"
#include "../include/fila_pedidos.h"

// bonus por utilizar heap na fila

NO *raiz_insert = NULL;
NO *raiz = NULL;

int main()
{
    printf("\nSISTEMA DE ENCOMENDA DE LIVRO\n");
    int resp = -1;
    while (resp != 0)
    {
        printf(" 1 - Encomendar um livro.\n");
        printf(" 2 - Remover uma encomenda de livro.\n");
        printf(" 3 - Remover um pedido de livro.\n");
        printf(" 0 - Sair do sistema!\n");
        printf("Digite a funcionalidade desejada:");
        scanf("%d", &resp);
        if (resp == 1)
        {
            // encomendar um livro
            printf(" Digite o nome do aluno:\n");
            char *nome = malloc(sizeof(char));
            scanf(" %[^\n]s", nome);
            //... matricula e descricao..
            // criar um funcao para gerar id unico (:D)
            // add_abb(id, nome, matricula, descricao);
        }
        else if (resp == 2)
        {
            // remover uma encomenda de livro da ABB (id)
            // para remover eu preciso:
            // 1 - visualizar as encomendas (in_ordem)
            in_ordem(raiz);
            // 2 - verificar o usuario
            printf(" Digite seu cpf:\n");
            char cpf[100];
            scanf("%s", &cpf);
            printf(" Digite sua senha:\n");
            char senha[100];
            scanf("%s", &senha);
            int retorno = verificar(cpf, senha);
            if (retorno == 1)
            {
                // 3 - chama a funcao remover_abb por id (CADE ESSA FUNCAO?)
                // 4 - setar novos dados (faltando)
                // 5 - add_fila(....);
            }else 
            if (resp == 3)
            {

                // 2 - verificar o usuario
                printf(" Digite seu cpf:\n");
                char cpf[100];
                scanf("%s", &cpf);
                printf(" Digite sua senha:\n");
                char senha[100];
                scanf("%s", &senha);
                int retorno = verificar(cpf, senha);
                if (retorno == 1)
                {
                    // remover da fila de prioridade
                }
            }
        }
    }
    // codigo jv
    int tam = 7;
    int vetor_de_id[] = {1, 2, 3, 4, 5, 6, 7};

    raiz = arvore(raiz, raiz_insert, vetor_de_id, 0, tam - 1);
    printf("Pos Ordem:\n");
    pos_ordem(raiz);
    printf("\n\n");
    printf("In Ordem:\n");
    in_ordem(raiz);
    printf("\n\n");
    printf("Pre Ordem:\n");
    pre_ordem(raiz);

    return 0;
}