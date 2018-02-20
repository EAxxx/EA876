
#include <stdio.h>
#include <stdlib.h>
#include <time.h> /* clock() */
#include <sys/time.h> /* gettimeofday() e timersub() */
#include <alloca.h>

#define TAM_MEMORIA 1000000

void memoria_estatica() {
  int a[TAM_MEMORIA];
  for (int i=0; i<TAM_MEMORIA; i++) a[i] = 0;
}

void memoria_dinamica_stack() {
  int *a = (int*) alloca(sizeof(int) * TAM_MEMORIA);
  for (int i=0; i<TAM_MEMORIA; i++) a[i] = 0;
}

void memoria_dinamica_heap() {
  int *a = (int*) malloc(sizeof(int) * TAM_MEMORIA);
  for (int i=0; i<TAM_MEMORIA; i++) a[i] = 0;
  free(a);
}

void medir_tempo(void (*funcao)()) {
  clock_t ct0, ct1, dct; /* Medida de tempo baseada no clock da CPU */
  struct timeval rt0, rt1, drt; /* Tempo baseada em tempo real */

  gettimeofday(&rt0, NULL);
  ct0 = clock();

  funcao();

  ct1 = clock();
  gettimeofday(&rt1, NULL);

  timersub(&rt1, &rt0, &drt);

  printf("Tempo real: %ld.%06ld segundos\n", drt.tv_sec, drt.tv_usec);
  printf("Tempo user: %f segundos\n", (double)(ct1-ct0)/CLOCKS_PER_SEC);



}

int main () {
  printf("Memoria estatica\n");
  medir_tempo(memoria_estatica);

  printf("\nMemoria dinamica (stack)\n");
  medir_tempo(memoria_dinamica_stack);

  printf("\nMemoria dinamica (heap)\n");
  medir_tempo(memoria_dinamica_heap);
  return 0;
}
