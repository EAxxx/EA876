#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>

int main() {
  const unsigned long int mem_size = 1e9;


  printf("Iniciei o programa!\n");
  printf("Pressione ENTER para continuar!\n");
  scanf("%s\n");


  /* Definir flags de protecao e visibilidade de memoria */
  int protection = PROT_READ | PROT_WRITE;
  int visibility = MAP_SHARED | MAP_ANON;

  /* Criar area de memoria mapeada */
  char *b;
  b = (char*) mmap(NULL, mem_size, protection, visibility, 0, 0);

  printf("Memoria esta mapeada\n");
  printf("Pressione ENTER para continuar!\n");
  scanf("%s\n");

  char *sw;
  for (sw=b; sw<(b+mem_size); sw++) {
    *sw = 0;
  }

  printf("Escrevi na memoria\n");
  printf("Pressione ENTER para continuar!\n");
  scanf("%s\n");

  printf("Start: %x\nEnd: %x\n", b, sw);

  munmap(b, mem_size);

  return 0;

}
