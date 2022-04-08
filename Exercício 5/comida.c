#include "comida.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct comida{
  char * nome;
  char * sabor;
  int nota;
  float preco;
};

Comida* NovaComida (char * nome, char * sabor, int nota, float preco){
  Comida * comida;
  comida = (Comida*) malloc (sizeof(Comida));
  comida->nome = strdup(nome);
  comida->sabor = strdup(sabor);
  comida->nota = nota;
  comida->preco = preco;
  return comida;
}

void MudaPreco (Comida * comida, float novopreco){
  comida->preco = novopreco;
}

void MudaNota (Comida * comida, int novanota){
  comida->nota = novanota;
}

char * NomeComida(Comida * comida){
  return comida->nome;
}

char * SaborComida(Comida * comida){
  return comida->sabor;
}

int NotaComida(Comida * comida){
  return comida->nota;
}

float PrecoComida(Comida * comida){
  return comida->preco;
}

void ImprimeComida(Comida * comida){
  printf("Nome: %s\nSabor: %s\nNota: %d\nPreco: %.2f\n\n", comida->nome, comida->sabor, comida->nota, comida->preco);
}

void DestroiComida(Comida * comida){
  free(comida->nome);
  free(comida->sabor);
  free(comida);
}
