#include "aluno.h"
#include <stdlib.h>

typedef struct lista Lista;

Lista* InicLista();

void InsereLista(Lista* lista, Aluno * al);

void imprimeLista(Lista* lista);

Aluno * RetiraLista(Lista * lista, char * chave);

Aluno * RetiraPosicao(Lista * lista, int pos);

void DestroiLista(Lista* lista);
