#include "../include/fila_pedidos.h"

fila_pedidos *inicio_pedido = NULL;
fila_pedidos *fim_pedido = NULL;
int tam_pedido = 0;

void add_fila_pedidos(no_encomenda *pedido, char *cpf)
{
    puts("--------ACESSO LIBERADO-------");

    printf("--------------------------------------------------\n"
           "|                     SALEB                      |\n"
           "|                 FICHA DO PEDIDO                |\n"
           "|    Nome: %s"
           "|    Matricula: %d\n"
           "|    Titulo do Livro: %s"
           "|    Autor do Livro: %s"
           "|                                                |\n"
           "--------------------------------------------------\n",
           pedido->nome_aluno, pedido->matricula_aluno, pedido->titulo_livro, pedido->autor_livro);

    fila_pedidos *novo = malloc(sizeof(fila_pedidos));

    char mem[1024] = {0};
    int mem_size;

    mem_size = strlen(busca_nome_acesso(cpf));
    novo->responsavel_encomenda = (char *)malloc((sizeof(char) * mem_size) + 1);
    strncpy(novo->responsavel_encomenda, busca_nome_acesso(cpf), mem_size);
    novo->responsavel_encomenda[mem_size] = '\0';

    mem_size = strlen(pedido->nome_aluno);
    novo->nome_aluno = (char *)malloc((sizeof(char) * mem_size) + 1);
    strncpy(novo->nome_aluno, pedido->nome_aluno, mem_size);
    novo->nome_aluno[mem_size] = '\0';

    novo->matricula_aluno = pedido->matricula_aluno;

    while ((getchar()) != '\n');
    
    printf("Insira o campus do aluno: ");
    if (fgets(mem, sizeof(mem), stdin) != NULL)
    {
        mem_size = strlen(mem);
        novo->campus_aluno = (char *)malloc((sizeof(char) * mem_size) + 1);
        strncpy(novo->campus_aluno, mem, mem_size);
        novo->campus_aluno[mem_size] = '\0';
    }

    printf("Insira o campus do livro: ");
    if (fgets(mem, sizeof(mem), stdin) != NULL)
    {
        mem_size = strlen(mem);
        novo->campus_livro = (char *)malloc((sizeof(char) * mem_size) + 1);
        strncpy(novo->campus_livro, mem, mem_size);
        novo->campus_livro[mem_size] = '\0';
    }

    printf("Insira a prioridade da encomenda: ");
    scanf("%d", &pedido->prioridade);

    mem_size = strlen(pedido->autor_livro);
    novo->autor_livro = (char *)malloc((sizeof(char) * mem_size) + 1);
    strncpy(novo->autor_livro, pedido->autor_livro, mem_size);
    novo->autor_livro[mem_size] = '\0';

    mem_size = strlen(pedido->titulo_livro);
    novo->titulo_livro = (char *)malloc((sizeof(char) * mem_size) + 1);
    strncpy(novo->titulo_livro, pedido->titulo_livro, mem_size);
    novo->titulo_livro[mem_size] = '\0';

    novo->prox = NULL;

    if (inicio_pedido == NULL)
    { 
        inicio_pedido = novo;
        fim_pedido = novo;
        tam_pedido++;
    }
    else if (novo->prioridade < fim_pedido->prioridade)
    {
        fim_pedido->prox = novo;
        fim_pedido = novo;
        tam_pedido++;
    }
    else if (novo->prioridade > inicio_pedido->prioridade)
    {
        novo->prox = inicio_pedido;
        inicio_pedido = novo;
        tam_pedido++;
    }
    else
    {
        fila_pedidos *aux = inicio_pedido;
        for (int i = 0; i < tam_pedido; i++)
        {
            if (aux->prox->prioridade < novo->prioridade)
            {
                novo->prox = aux->prox;
                aux->prox = novo;
                tam_pedido++;
                break;
            }
        }
    }
}

void remover_da_fila_de_prioridade()
{
    fila_pedidos removido;
    if (inicio_pedido != NULL)
    {
        

        fila_pedidos *lixo = inicio_pedido;
        inicio_pedido = inicio_pedido->prox;

        free(lixo);
        tam_pedido--;
        if (tam_pedido == 1)
        {
            fim_pedido = NULL;
        }
    }
    printf("PEDIDO ENCAMINHADO!\n");
}

void ver_prioridade()
{
    if (inicio_pedido != NULL)
    {
        printf("--------------------------------------------------\n"
               "|                     SALEB                      |\n"
               "|                DADOS PARA ENVIO                |\n"
               "|                                                |\n"
               "|  Titulo do livro: %s"
               "|  Dados do livro: %s"
               "|  Campus do livro: %s"
               "|  Destino do livro: %s"
               "|                                                |\n"
               "--------------------------------------------------\n",
               inicio_pedido->titulo_livro, inicio_pedido->autor_livro, inicio_pedido->campus_livro, inicio_pedido->campus_aluno);
    }
    printf("--------------------------------------------------\n"
           "|                     SALEB                      |\n"
           "|           DESEJA RETIRAR PARA ENVIO?           |\n"
           "|                                                |\n"
           "| 1 - Retirar encomenda                          |\n"
           "| 0 - Cancelar operacao                          |\n"
           "|                                                |\n"
           "--------------------------------------------------\n");
    int N;
    scanf("%d", &N);
    if (N == 1)
    {
        remover_da_fila_de_prioridade();
    }
    else
    {
        puts("Cancelando o peracao...");
        return;
    }
}