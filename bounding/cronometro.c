#include <time.h>
#include <sys/time.h>
#include <stdio.h>

void medir_tempo(void *(*funcao)(void *args), void *args) {
  clock_t ct0, ct1, dct; /* Medida de tempo baseada no clock da CPU */
  struct timeval rt0, rt1, drt; /* Tempo baseada em tempo real */
  void *P;

  gettimeofday(&rt0, NULL);
  ct0 = clock();

  P = funcao(args);

  ct1 = clock();
  gettimeofday(&rt1, NULL);

  timersub(&rt1, &rt0, &drt);

  printf("Tempo real: %ld.%06ld segundos\n", drt.tv_sec, drt.tv_usec);
  printf("Tempo user: %f segundos\n", (double)(ct1-ct0)/CLOCKS_PER_SEC);
}


