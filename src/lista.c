#include "../include/lista.h"

int tam_list = 0;

list *inicio = NULL;
list *fim = NULL;
int ids = 1;

list *return_inicio_list()
{
	return inicio;
}

void preenche_vec(int vetor_de_id[], int tam_vec)
{
	list *aux = inicio;

	for (int i = 0; i < tam_vec; i++)
	{
		vetor_de_id[i] = aux->id;
		aux = aux->prox;
	}
}

void add_list(int id, char *nome, int matricula, char *titulo, char *autor)
{
	char mem[1024] = {0};
	int mem_size = 0;

	list *novo = (list *)malloc(sizeof(list));

	novo->id = id;

	novo->matricula_aluno = matricula;

	mem_size = strlen(nome);
	novo->nome_aluno = (char *)malloc((sizeof(char) * mem_size) + 1);
	strncpy(novo->nome_aluno, nome, mem_size);
	novo->nome_aluno[mem_size] = '\0';

	mem_size = strlen(titulo);
	novo->titulo_livro = (char *)malloc((sizeof(char) * mem_size) + 1);
	strncpy(novo->titulo_livro, titulo, mem_size);
	novo->titulo_livro[mem_size] = '\0';

	mem_size = strlen(autor);
	novo->autor_livro = (char *)malloc((sizeof(char) * mem_size) + 1);
	strncpy(novo->autor_livro, autor, mem_size);
	novo->autor_livro[mem_size] = '\0';

	// colocar os outros elementos
	

	novo->prox = NULL;

	if (inicio == NULL)
	{

		inicio = novo;

		fim = novo;
		tam_list++;
	}
	else if (id <= inicio->id)
	{

		novo->prox = inicio;

		inicio = novo;
		tam_list++;
	}
	else if (id >= fim->id)
	{

		fim->prox = novo;

		fim = novo;
		tam_list++;
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
		tam_list++;
	}
}

void remover_na_list(int id)
{

	if (id == inicio->id)
	{
		list *lixo = inicio;
		if (tam_list <= 1)
		{
			inicio = NULL;
			fim = NULL;
			free(lixo);
			tam_list--;
		}
		else
		{
			inicio = inicio->prox;
			free(lixo);
			tam_list--;
		}
	}
	else
	{
		list *aux = inicio;
		while (aux->prox->id != id)
		{
			if (aux->prox == NULL)
			{
				printf("Posição invalida!");
				return;
			}
			aux = aux->prox;
		}
		if (aux->prox->prox == NULL)
		{
			fim = aux;
		}
		list *lixo = aux->prox;
		aux->prox = aux->prox->prox;
		free(lixo);
		tam_list--;
	}
}

void imprimir(list *aux)
{

	printf("%d ", aux->id);

	// coloca os outros elementos
	printf("%s", aux->nome_aluno);

	printf("\n");

	if (aux->id == fim->id)
	{

		return;
	}
	else
	{

		imprimir(aux->prox);
	}
}

void reconstroi_arvore(no_encomenda *teste)
{
	if (return_raiz() != NULL)
	{
		apaga_abb(return_raiz());
	}
	add_list(ids, teste->nome_aluno, teste->matricula_aluno, teste->titulo_livro, teste->autor_livro);

	int tam_vec = tam_list;
	// vetor_de_id tem o tamanho da lista
	int vetor_de_id[tam_vec];
	// preenche o vetor_de_id com os elementos da lista
	preenche_vec(vetor_de_id, tam_vec);
	// constroi a arvore
	arvore(return_raiz_insert(), vetor_de_id, 0, tam_vec - 1);
	// ids muda o id sequencialmente
	ids++;
}
