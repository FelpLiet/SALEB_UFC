#include "../include/lista.h"

int tam_list = 0;

list *inicio = NULL;
list *fim = NULL;
int ids = 1;

void preenche_vec(int vetor_de_id[], int tam_vec)
{
	list *aux = inicio;

	for (int i = 0; i < tam_vec; i++)
	{
		vetor_de_id[i] = aux->id;
		aux = aux->prox;
	}
}

void add_list(int id, char *nome)
{
	list *novo = (list *)malloc(sizeof(list));
	novo->id = id;
	novo->nome_aluno = nome;
	novo->prox = NULL;
	if (inicio == NULL)
	{
		inicio = novo;
		fim = novo;
	}
	else if (id <= inicio->id)
	{
		novo->prox = inicio;
		inicio = novo;
	}
	else if (id >= fim->id)
	{
		fim->prox = novo;
		fim = novo;
	}
	else
	{
		list *aux = inicio;
		while (aux->prox->id < novo->id)
		{
			aux = aux->prox;
		}
		novo->prox = aux->prox;
		aux->prox = novo;
	}
}

void imprimir(list *fim, list *aux)
{
	printf("%d ", aux->id);
	printf("%s", aux->nome_aluno);
	printf("\n");
	if (aux->id == fim->id)
	{
		return;
	}
	else
	{
		imprimir(fim, aux->prox);
	}
}

void reconstroi_arvore(no_encomenda *teste)
{
	if (return_raiz() != NULL)
	{
		apaga_abb(return_raiz());
	}
	add_list(ids, teste->nome_aluno);
	int tam_vec = fim->id;
	int vetor_de_id[tam_vec];
	preenche_vec(vetor_de_id, tam_vec);
	arvore(vetor_de_id, 0, tam_vec - 1);
	ids++;
	in_ordem(return_raiz());
}
