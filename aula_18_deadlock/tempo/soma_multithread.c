
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N_TESTES 100000

typedef struct {
  int resultado;
  int N;
} argumentos;


int soma(int N) {
  int j=0;
  for (int i=0; i<N; i++) {
    j+=i;
  }
  return j;
}


void *calc_soma(void *args) {
  argumentos *a = (argumentos*) args;
  a->resultado = soma(a->N);
  return NULL;
}

int main() {
  argumentos a;
  argumentos b;
  int N = 20000;
  int soma;

  a.resultado = 0;
  a.N = N;
  b.resultado = 0;
  b.N = N;

  pthread_t ta, tb;

  for (int i=0; i<(N_TESTES/2); i++) {
    pthread_create(&ta, NULL, calc_soma, &a);
    pthread_create(&tb, NULL, calc_soma, &b);
    pthread_join(ta, NULL);
    pthread_join(tb, NULL);
  }

  return 0;
}
