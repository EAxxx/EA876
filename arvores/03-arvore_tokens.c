
#include <stdio.h>

#define N_FILHOS 5

typedef enum {
  NUMERO,
  SOMA
} tipo_token;

typedef struct no {
  int valor;
  tipo_token tipo;
  struct no* filhos[N_FILHOS];
  int n_filhos;
} noarv, *Noarv;

noarv novo_no(int valor, tipo_token tipo) {
  noarv no;
  no.valor = valor;
  no.tipo = tipo;
  no.n_filhos = 0;
  return no;
}

void adicionar_filho(Noarv no_pai, Noarv no_filho) {
  if (no_pai->n_filhos < N_FILHOS) {
    no_pai->filhos[no_pai->n_filhos] = no_filho;
    no_pai->n_filhos += 1;
  }
}

int resolver(Noarv no) {
  if (no->tipo == NUMERO) {
    printf("Encontrei numero! Retornando %d\n", no->valor);\
    return no->valor;
  }

  if (no->tipo == SOMA) {
    int val=0;
    printf("Encontrei soma. Resolvendo...\n");
    for (int i=0; i<no->n_filhos; i++) {
      val += resolver(no->filhos[i]);
    }
    printf("Soma resolvida! Retornando %d\n", val);
    return val;
  }
}


int main() {
  noarv n1, n2, n3, n4, n5;

  n1 = novo_no(0,SOMA);
  n2 = novo_no(1,NUMERO);
  n3 = novo_no(2,NUMERO);

  adicionar_filho(&n1, &n2);
  adicionar_filho(&n1, &n3);

  printf("Resolvendo n1:\n");
  resolver(&n1);
  printf("----\n");

  n4 = novo_no(0, SOMA);
  n5 = novo_no(5, NUMERO);

  adicionar_filho(&n4, &n5);
  adicionar_filho(&n4, &n1);

  printf("Resolvendo n4:\n");
  resolver(&n4);
  printf("----\n");


  return 0;
}

