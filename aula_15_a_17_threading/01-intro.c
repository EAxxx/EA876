
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define n_threads 10

void* funcao_thread(void *arg) {
  int* N = (int*)arg;

  printf("Estou na thread %d!\n", *N);
  for (unsigned int i=0; i<5000000; i++);
  printf("Saindo da thread %d!\n", *N);
  return NULL;
}

int main(int argc, char **argv) {

  pthread_t threads[n_threads];
  void *args;
  int narg;

  for (int i = 0; i < (n_threads); i++) {
    narg = i;
    args = (void*) &narg;
    pthread_create(&(threads[i]), NULL, funcao_thread, args);
  }

  printf("Terminando programa!\n");
  return 0;
}
