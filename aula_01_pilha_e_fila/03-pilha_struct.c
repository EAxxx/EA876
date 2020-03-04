#include <stdio.h>

#define TAM_PILHA 10

typedef struct {
  char dados[TAM_PILHA];
  int n;
} pilha, *Pilha;

void pilha_init(Pilha p) {
  p->n = 0;
}

void push(Pilha p, char c) {
/* Insere caractere c na pilha */
  if (p->n < 10) {
    p->dados[p->n]=c;
    (p->n)++;
  }
}

char pop(Pilha p) {
/* Remove caractere do topo da pilha */
  char c;
  if ((p->n)>0) {
    (p->n)--;
    c = p->dados[p->n];
  }
  return c;
}

int main() {
  char c;
  pilha p1, p2;

  pilha_init(&p1);
  pilha_init(&p2);

  push(&p1, 'E');
  push(&p2, 'A');
  push(&p1, '8');
  push(&p2, '7');

  for (int i=0; i<2; i++) {
    c = pop(&p1);
    printf("%c\n", c);
  }

  for (int i=0; i<2; i++) {
    c = pop(&p2);
    printf("%c\n", c);
  }
}


