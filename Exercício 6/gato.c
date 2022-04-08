#include "gato.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct gato{
  char * nome;
  int arisco;
};

Gato * InicGato(char * nome, int arisco){
  Gato * gato = (Gato*) malloc (sizeof(Gato));
  gato->nome = strdup(nome);
  gato->arisco = arisco;
  return gato;
}

int RetornaGatoArisco(Gato * gato){
  return gato->arisco;
}

void ImprimeGato(Gato * gato){
  printf("GATO\nNome do gato: %s\n", gato->nome);
  if(gato->arisco){
    printf("Cuidado!!!Gato arisco!!!\n\n");
  } else {
    printf("Esse bichano eh da paz\n\n");
  }
}

void DestroiGato(Gato * gato){
  free(gato);
}
