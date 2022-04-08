#include "aluno.h"

typedef struct arv Arv;

Arv * arv_criaVazia();

Arv * arv_cria (Aluno * aluno, Arv * esq, Arv * dir);

Arv * arv_libera (Arv * arv);

int arv_vazia (Arv * arv);

int arv_pertence (Arv * arv,char * nome);

void arv_imprime (Arv * arv);

static int max2 (int a, int b);

int arv_altura (Arv * arv);

int folhas (Arv * arv);

int ocorrencias (Arv * arv, char * nome);