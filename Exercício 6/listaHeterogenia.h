#include <stdio.h>
#include "cachorro.h"
#include "gato.h"

typedef struct listaHet ListaHet;

ListaHet * InicLista();

void InsereCachorro(ListaHet * pets, Cachorro * cachorro);

void InsereGato(ListaHet * pets, Gato * gato);

void ImprimeAnimaiszinhos(ListaHet* pets);

void CustoDaTosa(ListaHet * pets);

void DestroiLista(ListaHet * pets);
