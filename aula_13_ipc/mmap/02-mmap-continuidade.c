/* Experimento 2
 * mmap-continuidade
 *
 * Pergunta: consigo alocar memoria continua ou ainda aumentar minha area
 * alocada?
 *
 * obs: ver experimento anterior para entender o que eh getpagesize()
 *
 * */

#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>

#define mem_size 1

int main() {
  char *c;
  char *d;
  int mem_count = 0;

  /* Verificar tamanho da pagina do sistema */
  size_t psize = getpagesize();

  /* Definir flags de protecao e visibilidade de memoria */
  int protection = PROT_READ | PROT_WRITE;
  int visibility = MAP_PRIVATE | MAP_ANON;

  /* Criar area de memoria mapeada */
  c = (char*) mmap(NULL, mem_size, protection, visibility, 0, 0);
  d = (char*) mmap(c+psize, mem_size, protection, visibility, 0, 0);


  while(1) {
    c[mem_count] = '0';
    printf("Acessei posicao: %d\n", mem_count++);
  }
  return 0;
}

/* Experimentos complementares
 *
 * 1) malloc() eh implementado com mmap(). Refaca esse mesmo experimento usando
 * malloc(). Quais sao os resultados?
 * 2) malloc()/free() e mmap()/munmap() podem ambos ser usados para administrar
 * memoria em um processo. Por que existe a interface malloc()/free()? Faca
 * hipoteses e monte programas que testam essa hipotese!
 * */

 *
 *

