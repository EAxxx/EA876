
#include <stdio.h>
#include <stdlib.h>

int main() {
  int *a;

  a = (int *) malloc (sizeof(int) * 50);
  printf("%ld\n", (long)&(a[0]) - (long)a);
  printf("%ld\n", (long)&(a[1]) - (long)&(a[0]) - sizeof(int));

  return 0;
}
