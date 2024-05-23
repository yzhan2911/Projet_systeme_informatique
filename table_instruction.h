#ifndef TABLE_INSTRUCTION_H
#define TABLE_INSTRUCTION_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ADD 0x01
#define MUL 0x02
#define SOU 0x03
#define DIV 0x04
#define COP 0x05
#define AFC 0x06
#define JMP 0x07
#define JMF 0x08
#define INF 0x09
#define SUP 0xA
#define EQU 0xB
#define PRI 0xC

typedef struct instruction {
    char * operation;
    int r0;
    int r1;
    int r2;
} instruction;

void add_instruction(char * op, int r0,int r1,int r2);
void ini_table_instruction();
void setInstruTR1(int index,int var,int registre);
int get_index_current();
int get_index_tab();
int add_condition(char * condition,int r1,int r2);
int excu_op (char* op,int r1, int r2);
void exportASMTable();

#endif
