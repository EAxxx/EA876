/* Experimento 1
 * mmap-pagina
 *
 * Pergunta: existe um tamanho minimo de bloco de memoria que podemos alocar?
 *
 * manpage do mmap: http://man7.org/linux/man-pages/man2/mmap.2.html
 * */

#include <stdio.h>
#include <sys/mman.h>

#define mem_size 1

int main() {
  char *c;
  int mem_count = 0;

  /* Definir flags de protecao e visibilidade de memoria */
  int protection = PROT_READ | PROT_WRITE;
  int visibility = MAP_PRIVATE | MAP_ANON;

  /* Criar area de memoria mapeada */
  c = (char*) mmap(NULL, mem_size, protection, visibility, 0, 0);

  while(1) {
    c[mem_count] = '0';
    printf("Acessei posicao: %d\n", mem_count++);
  }
  return 0;
}

/*
 * Leitura complementar:
 *
 * O nome do 'bloco de memoria' eh pagina.
 * No Linux Kernel Archives ha documentacao atualizada sobre como
 * isso esta implementado na versao atual do Kernel:
 * https://www.kernel.org/doc/gorman/html/understand/understand006.html
 * */


