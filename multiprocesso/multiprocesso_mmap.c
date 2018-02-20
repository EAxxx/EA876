
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <unistd.h>
#include <signal.h>

void sigquit() {
  /* Funcao que trata o sinal SIG_QUIT */
  printf("Recebi sinalizacao para terminar!\n");
  sleep(1);
  exit(0);
}

int main() {
  pid_t filho;
  int a;
  a = 5;

  int protection = PROT_READ | PROT_WRITE;
  int visibility = MAP_SHARED | MAP_ANON;

  /* Criar area de memoria compartilhada */
  int *b;
  b = (int*) mmap(NULL, sizeof(int)*100, protection, visibility, 0, 0);
  if ((int)b==-1) printf("Erro de alocacao!\n");
  (*b)=10;

  filho = fork();
  if (filho == 0) {
    /* Esta parte do codigo executa no processo filho */
    signal(SIGQUIT, sigquit); /* Associa sinal SIGQUIT a funcao sigquit */

    while(1) {
      printf("Processo filho: a=%d, *b=%d\n", a, *b);
      sleep(1);
    }

  } else {
    /* Esta parte executa no processo pai */
    printf("Processo filho tem PID: %d\n", filho);
    do {
      printf("Processo pai: a=%d, *b=%d\n", a, *b);
      sleep(1);
      a--;
      (*b)++;
      if (a==3) kill(filho, SIGQUIT); /* Termina filho */
    } while (a >  0);

  }
}

