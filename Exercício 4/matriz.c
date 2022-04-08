#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct matriz {
  int ** n;
  int linhas;
  int colunas;
  char * nome;
};

Matriz* inicializaMatriz (int nlinhas, int ncolunas, char * nome){
  Matriz * matriz;
  matriz = (Matriz*) malloc (sizeof(Matriz));
  matriz->n = (int**) malloc (nlinhas*sizeof(int *));
  for (int i=0;i<nlinhas;i++){
    matriz->n[i] = (int*) malloc (ncolunas*sizeof(int*));
    for(int j=0;j<ncolunas;j++){
      //matriz->n[i][j] = (int) malloc (sizeof(int));
    }
  }
  matriz->linhas = nlinhas;
  matriz->colunas = ncolunas;
  /*for (int i=0;i<nlinhas*ncolunas;i++){
    matriz[i].elem = (int) malloc (sizeof(int));
  }*/
  matriz->nome = strdup(nome);
  return matriz;
}

void modificaElemento (Matriz* mat, int linha, int coluna, int elem){
  mat->n[linha][coluna]=elem;
}

int recuperaElemento(Matriz* mat, int linha, int coluna){
  return mat->n[linha][coluna];
}

int recuperaNColunas (Matriz* mat){
  return mat->colunas;
}

int recuperaNLinhas (Matriz* mat){
  return mat->linhas;
}

Matriz* transposta (Matriz* mat){
  char * cop;
  cop = strdup(mat->nome);
  cop = strcat(cop, "t");
  Matriz * matt = inicializaMatriz(mat->colunas, mat->linhas, cop);
  matt->linhas = mat->colunas;
  matt->colunas = mat->linhas;
  for(int i=0; i< mat->colunas;i++){
    for(int j=0; j< mat->linhas;j++){
      matt->n[i][j] = mat->n[j][i];
    }
  }
  return matt;
}

Matriz* multiplicacao (Matriz* mat1, Matriz* mat2){
  Matriz * mult = inicializaMatriz(mat1->linhas, mat2->colunas, "multi");
  int aux=0;
  for(int i=0; i<mat1->linhas; i++){
    for (int j=0; j<mat2->colunas; j++){
      for (int k=0; k<mat1->colunas;k++){
        aux += + mat1->n[i][k]*mat2->n[k][j];
      }
      mult->n[i][j] = aux;
      aux=0;
    }
  }
  return mult;
}

void imprimeMatriz(Matriz* mat){
  printf("Nome: %s\n", mat->nome);
  for(int i=0; i<mat->linhas;i++){
    for(int j=0; j<mat->colunas;j++){
      printf("%d ", mat->n[i][j]);
    }
    printf("\n");
  }
  printf("\n\n");
}

void destroiMatriz(Matriz* mat){
  for (int i=0;i<mat->linhas;i++){
    free(mat->n[i]);
  }
  free (mat->n);
  free (mat);
}

char * RetornaNome(Matriz * mat){
  return mat->nome;
}

