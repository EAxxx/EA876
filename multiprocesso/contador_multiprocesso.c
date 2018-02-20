#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

unsigned int conta_c(const char *fname) {
  FILE *f;
  int r;
  unsigned int count = 0;

  f = fopen(fname, "r");
  if (f==0) {
    printf("Arquivo %s nao-encontrado!\n", fname);
    return 0;
  } else {
    printf("Abri arquivo %s\n", fname);

  }
  while ( (r = fgetc(f)) != EOF ) {
    count = count + 1;
  }
  fclose(f);

  return count;
}

void inicia_contagem(const char *buffer) {
  pid_t filho;
  unsigned int contador;
  filho = fork();
  if (filho == 0) {
    /* Esta parte do codigo executa no processo filho */
    printf("Iniciando processo filho para ler %s\n", buffer);
    contador = conta_c(buffer);
    printf("Terminando processo filho: contei %d caracteres em %s\n", contador, buffer);
    exit(EXIT_SUCCESS);
   } else {
    printf("Filho com PID %d\n", filho);
   }
}


int main() {
  char buffer[50];
  int c;
  unsigned int i = 0;
  int buffer_ok = 0;

  while (1)
  {
    c = getc(stdin);
    if (c!='\n') {
      buffer[i] = (char)c;
      i = i + 1;
    } else {
      buffer[i] = '\0';
      if ( (buffer[0]=='F') && (i==1) )
        break;

      i = 0;
      buffer_ok = 1;
     }
    if (c == EOF)
      break;

    if (buffer_ok == 1) {
      buffer_ok = 0;
      inicia_contagem(buffer);
    }
  }

  printf("Fim de programa!\n");
  return 0;
}


