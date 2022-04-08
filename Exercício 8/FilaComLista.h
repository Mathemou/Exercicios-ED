#include <stdio.h>
#include "aluno.h"

typedef struct filalist FilaList;

FilaList * InicFilaList();

void InsereFilaList(FilaList * fila, Aluno * aluno);

Aluno * RetiraFilaList(FilaList * fila);

void ImprimeFilaList(FilaList * fila);

void DestroiFilaList(FilaList * fila);
