#include <stdio.h>

#define TAM_FILA 10

typedef struct {
  char dados[TAM_FILA];
  int pos_escrita, pos_leitura, n;
} fila, *Fila;

void fila_init(Fila f) {
  f->pos_escrita = 0;
  f->pos_leitura = 0;
  f->n = 0;
}

void fila_adicionar(Fila f, char c) {
  if (f->n < TAM_FILA) {
    f->dados [f->pos_escrita] = c;
    f->pos_escrita = (f->pos_escrita + 1) % TAM_FILA;
    f->n += 1;
  }
}

char fila_remover(Fila f) {
  char c;
  if (f->n > 0) {
    c = f->dados [f->pos_leitura];
    f->pos_leitura = (f->pos_leitura + 1) % TAM_FILA;
    f->n -= 1;
    return c;
  }
}

int main() {
  fila f;

  fila_init(&f);

  fila_adicionar(&f, 'a');
  printf("%c\n", fila_remover(&f));
  fila_adicionar(&f, 'b');
  fila_adicionar(&f, 'c');
  fila_adicionar(&f, 'd');
  fila_adicionar(&f, 'e');
  printf("%c\n", fila_remover(&f));
  printf("%c\n", fila_remover(&f));
  fila_adicionar(&f, 'f');
  printf("%c\n", fila_remover(&f));
  fila_adicionar(&f, 'g');
  printf("%c\n", fila_remover(&f));
  printf("%c\n", fila_remover(&f));
  printf("%c\n", fila_remover(&f));
  return 0;



}
