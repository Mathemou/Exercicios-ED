#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

typedef struct indicepilha IndicePilha;

typedef struct tipopilhadupla TipoPilhaDupla;

TipoPilhaDupla * inicializaPilha();

void push_pilha1 (TipoPilhaDupla * pilha, Aluno * aluno);

Aluno * pop_pilha1 (TipoPilhaDupla * pilha);

void push_pilha2 (TipoPilhaDupla * pilha, Aluno * aluno);

Aluno * pop_pilha2 (TipoPilhaDupla * pilha);

void ImprimeTopoPilha2(TipoPilhaDupla * pilha);

void ImprimeAlunoPorPosicao(TipoPilhaDupla * pilha, int pos);

void ImprimePilha1(TipoPilhaDupla * pilha);

void ImprimePilha2(TipoPilhaDupla * pilha);

void destroi(TipoPilhaDupla * p);
