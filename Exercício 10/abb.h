#include "aluno.h"

typedef struct arvore Arvore;

Arvore * abbCria(void);

void abbImprime(Arvore * arvore);

Arvore * abbBusca(Arvore * arvore, int chave);

Arvore * abbInsere (Arvore * arvore, Aluno * aluno);

Arvore * abbRetira (Arvore * arvore, int valor);

Arvore * abbLibera(Arvore * arvore);

int abbEhFolha (Arvore * arvore);