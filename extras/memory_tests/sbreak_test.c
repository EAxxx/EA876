#include <stdio.h>
#include <unistd.h>

int main() {
  const unsigned int mem_size = 10000;
  void *mem_start;
  void *mem_end;

  mem_start = sbrk(mem_size);
  mem_end = sbrk(0);

  for (char* sw=mem_start; sw<mem_end; sw++) {
    *sw = 0;
  }

  printf("Start: %x\nEnd: %x\n", mem_start, mem_end);

  sbrk(-mem_size);
  return 0;

}
