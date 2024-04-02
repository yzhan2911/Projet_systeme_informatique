
#include <stdio.h>
#include "asmTable.h"
#include "stdlib.h"
#include <string.h>

static int labelCounter = 0;

/*At the start of the execution : the whole array is empty*/
static ASMLine* asmTable;
static int lineCounter = 0;
static int maxIndex = START_TABLE_SIZE;


#include "asmTable.h"
#include "table.h"

/* /!\ To be called at the beginning
 * Initializes the array of Symbols*/
void initASMTable(){
    asmTable = malloc(sizeof(ASMLine) * START_TABLE_SIZE);
}

/*Checks for the length of the array and reallocates if necessary*/
void checkASMArraySanity(){
    if (lineCounter == maxIndex){
        reallocateASMArray(maxIndex * 2);
    }
}

/*reallocates the array with the specified size*/
void reallocateASMArray(int size){
    ASMLine *temp = (ASMLine*) realloc(asmTable, (sizeof(ASMLine) * size));
    if (temp != NULL){
        asmTable = temp;
    }
    else {
        error("Cannot allocate more memory.\n");
    }
}

/*inserts an asm code line at the current index*/
void addLine(char* s) {
    strcpy(asmTable[lineCounter].name,s);
    asmTable[lineCounter].jumpLine = -1;
    asmTable[lineCounter].conditionAddr = -1;
    lineCounter++;
    checkASMArraySanity();
    displayASMTable();
}

/*inserts the address in case of jumps*/
void setJumpLine(int index, int addr) {
    asmTable[index].jumpLine = addr;
    displayASMTable();
}


/*inserts the condition's address in case of jumps*/
void setConditionAddr(int index, int addr) {
    asmTable[index].conditionAddr = addr;
    displayASMTable();
}

/*returns the current line (i.e. next one to insert)*/
int getCurrentLineNumber() {
    return lineCounter;
}

/*displays the entire table at this moment*/
void displayASMTable(){
    printf("\n");
    doubleLine();
    for (int i = 0; i < lineCounter; ++i) {
        ASMLine a = asmTable[i];
        if(a.jumpLine == -1) {
            printf("%d | %s\n", i, a.name);
        } else {
            if(a.conditionAddr == -1) {
                printf("%d | %s %d\n", i, a.name,a.jumpLine);
            } else {
                printf("%d | %s %d %d\n", i, a.name,a.conditionAddr,a.jumpLine);
            }
        }
        if (i != lineCounter -1) {
            line();
        }
    }
    doubleLine();
}

/*exports the entire table to asm*/
void exportASMTable(){
    FILE* fp;
    fp = fopen("asm", "a");
    for (int i = 0; i < lineCounter; ++i) {
        ASMLine a = asmTable[i];
        if(a.jumpLine == -1) {
            fprintf(fp,"%s\n", a.name);
        } else {
            if(a.conditionAddr == -1) {
                fprintf(fp,"%s %d\n", a.name,a.jumpLine);
            } else {
                fprintf(fp,"%s %d %d\n", a.name,a.conditionAddr,a.jumpLine);
            }
        }
    }
    fclose(fp);
}