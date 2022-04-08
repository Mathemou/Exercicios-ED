#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno{
  int mat;
  char * nome;
  float CR;
};

Aluno * InicAluno(int mat, char * nome, float CR){
  Aluno * aluno = (Aluno*) malloc (sizeof(Aluno));
  aluno->mat = mat;
  aluno->CR = CR;
  aluno->nome = strdup(nome);
  return aluno;
}

void ImprimeAluno (Aluno* aluno){
  printf("Nome: %s\nMatricula: %d\nCR: %.2f\n", aluno->nome, aluno->mat, aluno->CR);
}

int RetornaMat(Aluno * al){
  return al->mat;
}

char * RetornaNome(Aluno * al){
  return al->nome;
}

float RetornaCR(Aluno* al){
  return al->CR;
}

void DestroiAluno(Aluno * al){
  free(al->nome);
  free(al);
}
