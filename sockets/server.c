
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
  int socket_fd, msg;
  struct sockaddr_in myself, client;
  socklen_t client_size = (socklen_t)sizeof(client);
  char input_buffer[50];

  socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  printf("Socket criado\n");

  myself.sin_family = AF_INET;
  myself.sin_port = htons(3000);
  inet_aton("127.0.0.1", &(myself.sin_addr));

  printf("Tentando abrir porta 3000\n");
  if (bind(socket_fd, (struct sockaddr*)&myself, sizeof(myself)) != 0) {
    printf("Problemas ao abrir porta\n");
    return 0;
  }
  printf("Abri porta 3000!\n");

  listen(socket_fd, 2);
  printf("Estou ouvindo na porta 3000!\n");

  printf("Vou travar ate receber alguma coisa\n");
  msg = accept(socket_fd, (struct sockaddr*)&client, &client_size);
  printf("Recebi uma mensagem:\n");
  read(msg, input_buffer, 5);
  printf("%s\n", input_buffer);

  /* Identificando cliente */
  char ip_client[INET_ADDRSTRLEN];
  inet_ntop( AF_INET, &(client.sin_addr), ip_client, INET_ADDRSTRLEN );
  printf("IP que enviou: %s\n", ip_client);

  close(socket_fd);
  return 0;
}
