
#include <unistd.h>
#include <stdio.h>

int main() {
  intptr_t  nbytes;
  void *end;


  end = sbrk(0);
  printf("O final da minha memoria de programa esta em %lu\n", (long unsigned int)end);

  printf("Conteudo antes do fim da memoria: %d\n", *(int*)(end+4));
  printf("Conteudo no fim da memoria: %d\n", *(int*)(end));
  printf("Conteudo depois do fim da memoria: %d\n", *(int*)(end-4));

  return 0;
}
