
#include <stdio.h>

#define N_FILHOS 5

typedef struct no {
  int dado;
  struct no* filhos[N_FILHOS];
  int n_filhos;
} noarv, *Noarv;

noarv novo_no(int dado) {
  noarv no;
  no.dado = dado;
  no.n_filhos = 0;
  return no;
}

void adicionar_filho(Noarv no_pai, Noarv no_filho) {
  if (no_pai->n_filhos < N_FILHOS) {
    no_pai->filhos[no_pai->n_filhos] = no_filho;
    no_pai->n_filhos += 1;
  }
}

void pos_ordem(Noarv no) {
  for (int i=0; i<no->n_filhos; i++) {
    pos_ordem(no->filhos[i]);
  }
  printf("%d\n", no->dado);
}


int main() {
  noarv n1, n2, n3;

  n1 = novo_no(1);
  n2 = novo_no(2);
  n3 = novo_no(3);

  adicionar_filho(&n1, &n2);
  adicionar_filho(&n2, &n3);

  printf("pos-ordem a partir de n2:\n");
  pos_ordem(&n2);

  printf("\n\npos-ordem a partir de n1:\n");
  pos_ordem(&n1);

  return 0;
}

