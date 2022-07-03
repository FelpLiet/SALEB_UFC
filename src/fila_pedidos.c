#include "../include/fila_pedidos.h"

lista_pedidos * inicio_pedido = NULL;
lista_pedidos * fim_pedido = NULL;
int tam_pedido = 0;

void add_lista_pedidos(no_encomenda *pedido)
{
    lista_pedidos *novo = malloc(sizeof(lista_pedidos));
    novo->campus_aluno = pedido->campus_aluno;
    novo->campus_livro = pedido->campus_livro;
    novo->matricula_aluno = pedido->matricula_aluno;
    novo->nome_aluno = pedido->nome_aluno;
    novo->prioridade = pedido->prioridade;
    novo->responsavel_encomenda = pedido->responsavel_encomenda;
    novo->responsavel_trasporte = pedido->responsavel_trasporte;
    novo->resumo_livro = pedido->resumo_livro;
    novo->titulo_livro = pedido->titulo_livro;
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
        lista_pedidos *aux = inicio_pedido;
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
    lista_pedidos removido;
    if (inicio_pedido != NULL)
    {
        // remover usando o antigo remover do inicio_pedido da lista!

        lista_pedidos *lixo = inicio_pedido;
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
    if(inicio_pedido != NULL){
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
    scanf("%d",&N);
    if(N == 1){
        remover_da_fila_de_prioridade();

    }
}