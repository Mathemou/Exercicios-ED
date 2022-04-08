#include "palavra.h"
#include "hash.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct hash {
  Palavra ** vet;
  int tamanho;
};

static int hash (char * s, int tamanho){
  int i;
  int total = 0;
  for (i=0;s[i]!='\0';i++){
    total+=s[i];
    
  }
  return (total%tamanho);
}

Hash * inicHash(int tam){
  int i;
  Hash * h = (Hash*) malloc (sizeof(Hash));
  h->tamanho = tam;
  h->vet = (Palavra**)malloc(tam*sizeof(Palavra*));
  for(i=0;i<tam;i++){
    h->vet[i]=NULL;
  }
  return h;
  
}

Palavra * acessa(Hash * h, char * string){
  Palavra * p;
  int indice = hash(string, h->tamanho);
  p = buscaPalavra(h->vet[indice], string);
  if(p!=NULL){
    return p;
  }
  p = inicPalavra(string);
  h->vet[indice] = inserePalavraLista(h->vet[indice], p);
  return p;
}

int contaPalavras(Hash * h);

void imprimeHash(Hash * h){
  int i;
  for (i=0; i<h->tamanho;i++){
    printf("\nPosição do vetor[%d]: \n", i);
    imprimirLista(h->vet[i]);
  }
}

void liberaHash(Hash * h){
  int i;
  for(i=0;i<h->tamanho;i++){
    liberaListaPalavras(h->vet[i]);
  }
  free(h->vet);
  free(h);
}