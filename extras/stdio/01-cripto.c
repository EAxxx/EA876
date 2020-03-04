
#include <stdio.h>

int main() {
  char c;
  while (c != '\n') {
    scanf("%c", &c);
    printf("%c", c+1);
  }
  return 0;
}
