
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void troca (int *a, int *b) {
  int c;
  c = (*a);
  (*a) = (*b);
  (*b) = c;
}

void intercala(int *vetor1, int N1, int *vetor2, int N2) {
  int n1, n2, n3;
  n1 = 0;
  n2 = 0;
  n3 = 0;

  int *scratch;
  scratch = (int *) malloc(sizeof(int) * (N1+N2));

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
  free(scratch);
}

void mergesort(int *vetor, int N) {
  int M;

#ifdef debugmode
  printf("Mergesort com N=%d\n", N);
#endif

  if (N == 1)
    return;

  if (N == 2) {
    if (vetor[1] < vetor[0])
      troca( &(vetor[0]), &(vetor[1]) );
    return;
  }

  M = N/2;

#ifdef debugmode
  printf("   Quebrando em %d e %d\n", N, N-2);
#endif

  mergesort(vetor, M);
  mergesort(&(vetor[M]), N-M);
  intercala(vetor, M, &(vetor[M]), N-M);
  return;
}


int main(int argc, char **argv) {
  clock_t start, end;

  int tam_vetor = atoi(argv[1]);

  int *a = (int*) malloc(sizeof(int) * tam_vetor);
  for (int i = 0; i< tam_vetor; i++) {
    a[i] = tam_vetor-i;
  }

  start = clock();
  mergesort(a, tam_vetor);
  end = clock();

#ifdef debugmode
  for (int i=0; i<tam_vetor; i++) {
    printf("[%d] = %d\t", i, a[i]);
  }
#endif

  printf("Mergesort levou %f segundos para n=%d\n", (double)(end-start)/CLOCKS_PER_SEC, tam_vetor);

  free(a);

  return 0;

}
