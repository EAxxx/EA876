#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int j;
int i;

void *impares(void *args) {
  i = 1;
  while (i < 5000) {
    j += i;
    i += 2;
    usleep(10);
  }
  return NULL;
}

void *pares(void *args) {
  i = 2;
  while (i < 5000) {
    j += i;
    i += 2;
    usleep(15);
  }

  return NULL;
}

int main() {
  pthread_t t1, t2;

  j = 0;

  pthread_create(&t1, NULL, impares, NULL);
  pthread_create(&t2, NULL, pares, NULL);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  printf("Fim de programa!\nA soma foi: %d\n", j);

  return 0;
}


