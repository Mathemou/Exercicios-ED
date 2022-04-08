#include <stdio.h>
#include "listaMat.h"

int main(void) {
  Matriz * mat1 = inicializaMatriz(2, 2, "mat1");
  for (int i=0;i<2;i++)
        for (int j=0;j<2; j++)
            modificaElemento(mat1, i, j,i+j);

  Matriz * mat2 = inicializaMatriz(3, 3, "mat2");
  for (int i=0;i<3;i++)
        for (int j=0;j<3; j++)
            modificaElemento(mat2, i, j,i+j);

  Matriz * mat3 = inicializaMatriz(4, 4, "mat3");
  for (int i=0;i<4;i++)
        for (int j=0;j<4; j++)
            modificaElemento(mat3, i, j,i+j);

  Matriz * mat4 = inicializaMatriz(5, 4, "mat4");
  for (int i=0;i<5;i++)
        for (int j=0;j<4; j++)
            modificaElemento(mat4, i, j,i+j);

  Lista * lista = InicLista();
  InsereLista(lista, mat1);
  InsereLista(lista, mat2);
  InsereLista(lista, mat3);
  InsereLista(lista, mat4);

  printf("Matrizes comuns:\n");
  imprimeLista(lista);

  Matriz * matt1 = transposta(mat1);
  Matriz * matt2 = transposta(mat2);
  Matriz * matt3 = transposta(mat3);
  Matriz * matt4 = transposta(mat4);

  Lista * listat = InicLista();
  InsereLista(listat, matt1);
  InsereLista(listat, matt2);
  InsereLista(listat, matt3);
  InsereLista(listat, matt4);

  printf("Matrizes transpostas:\n");
  imprimeLista(listat);

  printf("Lista sem mat1:\n");
  RetiraLista(lista, "mat1");
  imprimeLista(lista);

  Matriz * mat5 = inicializaMatriz(3, 2, "mat5");
  for (int i=0;i<3;i++)
        for (int j=0;j<2; j++)
            modificaElemento(mat5, i, j,i+j);

  printf("Lista com mat5:\n");
  InsereLista(lista, mat5);
  imprimeLista(lista);

  DestroiLista(lista);
  DestroiLista(listat);
  return 0;
}
