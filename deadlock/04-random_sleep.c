
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


pthread_mutex_t trava1, trava2, trava3;

void *thread1(void *args) {
  for (int i=0; i<5; i++) {
    usleep(rand()%10000);
    pthread_mutex_lock(&trava1);
    printf("Thread 1 pegou mutex 1\n");
    sleep(1); /* Troque isso por alguma acao demorada */
    printf("Thread 1 tentando pegar trava 2\n");
    pthread_mutex_lock(&trava2);
    printf("Estou no loop da thread 1! i=%d\n", i);
    pthread_mutex_unlock(&trava1);
    pthread_mutex_unlock(&trava2);
      }
  return NULL;
}

void *thread2(void *args) {
  for (int i=0; i<5; i++) {
    usleep(rand()%10000);
    pthread_mutex_lock(&trava2);
    printf("Thread 2 pegou mutex 2\n");
    sleep(1); /* Troque isso por alguma acao demorada */
    printf("Thread 2 tentando pegar trava 1\n");
    pthread_mutex_lock(&trava1);
    printf("Estou no loop da thread 2! i=%d\n", i);
    pthread_mutex_unlock(&trava2);
    pthread_mutex_unlock(&trava1);
  }
  return NULL;
}

int main() {
  pthread_t t1, t2;

  pthread_create(&t1, NULL, thread1, NULL);
  pthread_create(&t2, NULL, thread2, NULL);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  printf("Fim de programa!\n");

  return 0;
}


