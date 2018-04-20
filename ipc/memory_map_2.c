
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <unistd.h>

int main() {
  pid_t filho;
  int a;
  a = 0;

  /* Definir flags de protecao e visibilidade de memoria */
  int protection = PROT_READ | PROT_WRITE;
  int visibility = MAP_SHARED | MAP_ANON;

  /* Criar area de memoria compartilhada */
  int *b;
  b = (int*) mmap(NULL, sizeof(int)*100, protection, visibility, 0, 0);
  if ((long int)b==-1) printf("Erro de alocacao!\n");
  (*b)=0;

  filho = fork();
  if (filho == 0) {
    /* Esta parte do codigo executa no processo filho */

    while(1) {
      a++;
      (*b)++;
      printf("Processo filho: a=%d, *b=%d\n", a, *b);
      sleep(1);
      if  ( (*b) == 5) {
        exit(0);
      }
    }

  } else {
    /* Esta parte executa no processo pai */
    printf("Processo filho tem PID: %d\n", filho);
    do {
      printf("Processo pai: a=%d, *b=%d\n", a, *b);
      sleep(1);
      a++;
      (*b)++;
    } while (a < 6);
  }
  return 0;

}

