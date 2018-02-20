
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

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

  filho = fork();
  if (filho == 0) {
    /* Esta parte do codigo executa no processo filho */
    signal(SIGQUIT, sigquit); /* Associa sinal SIGQUIT a funcao sigquit */

    while(1) {
      printf("Processo filho: a=%d\n", a);
      sleep(1);
    }
    printf("Terminando processo filho\n");
    exit(EXIT_SUCCESS);

  } else {
    /* Esta parte executa no processo pai */
    printf("Processo filho tem PID: %d\n", filho);
    do {
      printf("Processo pai: a=%d\n", a);
      sleep(1);
      a--;
      if (a==3) kill(filho, SIGQUIT); /* Termina filho */
    } while (a >  0);


}}

