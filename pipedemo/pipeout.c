#include <stdio.h>

int main() {
  FILE *fp;
  char c;

  unsigned int contador = 0;

  fp = popen("cat > teste.txt", "w");
  fprintf(fp, "Pipeout executou\n");
  pclose(fp);

  return 0;
}
