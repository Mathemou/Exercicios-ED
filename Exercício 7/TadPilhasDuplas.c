#include "TadPilhasDuplas.h"
#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>

#define MaxTam 1000

typedef int TipoItem;

struct indicepilha{
  int Topo, Base;
};

struct tipopilhadupla{
  Aluno * aluno[MaxTam];
  IndicePilha Pilha1, Pilha2;
};

TipoPilhaDupla * inicializaPilha(){
  TipoPilhaDupla * pilha = (TipoPilhaDupla*) malloc (sizeof(TipoPilhaDupla));
  pilha->Pilha1.Topo = 0;
  pilha->Pilha1.Base = 0;
  pilha->Pilha2.Topo = MaxTam-1;
  pilha->Pilha2.Base = MaxTam-1;
  return pilha;
}

void push_pilha1 (TipoPilhaDupla * pilha, Aluno * aluno){
  pilha->aluno[pilha->Pilha1.Topo] = aluno;
  pilha->Pilha1.Topo++;
}

Aluno * pop_pilha1 (TipoPilhaDupla * pilha){
  Aluno * aluno = pilha->aluno[pilha->Pilha1.Topo-1];
  pilha->Pilha1.Topo--;
  return aluno;
}

void push_pilha2 (TipoPilhaDupla * pilha, Aluno * aluno){
  pilha->aluno[pilha->Pilha2.Topo] = aluno;
  pilha->Pilha2.Topo--;
}

Aluno * pop_pilha2 (TipoPilhaDupla * pilha){
  Aluno * aluno = pilha->aluno[pilha->Pilha2.Topo+1];
  pilha->Pilha2.Topo++;
  return aluno;
}

void ImprimePilha1(TipoPilhaDupla * pilha){
  printf("Alunos com CR abaixo de 7:\n");
  for (int i=pilha->Pilha1.Topo-1; i>=pilha->Pilha1.Base; i--){
    ImprimeAluno(pilha->aluno[i]);
  }
  printf("\n~~~~~~~~~~~~~~~~~~~~\n");
}

void ImprimeTopoPilha2(TipoPilhaDupla * pilha){
  printf("%d\n", pilha->Pilha2.Topo);
}

void ImprimeAlunoPorPosicao(TipoPilhaDupla * pilha, int pos){
  ImprimeAluno(pilha->aluno[pos]);
}

void ImprimePilha2(TipoPilhaDupla * pilha){
  printf("Alunos com CR acima de 7:\n");
  for(int i=pilha->Pilha2.Topo+1; i<=pilha->Pilha2.Base;i++){
    ImprimeAluno(pilha->aluno[i]);
  }
  printf("\n~~~~~~~~~~~~~~~~~~~~\n");
}

void destroi(TipoPilhaDupla * p){
  free(p);
}

