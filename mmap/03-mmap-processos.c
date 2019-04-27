/* Experimento 3
 * mmap-processos
 *
 * Pergunta: a memoria mapeada como shared em um processo eh acessivel em outro
 * processo?
 * */

#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>

#define mem_size 1

int main() {
  int **shared;
  int mem_count = 0;
  pid_t pid;

  /* Definir flags de protecao e visibilidade de memoria */
  int protection = PROT_READ | PROT_WRITE;
  int visibility = MAP_SHARED | MAP_ANON;

  /* Criar area de memoria mapeada */
  shared = (int**) mmap(NULL, sizeof(int*), protection, visibility, 0, 0);

  pid = fork();

  if (pid==0) {
    /* Processo-filho */
    int *mem_filho;
    mem_filho = (int*) mmap(NULL, sizeof(int), protection, visibility, 0, 0);
    (*shared) = mem_filho;
    printf("Process-filho alocou memoria compartilhada\n");
    printf("Endereco mapeado no filho: %x\n", mem_filho);
    sleep(2);
    printf("Pai escreveu: %d\n", *mem_filho);

    exit(0);
  }
  /* Processo-pai */
  sleep(1);
  printf("Processo-pai tentando acessar memoria compartilhada pelo filho\n");
  int *mem_pai;
  mem_pai = (*shared);
  printf("Endereco lido no pai: %x\n", mem_pai);
  (*mem_pai) = 1; /* Escrever qualquer inteiro */
  sleep(3);
  return 0;
}


/* Reflexoes complementares
 *
 * De acordo com os resultados que voce encontrou neste programa, reflita:
 * a) A tabela que mapeia a memoria virtual para a fisica esta vinculada a cada
 * processo, ou ha uma tabela 'publica'?
 *
 * b) A tabela eh copiada quanto usamos o fork()?
 *
 * c) Explique o comportamento deste programa.
 */
