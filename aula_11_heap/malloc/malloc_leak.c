
#include <stdlib.h>
#include <stdio.h>

void funcao() {
  void *a;
  a = malloc(1000);
  printf("%p\n", a);
}

int main()
{

  funcao();
  funcao();
  funcao();
  funcao();

  return 0;
}
