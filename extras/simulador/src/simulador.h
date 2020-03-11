
#ifndef SIMULADOR_H
#define SIMULADOR_H

#include <stdint.h>

#define ROM_SIZE 20
#define RAM_SIZE 10

typedef enum {
  LDA = 0, /* Carrega posicao da memoria para A */
  LDB, /* Carrega posicao da memoria para B */
  STA, /* Guarda conteudo de A na posicao de memoria estabelecida */
  STB, /* Guarda conteudo de B na posicao de memoria estabelecida */
  SUM, /* Soma registradores A e B e guarda o resultado em A */
  SUB, /* Subtrai regitradores A e B e guarda o resultado em A */
  JZ, /* Se o conteudo de A for zero, pula para posicao de memoria determinada */

  /* Instrucoes nao-implementadas ainda */
  LLDA, /* Carrega literal para registrador A */
  LLDB, /* Carrega literal para registrador B */
  PLDB, /* Carrega em B o conteudo da memoria apontada por A */
  DECA, /* Decrementa registrador A em 1 */
  JNZ /* Se o conteudo de A nao for zero, pula para a posicao de memoria especificada */
} instrucao;


typedef struct {
  uint8_t regA; /* Registrador A */
  uint8_t regB; /* Registrador B */
  uint8_t PC; /* Program counter */
  instrucao rom[ROM_SIZE]; /* Memoria ROM (de programa) */
  uint8_t ram[RAM_SIZE]; /* Memoria RAM (de dados) */
 } Cpu;

/* Inicializa cpu */
void cpu_init(Cpu *c);

/* Instrucoes de maquina */
void cpu_LDA(Cpu *c);
void cpu_LDB(Cpu *c);
void cpu_STA(Cpu *c);
void cpu_STB(Cpu *c);
void cpu_SUM(Cpu *c);
void cpu_SUB(Cpu *c);
void cpu_JZ(Cpu *c);

/* Imprime estado da CPU na tela */
void cpu_dump(Cpu *c);

/* Executa instrucao */
void cpu_step(Cpu *c);

#endif
