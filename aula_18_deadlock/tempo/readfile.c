
#include <stdio.h>

int main() {
  FILE *p;
  char c;
  int N = 5000090;
  p = fopen("biblia.txt", "r");

  while (N > 0) {
    c = fgetc(p);
    N--;
  }

  fclose(p);
  return 0;
}
