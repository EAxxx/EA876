
#include <stdio.h>

char mensagem[] = "Mensagem secreta!";

int main() {
  printf("Mensagem: %s\n", mensagem);

  /* Executar cifra */
  int i=0;
  while (mensagem[i] != '\0'){
    mensagem[i] ++;
    i++;
  }

  printf("Mensagem que trafega: %s\n", mensagem);

  /* Recuperar cifra */
  i = 0;
  while(mensagem[i] != '\0') {
    mensagem[i]--;
    i++;
  }

  printf("Mensagem recuperada: %s\n", mensagem);

  return 0;
}
