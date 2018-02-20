
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

volatile int n_threads_ativas;
volatile int n_max_threads;
int *scratch;

typedef struct {
  int *vetor;
  int N;
} argumentos;

void troca (int *a, int *b) {
  int c;
#ifdef debugmode
  printf("Trocando %d com %d\n", *a, *b);
#endif
  c = (*a);
  (*a) = (*b);
  (*b) = c;

}

void intercala(int *vetor1, int N1, int *vetor2, int N2) {
  int n1, n2, n3;
  n1 = 0;
  n2 = 0;
  n3 = 0;
  extern int *scratch;

  /* Intercalar em area auxiliar */
  while ((n1 < N1) && (n2 < N2)) {
    if (vetor1[n1] < vetor2[n2]){
      scratch[n3] = vetor1[n1];
      n1++;
      n3++;
    } else{
      scratch[n3] = vetor2[n2];
      n2++;
      n3++;
    }
  }
  while (n1 < N1) {
    scratch[n3] = vetor1[n1];
    n1++;
    n3++;
  }

  while (n2 < N2) {
    scratch[n3] = vetor2[n2];
    n2++;
    n3++;
  }

  /* Retornar a vetores originais */
  n1=0;
  n2=0;
  n3=0;
  while (n1 < N1) {
    vetor1[n1] = scratch[n3];
    n1++;
    n3++;
  }
  while (n2 < N2) {
    vetor2[n2] = scratch[n3];
    n2++;
    n3++;
  }

  /* Libera memoria auxiliar */

}

void* mergesort(void *args) {
  pthread_t auxiliar;
  int threaded = 0;
  int M;
  argumentos *A = args;
  int *vetor = A->vetor;
  int N = A->N;

#ifdef debugmode
  printf("Mergesort com N=%d\n", N);
#endif

  if (N == 1)
    return (void*)0;

  if (N == 2) {
    if (vetor[1] < vetor[0])
      troca( &(vetor[0]), &(vetor[1]) );
    return (void*)0;
  }

  M = N/2;

#ifdef debugmode
  printf("   Quebrando em %d e %d\n", M, N-M);
#endif

  argumentos arg1, arg2;
  arg1.vetor = vetor;
  arg1.N = M;
  arg2.vetor = &(vetor[M]);
  arg2.N = N-M;

  if ( (n_threads_ativas < n_max_threads) && (N < 20000) && (N>1000)) {
    n_threads_ativas += 1;
    threaded = 1;
    pthread_create(&(auxiliar), NULL, mergesort, &(arg1));
  } else {
    mergesort(&arg1);
  }
  mergesort(&arg2);
  if (threaded) {
    pthread_join(auxiliar, NULL);
    n_threads_ativas -= 1;
  }
  intercala(vetor, M, &(vetor[M]), N-M);
  return (void*)0;

}



int main(int argc, char **argv) {
  clock_t start, end;

  int tam_vetor = atoi(argv[1]);
  n_max_threads = atoi(argv[2]);

  int *a = (int*) malloc(sizeof(int) * tam_vetor);
  scratch = (int*) malloc(sizeof(int) * tam_vetor);
  for (int i = 0; i< tam_vetor; i++) {
    a[i] = tam_vetor-i;
   }

  n_threads_ativas = 1;

  argumentos A;
  A.vetor = a;
  A.N = tam_vetor;

  start = clock();
  mergesort((void*) &A);
  end = clock();

#ifdef debugmode
  for (int i=0; i<tam_vetor; i++) {
    printf("[%d] = %d\t", i, a[i]);
  }
#endif

  printf("Mergesort levou %f segundos para n=%d\n", (double)(end-start)/CLOCKS_PER_SEC, tam_vetor);

  free(a);
  free(scratch);

  return 0;

}
