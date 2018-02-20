
#include <stdio.h>
#include <stdlib.h>

#define TAM_VETOR 100000
#define N_TESTES 10000

typedef struct {
  int resultado;
  int *vetor;
  unsigned int inicio;
  unsigned int fim;
} argumentos;

void *somar_vetor(void *args) {
  argumentos *a = (argumentos*) args;
  a->resultado = 0;
  for (int i=(a->inicio); i<(a->fim); i++) {
    a->resultado += (a->vetor)[i];
  }
  return NULL;
}

int main() {
  int vetor[TAM_VETOR];

  double deltat_s;

  argumentos a;

  a.resultado = 0;
  a.vetor = vetor;
  a.inicio = 0;
  a.fim = TAM_VETOR;

  for (int i=0; i<N_TESTES; i++)
    somar_vetor(&a);

  return 0;
}
