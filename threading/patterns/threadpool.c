
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUMEROS 7

#define WORKERS 3


pthread_mutex_t trava;

/* Definicao do problema */
int completos[NUMEROS] = {0, 0, 0, 0, 0, 0, 0};
int numeros[NUMEROS] = {45, 2, 2, 20, 30, 45, 2};
int resultados[NUMEROS];

int fibo(int N) {
  if (N<=2) return 1;
  else return (fibo(N-1) + fibo(N-2));
}

void* worker(void *arg) {
  /* Inicializacao: guardar o proprio numero da thread */
  int *N = (int*)(arg);
  int M = (*N);
  printf("Iniciando thread %d\n", M);
  int instancia=0;
  while (1) {

    pthread_mutex_lock(&trava);
    /* Busca por uma instancia do problema que ainda nao foi resolvida */
    while ( (completos[instancia]!=0) && (instancia < NUMEROS)) {
      printf("Thread %d testou instancia %d\n", M, instancia);
      instancia++;
    }
    printf("Thread %d tentando tomar intancia %d\n", M, instancia);
    if (instancia >= NUMEROS) { /* Acabaram as instancias */
      pthread_mutex_unlock(&trava);
      break;
    }
    completos[instancia] = 1; /* Proponho-me a resolver a instancia */
    pthread_mutex_unlock(&trava);

    printf("Instancia %d acessada por thread %d\n", instancia, M);
    resultados[instancia] = fibo(numeros[instancia]);
    printf("Fibo(%d) = %d\n", numeros[instancia], resultados[instancia]);


  }
  printf("Saindo de thread %d\n", M);
  return NULL;
}


int main(int argc, char **argv) {
  pthread_t workers[WORKERS];
  int thread_id[WORKERS];

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
  printf("Resultados: \n");
  for (int i=0; i<NUMEROS; i++) {
    printf("%d\n", resultados[i]);
  }

  return 0;
}
