
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t trava;

/* Definindo um buffer circular */
#define TAM_FILA 3
int fila[TAM_FILA];
int n_leitura=0, n_escrita=0;
int n_elementos = 0;

void escrever(int elemento) {
  fila[n_escrita] = elemento;
  n_escrita ++;
  n_elementos ++;
  if (n_escrita >= TAM_FILA) n_escrita -= TAM_FILA;
}

int ler() {
  int ret;
  ret = fila[n_leitura];
  n_leitura++;
  n_elementos--;
  if (n_leitura >= TAM_FILA) n_leitura -= TAM_FILA;
  return ret;
}


/* Gerar dados */
int seed = 0;
int gerar() {
  seed += 1;
  return seed % 40;
}

/* Processar dados */
int fibo(int N) {
  if (N<=2) return 1;
  else return (fibo(N-1) + fibo(N-2));
}

void *produtor(void *arg) {
  int prod;
  while (1) {
    prod = gerar();
    escrever(prod);
    printf("Produtor: %d\n", prod);
    sleep(1);
  }
}

void *consumidor(void *arg) {
  int prod, res;
  while (1) {
    prod = ler();
    printf("Consumiu: %d\n", prod);
    res = fibo(prod);
    printf("Gerou: %d\n", res);
    sleep(3);
  }
}

int main(int argc, char **argv) {
  pthread_t prod, cons;

  /* Disparanto threads */
  pthread_create(&prod, NULL, produtor, NULL);
  pthread_create(&cons, NULL, consumidor, NULL);

  /* Esperando threads */
  pthread_join(prod, NULL);
  pthread_join(cons, NULL);


  return 0;
}
