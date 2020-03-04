
#include <stdio.h>
#include <malloc.h>
#include <pthread.h>

#include "cronometro.h"


typedef struct {
  int *x;
  int N;
  int result;
} threadargs;


int soma_iterativo(int *x, int N) {
  int acc = 0;
  for (int i=0; i<N; i++) {
    acc += x[i];
  }
  return acc;
}

void *soma(void *args) {
  threadargs *a = (threadargs*) args;
  a->result = soma_iterativo(a->x, a->N);
  return NULL;
}

void *soma_threads(void *args) {
  threadargs *a = (threadargs*) args;
  threadargs a1, a2;

  /* Preparacao de argumentos */
  a1.N = (a->N)/2;
  a2.N = (a->N)-(a1.N);
  a1.x = a->x;

  int *novo_x = a1.x;
  novo_x = & (novo_x[a1.N]);
  a2.x = novo_x;

  pthread_t ta, tb;

  pthread_create(&ta, NULL, soma, &a1);
  pthread_create(&tb, NULL, soma, &a2);
  pthread_join(ta, NULL);
  pthread_join(tb, NULL);

  a->result = a1.result + a2.result;
  return NULL;
}


int main () {
  threadargs f;

  const int n_elementos = 50000000;

  f.N = n_elementos;
  f.x = (int*) malloc (sizeof(int) * n_elementos);

  printf("Single-thread\n");
  medir_tempo(soma, &f);
  printf("\nDuas threads\n");
  medir_tempo(soma_threads, &f);

  free(f.x);

  return 0;
}
