#include <stdio.h>

#include <stdlib.h>

#include <string.h>



typedef struct NO {

  int id;

  char *nome;



  struct NO *esq;

  struct NO *dir;

} NO;



typedef struct list {

  int id;

  char *nome;



  struct list *prox;

}list;



// valores da arvore
NO *raiz_insert = NULL;

NO *raiz = NULL;

int tamp_temp = 0;


// valores da lista
list *inicio = NULL;

list *fim = NULL;

int tam_list = 0;



//valor do id automatico
int ids = 1;



// adiciona na lista
void add_list(int id, char *nome){

  list *novo = (list*)malloc(sizeof(list));

  novo->id = id;

  // colocar os outros elementos
  novo->nome = nome;

  novo->prox = NULL;

  if(inicio == NULL){

    inicio = novo;

    fim = novo;
    tam_list++;

  }else if(id <= inicio->id){

    novo->prox = inicio;

    inicio = novo;
    tam_list++;

  }else if(id >= fim->id){

    fim->prox = novo;

    fim = novo;
    tam_list++;

  }else{

    list *aux = inicio;

    while(aux->prox->id < novo->id){

      aux = aux->prox;

    }

    novo->prox = aux->prox;

    aux->prox = novo;
    tam_list++;

  }

}

//remove da lista
void remover_na_list(int id){

  if(id == inicio->id){
    list *lixo = inicio;
    if(tam_list <= 1){
      inicio = NULL;
      fim = NULL;
      free(lixo);
      tam_list--;
    }else{
      inicio = inicio->prox;
      free(lixo);
      tam_list--;
    }
  }else{
    list *aux = inicio;
    while(aux->prox->id != id){
      if(aux->prox == NULL){
        printf("Posição invalida!");
        return;
      }
      aux = aux->prox;
    }
    if(aux->prox->prox == NULL){
      fim = aux;
    }
    list *lixo = aux->prox;
    aux->prox = aux->prox->prox;
    free(lixo);
    tam_list--;
  }
}



// imprime a lista
void imprimir(list *aux){

  printf("%d ",aux->id);

  // coloca os outros elementos
  printf("%s", aux->nome);

  printf("\n");

  if(aux->id == fim->id){

    return;

  }else{

    imprimir(aux->prox);

  }

}



//busca na arvore
NO* buscaRecursiva(NO *no, int id) {

  if (no == NULL)

    return NULL;

  else if (no->id == id)

    return no;

  else if (no->id > id)

    return buscaRecursiva(no->esq, id);

  else

    return buscaRecursiva(no->dir, id);

}



//insere na arvore
NO *insere_na_arvore(NO *no, int id) {

  list *aux = inicio;

  if (no == NULL){

    no = (NO *) malloc(sizeof(NO));

    no->id = id;

    if(aux->id < id){

      while (aux->id < id){

        aux = aux->prox;

      }  

    }

    // coloca os outros elementos
    no->nome = aux->nome;

    no->esq = NULL;

    no->dir = NULL;

  }else if(id < (no->id)){

    no->esq = insere_na_arvore(no->esq, id);

  }else if(id > (no->id)){

    no->dir = insere_na_arvore(no->dir, id);

  }else{

    printf("Inserção inválida! "); // id já existe

    exit(1);

  }

  return no;

}



//busca o valor para depois chamar : incere_na_arvore
void arvore(NO *raiz_insert, int vetor_de_id[], int inicio, int fim) {

  if (inicio <= fim) {

    int meio = (inicio + fim) / 2;

    raiz_insert = insere_na_arvore(raiz_insert, vetor_de_id[meio]);

    if(raiz == NULL){

      raiz = raiz_insert;

    }



    arvore(raiz_insert, vetor_de_id, inicio, meio - 1);

    arvore(raiz_insert, vetor_de_id, meio + 1, fim);

  }

}



//remove da arvore
NO *abb_remove(NO *r, int v){

  if(r == NULL){

    return NULL;

  }else if(r->id > v){

    r->esq = abb_remove(r->esq, v);

  }else if(r->id < v){

    r->dir = abb_remove(r->dir, v);

  }else{

    if(r->esq == NULL && r->dir == NULL){
      free(r);

      r = NULL;

    }else if(r->esq == NULL){

      NO *t = r;

      r = r->esq;

    }else{

      NO *f = r->esq;

      while(f->dir != NULL){

        f = f->dir;

      }

      r->id = f->id;
      //faz a mesma coisa com os outros elementos
      r->nome = f->nome;

      f->id = v;

      r->esq = abb_remove(r->esq, v);

    }

  }

  return r;

}


