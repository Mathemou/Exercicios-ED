#include <stdio.h>
#include "aluno.h"
#include "FilaComVetor.h"
#include "FilaComLista.h"

int main(void) {
  Aluno * matheus = InicAluno(2020102131, "Matheus", 8);
  Aluno * daniela = InicAluno(2020102132, "Daniela", 10);
  Aluno * monica = InicAluno(2020102133, "Monica", 10);
  Aluno * alexandre = InicAluno(2020102134, "Alexandre", 6);
  FilaList * fila = InicFilaList();
  InsereFilaList(fila, matheus);
  InsereFilaList(fila, daniela);
  InsereFilaList(fila, monica);
  InsereFilaList(fila, alexandre);
  ImprimeFilaList(fila);
  RetiraFilaList(fila);
  ImprimeFilaList(fila);
  /*
  teste fila com vet
  FilaVet * fila = InicFilaVet();
  InsereFilaVet(fila, matheus);
  InsereFilaVet(fila, daniela);
  InsereFilaVet(fila, monica);
  InsereFilaVet(fila, alexandre);
  ImprimeFilaVet(fila);
  RetiraFilaVet(fila);
  printf("~\n");
  ImprimeFilaVet(fila);]
  DestroiFilaVet(fila);
  */
  DestroiAluno(matheus);
  DestroiAluno(daniela);
  DestroiAluno(monica);
  DestroiAluno(alexandre);
  return 0;
}
