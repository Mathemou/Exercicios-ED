#ifndef ListaDLP_h
#define ListaDLP_h

#include <stdio.h>
#include "comida.h"

typedef struct listadlp ListaDlp;

ListaDlp * IniciaLista(void);

ListaDlp * InsereCardapio(ListaDlp * lista, Comida * comida);

ListaDlp * RetiraCardapio(ListaDlp * lista, char * nome);

void ImprimeCardapio(ListaDlp * lista);

void DestroiCardapio(ListaDlp * lista);

#endif
