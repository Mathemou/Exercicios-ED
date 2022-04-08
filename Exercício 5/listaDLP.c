#include "listaDPL.h"
#include "comida.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct listadlp{
  Comida * comida;
  ListaDlp * prox;
  ListaDlp * ant;
};



ListaDlp * IniciaLista(){
  return NULL;
}

ListaDlp * InsereCardapio(ListaDlp * lista, Comida * comida){
  ListaDlp * nova = (ListaDlp*) malloc (sizeof(ListaDlp));
  nova->comida = comida;
  nova->ant = NULL;
  nova->prox = lista;
  if(lista!=NULL){
    lista->ant = nova;
  }
  return nova;
}

static ListaDlp * Busca (ListaDlp * lista, char * chave){
  ListaDlp * p;
  for (p= lista; p!= NULL; p = p->prox){
    if(strcmp(NomeComida(p->comida), chave)==0){
      return p;
    }
  }
  return NULL;
}

ListaDlp * RetiraCardapio (ListaDlp * lista, char * chave){
  ListaDlp * p = Busca(lista, chave);

  if(p==NULL){
    return NULL;
  }

  if (p->ant != NULL){
    p->ant->prox = p->prox;
  } else {
    lista = p->prox;
    lista->ant = NULL;
  }

  if(p->prox==NULL){
    p->prox->ant = p->ant;
  } else {
    p->ant->prox = NULL;
  }

  free(p);

  return lista;
}

void ImprimeCardapio(ListaDlp * lista){
  ListaDlp * p;
  for (p=lista; p!=NULL; p=p->prox){
    ImprimeComida(p->comida);
  }
}

void DestroiCardapio(ListaDlp * lista){
  ListaDlp * p = lista;
  ListaDlp * t;

  while(p!=NULL){
    t = p->prox;
    free(p);
    p = t;
  }

}
