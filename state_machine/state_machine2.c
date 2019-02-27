
/* Demonstracao de maquina de estados */

#include <stdio.h>

/* Maquina de estados:
 * Detecta se existe ao menos um numero inteiro na linha inserida */

int eh_digito(char c)
{
  if ((c >= '0') && (c <= '9')) return 1;
  else return 0;
}

int eh_espaco(char c)
{
  if ((c == ' ') || (c == '\t')) return 1;
  else return 0;
}

int eh_eol(char c)
{
  if ((c == '\n') || (c == '\r')) return 1;
  else return 0;
}

typedef struct {
  int estado_atual;
} fsm, *Fsm; /* fsm = finite state machine */

int opera_fsm(void *this_fsm, char entrada) {
  Fsm maquina = (Fsm) this_fsm;

  switch (maquina->estado_atual) {
    case 0:
      if (eh_digito(entrada)) {
        maquina->estado_atual = 3;
      } else {
        maquina->estado_atual = 1;
      }
      break;

    case 1:
      if (eh_espaco(entrada)) {
        maquina->estado_atual = 2;
      }
      break;

    case 2:
      if (eh_espaco(entrada)) {
        maquina->estado_atual = 2;
      } else if (eh_digito(entrada)) {
        maquina->estado_atual = 3;
      } else {
        maquina->estado_atual = 1;
      }
      break;

    case 3:
      if (eh_espaco(entrada) || eh_eol(entrada)) {
        maquina->estado_atual = 4;
      } else if (eh_digito(entrada)) {
        maquina->estado_atual = 3;
      } else {
        maquina->estado_atual = 1;
      }
      break;

    case 4:
      if (eh_espaco(entrada)) {
        maquina->estado_atual = 2;
      } else if (eh_digito(entrada)) {
        maquina->estado_atual = 3;
      } else {
        maquina->estado_atual = 1;
      }
      break;
  }
  return (maquina->estado_atual);
}

int main() {
  char buffer_in[100];
  char c;
  int pointer;
  int achei_inteiro;

  for (int i=0; i<100; i++) buffer_in[i] = '\0';

  pointer = 0;
  do {
    c=getchar();
    buffer_in[pointer++] = c;
  } while (c != '\n');


  fsm maquina;
  maquina.estado_atual = 0;

  pointer = 0;
  achei_inteiro = 0;
  while (buffer_in[pointer] != '\0') {
    opera_fsm((void*) (&maquina), buffer_in[pointer]);
    if (maquina.estado_atual == 4) achei_inteiro = 1;
    printf("Entrada: %c\tEstado: %d\n", buffer_in[pointer], maquina.estado_atual);
    pointer++;
  }

  if (achei_inteiro == 1) printf("ACEITAR\n");
  else printf("REJEITAR\n");

  return 0;
}
