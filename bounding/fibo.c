
#include <stdio.h>
#include <pthread.h>

#include "cronometro.h"
/* Define medir_tempo(a, b), cujos parametros sao:
 * a - ponteiro para funcao que retorna void* e recebe void* como parametro
 * b - ponteiro para void contendo o parametro que sera passado para a funcao */


typedef struct {
  int N;
  int result;
} fiboargs;


int fibo_rec(int N) {
  if (N<=2) return 1;
  else return fibo_rec(N-1) + fibo_rec(N-2);
}

void *fibo(void *args) {
  fiboargs *f = (fiboargs*) args;
  f->result = fibo_rec(f->N);
  return NULL;
}

void *fibo_threads(void *args) {
  fiboargs *f = (fiboargs*) args;
   if (f->N <= 2) {
    f->result = 1;
    return NULL;
  }

  fiboargs f1, f2;

  f1.N = (f->N)-1;
  f2.N = (f->N)-2;

  pthread_t ta, tb;

  pthread_create(&ta, NULL, fibo, &f1);
  pthread_create(&tb, NULL, fibo, &f2);
  pthread_join(ta, NULL);
  pthread_join(tb, NULL);

  f->result = f1.result + f2.result;
  return NULL;
}


int main () {
  fiboargs f;
  f.N = 40;

  printf("Single-thread\n");
  medir_tempo(fibo, &f);
  printf("\nDuas threads\n");
  medir_tempo(fibo_threads, &f);

  return 0;
}
