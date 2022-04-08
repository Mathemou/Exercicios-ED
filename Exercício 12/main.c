#include <stdio.h>
#include "listagen.h"
#include "aluno.h"
#include "listaalunos.h"

int main(void) {
  ListaGen * lista = criaLista();

  Aluno * Matheus = InicAluno(123, "Matheus", 10);
  lista = insereLista(lista, Matheus);
  Aluno * Carlos = InicAluno(124, "Carlos", 7);
  lista = insereLista(lista, Carlos);
  Aluno * Bruno = InicAluno(125, "Bruno", 5);
  lista = insereLista(lista, Bruno);
  Aluno * Daniel = InicAluno(126, "Daniel", 3);
  lista = insereLista(lista, Daniel);
  Aluno * Eugenio = InicAluno(127, "Eugenio", 5);
  lista = insereLista(lista, Eugenio);
  Aluno * Francisco = InicAluno(128, "Francisco", 4);
  lista = insereLista(lista, Francisco);
  Aluno * Geraldo = InicAluno(129, "Geraldo", 2);
  lista = insereLista(lista, Geraldo);
  Aluno * Ivan = InicAluno(130, "Ivan", 1);
  lista = insereLista(lista, Ivan);
  Aluno * Joaquim = InicAluno(131, "Joaquim", 5.5);
  lista = insereLista(lista, Joaquim);
  Aluno * Kaua = InicAluno(132, "Kaua", 7.8);
  lista = insereLista(lista, Kaua);
  Aluno * Leonardo = InicAluno(133, "Leonardo", 9.9);
  lista = insereLista(lista, Leonardo);
  Aluno * Nathan = InicAluno(134, "Nathan", 0.1);
  lista = insereLista(lista, Nathan);
  Aluno * Osvaldo = InicAluno(135, "Osvaldo", 4);
  lista = insereLista(lista, Osvaldo);
  Aluno * Pedro = InicAluno(136, "Pedro", 8.8);
  lista = insereLista(lista, Pedro);
  Aluno * Queiroz = InicAluno(137, "Queiroz", 1);
  lista = insereLista(lista, Queiroz);

  printf("Lista incial\n---------------------------------\n");

  imprimeListaAlunos(lista);

  lista = retiraAluno(lista, 137);
  lista = retiraAluno(lista, 136);
  lista = retiraAluno(lista, 135);
  lista = retiraAluno(lista, 134);
  lista = retiraAluno(lista, 133);
  lista = retiraAluno(lista, 132);

  printf("Após retirar alunos 137, 136, 135, 134, 133 e 132\n---------------------------------\n\n");
  imprimeListaAlunos(lista);

  if(pertenceAluno(lista, 123)==0){
    printf("\n\nO aluno com matricula 123 (Matheus) está na lista.\n");
  } else {
    printf("\n\nO aluno com matricula 123 não está na lista.\n");
  }

  if(pertenceAluno(lista, 999)==0){
    printf("\n\nO aluno com matricula 999 (???) está na lista.\n");
  } else {
    printf("\n\nO aluno com matricula 999 não está na lista.\n");
  }

  
  printf("\n--------------\nA média da turma é: %.2f\n--------------\n", mediaTurma(lista));
  
  liberaLista(lista);
  DestroiAluno(Matheus);
  DestroiAluno(Carlos);
  DestroiAluno(Bruno);
  DestroiAluno(Daniel);
  DestroiAluno(Eugenio);
  DestroiAluno(Francisco);
  DestroiAluno(Geraldo);
  DestroiAluno(Ivan);
  DestroiAluno(Joaquim);
  DestroiAluno(Kaua);
  DestroiAluno(Leonardo);
  DestroiAluno(Nathan);
  DestroiAluno(Osvaldo);
  DestroiAluno(Pedro);
  DestroiAluno(Queiroz);
  
  return 0;
}