#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926536

/*-------prototipos das funcoes-------------------*/
void calc_esfera (float r, float* area, float * volume);

float * AlocarMemoriaFloat (float * ponteiro);

int raizes (float a, float b, float c, float* x1, float* x2);

int pares (int n, int* vet);

void inverte (int n, int* vet);

void inverte_double (int n, double* vet);

void PrintaVetor(int n, int*vet);

double avalia (double* poli, int grau, double x);

int main(void){
  int grau;
  double * poli;
  double x, valor;
  printf("Digite o grau do polinomio: ");
  scanf("%d", &grau);
  grau++;
  poli = (double*) malloc ((grau+1)*sizeof(double));
  for (int i=0;i<grau;i++){
    printf("Digite o elemento %d do polinomio: ", i+1);
    scanf("%lf", &poli[i]);
  }
  inverte_double(grau, poli);

  printf("Digite o valor de x: ");
  scanf("%lf", &x);
  valor = avalia(poli, grau, x);
  printf("\nResultado: %lf", valor);
  return 0;
}

/*int main(void){
  int * vet;
  int n;
  printf("Digite o tamanho do vetor: ");
  scanf("%d", &n);
  vet = (int*) malloc (n*sizeof(int));
  for (int i=0;i<n;i++){
    printf("Digite o %dº elemento do vetor:\n", i+1);
    scanf("%d", &vet[i]);
  }
  PrintaVetor(n, vet);
  inverte(n, vet);
  PrintaVetor(n, vet);
  return 0;
}*/

/*int main(void){
  int n;
  int * vet;
  printf("Digite o tamano do vetor: ");
  scanf("%d", &n);
  vet = (int*) malloc (n*sizeof(int));
  for (int i=0; i<n; i++){
    printf("Digite o %dº elemento do vetor:\n", i+1);
    scanf("%d", &vet[i]);
  }
  printf("Esse vetor tem %d numeros pares!", pares(n, vet));
  return 0;
}*/

/*int main(void){
  float a, b, c;
  float * x1;
  x1 = AlocarMemoriaFloat(x1);
  float * x2;
  x2 = AlocarMemoriaFloat(x2);
  printf("Digite a equacao do segundo grau no formato ax^2?bx?c\nOnde ? pode ser + ou -\n");
  scanf("%fx^2%fx%f", &a, &b, &c);
  if (raizes(a, b, c, x1, x2)){
    printf("Valor de x1: %f\n", (*x1));
    printf("Valor de x2: %f\n", (*x2));
  } else {
    printf("Raizes nao existem");
  }
  return 0;
}*/

/*int main(void) {
  float r;
  float * area;
  area = AlocarMemoriaFloat(area);
  float * volume;
  volume = AlocarMemoriaFloat(volume);

  printf("Digite o valor do raio da esfera: ");
  scanf("%f", &r);
  calc_esfera (r, area, volume);
  printf("Valor da area: %f\nValor do volume: %f\n", (*area), (*volume));
  return 0;
}*/

/*-------------implementacao das funcoes-------------*/

void calc_esfera (float r, float * area, float * volume){
  (*area)=4*PI*pow(r,2);
  (*volume)=(4*PI*pow(r,3))/3;
}

float * AlocarMemoriaFloat (float * ponteiro){
  ponteiro = (float*) malloc (sizeof(float));
  return ponteiro;
}

int raizes (float a, float b, float c, float* x1, float* x2){
  float delta;
  delta = pow(b,2);
  delta += -4*a*c;
  if (delta>0){
    (*x1) = ((-1*b)+sqrt(delta))/2;
    (*x2) = ((-1*b)-sqrt(delta))/2;
    return 1;
  } else {
    return 0;
  }
}

int pares (int n, int* vet){
  int pares=0;
  for(int i=0; i<n;i++){
    if(vet[i]%2==0){
      pares++;
    }
  }
  return pares;
}

void inverte (int n, int * vet){
  int * vet_inv;
  vet_inv = (int*) malloc (n*sizeof(int));
  for(int i=0; i<n;i++){
    vet_inv[i]=vet[n-i-1];
  }
  for(int i=0; i<n;i++){
    vet[i]=vet_inv[i];
  }
}

void PrintaVetor(int n, int*vet){
  for(int i=0;i<n;i++){
    if(i==0){
      printf("{");
    }
    if (i<n-1){
      printf("%d, ", vet[i]);
    } else {
      printf("%d}", vet[i]);
    }
  }
}

void inverte_double (int n, double* vet){
  double * vet_inv;
  vet_inv = (double*) malloc (n*sizeof(double));
  for(int i=0; i<n;i++){
    vet_inv[i]=vet[n-i-1];
  }
  for(int i=0; i<n;i++){
    vet[i]=vet_inv[i];
  }
}

double avalia (double* poli, int grau, double x){
  double resultado=0;
  for (int i=0;i<grau;i++){
    resultado += poli[i]*(pow(x,i));
  }
  return resultado;
}
