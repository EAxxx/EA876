
#include <stdio.h>
#include <stdlib.h> /* exit() */
#include <sys/types.h> /* define pid_t */
#include <unistd.h> /* fork() */

int main() {
  pid_t pid;
  int i;

  pid = fork();
  if (pid==0) {
    printf("Processo filho\n");
    scanf("%d", &i);
    printf("Saindo do proceso filho\n");
    exit(0);
  }
  printf("Processo pai. PID do filho: %d\n", pid);
  scanf("%d", &i);
  printf("Saindo do processo pai\n");
  return 0;
}
