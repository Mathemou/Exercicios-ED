#include "palavra.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct palavra {
  char * string;
  int n;
  struct palavra * prox;
};

Palavra * inicPalavra(char * string){
  Palavra * pal = (Palavra*) malloc (sizeof(Palavra));
  pal->string = strdup(string);
  pal->n=0;
  pal->prox=NULL;
  return pal;
}

char * retornaString(Palavra * palavra){
  return palavra->string;
}

void atualizaOcorrencias (Palavra * palavra){
  palavra->n++;
}

int retornaOcorrencias (Palavra * palavra){
  return palavra->n;
}

Palavra * buscaPalavra (Palavra * palavra, char * string){
  Palavra * p;
  for(p=palavra;p!=NULL;p=p->prox){
    if(strcmp(p->string, string)==0){
      return p;
    }
  }
  return NULL;
}

Palavra * inserePalavraLista(Palavra * lista, Palavra * p){
  p->prox = lista;
  return p;
}

int contaPalavrasLista(Palavra * p){
  Palavra * pal;
  int i=0;
  for(pal=p;p!=NULL;p=p->prox){
    i++;
  }
  return i;
}

void imprimirLista(Palavra * p){
  Palavra * aux;
  for(aux = p; aux!= NULL; aux=aux->prox){
    printf("String: %s - Ocorrencias: %d\n", aux->string, aux->n);
  }
}

void liberaListaPalavras(Palavra * p){
  Palavra * aux = p;
  Palavra * t;
  while(aux!=NULL){
    t = aux->prox;
    free(aux->string);
    free(aux);
    aux=t;
  }
}