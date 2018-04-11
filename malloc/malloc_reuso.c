
#include <stdlib.h>
#include <stdio.h>

int main() {
  void *a;
  void *b;
  void *c;

  printf("Reuso com Malloc e Free:\n");
  a = malloc(1000);
  printf("%p\n", a);
  free(a);
  a = malloc(1000);
  printf("%p\n", a);
  free(a);

  printf("Reuso e segmentacao:\n");
  a = malloc(1000);
  b = malloc(1000);
  c = malloc(1000);
  printf("%p %p %p\n", a, b, c);

  free(b);
  free(a);
  a = malloc(1500);
  b = malloc(1000);

  printf("%p %p %p\n", a, b, c);


  free(a);
  free(b);
  free(c);
  return 0;
}
