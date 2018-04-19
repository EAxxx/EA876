
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <unistd.h>

#define N_PROCESSOS 10

unsigned int fibo(unsigned int N) {
  if (N<2) return 1;
  else return fibo(N-1) + fibo(N-2);
}

int main() {
  pid_t filho[N_PROCESSOS];
  const unsigned int N = 40;
  unsigned int f;


  /* Definir flags de protecao e visibilidade de memoria */
  int protection = PROT_READ | PROT_WRITE;
  int visibility = MAP_SHARED | MAP_ANON;

  /* Criar area de memoria compartilhada */
  int *b;
  b = (int*) mmap(NULL, sizeof(int), protection, visibility, 0, 0);

  for (int i=0; i<N_PROCESSOS; i++) {
    filho[i] = fork();
    if (filho[i] == 0) {
      /* Esta parte do codigo executa no processo filho */
      f = fibo(N);
      printf("Filho %d achou fibo(%d)=%d\n", i, N, f);
      (*b) = i;
      exit(0);
    }
  }

  printf("Todos os filhos foram gerados. Esperando...\n");
  for (int i=0; i<N_PROCESSOS; i++) {
    waitpid(filho[i], NULL, 0);
  }

  printf("Todos os filhos terminaram! Final: *b=%d\n", *b);
  return 0;

}
