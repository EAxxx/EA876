
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define PATH_SERIO "./serio"

int main() {
  pid_t pid;
  char *args[] = {PATH_SERIO, NULL};

  printf("Sou um programa malicioso mas vou fingir que sou serio\n");

  pid = fork();

  if (pid==0) {
    execv(PATH_SERIO, args);
  } else {
    printf("Enquanto o programa serio executa, o processo malicioso infecta\n");
    printf("o computador sem que ninguem perceba. Como um cavalo de troia...\n");
    exit(1);
  }

}
