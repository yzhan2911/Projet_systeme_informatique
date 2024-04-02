//
// Created by chepycou on 4/18/23.
//

#ifndef PROJET_SYSTEMES_INFORMATIQUES_ASMTABLE_H
#define PROJET_SYSTEMES_INFORMATIQUES_ASMTABLE_H

#define START_TABLE_SIZE 128
#define LINE_MAX_LENGTH 50

typedef struct {
    char name[LINE_MAX_LENGTH];
    int conditionAddr;
    int jumpLine;
} ASMLine;

/*============================
    Array and Reallocation
 ============================*/

/*reallocates the array with the specified size*/
void reallocateASMArray(int size);

/*Checks for the length of the array and reallocates if necessary*/
void checkASMArraySanity();

/*inserts an asm code line at the current index*/
void addLine(char* s);

/* /!\ To be called at the beginning
 * Initializes the array of Symbols*/
void initASMTable();

/*inserts the address in case of jumps*/
void setJumpLine(int index, int addr);

/*inserts the condition's address in case of jumps*/
void setConditionAddr(int index, int addr);

/*returns the current line (i.e. next one to insert)*/
int getCurrentLineNumber();

/*displays the entire table at this moment*/
void displayASMTable();

/*exports the entire table to asm*/
void exportASMTable();
#endif //PROJET_SYSTEMES_INFORMATIQUES_ASMTABLE_H
