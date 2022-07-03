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
    int id, escolha;
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
            // encomendar um livro
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

            reconstroi_arvore(&teste);
            
            // aumenta o tamanho da arvore
            tamp_temp++;
            // if (raiz != NULL)
            // {
            //     apaga_abb(raiz);
            // }
            // add_list(ids, teste.nome_aluno);
            // int tam_vec = fim->id;
            // int vetor_de_id[tam_vec];
            // preenche_vec(vetor_de_id, tam_vec);
            // arvore(vetor_de_id, 0, tam_vec - 1);
            // ids++;
            // in_ordem(raiz);

            //... matricula e descricao..
            // criar um funcao para gerar id unico (:D)
            // add_abb(id, nome, matricula, descricao);
        }
        else if (resp == 2)
        {
            // remover uma encomenda de livro da ABB (id)
            // para remover eu preciso:
            int estado_encomenda = -1;
            while (estado_encomenda != 0)
            { // 1 - visualizar as encomendas (in_ordem)
                printf("--------------------------------------------------\n"
                       "|                                                |\n"
                       "| 1 - Listar id das encomendas                   |\n"
                       "| 2 - Remover da lista de encomenda pelo id      |\n"
                       "| 0 - Voltar ao menu                             |\n"
                       "|                                                |\n"
                       "--------------------------------------------------\n");
                printf("Digite a funcionalidade desejada:");
                scanf("%d%*c", &estado_encomenda);
                if (estado_encomenda == 1)
                {
                    in_ordem(return_raiz());
                }
                else if (estado_encomenda == 2)
                {
                    // 2 - verificar o usuario
                    printf(" Digite seu cpf:\n");
                    char cpf[100];
                    scanf("%s", cpf);
                    printf(" Digite sua senha:\n");
                    char senha[100];
                    scanf("%s", senha);
                    if (verificar_acesso_secretario(cpf, senha) == 1)
                    {
                        int id_remove;
                        printf("qualo id para remocao:\n");
                        scanf("%d", &id_remove);
                        add_fila_pedidos(buscaRecursiva(return_raiz(), id), cpf);
                        apaga_abb(buscaRecursiva(return_raiz(), id));
                        // 3 - chama a funcao remover_abb por id (CADE ESSA FUNCAO?)
                        // 4 - setar novos dados (faltando)
                        // 5 - add_fila(....);
                    }
                    else
                    {
                        puts("Usuario nao encontrado");
                    }
                }
                else
                {
                    puts("Restornando");
                }
            }
        }
        else if (resp == 3)
        {

            printf("--------------------------------------------------\n"
                   "|                                                |\n"
                   "| 1 - Remover livro para entrega                 |\n"
                   "| 0 - Voltar ao menu                             |\n"
                   "|                                                |\n"
                   "--------------------------------------------------\n");
            printf("Digite a funcionalidade desejada:");
            scanf("%d%*c", &escolha);
            if (escolha == 1)
            {
                // 2 - verificar o usuario
                printf(" Digite seu cpf:\n");
                char cpf[100];
                scanf("%s", cpf);
                printf(" Digite sua senha:\n");
                char senha[100];
                scanf("%s", senha);
                if (verificar_acesso_transportador(cpf, senha) == 1)
                {
                    // remover da fila de prioridade
                    remover_da_fila_de_prioridade();
                }
                else
                {
                    puts("Usuario nao encontrado");
                }
            }
            else
            {
                puts("Restornando");
            }
        }
    }
    return 0;
}
