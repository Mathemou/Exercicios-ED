#include "palavra.h"

typedef struct hash Hash;

Hash * inicHash(int tam);

Palavra * acessa(Hash * h, char * string);

int contaPalavras(Hash * h);

void imprimeHash(Hash * h);

void liberaHash(Hash * h);