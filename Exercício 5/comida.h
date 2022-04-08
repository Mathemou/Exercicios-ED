#ifndef comida_h
#define comida_h

typedef struct comida Comida;

Comida* NovaComida (char * nome, char * sabor, int nota, float preco);

void MudaPreco (Comida * comida, float novopreco);

void MudaNota (Comida * comida, int novanota);

char * NomeComida(Comida * comida);

char * SaborComida(Comida * comida);

float PrecoComida(Comida * comida);

void ImprimeComida(Comida * comida);

void DestroiComida(Comida * comida);

#endif
