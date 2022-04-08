#include "cachorro.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct cachorro{
  char * nome;
  float peso;
};

Cachorro * InicCachorro(char * nome, float peso){
  Cachorro * cachorro = (Cachorro*) malloc (sizeof(Cachorro));
  cachorro->nome = nome;
  cachorro->peso = peso;
  return cachorro;
}

float RetornaPesoCachorro(Cachorro * cachorro){
  return cachorro->peso;
}

void ImprimeCachorro (Cachorro * cachorro){
  printf("CACHORRO\nNome do cachorro: %s\n", cachorro->nome);
  if (cachorro->peso >= 100){
    printf("EH NORMAL UM CACHORRO PESAR TANTO?!\nDeve ser o Tony...\n\n");
  } else {
    printf("\n");
  }
}

void DestroiCachorro(Cachorro * cachorro){
  free(cachorro);
}
