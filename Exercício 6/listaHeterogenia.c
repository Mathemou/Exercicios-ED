#include "gato.h"
#include "cachorro.h"
#include "listaHeterogenia.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define GATO 0
#define CACHORRO 1

typedef struct cel Celula;

struct cel{
  Celula * prox;
  void * item;
  int tipo;
};

struct listaHet{
  Celula * prim;
  Celula * ult;
};

ListaHet * InicLista (){
  ListaHet * lista = (ListaHet*) malloc (sizeof(ListaHet));
  lista->prim = NULL;
  lista->ult = NULL;
  return lista;
}

void InsereCachorro (ListaHet * pets, Cachorro * cachorro){
  Celula * nova = (Celula*) malloc (sizeof(Celula));
  nova->item = cachorro;
  nova->tipo = CACHORRO;
  nova->prox = pets->prim;
  pets->prim = nova;
  if(pets->ult==NULL){
    pets->ult = nova;
  }
}

void InsereGato (ListaHet * pets, Gato * gato){
  Celula * nova = (Celula*) malloc (sizeof(Celula));
  nova->item = gato;
  nova->tipo = GATO;
  nova->prox = pets->prim;
  pets->prim = nova;
  if(pets->ult==NULL){
    pets->ult = nova;
  }
}

void ImprimeAnimaiszinhos(ListaHet* pets){
  Celula * p;
  printf("PETS DO DIA~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
  for(p=pets->prim; p!=NULL;p=p->prox){
    if(p->tipo == CACHORRO){
      ImprimeCachorro((Cachorro*)p->item);
    }
    if(p->tipo == GATO){
      ImprimeGato((Gato*)p->item);
    }
  }
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n");
}

//Para cachorro: 5 reais p/ quilo;
//Para gatos: 25 se ele for manso, 30 se for arisco;
void CustoDaTosa(ListaHet * pets){
  float valor=0;
  Celula * p;

  for(p=pets->prim; p!=NULL;p=p->prox){
    if(p->tipo == CACHORRO){
      valor += RetornaPesoCachorro(p->item)*5;
    }
    if (p->tipo == GATO){
      if (RetornaGatoArisco(p->item)){
        valor += 30;
      } else {
        valor +=25;
      }
    }
  }

  printf("Valor total do banho de todos os pets: %.2f", valor);
}

void DestroiLista(ListaHet * pets){
  Celula * p = pets->prim;
  Celula * t;
  while (p!=NULL){
    t = p->prox;
    free(p);
    p = t;
  }

  free(pets);
}
