
#include <stdio.h>
#include <unistd.h>

int main() {
  fwrite("teste\n", 6, 1, stdout);
  sleep(1);
  fwrite("teste\n", 6, 1, stdout);
  sleep(1);
  fwrite("teste\n", 6, 1, stdout);
  return 0;
}
