
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t trava;
pthread_mutex_t tem_espaco, tem_dados;

/* Definindo um buffer circular */
#define TAM_FILA 3
int fila[TAM_FILA];
int n_leitura=0, n_escrita=0;
int n_elementos = 0;

void escrever(int elemento) {
/* Inicio de regiao critica */

  pthread_mutex_lock(&tem_espaco);
  pthread_mutex_lock(&trava);
  fila[n_escrita] = elemento;
  n_escrita ++;
  n_elementos ++;
  if (n_escrita >= TAM_FILA) n_escrita -= TAM_FILA;
  pthread_mutex_unlock(&tem_dados);
  if (n_elementos < TAM_FILA) pthread_mutex_unlock(&tem_espaco);
  pthread_mutex_unlock(&trava);
/* Fim de regiao critica */
}

int ler() {
  int ret;
  /* Inicio de regiao critica */

  pthread_mutex_lock(&tem_dados);
  pthread_mutex_lock(&trava);
  ret = fila[n_leitura];
  n_leitura++;
  n_elementos--;
  if (n_leitura >= TAM_FILA) n_leitura -= TAM_FILA;
  pthread_mutex_unlock(&tem_espaco);
  if (n_elementos > 0) pthread_mutex_unlock(&tem_dados);
  pthread_mutex_unlock(&trava);
  /* Fim de regiao critica */
  return ret;
}


/* Gerar dados */
int seed = 0;
int gerar() {
  seed += 1;
  return seed % 50;
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
  }
}

void *consumidor(void *arg) {
  int prod, res;
  while (1) {

    prod = ler();
    printf("Consumiu: %d\n", prod);
    res = fibo(prod);
    printf("Gerou: %d\n", res);
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
