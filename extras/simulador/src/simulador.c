

#include <stdio.h>

#include "simulador.h"

void cpu_init(Cpu *c) {
  int i;
  c->regA = 0;
  c->regB = 0;
  c->PC = 0;
  for (i=0; i<RAM_SIZE; i++)
    c->ram[i] = 0;
  for (i=0; i<ROM_SIZE; i++)
    c->rom[i] = 0;
}

/* Instrucoes de maquina */
void cpu_LDA(Cpu *c) {
  c->regA = c->ram[c->rom[(c->PC)+1]];
  c->PC += 2;
}

void cpu_LDB(Cpu *c) {
  c->regB = c->ram[c->rom[(c->PC)+1]];
  c->PC += 2;
}

void cpu_STA(Cpu *c) {
  c->ram[c->rom[(c->PC)+1]] = c->regA;
  c->PC += 2;
}

void cpu_STB(Cpu *c) {
  c->ram[c->rom[(c->PC)+1]] = c->regB;
  c->PC += 2;
}

void cpu_SUM(Cpu *c) {
  c->regA += c->regB;
  c->PC += 1;
}

void cpu_SUB(Cpu *c) {
  c->regA -= c->regB;
  c->PC += 1;
}

void cpu_JZ(Cpu *c) {
  if ( (c->regA)==0 ) {
    c->PC = c->rom[(c->PC)+1];
  } else {
    c->PC += 1;
  }
}

void cpu_dump(Cpu *c) {
  int i;
  printf("Estado da CPU\n");
  printf("A=%d\tB=%d\tPC=%d\n", c->regA, c->regB, c->PC);
  printf("RAM: ");
  for (i=0; i<RAM_SIZE; i++)
    printf("%02d ", c->ram[i]);
  printf("\nROM: ");
  for (i=0; i<ROM_SIZE; i++) {
    if (i==c->PC) {printf("*");}
    printf("%02d ", c->rom[i]);
  }
  printf("\n--\n");
}


void cpu_step(Cpu *c) {
  switch (c->rom[c->PC]) {
    case LDA:
      cpu_LDA(c);
      break;
    case LDB:
      cpu_LDB(c);
      break;
    case STA:
      cpu_STA(c);
      break;
    case STB:
      cpu_STB(c);
      break;
    case SUM:
      cpu_SUM(c);
      break;
    case SUB:
      cpu_SUB(c);
      break;
    case JZ:
      cpu_JZ(c);
      break;
    default:
      printf("Instrucao invalida!! PC=%d, [PC]=%d\n", c->PC, c->rom[c->PC]);
  }
}
