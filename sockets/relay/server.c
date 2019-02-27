
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CONEXOES 5

/* Estou usando variaveis globais para me referir a variaveis que sao usadas
 * tanto pela trhead principal quanto pela auxiliar. Mas, criancas, nao facam
 * isso em casa. A abordagem correta eh colocar todas as variaveis numa struct e
 * passa-la como parametro na chamada da thread */

struct sockaddr_in myself, client;
socklen_t client_size;
int socket_fd;
int connection_fd[MAX_CONEXOES];
int conexao_usada[MAX_CONEXOES];
int running;


int adicionar_conexao(int new_connection_fd) {
  int i;
  for (i=0; i<MAX_CONEXOES; i++) {
    if (conexao_usada[i] == 0) {
      conexao_usada[i] = 1;
      connection_fd[i] = new_connection_fd;
      return i;
    }
  }
  return -1;
}

int remover_conexao(int user) {
  if (conexao_usada[user]==1) {
  conexao_usada[user] = 0;
  close(connection_fd[user]);
  }
  return 1;
}

void *wait_connections(void *parameters) {
  int conn_fd;
  int user_id;
  while(running) {
    conn_fd = accept(socket_fd, (struct sockaddr*)&client, &client_size);
    user_id = adicionar_conexao(conn_fd);
    if (user_id != -1) {
      printf("Novo usuario chegou! ID=%d\n", user_id);
    } else {
      printf("Maximo de usuarios atingido!\n");
    }
  }
  return NULL;
}



int main() {
  pthread_t esperar_conexoes;
  int msglen;
  int user_iterator;
  char output_buffer[60];
  char input_buffer[60];

  /* Inicializando variaveis */
  client_size = (socklen_t)sizeof(client);
  for (int i=0; i<MAX_CONEXOES; i++) {
    conexao_usada[i] = 0;
  }
  running = 1;

  /* socket, bind, listen */
  socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  printf("Socket criado\n");
  myself.sin_family = AF_INET;
  myself.sin_port = htons(3001);
  inet_aton("127.0.0.1", &(myself.sin_addr));
  printf("Tentando abrir porta 3001\n");
  if (bind(socket_fd, (struct sockaddr*)&myself, sizeof(myself)) != 0) {
    printf("Problemas ao abrir porta\n");
    return 0;
  }
  printf("Abri porta 3001!\n");
  listen(socket_fd, 2);
  printf("Estou ouvindo na porta 3001!\n");

  /* Dispara thread para ouvir conexoes */
  pthread_create(&esperar_conexoes, NULL, wait_connections, NULL);

  while (running) {
    for (user_iterator=0; user_iterator<MAX_CONEXOES; user_iterator++) {
      if (conexao_usada[user_iterator] == 1) {
        msglen = recv(connection_fd[user_iterator], input_buffer, 50, MSG_DONTWAIT);
        if (msglen > 0) {
          printf("Recebi mensagem de %d\n", user_iterator);
          if ( strcmp(input_buffer, "END") == 0) running=0;
          sprintf(output_buffer, "USER %d: %s\n", user_iterator, input_buffer);
          printf("%s", output_buffer);
          for (int ret=0; ret<MAX_CONEXOES; ret++) {
            if (conexao_usada[ret] == 1) {
              printf("Avisando user %d\n", ret);
              if (send(connection_fd[ret], output_buffer, 50, MSG_NOSIGNAL) == -1) {
               /* Usuario desconectou!?? */
                printf("Usuario %d desconectou!\n", ret);
                remover_conexao(ret);
              }
            }
          }
          for (int i=0; i<60; i++){
            output_buffer[i]='\0';
            input_buffer[i]='\0';
          }
        }
      }
    }
  }

  printf("Encerrando server...\n");
  for (user_iterator=0; user_iterator<MAX_CONEXOES; user_iterator++)
    remover_conexao(user_iterator);

  pthread_join(esperar_conexoes, NULL);

  return 0;
}
