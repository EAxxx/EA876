#include <stdio.h>
#include <time.h>
#include <stdlib.h>


typedef struct {
  float *dados;
  int I;
  int J;
 } matriz, *Matriz;

void nova_matriz(matriz **M, int I, int J) {
  matriz *NovaMatriz;

  NovaMatriz = (matriz*) malloc (sizeof(matriz));
  NovaMatriz->dados = (float*) malloc(sizeof(float) * I * J);
  NovaMatriz->I = I;
  NovaMatriz->J = J;

  (*M) = NovaMatriz;
}

void nova_matriz_rand(matriz **M, int I, int J) {
  matriz *NovaMatriz;
  int i;

  NovaMatriz = (matriz*) malloc (sizeof(matriz));
  NovaMatriz->dados = (float*) malloc(sizeof(float) * I * J);

  srand(time(NULL));
  for (i=0; i<I*J; i++) {
    NovaMatriz->dados[i] = (float)rand()/(float)RAND_MAX;
  }

  NovaMatriz->I = I;
  NovaMatriz->J = J;

  (*M) = NovaMatriz;
}



void deletar_matriz(matriz **M) {
  free ((*M)->dados);
  free (*M);
}


float get_elemento(matriz **M, int i, int j) {
  float x;
  int idx;
  idx = i * (*M)->J + j;
  x = (*M)->dados[idx];
  return x;
}

void set_elemento(matriz **M, int i, int j, float x) {
  int idx;
  idx = i * (*M)->J + j;
  (*M)->dados[idx] = x;
}

void imprimir(matriz **M) {
  int i;
  int j;
  for (i=0; i<(*M)->I; i++) {
    for (j=0; j<(*M)->J; j++) {
      printf("%f\t", get_elemento(M, i, j));
    }
    printf("\n");
  }

}


void multiplicar(matriz **A, matriz **B, matriz **C) {
  /* C = A * B (multiplicacao matricial) */
  int i;
  int j;
  int k;

  float x;

  for (i=0; i<(*C)->I; i++) {
    for (j=0; j<(*C)->J; j++) {
      x = 0;
      for (k=0; k<(*A)->J; k++) {
        x = x + get_elemento(A, i, k) * get_elemento(B, k, j);
      }
      set_elemento(C, i, j, x);
    }
  }
}



int main(int argv, char **argc) {
  int lado = atoi(argc[1]);
  clock_t t0, t1, t2;
  matriz *A, *B, *C;

  t0=clock();
  nova_matriz_rand(&A, lado, lado);
  nova_matriz_rand(&C, lado, lado);

  t1=clock();
  nova_matriz(&B, lado, lado);
  multiplicar(&A, &C, &B);
  t2=clock();

  printf("Teste com matriz lado N=%d\n", lado);
  printf("Tempo para gerar matriz: %f\n", 1000*(double)(t1-t0)/CLOCKS_PER_SEC);
  printf("Tempo para multiplicar: %f\n", 1000*(double)(t2-t1)/CLOCKS_PER_SEC);

#ifdef FLAG_IMPRIMIR
  imprimir(&A);
  imprimir(&C);
  imprimir(&B);
#endif

  return 0;
}