//faz o free na arvore inteira para depois usar a função que reconstroi
void apaga_abb(NO *aux)

{

	if (aux == NULL) {

		return;

	}



	apaga_abb(aux->esq);

	apaga_abb(aux->dir);



	free(aux);



	aux = NULL;

}

// in_ordem modificado para a arvore apos a remoção
void in_ordem(NO *aux){

    if(aux == NULL){
      printf("Vazio!");
      return;
    }

    if(aux->esq != NULL){

        in_ordem(aux->esq);

    }

    printf("ID: ");

    printf("%d\t", aux->id);

    //coloca os outros elementos
    printf("Nome: ");

    printf("%s\n", aux->nome);

    if(aux->dir != NULL){

        in_ordem(aux->dir);

    }

}


//preenche o vetor "vetor_de_id" com os ids da lista
void preenche_vec(int vetor_de_id[], int tam_vec){

  list *aux = inicio;



  for(int i = 0; i < tam_vec; i++){

    vetor_de_id[i] = aux->id;

    aux = aux->prox;

  }

}



int main() {



    int choice;

    int seu_id;

    char user_name[100];

    do{

        printf("--------------------------------\n"

               "| 0 : Adicionar                |\n"

               "| 1 : Remover                  |\n"

               "| 2 : Imprimir                 |\n"

               "| 3 : Buscar                   |\n"

               "| 4 : Sair                     |\n"

               "--------------------------------\n");

        

        printf("Digite: ");

        scanf("%d", &choice);

        

    }while (choice != 0 && choice != 1 && choice != 2 && choice != 3 && choice != 4);



    if(choice == 0){

        printf("Digite seu nome: ");

        scanf(" %[^\n]s ", user_name);
        
        /*faz o free na arrvore se ela for != de NULL
          para poder reconstruir*/
        if(raiz != NULL){

          apaga_abb(raiz);

        }

        add_list(ids, user_name);

        int tam_vec = tam_list;
        // vetor_de_id tem o tamanho da lista
        int vetor_de_id[tam_vec];
        // preenche o vetor_de_id com os elementos da lista
        preenche_vec(vetor_de_id, tam_vec);
        // constroi a arvore
        arvore(raiz_insert,vetor_de_id,0,tam_vec-1);
        // ids muda o id sequencialmente
        ids++;
        //aumenta o tamanho da arvore
        tamp_temp++;

    }else if(choice == 1){

        printf("Seu ID: ");

        scanf("%d", &seu_id);
        //remove da arvore
        abb_remove(raiz, seu_id);
        // remove da lista
        remover_na_list(seu_id);
        // diminui o tamanho da arvore 
        tamp_temp--;

    }else if(choice == 2){

        // utilizar para evitar erros quando tamp_temp for 0 raiz = NULL
        if(tamp_temp == 0){
          raiz = NULL;
        }
        in_ordem(raiz);
        printf("\n\n");
        // pre_ordem(raiz);
        // printf("\n\n");
        // pos_ordem(raiz);
        printf("%d", tam_list);
        printf("\n\n");

    }else if(choice == 3){

        printf("Seu ID: ");

        scanf("%d", &seu_id);

        NO *busc = buscaRecursiva(raiz, seu_id);

        printf("ID: %d\n", busc->id);

        printf("Nome: %s\n", busc->nome);

    }



    if(choice != 4){

        main();

    }



//   add_list(2, "jovi");

//   add_list(1, "pedro");

//   add_list(4, "billy");

//   add_list(3, "felp");

//   add_list(5, "wes");

//   imprimir(inicio);

//   printf("\n\n");

//   int tam_vec = fim->id;

//   int vetor_de_id[tam_vec];

//   preenche_vec(vetor_de_id, tam_vec);





//   arvore(raiz_insert,vetor_de_id,0,tam_vec-1);

//   printf("Pos Ordem:\n");

//   pos_ordem(raiz);

//   printf("\n\n");

//   printf("In Ordem:\n");

//   in_ordem(raiz);

//   printf("\n\n");

//   printf("Pre Ordem:\n");

//   pre_ordem(raiz);



//   abb_remove(raiz, 2);

//   printf("\n\n");

//   printf("Pos Ordem:\n");

//   pos_ordem(raiz);

//   printf("\n\n");

//   printf("In Ordem:\n");

//   in_ordem(raiz);

//   printf("\n\n");

//   printf("Pre Ordem:\n");

//   pre_ordem(raiz);



  return 0;

};