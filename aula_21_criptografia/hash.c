
#include <openssl/sha.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  unsigned char output[64];

  printf("SHA512 para %s\n", argv[1]);

  SHA512(argv[1], strlen(argv[1]), output);

  for (int i=0; i<64; i++)

    printf("%02x", output[i]);
  printf("\n");


  return 0;
}
