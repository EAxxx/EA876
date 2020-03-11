
#include <stdlib.h>
#include <stdio.h>



int main() {
  int a;
  void *p;
  void *i;

  printf("Pilha: %p (%lu)\n", &a, (long unsigned int)&a);

  p = malloc(1);
  printf("Heap: %p (%lu)\n", p, (long unsigned int)p);

  printf("Navegando (leitura)\n");
  for (i=p; i<&a; i+=4) {
    a = *(int*)i;
  }

  printf("Navegando (escrita)\n");
  for (i=p; i<&a; i+=4) {
    *(int*)i = 0;
  }

  return 0;
}
