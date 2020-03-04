#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *impares(void *args) {
  int i = 1;
  int j = 0;
  while (i < 5000) {
    j += i;
    i += 2;
    usleep(10);
  }
  *(int*)(args) = j;
  return NULL;
}

void *pares(void *args) {
  int i = 2;
  int j = 0;
  while (i < 5000) {
    j += i;
    i += 2;
    usleep(15);
  }
  *(int*)(args) = j;
  return NULL;
}

int main() {
  pthread_t t1, t2;

  int j1, j2, j;

  pthread_create(&t1, NULL, impares, (void*)&j1);
  pthread_create(&t2, NULL, pares, (void*)&j2);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  j = j1 + j2;

  printf("Fim de programa!\nA soma foi: %d\n", j);

  return 0;
}


