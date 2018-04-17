

#include <stdio.h>
#include <stdlib.h> /* exit() */
#include <sys/types.h> /* define pid_t */
#include <sys/wait.h>
#include <unistd.h> /* fork() */

int main() {
  pid_t pid;
  int i = 0;
  pid = fork();
  i += 1;
  if (pid==0) {
    i = 2;
    exit(0);
  }
  i += 4;
  waitpid(pid, NULL, 0);
  i += 8;
  printf("%d\n", i);
  return 0;
}
