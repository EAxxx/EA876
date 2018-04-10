
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
  const unsigned long int size = 150;
  start = malloc(size);
  free(start);


  /* Inicializar memoria sensivel */
  memoria_sensivel = (char*) malloc (sizeof(char)*5);
  for (int i=0; i<5; i++) memoria_sensivel[i] = senha[i];
  outra_memoria_sensivel = (char*) malloc (sizeof(char)*10);
  for (int i=0; i<10; i++) outra_memoria_sensivel[i] = outra_senha[i];

/*  printf("%p\n", memoria_sensivel);
  printf("%p\n", outra_memoria_sensivel);
*/
  /*free(memoria_sensivel);
  free(outra_memoria_sensivel);*/


/*  printf("%p\n", start);
*/

  printf("Varrendo heap\n");
  /* Codigo malicioso: parte 2 */
  void *end = start + size;
  for (c=(char*)start; c<(char*)end; c++) {
    /*printf("%lu\n", (unsigned long int)((int)c-(int)start));*/
    if (*c != 0) {
      printf("%p %c\n", c, *c);
    }
  }

  return 0;
}


