
#include <stdio.h>
#include <stdlib.h>
#include <alloca.h>
#include <time.h>

void *aloca_pilha(size_t N);
void *aloca_heap(size_t N);
void acessa_pilha(size_t N);
void acessa_heap(size_t N);

const size_t tamanho_max = 1e10;


int main() {
  printf("A Pilha e o Heap\n");

  printf("Experimento 1: posso alocar mais memória no heap que na pilha\n");
  size_t tamanho;
  int expoente;
  tamanho = 10;
  expoente = 1;

  while (tamanho < tamanho_max) {
    if (aloca_pilha(tamanho)<0) break;
    tamanho *= 10;
    expoente += 1;
  }
  printf("consegui alocar 10^%d bytes com alloca()\n", expoente);

  tamanho = 10;
  expoente = 1;
  while (tamanho < tamanho_max) {
      if (aloca_heap(tamanho)<0) break;
    tamanho *= 10;
    expoente += 1;
  }
  printf("consegui alocar 10^%d bytes com malloc()\n", expoente);


  printf("\n---------\n");
  printf("Experimento 2: qual eh mais rapido para alocar - pilha ou heap?\n");

  clock_t start, end, dif1, dif2;
  start = clock();
  for(unsigned int i=0; i<1000000; i++) {
    aloca_pilha(1000000);
  }
  end = clock();
  dif1 = end-start;

  start = clock();
  for(unsigned int i=0; i<1000000; i++) {
    aloca_heap(1000000);
  }
  end = clock();
  dif2 = end-start;

  double t_pilha = 1000 * (double)dif1/CLOCKS_PER_SEC;
  double t_heap = 1000 * (double)dif2/CLOCKS_PER_SEC;
  printf("Alocar na pilha:\t%f ms\nAlocar no heap: \t%f ms\n", t_pilha, t_heap);

  printf("\n---------\n");
  printf("Experimento 3: qual eh mais rapido para acessar - pilha ou heap?\n");

  long int tam_max = 1e4;
  unsigned int iterations = 1e4;
  char *p1 = (char*)alloca(tam_max);
  start = clock();
  for (int i=0; i<iterations; i++) {
    for (int j=0; j<tam_max; j++) {
      p1[j] = 'A';
    }
  }

  end = clock();
  dif1 = end-start;

  char *p2 = (char*)malloc(tam_max);
  start = clock();
  for (int i=0; i<iterations; i++) {
    for (int j=0; j<tam_max; j++) {
      p2[j] = 'A';
    }
  }
  free(p2);

  end = clock();
  dif2 = end-start;

  t_pilha = 1000 * (double)dif1/CLOCKS_PER_SEC;
  t_heap = 1000 * (double)dif2/CLOCKS_PER_SEC;
  printf("Acessar na pilha:\t%f ms\nAcessar no heap: \t%f ms\n", t_pilha, t_heap);

  printf("Experimento 4: outro experimento sobre alocar mais memória no heap que na pilha\n");
  tamanho = 10;

  while (tamanho < tamanho_max) {
    printf("Tentando acessar %u bytes no heap\n", tamanho);
    acessa_heap(tamanho);
    printf("Consegui!\n");
    tamanho *= 10;
  }


  tamanho = 10;
  while (tamanho < tamanho_max) {
    printf("Tentando acessar %u bytes na pilha\n", tamanho);
    acessa_pilha(tamanho);
    printf("Consegui!\n");
    tamanho *= 10;
  }





  return 0;
}


void* aloca_pilha(size_t N) {
  void *p = alloca(N);
  return p;
}

void *aloca_heap(size_t N) {
  void *p = malloc(N);
  free(p);
  return p;
}

void acessa_pilha(size_t N) {
  char *p = (char*)alloca(N);
  for (unsigned long int i=0; i<N; i++)
    p[i]='A';
  return;
}

void acessa_heap(size_t N) {
  char *p = (char*)malloc(N);
  for (unsigned long int i=0; i<N; i++)
    p[i]='A';
  free(p);

  return ;
}


