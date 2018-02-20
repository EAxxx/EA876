#include <stdio.h>

int main() {
  char c;

  int contador = 0;

  while (c != EOF) {
    c = getchar();
    if (c=='c')
      contador++;
  }

  printf("Encontrei %d letras c\n", contador);
  return 0;
}
