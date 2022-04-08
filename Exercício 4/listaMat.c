#include "listaMat.h"
#include <string.h>

typedef struct cel Celula;

struct cel {
  Matriz * mat;
  Celula* prox;
};

struct lista{
  Celula * prim;
  Celula * ult;
};

typedef struct lista Lista;

Lista* InicLista(){
  Lista * lista = (Lista*) malloc (sizeof(Lista));
  lista->prim = NULL;
  lista->ult=NULL;
  return lista;
}

void InsereLista(Lista* lista, Matriz * mat){
  Celula * nova = (Celula*) malloc (sizeof(Celula));
  nova->mat = mat;
  nova->prox = lista->prim;
  lista->prim = nova;
  if (lista->ult==NULL){
    lista->ult = nova;
  }
}

void imprimeLista(Lista* lista){
  Celula * p;

  for(p = lista->prim; p!=NULL; p = p->prox){
    imprimeMatriz(p->mat);
  }
}

Matriz * RetiraLista(Lista * lista, char * chave){
  Celula * p = lista->prim;
  Matriz * mat;
  Celula * ant = NULL;

  while (p!=NULL && strcmp (RetornaNome(p->mat), chave)){
    ant = p;
    p = p->prox;
  }

  if (p==NULL){
    return NULL;
  }

  mat = p->mat;

  if (p== lista->prim && p == lista->ult){
    lista->prim = lista->ult = NULL;
  } else if (p==lista->prim){
    lista->prim = p->prox;
  } else if (p==lista->ult){
    lista->ult = ant;
    lista->ult->prox = NULL;
  } else {
    ant->prox = p->prox;
  }

  free(p);

  return mat;
}

void DestroiLista(Lista* lista){
   Celula * p = lista->prim;
  Celula * t;

  while (p!=NULL){
    t = p->prox;
    destroiMatriz(p->mat);
    free(p);
    p = t;
  }

  free(lista);
}
