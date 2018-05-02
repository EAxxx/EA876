
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define n_threads 10

void* funcao_thread(void *arg) {
  int* N = (int*)arg;
  printf("Estou na thread %d!\n", *N);
  printf("Saindo da thread %d!\n", *N);
  return NULL;
}

int main(int argc, char **argv) {

  pthread_t thread;
  void *args;
  int narg;

  args = (void*) &narg;
  pthread_create(&(thread), NULL, funcao_thread, args);

  printf("Terminando programa!\n");
  return 0;
}
