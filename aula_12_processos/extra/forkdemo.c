
#include <stdio.h>
#include <stdlib.h> /* exit() */
#include <sys/types.h> /* define pid_t */
#include <unistd.h> /* fork() */

int main() {
  pid_t pid;

  for (int i=0; i<5; i++) {
    pid = fork();
    if (pid==0) {
      printf("Processo filho - i = %d\n", i);
    }
  }
  printf("Fim de um processo\n");
  sleep(1);
  return 0;

}
