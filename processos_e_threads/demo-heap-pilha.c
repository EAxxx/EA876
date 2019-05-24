
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int b;

void *funcao_thread(void *arg);

int main(int argc, char **argv) {
  int a = 0;

  int *c = (int*) malloc (sizeof(int));
  (*c) = 0;

  pthread_t thread;

  pthread_create(&thread, NULL, funcao_thread, c);
  pthread_join(thread, NULL);
  printf("Terminei thread. a=%d, b=%d, c=%d\n", a, b, *c);


  pid_t pid;
  pid = fork();
  if (pid == 0) {
    a = 10;
    b = 10;
    (*c) = 10;
    exit(0);
  }
  else {
    waitpid(pid, NULL, 0);
  }

  printf("Terminei processo. a=%d, b=%d, c=%d\n", a, b, *c);
  printf("Terminando programa!\n");
  return 0;
}

void* funcao_thread(void *arg) {
  int *a;
  a = (int*) arg;
  b = 5;
  *a = 5;
}
