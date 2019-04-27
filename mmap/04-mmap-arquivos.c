/* Experimento 4
 * mmap-arquivos
 *
 * Pergunta: como mapear um arquivo usando mmap?
 *
 * manpage do mmap: http://man7.org/linux/man-pages/man2/mmap.2.html
 * manpage do open: http://man7.org/linux/man-pages/man2/open.2.html
 * */

#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define mem_size 10

int main() {
  char *c;
  int i = 0;

  int fd;

  int file_flags = O_CREAT | O_RDWR | O_APPEND;
  fd = open("./teste.txt", file_flags);


  int protection = PROT_READ | PROT_WRITE;
  int visibility = MAP_SHARED;

  /* Criar area de memoria mapeada */
  c = (char*) mmap(NULL, mem_size, protection, visibility, fd, 0);

  printf("Primeira passagem:\n");
  for (i=0; i<10; i++) {
    printf("Li do arquivo na posicao [%d]: %c\n", i, c[i]);
    c[i] = c[i]+1;
  }

 close(fd);

  return 0;
}


