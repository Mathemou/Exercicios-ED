#include <stdio.h>
#include "comida.h"
#include "listaDPL.h"

int main(void) {
  Comida * batata_frita = NovaComida("Batata frita", "Salgado", 5, 12.99);
  Comida * lasagna = NovaComida("Lasagna", "Salgado", 6, 24.99);
  Comida * frango_grelhado = NovaComida("Frango grelhado", "Salgado", 8, 39.99);
  Comida * hamburguer = NovaComida("Hamburguer", "Salgado", 8, 2.99);
  Comida * bolo = NovaComida("Bolo", "Doce", 4, 9.99);

  ListaDlp * cardapio = IniciaLista();

  cardapio = InsereCardapio(cardapio, batata_frita);
  cardapio = InsereCardapio(cardapio, lasagna);
  cardapio = InsereCardapio(cardapio, frango_grelhado);
  cardapio = InsereCardapio(cardapio, hamburguer);
  cardapio = InsereCardapio(cardapio, bolo);

  ImprimeCardapio(cardapio);

  return 0;
}
