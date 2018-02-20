
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define n_threads 10

void* funcao_thread(void *arg) {
  int* N = (int*)arg;
  int M = (*N);

  printf("Estou na thread %d!\n", M);
  for (unsigned int j=0; j<5000000; j++);
  printf("Saindo da thread %d!\n", M);
  return NULL;
}

int main(int argc, char **argv) {

  pthread_t threads[n_threads];
  int thread_args[n_threads];

  for (int i = 0; i < (n_threads); i++) {
    thread_args[i] = i;
    pthread_create(&(threads[i]), NULL, funcao_thread, &(thread_args[i]));
  }

  printf("Terminando programa!\n");
  return 0;
}
