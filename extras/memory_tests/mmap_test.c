#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>

int main() {
  const unsigned int mem_size = 100000;

  /* Definir flags de protecao e visibilidade de memoria */
  int protection = PROT_READ | PROT_WRITE;
  int visibility = MAP_SHARED | MAP_ANON;

  /* Criar area de memoria mapeada */
  char *b;
  b = (char*) mmap(NULL, mem_size, protection, visibility, 0, 0);


  char *sw;
  for (sw=b; sw<(b+mem_size); sw++) {
    *sw = 0;
  }

  printf("Start: %x\nEnd: %x\n", b, sw);

  munmap(b, mem_size);

  return 0;

}
