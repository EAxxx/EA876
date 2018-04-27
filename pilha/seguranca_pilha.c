#include <stdio.h>

void funcao_maliciosa() {
  char c, *d;
  d = &c;
  for (int i = 0; i < 150; i++) {
    printf("%c", *d);
    d++;
  }
  printf("\n");
  return;

}

int main() {
  char dado_sigiloso[] = "MINHA SENHA";

  funcao_maliciosa();
  return 0;
}
