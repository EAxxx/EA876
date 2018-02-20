
#include <stdio.h>


void funcao_maliciosa() {
  char c, *p;
  c = 'T';
  p = &c;
  for (int i = 0; i < 150; i++) {
    printf("%c", *p);
    p += 1;
  }
  printf("\n");
  return;

}

int main() {
  char dado_sigiloso[4] = "FEEC";

  funcao_maliciosa();
  return 0;
}
