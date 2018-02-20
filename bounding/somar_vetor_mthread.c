
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

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

  int soma;

  argumentos a;

  a.resultado = 0;
  a.vetor = vetor;
  a.inicio = TAM_VETOR/2;
  a.fim = TAM_VETOR;

  argumentos b;

  b.resultado = 0;
  b.vetor = vetor;
  b.inicio = 0;
  b.fim = TAM_VETOR/2;

  pthread_t ta, tb;

  for (int i=0; i<N_TESTES; i++) {
    pthread_create(&ta, NULL, somar_vetor, &a);
    pthread_create(&tb, NULL, somar_vetor, &b);
    pthread_join(ta, NULL);
    pthread_join(tb, NULL);
    soma = a.resultado + b.resultado;
  }

  return 0;
}
