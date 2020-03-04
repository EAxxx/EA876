#include <stdio.h>

char pilha[10];
int n_pilha=0;

void push(char c) {
/* Insere caractere c na pilha */
  if (n_pilha < 10) {
    pilha[n_pilha]=c;
    n_pilha++;
  }
}

char pop() {
/* Remove caractere do topo da pilha */
  char c;
  if (n_pilha>0) {
    n_pilha--;
    c = pilha[n_pilha];
  }
  return c;
}

int main() {
  char c;

  push('E');
  push('A');
  push('8');
  push('7');
  push('6');

  for (int i=0; i<5; i++) {
    c = pop();
    printf("%c\n", c);
  }
}
