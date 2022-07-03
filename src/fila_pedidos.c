#include "../include/fila_pedidos.h"

fila_pedidos *inicio_pedido = NULL;
fila_pedidos *fim_pedido = NULL;
int tam_pedido = 0;

void add_fila_pedidos(no_encomenda *pedido, char *cpf)
{
    fila_pedidos *novo = malloc(sizeof(fila_pedidos));

    char mem[1024] = {0};
    int mem_size;

    mem_size = strlen(pedido->campus_aluno);
    novo->campus_aluno = (char *)malloc((sizeof(char) * mem_size) + 1);
    strncpy(novo->campus_aluno, pedido->campus_aluno, mem_size);
    novo->campus_aluno[mem_size] = '\0';

    mem_size = strlen(pedido->campus_livro);
    novo->campus_livro = (char *)malloc((sizeof(char) * mem_size) + 1);
    strncpy(novo->campus_livro, pedido->campus_livro, mem_size);
    novo->campus_livro[mem_size] = '\0';

    novo->matricula_aluno = pedido->matricula_aluno;

    mem_size = strlen(pedido->nome_aluno);
    novo->nome_aluno = (char *)malloc((sizeof(char) * mem_size) + 1);
    strncpy(novo->nome_aluno, pedido->nome_aluno, mem_size);
    novo->nome_aluno[mem_size] = '\0';

    novo->prioridade = pedido->prioridade;

    mem_size = strlen(pedido->resumo_livro);
    novo->resumo_livro = (char *)malloc((sizeof(char) * mem_size) + 1);
    strncpy(novo->resumo_livro, pedido->resumo_livro, mem_size);
    novo->resumo_livro[mem_size] = '\0';

    mem_size = strlen(pedido->titulo_livro);
    novo->titulo_livro = (char *)malloc((sizeof(char) * mem_size) + 1);
    strncpy(novo->titulo_livro, pedido->titulo_livro, mem_size);
    novo->titulo_livro[mem_size] = '\0';

    novo->prox = NULL;

    if (inicio_pedido == NULL)
    { // fila vazia
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
        // remover usando o antigo remover do inicio_pedido da lista!

        fila_pedidos *lixo = inicio_pedido;
        inicio_pedido = inicio_pedido->prox;
        /*//copia os dados para o retorno!!_______________________________
        removido.campus_aluno = lixo->campus_aluno;
        removido.campus_livro = lixo->campus_livro;
        removido.matricula_aluno = lixo->matricula_aluno;
        removido.nome_aluno = lixo->nome_aluno;
        removido.prioridade = lixo->prioridade;
        removido.prox = NULL;
        removido.responsavel_encomenda = lixo->responsavel_encomenda;
        removido.responsavel_trasporte = lixo->responsavel_trasporte;
        removido.resumo_livro = lixo->resumo_livro;
        removido.titulo_livro = lixo->titulo_livro;
        //______________________________________________________________*/

        free(lixo);
        tam_pedido--;
        if (tam_pedido == 1)
        {
            fim_pedido = NULL;
        }
    }
    printf("PEDIDO ENCAMINHADO!");
}

void ver_prioridade()
{
    if (inicio_pedido != NULL)
    {
        puts("-----------------------------------------------------------------");
        printf("titulo do livro: %s/n", inicio_pedido->titulo_livro);
        printf("dados do livro: %s/n", inicio_pedido->resumo_livro);
        printf("campus do livro: %s/n", inicio_pedido->campus_livro);
        printf("destino do livro: %s/n", inicio_pedido->campus_aluno);
        puts("-----------------------------------------------------------------");
    }
    printf("1 - PEDIDO ENCAMINHADO (REMOVER DA ESPERA)\n"
           "2 - EXIT \n\n");
    int N;
    scanf("%d", &N);
    if (N == 1)
    {
        remover_da_fila_de_prioridade();
    }
}