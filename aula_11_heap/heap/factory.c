
#include <stdlib.h>
#include <stdio.h>

typedef struct {
  int matricula;
  float salario;
} reg, *registro;

void novo_registro(registro *r) {
  (*r) = (registro) malloc(sizeof(reg));
}

void remover_registro(registro *r) {
  free (*r);
}

void imprimir_registro(registro *r) {
  printf("Imprimindo registro\n");
  printf("Matricula: %d\n", (*r)->matricula);
  printf("Salario: %f\n", (*r)->salario);
}

int main() {
  registro r;
  novo_registro(&r);
  r->matricula = 1324;
  r->salario = 1937.34;
  imprimir_registro(&r);
  remover_registro(&r);
  return 0;
}
