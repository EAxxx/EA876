
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *arquivo;

  /* Escrevendo em um arquivo */
  arquivo = fopen("teste.txt", "w");
  fwrite("Tiago esteve aqui!\n", 13, 1, arquivo);
  fwrite("Escrevendo denovo!\n", 10, 2, arquivo);
  fclose(arquivo);

  /* Lendo um arquivo */
  char buffer[10];
  arquivo = fopen("teste.txt", "r");
  fread(buffer, 5, 1, arquivo);
  printf("%s", buffer);
  fread(buffer, 5, 1, arquivo);

  fread(arquivo, buffer, 5);
  printf("%s", buffer);
  fread(arquivo, buffer, 5);
  printf("%s", buffer);
  fclose(arquivo);

  return 0;
}
