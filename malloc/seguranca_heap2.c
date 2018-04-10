
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

const char senha[5] = "SENHA";
const char outra_senha[10] = "OUTRASENHA";

int main() {
  char *memoria_sensivel;
  char *outra_memoria_sensivel;

  /* Codigo malicioso: parte 1 */
  void *start;
  char *c;
  const unsigned long int size = 50000;

  start = malloc(size);
  free(start);

  /* Inicializar memoria sensivel */
  memoria_sensivel = (char*) malloc (sizeof(char)*5);
  for (int i=0; i<5; i++) memoria_sensivel[i] = senha[i];
  outra_memoria_sensivel = (char*) malloc (sizeof(char)*5);
  for (int i=0; i<10; i++) outra_memoria_sensivel[i] = outra_senha[i];


  /* Codigo malicioso: parte 2 */
  end = sbrk(0);
  for (c=(char*)0; c<(char*)size; c++) {
    if (*c != 0) {
      printf("%05d %c\n", (long unsigned int)c, *(c+(char*)start));
    }
  }

  return 0;
}
