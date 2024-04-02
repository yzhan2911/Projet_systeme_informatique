#ifndef TABLE_H
#define TABLE_H

#include <stdio.h>
#include <stdbool.h>

/*defined constants*/
#define START_TABLE_SIZE 128
#define NAME_MAX_LENGTH 30

// a list of all type
typedef enum enumVarType {INT, FLOAT} enumVarType;

// a list of all type's sizes
extern int memorySizes[2];

typedef struct {
    char name[NAME_MAX_LENGTH];
    bool init;
    enumVarType varType;
    int index;
    int depth;
} Symbol;

/*============================
    Array and Reallocation
 ============================*/

/*reallocates the array with the specified size*/
void reallocateArray(int size);

/*Checks for the length of the array and reallocates if necessary*/
void checkArraySanity();

/* /!\ To be called at the beginning
 * Initializes the array of Symbols*/
void initSymbolTable();

/*resets the symbol table*/
void resetSymboltable();

/*inserts an asm code line at the current index*/
void addLine(char* s);

/*returns the current line (i.e. next one to insert)*/
int getCurrentLineNumber();

/*============================
       Element Management
 ============================*/

/* removes all symbols associated with the current Depth*/
void clearOutOfScopeVariable();

/* removes all symbols */
void flushSymbolTable();

/* Adds an element */
void addElement(char* name, enumVarType type);

/* Adds an element and returns the index of it */
int addElementAndGetAddress(char* name, enumVarType type);

/* Adds a temporary Int element and returns the index of it */
int addTempINTAndGetAddress();

/* Adds a temporary Conditional element and returns the index of it */
int addTempCONDAndGetAddress();

/*creates a new structure and updates variables*/
Symbol createNewStructure(char* name, enumVarType type);

/*============================
       Element Edition
 ============================*/

/* sets the init state of the symbol to true */
void setInit(char *name);

/*removes one element*/
void suppressElement(char* name);

/*removes all temporary variables used for INTs*/
void suppressTempINTElements();

/*removes all temporary variables used for CONDITIONS*/
void suppressCONDElements();

/*============================
       Element Access
 ============================*/

/* Returns the index with this name*/
int getIndex(char* name);

/* Returns the structure with this name */
Symbol getStruct(char* name);

/* Returns the index from EBP to the symbol in the stack */
int getindex(char* name);


/*==========================
       Flow/Block control
 =========================*/

/*increases the depth (i.e. when entering a block)*/
void increaseDepth();

/*decreases the depth (i.e. when leaving a block)*/
void decreaseDepth();

/*============================================
       Display, Todo : put in another .h file
 ============================================*/

void error(char* mess);
void line();
void doubleLine();

/*displays the entire table at this moment including all information
 * regarding the symbols and the current depth*/
void displayTable();

#endif
