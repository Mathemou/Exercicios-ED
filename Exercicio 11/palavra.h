typedef struct palavra Palavra;

Palavra * inicPalavra (char * string);

char * retornaString(Palavra * palavra);

void atualizaOcorrencias (Palavra * palavra);

int retornaOcorrencias (Palavra * palavra);

Palavra * buscaPalavra (Palavra * palavra, char * string);

Palavra * inserePalavraLista(Palavra * lista, Palavra * p);

int contaPalavrasLista(Palavra * p);

void imprimirLista(Palavra * p);

void liberaListaPalavras(Palavra * p);