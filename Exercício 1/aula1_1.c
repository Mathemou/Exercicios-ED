#include <stdio.h>

/*----------Prototipos das funcoes-----------*/
void PreencheVariaveis(int *var1p, int *var2p, int*var3p, int *var4p);

void PrintaVariaveisInteiros(int var1, int var2, int var3, int var4);

void SomaUmValorNosPonteiros(int *var1p, int *var2p, int*var3p, int *var4p);

void SubtraiUmValorNosPonteiros(int *var1p, int *var2p, int*var3p, int *var4p);

void MultiplicaPorUmValorOsPonteiros(int *var1p, int *var2p, int *var3p, int *var4p);

void DividePorUmValorOsPonteiros(int *var1p, int *var2p, int *var3p, int *var4p);

/*-----------Funcao principal---------------*/
int main(void) {
  int var1, var2, var3, var4;
  int * var1p, *var2p, *var3p, *var4p;
  var1p = &var1;
  var2p = &var2;
  var3p = &var3;
  var4p = &var4;
  PreencheVariaveis(var1p, var2p, var3p, var4p);
  SomaUmValorNosPonteiros(var1p, var2p, var3p, var4p);
  SubtraiUmValorNosPonteiros(var1p, var2p, var3p, var4p);
  MultiplicaPorUmValorOsPonteiros(var1p, var2p, var3p, var4p);
  DividePorUmValorOsPonteiros(var1p, var2p, var3p, var4p);

  /*Valor final das variaveis*/
  printf("Valor final das variaveis:\nValor var1:%d\nValor var2:%d\nValor var3:%d\nValor var4:%d\n", var1, var2, var3, var4);

  return 0;
}

/*-----------implementacao das funcoes-------------*/
void PreencheVariaveis(int *var1p, int *var2p, int*var3p, int *var4p){
  printf("Digite o valor da var1:");
  scanf("%d", var1p);
  printf("Digite o valor da var2:");
  scanf("%d", var2p);
  printf("Digite o valor da var3:");
  scanf("%d", var3p);
  printf("Digite o valor da var4:");
  scanf("%d", var4p);
}

void PrintaVariaveisInteiros(int var1, int var2, int var3, int var4){
  printf("O valor de var1 eh: %d\n", (var1));
  printf("O valor de var2 eh: %d\n", (var2));
  printf("O valor de var3 eh: %d\n", (var3));
  printf("O valor de var4 eh: %d\n\n\n", (var4));
}

void SomaUmValorNosPonteiros(int *var1p, int *var2p, int*var3p, int *var4p){
  int val;
  int * valp;
  valp = &val;
  printf("Digite um valor para somar em todas as variaveis:");
  scanf("%d", valp);
  (*var1p)+=(*valp);
  (*var2p)+=(*valp);
  (*var3p)+=(*valp);
  (*var4p)+=(*valp);
  PrintaVariaveisInteiros((*var1p), (*var2p), (*var3p), (*var4p));
}

void SubtraiUmValorNosPonteiros(int *var1p, int *var2p, int*var3p, int *var4p){
  int val;
  int * valp;
  valp = &val;
  printf("Digite um valor para subtrair em todas as variaveis:");
  scanf("%d", valp);
  (*var1p)-=(*valp);
  (*var2p)-=(*valp);
  (*var3p)-=(*valp);
  (*var4p)-=(*valp);
  PrintaVariaveisInteiros((*var1p), (*var2p), (*var3p), (*var4p));
}

void MultiplicaPorUmValorOsPonteiros(int *var1p, int *var2p, int *var3p, int *var4p){
  int val;
  int * valp;
  valp = &val;
  printf("Digite um valor para multiplicar todas as variaveis:");
  scanf("%d", valp);
  (*var1p)*=(*valp);
  (*var2p)*=(*valp);
  (*var3p)*=(*valp);
  (*var4p)*=(*valp);
  PrintaVariaveisInteiros((*var1p), (*var2p), (*var3p), (*var4p));
}

void DividePorUmValorOsPonteiros(int *var1p, int *var2p, int *var3p, int *var4p){
  int val;
  int * valp;
  valp = &val;
  printf("Digite um valor para dividir todas as variaveis:");
  scanf("%d", valp);
  (*var1p)/=(*valp);
  (*var2p)/=(*valp);
  (*var3p)/=(*valp);
  (*var4p)/=(*valp);
  PrintaVariaveisInteiros((*var1p), (*var2p), (*var3p), (*var4p));
}
