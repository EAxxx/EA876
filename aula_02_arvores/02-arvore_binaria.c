
#include <stdio.h>

typedef struct no {
  int dado;
  struct no* f_esq;
  struct no* f_dir;
} noarv, *Noarv;

noarv novo_no(int dado) {
  noarv no;
  no.dado = dado;
  no.f_esq = NULL;
  no.f_dir = NULL;
  return no;
}

void in_ordem(Noarv no) {
  if (no == NULL) return;
  in_ordem(no->f_esq);
  printf("%d\n", no->dado);
  in_ordem(no->f_dir);
}

void imprimir_parenteses(Noarv no) {
  if (no == NULL) return;

  printf("(");
  imprimir_parenteses(no->f_esq);
  printf(")");

  printf(" %d ", no->dado);

  printf("(");
  imprimir_parenteses(no->f_dir);
  printf(")");
}

int main() {
  noarv n1, n2, n3;

  n1 = novo_no(1);
  n2 = novo_no(2);
  n3 = novo_no(3);

  n1.f_esq = &n2;
  n1.f_dir = &n3;

  printf("Percurso em inordem: \n");
  in_ordem(&n1);

  printf("\n\nNotacao parentetica:\n");
  imprimir_parenteses(&n1);
  printf("\n");

  return 0;
}

