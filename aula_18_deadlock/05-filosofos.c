
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
/* Estrutura do problema */
#define N_FILOSOFOS 5
#define MAX_PRATO 5

pthread_t filosofos[N_FILOSOFOS];
int pratos[N_FILOSOFOS];
pthread_mutex_t palitos[N_FILOSOFOS];

/* Implementacao */

void *filosofo(void *args) {
  int *ptr = (int*) (args);
  int N = (*ptr);
    printf("Entrando no filosofo %d\n", N);
  while (pratos[N] < MAX_PRATO) {
    /* Pega palito a esquerda */
    pthread_mutex_lock(& (palitos[N]) );
    /* Pega palito a direita */
    pthread_mutex_lock(& (palitos[(N+1)%N_FILOSOFOS]) );
    /* Se alimenta */
    pratos[N] += 1;
    printf("Filosofo %d: prato %d\n", N, pratos[N]);
    sleep(1);
    /* Devolve palito a esquerda */
    pthread_mutex_unlock(& (palitos[N]) );
    /* Devolve palito a direita */
    pthread_mutex_unlock(& (palitos[(N+1)%N_FILOSOFOS]) );
  }
  return 0;
}




int main() {
  int k;
  int idx[N_FILOSOFOS];
  for (int i=0; i<N_FILOSOFOS; i++) {
    idx[i] = i;
    pthread_create(& (filosofos[i]), NULL, filosofo, &(idx[i]) );
  }

  while (1) {
    sleep(1);
    k=0;
    for (int i=0; i<N_FILOSOFOS; i++)
      if (pratos[i] < MAX_PRATO) k++;
    printf("Thread principal esta viva! Faltam %d filosofos\n", k);
    if (k==0) break;
  }
}
