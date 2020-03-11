
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t trava1, trava2;

void *thread1(void *args) {
  int status;
  int i=0;
  while(i<5) {
    pthread_mutex_lock(&trava1);
    printf("Thread 1 pegou mutex 1\n");
    sleep(1); /* Troque isso por alguma acao demorada */
    printf("Thread 1 tentando pegar trava 2\n");
    status = pthread_mutex_trylock(&trava2);
    if (status==0) { /* Consegui trava2 */
      printf("Estou no loop da thread 1! i=%d\n", i);
      pthread_mutex_unlock(&trava1);
      pthread_mutex_unlock(&trava2);
      printf("Thread 1 liberou travas 1 e 2\n");
      i++;
    } else { /* Nao consegui trava2 */
      printf("***Thread 1 libera mutex 1\n");
      pthread_mutex_unlock(&trava1);
      sleep(1);
    }
  }
  return NULL;
}

void *thread2(void *args) {
  for (int i=0; i<5; i++) {
    pthread_mutex_lock(&trava2);
    printf("Thread 2 pegou mutex 2\n");
    sleep(1); /* Troque isso por alguma acao demorada */
    printf("Thread 2 tentando pegar trava 1\n");
    pthread_mutex_lock(&trava1);
    printf("Estou no loop da thread 2! i=%d\n", i);
    pthread_mutex_unlock(&trava2);
    pthread_mutex_unlock(&trava1);
    printf("Thread 2 liberou travas 1 e 2\n");
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


