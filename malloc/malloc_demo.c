#include <stdlib.h>
#include <stdio.h>

int main() {
  void *p;
  int i;

  for (i=0; i<10; i++) {
    p = malloc(1024);
    printf("Ponteiro: %p (%lu)\n", p, (long unsigned int)p);
  }

  return 0;
}
