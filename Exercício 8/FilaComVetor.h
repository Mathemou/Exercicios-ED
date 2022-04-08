#include <stdio.h>
#include "aluno.h"

typedef struct filavet FilaVet;

FilaVet * InicFilaVet();

void InsereFilaVet(FilaVet * fila, Aluno * aluno);

Aluno * RetiraFilaVet (FilaVet * fila);

void ImprimeFilaVet (FilaVet * fila);

void DestroiFilaVet(FilaVet * fila);

