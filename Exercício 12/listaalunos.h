#include "listagen.h"
#include "aluno.h"
#include <stdio.h>

ListaGen * retiraAluno(ListaGen * lista, int matricula);

int pertenceAluno(ListaGen * lista, int matricula);

void imprimeListaAlunos(ListaGen * lista);

float mediaTurma(ListaGen * lista);