
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define tam_buffer 10

int buffer[tam_buffer];
int inicio_buffer = 0;
int final_buffer = 0;
int total_buffer = 0;

#define producoes 20

pthread_mutex_t trava;

void* produtor(void *arg) {
  for (int i = 0; i < producoes; i++) {
    while (total_buffer == tam_buffer);

    buffer[inicio_buffer] = i;

    pthread_mutex_lock(&trava);
    total_buffer += 1;
    pthread_mutex_unlock(&trava);

    inicio_buffer += 1;
    if (inicio_buffer == tam_buffer) inicio_buffer = 0;
  }
  return NULL;
}

void* consumidor(void *arg) {
  for (int j = 0; j < producoes; j++) {
    while (total_buffer == 0);

    printf("%d\t", buffer[final_buffer]);

    pthread_mutex_lock(&trava);
    total_buffer -= 1;
    pthread_mutex_unlock(&trava);

    final_buffer += 1;
    if (final_buffer == tam_buffer) final_buffer = 0;
  }
  return NULL;
}

int main(int argc, char **argv) {

  pthread_t thread_prod, thread_cons;

  pthread_create(&thread_prod, NULL, produtor, NULL);
  pthread_create(&thread_cons, NULL, consumidor, NULL);

  pthread_join(thread_prod, NULL);
  pthread_join(thread_cons, NULL);

  printf("Terminando programa!\n");
  return 0;
}
