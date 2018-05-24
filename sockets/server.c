
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
  int socket_fd, connection_fd;
  struct sockaddr_in myself, client;
  socklen_t client_size = (socklen_t)sizeof(client);
  char input_buffer[50];

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

  while (1) {
    printf("Vou travar ate receber alguma coisa\n");
    connection_fd = accept(socket_fd, (struct sockaddr*)&client, &client_size);
    printf("Recebi uma mensagem:\n");
    recv(connection_fd, input_buffer, 5, 0);
    printf("%s\n", input_buffer);

    /* Identificando cliente */
    char ip_client[INET_ADDRSTRLEN];
    inet_ntop( AF_INET, &(client.sin_addr), ip_client, INET_ADDRSTRLEN );
    printf("IP que enviou: %s\n", ip_client);

    /* Respondendo */
    printf("Enviando mensagem de retorno\n");
    if (send(connection_fd, "PONG", 5, 0) < 0) {
      printf("Erro ao enviar mensagem de retorno\n");
    } else {
      printf("Sucesso para enviar mensagem de retorno\n");
    }
  }

  close(socket_fd);
  return 0;
}
