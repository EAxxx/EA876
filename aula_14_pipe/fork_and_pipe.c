#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
  pid_t pid;
  int pipefd[2];

  pipe(pipefd);
  pid = fork();

  if (pid == 0) {
    /* Processo filho */
    char c;
    close(pipefd[1]);
    while(read(pipefd[0], &c, 1) > 0) {
      fprintf(stdout, "Proc. Filho escreve: %c\n", c);
      sleep(1);
    }
    exit(1);
  }
    close(pipefd[0]);
    write(pipefd[1], "OLA\n", 4);
    close(pipefd[1]);
    waitpid(pid, NULL, 0);
    printf("Saindo do programa...\n");
    return 0;
}
