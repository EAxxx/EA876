
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>


void sigquit() {
  /* Funcao que trata o sinal SIG_QUIT */
  printf("Recebi sinalizacao para terminar!\n");
  sleep(1);
  printf("Adeus!\n");
  exit(0);
}

int main() {
  pid_t filho;
  int a=0;

  filho = fork();
  if (filho == 0) {
    /* Esta parte do codigo executa no processo filho */
    signal(SIGQUIT, sigquit); /* Associa sinal SIGQUIT a funcao sigquit */

    while(1) {
      printf("Processo filho\n");
      sleep(1);
    }

  } else {

    /* Esta parte executa no processo pai */
    printf("Processo filho tem PID: %d\n", filho);
    do {
      printf("Processo pai: a=%d\n", a);
      sleep(1);
      a++;
      if (a==3) kill(filho, SIGQUIT); /* Termina filho */
    } while (a < 6);
  waitpid(filho, 0, 0);
  return 0;


  }
}

