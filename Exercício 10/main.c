#include <stdio.h>
#include "abb.h"
#include "aluno.h"

int main(void) {
  Aluno * matheus = InicAluno(10, "Matheus", 10);
  Aluno * daniela = InicAluno(9, "Daniela", 10);
  Aluno * monica = InicAluno(8, "Monica", 10);
  Aluno * alexandre = InicAluno(11, "Alexandre", 7);
  Aluno * roberto = InicAluno(20, "Roberto", 6);
  Aluno * rosana = InicAluno(30, "Rosana", 4);

  Arvore * arv = abbCria();

  arv = abbInsere(arv, matheus);
  arv = abbInsere(arv, daniela);
  arv = abbInsere(arv, monica);
  arv = abbInsere(arv, roberto);
  arv = abbInsere(arv, alexandre);
  arv = abbInsere(arv, rosana);
  
  printf("Primeira versão da árvore:\n");
  abbImprime(arv);

  abbRetira(arv, 11);

  printf("\n\nSegunda versão da árvore, após remover Alexandre:\n");
  abbImprime(arv);;

  Aluno * cleber = InicAluno(15, "Cleber", 2);
  arv = abbInsere(arv, cleber);
  
  printf("\n\nTerceira versão da árvore, após adicionar Cléber:\n");
  abbImprime(arv);

  abbRetira(arv, 20);

  printf("\n\nQuarta versão da árvore, após retirar Roberto:\n");
  abbImprime(arv);
  
  
  abbLibera(arv);

  DestroiAluno(matheus);
  DestroiAluno(daniela);
  DestroiAluno(monica);
  DestroiAluno(roberto);
  DestroiAluno(alexandre);
  DestroiAluno(rosana);
  DestroiAluno(cleber);
  
  return 0;
}