#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/abb_encomendas.h"
#include "../include/lista_acesso.h"
#include "../include/fila_pedidos.h"
#include "../include/lista.h"

int tamp_temp = 0;

int main()
{
    carrega_dado_lista_de_permicao();
    char mem[1024] = {0};
    int id, escolha, id_remove;
    no_encomenda teste;

    printf("\nSISTEMA DE ALOCACAO DE LIVROS ENTRE BIBLIOTECAS DA UFC\n");
    int resp = -1;
    while (resp != 0)
    {
        printf("--------------------------------------------------\n"
               "|                                                |\n"
               "| 1 - Encomendar um livro                        |\n"
               "| 2 - Remover uma encomenda de livro             |\n"
               "| 3 - Remover pedido para transporte             |\n"
               "| 0 - Sair do sistema                            |\n"
               "|                                                |\n"
               "--------------------------------------------------\n");

        printf("Digite a funcionalidade desejada: ");
        scanf("%d%*c", &resp);

        if (resp == 1)
        {

            printf("Digite o nome do aluno: ");
            if (fgets(mem, sizeof(mem), stdin) != NULL)
            {
                int mem_size = strlen(mem);
                teste.nome_aluno = (char *)malloc((sizeof(char) * mem_size) + 1);
                strncpy(teste.nome_aluno, mem, mem_size);
                teste.nome_aluno[mem_size] = '\0';
            }

            printf("Digite a matricula do aluno: ");
            scanf("%d%*c", &teste.matricula_aluno);

            printf("Insira o titulo do livro: ");
            if (fgets(mem, sizeof(mem), stdin) != NULL)
            {
                int mem_size = strlen(mem);
                teste.titulo_livro = (char *)malloc((sizeof(char) * mem_size) + 1);
                strncpy(teste.titulo_livro, mem, mem_size);
                teste.titulo_livro[mem_size] = '\0';
            }

            printf("Insira o autor do livro: ");
            if (fgets(mem, sizeof(mem), stdin) != NULL)
            {
                int mem_size = strlen(mem);
                teste.autor_livro = (char *)malloc((sizeof(char) * mem_size) + 1);
                strncpy(teste.autor_livro, mem, mem_size);
                teste.autor_livro[mem_size] = '\0';
            }

            reconstroi_arvore(&teste);

            tamp_temp++;

            puts("Retornando ao menu principal...");
        }
        else if (resp == 2)
        {
            int estado_encomenda = -1;
            while (estado_encomenda != 0)
            {
                printf("--------------------------------------------------\n"
                       "|                     SALEB                      |\n"
                       "|                MENU SECRETARIOS                |\n"
                       "|                                                |\n"
                       "| 1 - Listar id das encomendas                   |\n"
                       "| 2 - Remover da lista de encomenda pelo id      |\n"
                       "| 0 - Voltar ao menu                             |\n"
                       "|                                                |\n"
                       "--------------------------------------------------\n");
                printf("Digite a funcionalidade desejada: ");
                scanf("%d%*c", &estado_encomenda);
                if (estado_encomenda == 1)
                {

                    in_ordem(return_raiz());
                }
                else if (estado_encomenda == 2)
                {

                    printf("Qual o id para remocao: ");
                    scanf("%d", &id_remove);
                    printf("Digite seu cpf: ");
                    char cpf[100];
                    scanf("%s", cpf);
                    printf("Digite sua senha: ");
                    char senha[100];
                    scanf("%s", senha);
                    if (verificar_acesso_secretario(cpf, senha) == 1)
                    {
                        add_fila_pedidos(buscaRecursiva(return_raiz(), id_remove), cpf);
                        abb_remove(return_raiz(), id_remove);
                        remover_na_list(id_remove);
                        tamp_temp--;
                    }
                    else
                    {
                        puts("Usuario nao encontrado");
                    }
                }
                else
                {
                    puts("Retornando ao menu principal...");
                }
                if (tamp_temp == 0)
                {
                    null_raiz();
                }
                if (return_raiz() == NULL)
                {
                    estado_encomenda = 0;
                }
            }
        }
        else if (resp == 3)
        {
            int estado_entrega = -1;
            while (estado_entrega != 0)
            {
                printf("--------------------------------------------------\n"
                       "|                     SALEB                      |\n"
                       "|               MENU TRANSPORTADOR               |\n"
                       "|                                                |\n"
                       "| 1 - Remover livro para entrega                 |\n"
                       "| 0 - Voltar ao menu                             |\n"
                       "|                                                |\n"
                       "--------------------------------------------------\n");
                printf("Digite a funcionalidade desejada:");
                scanf("%d%*c", &estado_entrega);
                if (estado_entrega == 1)
                {

                    printf("Digite seu cpf: ");
                    char cpf[100];
                    scanf("%s", cpf);
                    printf("Digite sua senha: ");
                    char senha[100];
                    scanf("%s", senha);
                    if (verificar_acesso_transportador(cpf, senha) == 1)
                    {
                        ver_prioridade();
                    }
                    else
                    {
                        puts("Usuario nao encontrado");
                    }
                }
                else
                {
                    puts("Retornando ao menu principal...");
                }
                if (lista_acesso_esta_vazia() == 1)
                {
                    estado_entrega = 0;
                }
            }
        }
    }
    return 0;
}
