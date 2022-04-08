#include "matriz.h"
#include <stdlib.h>

typedef struct lista Lista;

Lista* InicLista();

void InsereLista(Lista* lista, Matriz * mat);

void imprimeLista(Lista* lista);

Matriz * RetiraLista(Lista * lista, char * chave);

void DestroiLista(Lista* lista);
