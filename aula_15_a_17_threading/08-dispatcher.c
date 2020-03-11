
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_WORKERS 4
#define ATIVO 1
#define INATIVO 0

typedef struct {
  int N;
  int ID;
} thread_args;

pthread_mutex_t trava;
int n_workers = 0;
pthread_t workers[MAX_WORKERS];
int worker_status[MAX_WORKERS];

int fibo(int N) {
  if (N<=2) return 1;
  else return (fibo(N-1) + fibo(N-2));
}

void* worker(void *arg) {
  thread_args *info = (thread_args *)arg;
  int M = fibo(info->N);
  printf("Fibo(%d)=%d\n", info->N, M);
  pthread_mutex_lock(&trava);
  n_workers -= 1;
  worker_status[info->ID] = INATIVO;
  free(info);
  pthread_mutex_unlock(&trava);
  return NULL;
}

int main(int argc, char **argv) {
  int numero_recebido;
  thread_args *send_args;
  int j;

  while (1) {
    scanf("%d", &numero_recebido);
    printf("Recebi: %d\n", numero_recebido);
    if (numero_recebido<0) break;
    if (n_workers >= MAX_WORKERS) {
      printf("Muitas tarefas sendo executadas. Ingnorando entrada\n");
    } else {
      pthread_mutex_lock(&trava);
      printf("Iniciando nova thread\n");
      send_args = (thread_args*)malloc(sizeof(thread_args));
      send_args->N = numero_recebido;
      /* Procura espaco para thread livre */
      j = 0;
      while (worker_status[j] == ATIVO) j++;
      send_args->ID = j;
      worker_status[j] = ATIVO;
      n_workers += 1;
      printf("Threads ativas: %d de %d\n", n_workers, MAX_WORKERS);
      pthread_create(& (workers[j]), NULL, worker, (void*) send_args);
      pthread_mutex_unlock(&trava);
    }
  }

  /* Esperando threads */
  printf("Terminando programa. Esperando threads terminarem...\n");
  for (int i=0; i<MAX_WORKERS; i++) {
    if (worker_status[i]==ATIVO) {
      pthread_join(workers[i], NULL);
    }
  }
  printf("FIM!\n");

  return 0;
}
