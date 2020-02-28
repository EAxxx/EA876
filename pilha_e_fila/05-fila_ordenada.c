#include <stdio.h>

#define TAM_FILA 10

typedef struct {
  int dados[TAM_FILA];
  int n;
} fila, *Fila;

void fila_init(Fila f) {
  f->n = 0;
}

void fila_imprimir(Fila f) {
  for (int i=0; i< f->n; i++) {
    printf("%d ", f->dados[i]);
  }
  printf("\n");
}

void fila_adicionar(Fila f, int val) {
  int i;
  int k;
  if (f->n < TAM_FILA) {
    i = f->n;
    f->dados[i] = val;
    while ( (i>0) && (f->dados[i] < f->dados[i-1]) ) {
      k = f->dados[i];
      f->dados[i] = f->dados[i-1];
      f->dados[i-1] = k;
      i--;
    }
    f->n += 1;
  }
}


int main() {
  fila f;

  fila_init(&f);

  fila_adicionar(&f, 1);
  fila_adicionar(&f, 3);
  fila_adicionar(&f, 2);
  fila_adicionar(&f, 10);
  fila_adicionar(&f, 6);

  fila_imprimir(&f);


  return 0;



}
