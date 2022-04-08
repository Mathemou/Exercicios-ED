#include <stdio.h>
#include "FilaComVetor.h"
#include "aluno.h"

#define TAM 10

struct filavet{
  int ini;
  int n;
  Aluno * alunos[TAM];
};

FilaVet * InicFilaVet(){
  FilaVet * fila = (FilaVet*) malloc (sizeof(FilaVet));
  fila->ini=0;
  fila->n=0;
  return fila;
}

void InsereFilaVet(FilaVet * fila, Aluno * aluno){
  if(!fila||fila->n>=TAM){
    printf("Fila inválida ou cheia\n");
    return;
  }
  int pos = (fila->ini+fila->n) % TAM;
  fila->alunos[pos] = aluno;
  fila->n++;
}

Aluno * RetiraFilaVet(FilaVet * fila){
  if(!fila||fila->n==0){
    printf("Fila inválida ou vazia\n");
    return NULL;
  }
  Aluno * aluno = fila->alunos[fila->ini];
  fila->ini = (fila->ini+1)%TAM;
  fila->n--;
  return aluno;
}

void ImprimeFilaVet(FilaVet * fila){
  int i;
  int pos = 0;
  if (!fila){
    return;
  }
  for(i=0;i<fila->n;i++){
    pos = (fila->ini+i)%TAM;
    ImprimeAluno(fila->alunos[pos]);
  }
}

void DestroiFilaVet(FilaVet * fila){
  if(!fila){
    return;
  }
  free(fila);
}
