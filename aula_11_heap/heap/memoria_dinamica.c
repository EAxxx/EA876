#include <stdlib.h>


void func() {
  int *a = (int*) malloc (sizeof(int));
  (*a) = 1;
  free(a);
}

int main() {
  for (int i=0; i<900000; i++) {
    func();
  }
  return 0;
}
