#include <stdio.h>
#include <unistd.h>

int main() {
  const unsigned int mem_size = 10000;
  char c;
  char *mem_end = &c;
  char *mem_start;

  mem_start = sbrk(0);

  printf("Start: %x\nEnd: %x\n", mem_start, mem_end);

  for (char* sw=mem_start; sw<mem_end; sw++) {
    *sw = 0;
  }



  return 0;
}
