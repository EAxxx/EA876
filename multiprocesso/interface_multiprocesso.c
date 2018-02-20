#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void imprime_lento(char letra) {
  pid_t filho;
  unsigned int contador;
  filho = fork();
  if (filho == 0) {
    /* Esta parte do codigo executa no processo filho */
    for (int i=0; i<5; i++) {
      printf("%c\n", letra);
      sleep(1);
    }
    exit(EXIT_SUCCESS);
   } else {
    printf("Filho com PID %d\n", filho);
   }
}


int main() {
  int c;
  unsigned int i = 0;

  while (1)
  {
    c = getc(stdin);
    if (c == EOF)
      break;
    else {

      if (c != '\n')
      imprime_lento(c);
    }
  }

  printf("Fim de programa!\n");
  return 0;
}


