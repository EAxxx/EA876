
#include <stdio.h>

int main() {
  char c;
  char d;

  while (c != '\n') {
    fread(&c, 1, 1, stdin);
    d = c + 1;
    fwrite(&d, 1, 1, stdout);
  }
    return 0;
}
