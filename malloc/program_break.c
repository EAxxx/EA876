
#include <unistd.h>
#include <stdio.h>

int main() {
  intptr_t  nbytes;
  void *end;

  end = sbrk(0);
  printf("Comeco do heap: %p\n", end);


  end = sbrk(10);
  end = sbrk(-10);
  end = sbrk(0);
  printf("Fim do Heap: %p\n", end);

  printf("Conteudo antes do fim do heap: %d\n", *(int*)(end-4));
  printf("Conteudo no fim do heap: %d\n", *(int*)(end));
  printf("Conteudo depois do fim do heap: %d\n", *(int*)(end+4));

  return 0;
}

