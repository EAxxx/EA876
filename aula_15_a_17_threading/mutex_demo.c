
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t trava;


void *worker(void *w) {
  printf("Thread worker tentando pegar trava...\n");
  pthread_mutex_lock(&trava);
  printf("Thread worker pegou trava!\n");
  sleep(5);
  printf("Thread worker vai liberar trava!\n");
  pthread_mutex_unlock(&trava);
  printf("Thread worker liberou trava!\n");

  return NULL;
}

int main(int argc, char **argv) {

  pthread_t thread;

  pthread_mutex_lock(&trava);
  pthread_create(&thread, NULL, worker, NULL);
  sleep(2);
  pthread_mutex_unlock(&trava);
  sleep(1);
  printf("Thread principal tentando pegar trava...\n");
  pthread_mutex_lock(&trava);
  printf("Thread principal pegou trava\n");
  sleep(1);
  printf("Thread principal liberando trava\n");
  pthread_mutex_unlock(&trava);

  pthread_join(thread, NULL);

  printf("Terminando programa!\n");
  return 0;
}
