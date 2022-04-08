#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno{
  char* nome;
  int matricula;
  float p1;
  float p2;
  float p3;
} Aluno;

void imprime_aprovados (int n, Aluno** turma);

float media_turma (int n, Aluno** turma);

void PreencherTurma(int n, Aluno ** turma);

char * LeNome(void);

int main(void) {
  int n;
  char str[51];
  Aluno ** turma;
  printf("Informe o número de alunos na turma: ");
  scanf("%d", &n);
  //Aloca espaço para os alunos na turma;
  turma = (Aluno**) malloc (n*sizeof(Aluno*));
  //Aloca o espaço pro aluno na turma;
  for (int i=0;i<n;i++){
    turma[i] = (Aluno*) malloc (sizeof(Aluno));
  }
  PreencherTurma(n, turma);
  printf("\n\n\n");
  imprime_aprovados (n , turma);
  printf("\n\nMedia da turma: %f", media_turma(n, turma));
    for (int i=0;i<n;i++){
        free(turma[i]);
    }
    free(turma);
  return 0;
}

void PreencherTurma(int n, Aluno ** turma){
  for (int i=0; i<n;i++){
    printf("Digite os dados do aluno %d:\n", i+1);
    printf("Nome: ");
    turma[i]->nome = LeNome();
    printf("Matricula: ");
    scanf("%d", &turma[i]->matricula);
    printf("Nota primeira prova: ");
    scanf("%f", &turma[i]->p1);
    printf("Nota segunda prova: ");
    scanf("%f", &turma[i]->p2);
    printf("Nota terceira prova: ");
    scanf("%f", &turma[i]->p3);
  }
}

char * LeNome(){
  char str[51];
  scanf(" %50[^\n]", str);
  return strdup(str);
}

void imprime_aprovados (int n, Aluno** turma){
  float media;
  printf("Alunos aprovados: \n");
  for (int i=0;i<n;i++){
    media = (turma[i]->p1+turma[i]->p2+turma[i]->p3)/3;
    if (media>=5){
      printf("%s\n", turma[i]->nome);
    }
  }
}

float media_turma(int n, Aluno ** turma){
  float media=0;
  for (int i=0; i<n; i++)
    media += (turma[i]->p1+turma[i]->p2+turma[i]->p3)/3;
  media /= n;
  return media;
}
