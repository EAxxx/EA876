/* interface01.c */
#include <stdio.h>
#include "interface.h"

typedef struct {
  int secret;
  float top_secret;
} segredo, *Segredo;

void imprimir() {
  printf("01\n");
  segredo S;
  /* Isso aqui e tudo segredo! */

}
