#include "../include/abb_encomendas.h"


no_encomenda *raiz_insert = NULL;
no_encomenda *raiz = NULL;

no_encomenda *return_raiz_insert(){
    return raiz_insert;
}

no_encomenda *return_raiz()
{
    return raiz;
}

no_encomenda *buscaRecursiva(no_encomenda *no, int id)
{
    if (no == NULL)
        return NULL;
    else if (no->id == id)
        return no;
    else if (no->id > id)
        return buscaRecursiva(no->esq, id);
    else
        return buscaRecursiva(no->dir, id);
}

no_encomenda *insere_na_arvore(no_encomenda *no, int id)
{
    list *aux = return_inicio_list();
    if (no == NULL)
    {
        no = (no_encomenda *)malloc(sizeof(no_encomenda));
        no->id = id;

        if (aux->id < id)
        {

            while (aux->id < id)
            {

                aux = aux->prox;
            }
        }

        // coloca os outros elementos
        no->nome_aluno = aux->nome_aluno;
        no->matricula_aluno = aux->matricula_aluno;
        no->titulo_livro = aux->titulo_livro;
        no->autor_livro = aux->autor_livro;


        no->esq = NULL;
        no->dir = NULL;
    }
    else if (id < (no->id))
    {
        no->esq = insere_na_arvore(no->esq, id);
    }
    else if (id > (no->id))
    {
        no->dir = insere_na_arvore(no->dir, id);
    }
    else
    {
        printf("Inserção inválida! "); // id já existe
        exit(1);
    }
    return no;
}

void arvore(no_encomenda *raiz_insert, int vetor_de_id[], int inicio, int fim)
{

    if (inicio <= fim)
    {

        int meio = (inicio + fim) / 2;

        raiz_insert = insere_na_arvore(raiz_insert, vetor_de_id[meio]);

        if (raiz == NULL)
        {

            raiz = raiz_insert;
        }

        arvore(raiz_insert, vetor_de_id, inicio, meio - 1);

        arvore(raiz_insert, vetor_de_id, meio + 1, fim);
    }
}

void apaga_abb(no_encomenda *aux)
{
    if (aux == NULL)
    {
        return;
    }

    apaga_abb(aux->esq);
    apaga_abb(aux->dir);

    free(aux);

    aux = NULL;
}


no_encomenda *abb_remove(no_encomenda *r, int v){

  if(r == NULL){

    return NULL;

  }else if(r->id > v){

    r->esq = abb_remove(r->esq, v);

  }else if(r->id < v){

    r->dir = abb_remove(r->dir, v);

  }else{

    if(r->esq == NULL && r->dir == NULL){

      r = NULL;

    }else if(r->esq == NULL){

      no_encomenda *t = r;

      r = r->esq;

    }else{

      no_encomenda *f = r->esq;

      while(f->dir != NULL){

        f = f->dir;

      }

      r->id = f->id;
      r->nome_aluno = f->nome_aluno;

      f->id = v;

      r->esq = abb_remove(r->esq, v);

    }

  }
}

void copia_no(no_encomenda *origem, no_encomenda *destino)
{
    int mem_size;
    mem_size = strlen(origem->campus_aluno);
    destino->campus_aluno = (char *)malloc((sizeof(char) * mem_size) + 1);
    strncpy(destino->campus_aluno, origem->campus_aluno, mem_size);
    destino->campus_aluno[mem_size] = '\0';

    mem_size = strlen(origem->campus_livro);
    destino->campus_livro = (char *)malloc((sizeof(char) * mem_size) + 1);
    strncpy(destino->campus_livro, origem->campus_livro, mem_size);
    destino->campus_livro[mem_size] = '\0';

    destino->matricula_aluno = origem->matricula_aluno;

    mem_size = strlen(origem->nome_aluno);
    destino->nome_aluno = (char *)malloc((sizeof(char) * mem_size) + 1);
    strncpy(destino->nome_aluno, origem->nome_aluno, mem_size);
    destino->nome_aluno[mem_size] = '\0';

    destino->prioridade = origem->prioridade;

    mem_size = strlen(origem->autor_livro);
    destino->autor_livro = (char *)malloc((sizeof(char) * mem_size) + 1);
    strncpy(destino->autor_livro, origem->autor_livro, mem_size);
    destino->autor_livro[mem_size] = '\0';

    mem_size = strlen(origem->titulo_livro);
    destino->titulo_livro = (char *)malloc((sizeof(char) * mem_size) + 1);
    strncpy(destino->titulo_livro, origem->titulo_livro, mem_size);
    destino->titulo_livro[mem_size] = '\0';
}

void pos_ordem(no_encomenda *aux)
{

    if (aux->esq != NULL)
    {
        pos_ordem(aux->esq);
    }
    if (aux->dir != NULL)
    {
        pos_ordem(aux->dir);
    }
    printf("ID: ");
    printf("%d\t", aux->id);
    printf("Nome: ");
    printf("%s\n", aux->nome_aluno);
}
void in_ordem(no_encomenda *aux)
{

    if (aux->esq != NULL)
    {
        in_ordem(aux->esq);
    }
    printf("ID: ");
    printf("%d\t", aux->id);
    printf("Nome: ");
    printf("%s\n", aux->nome_aluno);
    if (aux->dir != NULL)
    {
        in_ordem(aux->dir);
    }
}
void pre_ordem(no_encomenda *aux)
{
    printf("ID: ");
    printf("%d\t", aux->id);
    printf("Nome: ");
    printf("%s\n", aux->nome_aluno);
    if (aux->esq != NULL)
    {
        pre_ordem(aux->esq);
    }
    if (aux->dir != NULL)
    {
        pre_ordem(aux->dir);
    }
}