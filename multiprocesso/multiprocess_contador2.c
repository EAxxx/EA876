
/* Sistema multiprocessado */


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

  pid_t p1, p2;

  int protection = PROT_READ | PROT_WRITE;
  int visibility = MAP_SHARED | MAP_ANON;

  /* Criar area de memoria compartilhada */
  char *b;
  b = (char*) mmap(NULL, sizeof(char)*100, protection, visibility, 0, 0);
  if (b==(char*)-1) printf("Erro de alocacao!\n");

  for (int i=0; i<100; i++)
    b[i] = '\n';


  /* Outra area de memoria compartilhada! */
  int *N; /* Numero de elementos que ja foram processados */
  N = (int*) mmap(NULL, sizeof(int), protection, visibility, 0, 0);
  if (N==(int*)-1) printf("Erro de alocacao!\n");
  (*N) = 0;

  p2 = fork();

  if (p2==0) {
    FILE *fp;
    char c;
    fp = fopen("./multiprocess_contador.c", "r");

    for (int i=0; i<100; i++) {
      /* Processo executa tarefa demorada e coloca no buffer de saida */
      for(int j=0; j<10000; j++); /* Etapa 1 da tarefa demorada */
      fread(&c, 1, 1, fp), /* Etapa 2 da tarefa demorada */
      b[i] = c;
      (*N) = (*N)+1;
    }
    exit(EXIT_SUCCESS);
  }


  p1 = fork();

  if (p1==0) {
    int count=0;
    for (int i=0; i<100; i++) {

      while ((*N)==0);

      if (b[i] == '\n') count++;
      (*N) = (*N)-1;
    }

    printf("Contei %d quebras de linha!\n", count);
    exit(EXIT_SUCCESS);
  }
  int status;
  waitpid(p1, &status, 0);
  waitpid(p2, &status, 0);

  return 0;
}
