#include <stdio.h>


void push(char *pilha, int *n_pilha, char c) {
/* Insere caractere c na pilha */
  if ((*n_pilha) < 10) {
    pilha[*n_pilha]=c;
    (*n_pilha)++;
  }
}

char pop(char *pilha, int (*n_pilha)) {
/* Remove caractere do topo da pilha */
  char c;
  if ((*n_pilha)>0) {
    (*n_pilha)--;
    c = pilha[*n_pilha];
  }
  return c;
}

int main() {
  char c;
  char pilha_1[10];
  char pilha_2[10];
  int n_pilha_1=0;
  int n_pilha_2=0;

  push(pilha_1, &n_pilha_1, 'E');
  push(pilha_2, &n_pilha_2, 'A');
  push(pilha_1, &n_pilha_1, '8');
  push(pilha_2, &n_pilha_2, '7');

  for (int i=0; i<2; i++) {
    c = pop(pilha_1, &n_pilha_1);
    printf("%c\n", c);
  }

  for (int i=0; i<2; i++) {
    c = pop(pilha_2, &n_pilha_2);
    printf("%c\n", c);
  }
}


