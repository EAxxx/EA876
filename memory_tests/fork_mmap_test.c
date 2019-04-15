#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdlib.h>

int main() {
  const unsigned long int mem_size = 1e9;


  printf("Iniciei o programa!\n");
  printf("Pressione ENTER para continuar!\n");
  getchar();


  /* Definir flags de protecao e visibilidade de memoria */
  int protection = PROT_READ | PROT_WRITE;
  int visibility = MAP_SHARED | MAP_ANON;

  /* Criar area de memoria mapeada */
  char *b;
  b = (char*) mmap(NULL, mem_size, protection, visibility, 0, 0);

  printf("Memoria esta mapeada\n");
  printf("Pressione ENTER para continuar!\n");
  getchar();

  char *sw;
  for (sw=b; sw<(b+mem_size); sw++) {
    *sw = 0;
  }

  printf("Escrevi na memoria\n");
  printf("Pressione ENTER para continuar!\n");
  getchar();

  pid_t pid = fork();
  if (pid == 0) {
    printf("Entrei no processo-filho!\n");
    printf("Pressione ENTER para continuar!\n");
    getchar();

    for (char *sw1=b; sw1<(b+mem_size); sw1++) {
      *sw1 = 5;
    }

    printf("Escrevi na memoria\n");
    printf("Pressione ENTER para continuar!\n");
    getchar();

    printf("Encerrando processo-filho!\n");
    exit(0);
  }
  printf("PID do filho: %d\n", pid);
  waitpid(pid, NULL, 0);
  printf("Encerrando processo-pai!\n");

  return 0;

}
