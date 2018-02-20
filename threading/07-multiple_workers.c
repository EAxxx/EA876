
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUMEROS 10

#define WORKERS 3


int n_completos = 0;
pthread_mutex_t trava;
int numeros[NUMEROS];

void* worker(void *arg) {
  int *N = (int*)(arg);
  int M = (*N);
  printf("Iniciando thread %d\n", M);
  int atuador = -1;
  while (1) {
    pthread_mutex_lock(&trava);
    if (n_completos >= NUMEROS) break;
    atuador = n_completos;
    n_completos += 1;
    pthread_mutex_unlock(&trava);
    printf("Numero %d acessado por thread %d\n", atuador, M);
    numeros[atuador] *= 2;
    for (int j=0; j<500000; j++);
  }
  printf("Saindo de thread %d\n", M);
  return NULL;
}



int main(int argc, char **argv) {
  pthread_t workers[WORKERS];
  int thread_id[WORKERS];

  /* Criando numeros */
  for (int i=0; i<NUMEROS; i++)
    numeros[i] = i;

  /* Identificadores de thread */
  for (int i=0; i<WORKERS; i++) {
    thread_id[i] = i;
  }

  /* Disparanto threads */
  for (int i=0; i<WORKERS; i++) {
    pthread_create(&(workers[i]), NULL, worker, (void*) (&thread_id[i]));
  }

  /* Esperando threads */
  for (int i=0; i<WORKERS; i++) {
    pthread_join(workers[i], NULL);
  }

  /* Escrevendo vetor */
  for (int i=0; i<NUMEROS; i++) {
    printf("%d\n", numeros[i]);
  }

  return 0;
}
