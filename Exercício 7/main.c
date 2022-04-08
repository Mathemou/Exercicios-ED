#include <stdio.h>
#include "aluno.h"
#include "TadPilhasDuplas.h"

int main(void) {
  Aluno * matheus = InicAluno(2020102131, "Matheus", 5);
  Aluno * daniela = InicAluno(2020102132, "Daniela", 10);
  Aluno * monica = InicAluno(2020102133, "Monica", 10);
  Aluno * alexandre = InicAluno(2020102134, "Alexandre", 2);
  Aluno * jorge = InicAluno(2020102135, "Jorge", 10);

  TipoPilhaDupla * Alunos = inicializaPilha();


  push_pilha2(Alunos, daniela);
  push_pilha2(Alunos, monica);
  push_pilha1(Alunos, alexandre);
  push_pilha1(Alunos, matheus);

  ImprimePilha1(Alunos);
  ImprimePilha2(Alunos);
  printf("\nAtualizando situacao...\n\n");
  MudaCR(matheus, 8);
  push_pilha2(Alunos, pop_pilha1(Alunos));

  push_pilha2(Alunos, jorge);

  ImprimePilha1(Alunos);
  ImprimePilha2(Alunos);

  printf("\nAtualizando situacao...\n\n");
  MudaCR(jorge, 3);
  push_pilha1(Alunos, pop_pilha2(Alunos));

  ImprimePilha1(Alunos);
  ImprimePilha2(Alunos);



  DestroiAluno(matheus);
  DestroiAluno(daniela);
  DestroiAluno(monica);
  DestroiAluno(alexandre);

  destroi(Alunos);
  return 0;
}
