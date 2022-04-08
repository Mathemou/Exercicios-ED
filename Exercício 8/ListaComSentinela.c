#include "ListaComSentinela.h"
#include "aluno.h"
typedef struct cel Celula;

struct cel {
  Aluno* al;
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

void InsereLista(Lista* lista, Aluno * al){
  Celula * nova = (Celula*) malloc (sizeof(Celula));
  nova->al = al;
  nova->prox = lista->prim;
  lista->prim = nova;
  if (lista->ult==NULL){
    lista->ult = nova;
  }

}

void imprimeLista(Lista* lista){
  Celula * p;

  for(p = lista->prim; p!=NULL; p = p->prox){
    ImprimeAluno(p->al);
  }
}

Aluno * RetiraLista(Lista * lista, char * chave){
  Celula * p = lista->prim;
  Aluno * al;
  Celula * ant = NULL;

  while (p!=NULL && strcmp (RetornaNome(p->al), chave)){
    ant = p;
    p = p->prox;
  }

  if (p==NULL){
    return NULL;
  }

  al = p->al;

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

  return al;

}

Aluno * RetiraPosicao(Lista * lista, int pos){
  Celula * p;
  int i =0;
  for(p=lista->prim;p!=NULL;p=p->prox){
    if(i==pos){
      RetiraLista(lista, RetornaNome(p->al));
      return p->al;
    }
  }
}

void DestroiLista(Lista* lista){
  Celula * p = lista->prim;
  Celula * t;

  while (p!=NULL){
    t = p->prox;
    DestroiAluno(p->al);
    free(p);
    p = t;
  }

  free(lista);
}
