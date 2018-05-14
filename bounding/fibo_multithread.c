
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


typedef struct {
  int resultado;
  int N;
} argumentos;

int fibo(int N) {
  if (N<=2) return 1;
  else return fibo(N-1) + fibo(N-2);
}

void *calc_fibo(void *args) {
  argumentos *a = (argumentos*) args;
  a->resultado = fibo(a->N);
  return NULL;
}

int main() {
  argumentos a;
  argumentos b;
  int N = 43;
  int soma;

  a.resultado = 0;
  a.N = N;
  b.resultado = 0;
  b.N = N;

  pthread_t ta, tb;

  pthread_create(&ta, NULL, calc_fibo, &a);
  pthread_create(&tb, NULL, calc_fibo, &b);
  pthread_join(ta, NULL);
  pthread_join(tb, NULL);
  soma = a.resultado + b.resultado;

  return 0;
}
