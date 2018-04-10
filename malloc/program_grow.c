
#include <unistd.h>
#include <stdio.h>

int main() {
  intptr_t  nbytes;
  int b;
  void *end;

  end = sbrk(10);
  end = sbrk(-10);
  printf("No comeco de tudo, meu heap acaba em %p\n", end);


  while (1) {
    printf("Quantos bytes devo alocar?\n");
    scanf("%d", &b);
    nbytes = (long int) b;
    printf("Alocando mais memoria!\n");
    end = sbrk(nbytes);
    end = sbrk(0);
    printf("Depois de alocar %ld bytes, meu heap acaba em %p\n", nbytes, end);
  }

  return 0;
}
