#include <stdio.h>
#include "aluno.h"
#include "FilaComLista.h"
#include "ListaComSentinela.h"

struct filalist {
  Lista * lista;
};

FilaList * InicFilaList(){
  FilaList * fila = (FilaList*) malloc (sizeof(FilaList));
  fila->lista=InicLista();
  return fila;
}

void InsereFilaList(FilaList * fila, Aluno * aluno){
  InsereLista(fila->lista, aluno);
}

Aluno * RetiraFilaList(FilaList * fila){
  return RetiraPosicao(fila->lista, 0);
}

void ImprimeFilaList(FilaList * fila){
  imprimeLista(fila->lista);
}

void DestroiFilaList(FilaList * fila){
  DestroiLista(fila->lista);
  free(fila);
}
