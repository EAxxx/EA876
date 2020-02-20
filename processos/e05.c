
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  char * const arglist[] = {"/bin/ls", "-l",  NULL};
  printf("Comutando...\n");
  execv("/bin/ls", arglist);
  printf("Vou chegar aqui?\n");

  return 0;
}
