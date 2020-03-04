#include "simulador.h"
#include <stdio.h>

#define TAM_PROG 12
#define TAM_MEM 2

const uint8_t rom_inicial[TAM_PROG] = {0, 0, 1, 1, 4, 2, 0, 1, 0, 5, 6, 0};
const uint8_t ram_inicial[TAM_MEM] = {3, 4};

int main() {
  int i;
  Cpu minha_cpu;
  Cpu *c;
  c = &minha_cpu;

  cpu_init(c);

  for (i=0; i<TAM_PROG; i++)
    c->rom[i] = rom_inicial[i];
  for (i=0; i<TAM_MEM; i++)
    c->ram[i] = ram_inicial[i];

  cpu_dump(c);

  for (i=0; i<20; i++) {
    printf("Step: %d\n", i);
    cpu_step(c);
    cpu_dump(c);
  }

  return 0;
}
