#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno Aluno;

Aluno * InicAluno(int mat, char * nome, float CR);

void ImprimeAluno (Aluno* aluno);

int RetornaMat(Aluno * al);

char * RetornaNome(Aluno * al);

float RetornaCR(Aluno* al);

Aluno * MudaCR(Aluno * aluno, float CR);

void DestroiAluno(Aluno * al);
