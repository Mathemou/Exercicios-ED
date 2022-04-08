#include "gato.h"
#include "cachorro.h"
#include "listaHeterogenia.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NEHARISCO 0
#define EHARISCO 1

int main(void) {
  Cachorro * rex = InicCachorro("Rex", 2.5);
  Gato * mingau = InicGato("Mingau", EHARISCO);
  Gato * alvarininho = InicGato("Alvarininho", NEHARISCO);
  Gato * eugenio = InicGato("Eugenio", NEHARISCO);
  Cachorro * tony = InicCachorro("Tony", 120);
  Cachorro * fred = InicCachorro("Fred", 10);

  ListaHet * pets = InicLista();

  InsereCachorro(pets, rex);
  InsereGato(pets, mingau);
  InsereGato(pets, alvarininho);
  InsereGato(pets, eugenio);
  InsereCachorro(pets, tony);
  InsereCachorro(pets, fred);

  ImprimeAnimaiszinhos(pets);

  CustoDaTosa(pets);

  DestroiLista(pets);

  DestroiCachorro(rex);
  DestroiGato(mingau);
  DestroiGato(alvarininho);
  DestroiGato(eugenio);
  DestroiCachorro(tony);
  DestroiCachorro(fred);

  return 0;
}
