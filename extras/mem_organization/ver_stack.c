
#include <stdio.h>


int recursiva(int N) {
  int c;
  printf("Stack em %p (%lu)\n", &c, (unsigned long int)&c);
  if (N==1) return 1;
  else {
    c = 1 + recursiva(N-1);
    return c;
  }
}

int recursiva2(int N) {
  int c;
  int d = 1;
  if (N==1) return 1;
  else {
    c = d + recursiva2(N-1);
    return c;
  }
}


int main() {
  printf("int: %lu bytes\n", sizeof(int));
  printf("void *: %lu bytes\n", sizeof(void*));

  recursiva(4);
  printf("\n\n\n");
  recursiva2(4);

  return 0;
}
