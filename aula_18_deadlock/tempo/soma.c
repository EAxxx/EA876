
#include <stdio.h>
#include <stdlib.h>

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

  a.resultado = 0;
  a.N = 20000;

  for (int i=0; i<N_TESTES; i++)
    calc_soma(&a);

  return 0;
}
