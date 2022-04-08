#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno Aluno;

Aluno * InicAluno(int mat, char * nome, float CR);

void ImprimeAluno (Aluno* aluno);

int RetornaMat(Aluno * al);

char * RetornaNome(Aluno * al);

float RetornaCR(Aluno* al);

void DestroiAluno(Aluno * al);
