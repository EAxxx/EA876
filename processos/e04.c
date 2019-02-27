

#include <stdio.h>
#include <stdlib.h> /* exit() */
#include <sys/types.h> /* define pid_t */
#include <sys/wait.h>
#include <unistd.h> /* fork() */

int fibo(int N) {
  if (N<2) return 1;
  else return fibo(N-1)+fibo(N-2);
}

int main() {
  pid_t pid[40];
  int i = 0;
  for (int j=0; j<40; j++) {
    pid[j] = fork();
    i += 1;
    if (pid[j]==0) {
      i = 2;
      fibo(60);
      exit(0);
    }
  }
  i += 4;
  for (int j=0; j<40; j++)
    waitpid(pid[j], NULL, 0);
  i += 8;
  printf("%d\n", i);
  return 0;
}
