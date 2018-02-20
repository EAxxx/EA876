
#include <stdio.h>


void func(int N) {
  int a;
  printf("Stack em %p (%lu)\n", &a, (unsigned long int)&a);
  if (N<10) func(N+1);
}

int main() {
  printf("int: %lu bytes\n", sizeof(int));
  printf("void *: %lu bytes\n", sizeof(void*));

  func(0);
  printf("\n\n\n");

  return 0;
}
