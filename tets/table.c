#include <stdlib.h>
#include <string.h>
#include "table.h"

#define VERBOSITY 0 // 1 -> displays the table, 0 no display

int memorySizes[2] = {1,1};
int tempCounter = 0;
int condCounter = 0; // to store whether there is a conditional variable

/*At the start of the execution : the whole array is empty*/
static Symbol* symbolTable;

/*indexes in the array*/
static int currentIndex = 0; // the next to index to be used
static int maxIndex = START_TABLE_SIZE;

// stack pointers
static int esp = 0;
static int ebp = 0;

static int currentDepth = 0;

/* /!\ To be called at the beginning
 * Initializes the array of Symbols*/
void initSymbolTable(){
    symbolTable = malloc(sizeof(Symbol) * START_TABLE_SIZE);
}

/*resets the symbol table*/
void resetSymboltable(){
    currentIndex = 0;
    maxIndex = START_TABLE_SIZE;

// stack pointers
    esp = 0;
    ebp = 0;

    currentDepth = 0;
}


/* Error display */
void error(char* mess){
    printf("ERROR : %s\n", mess);
    exit(-1);
}

/* Returns the index from EBP to the symbol in the stack */
int getindex(char* name){
    return (ebp + getStruct(name).index);
}

/* Returns the structure with this name */
Symbol getStruct(char* name){
    for(int i=0; i < currentIndex; i++){
        if (strcmp(symbolTable[i].name, name) == 0){
            return symbolTable[i];
        }
    }
    if (VERBOSITY) {
        printf("\n\n%s not found \n\n", name);
        displayTable();
    }
    error("No structure found");
    return (createNewStructure("error", 0));
}

/* Returns the index with this name*/
int getIndex(char* name){
    for(int i=0; i < currentIndex; i++){
        if (strcmp(symbolTable[i].name, name) == 0){
            return i;
        }
    }
    printf("%s",name);
    error("No index found");
    return (0);
}

/* removes all symbols associated with the current Depth*/
void clearOutOfScopeVariable(){
    int i = 0;
    int memoryFreed = 0;

    // we get to the first symbol that we need to remove
    while(i < currentIndex) {
        if (symbolTable[i].depth == currentDepth) {
            break;
        }
        i++;
    }

    int futureCurrentIndex = i;

    while(i < currentIndex) {
        memoryFreed += memorySizes[symbolTable[i].varType];
        i++;
    }

    // now we remove all the symbols
    currentIndex = futureCurrentIndex;
    checkArraySanity();

    // and we free their memory (i.e. decrease esp)
    esp -= memoryFreed;

    if (VERBOSITY) {
        printf("\n\nclearOutOfScopeVariable::After");
        displayTable();
    }
}


/* sets the init state of the symbol to true */
void setInit(char *name){
    symbolTable[getIndex(name)].init = true;

    if (VERBOSITY) {
        printf("\n\nsetInit %s", name);
        displayTable();
    }
}

/*creates a new structure and updates variables*/
Symbol createNewStructure(char* name, enumVarType type){
    Symbol s;
    strcpy(s.name,name);
    s.init = false;
    s.varType = type;
    s.index = esp; // the index is the current esp
    s.depth = currentDepth;
    return s;
}


/* Adds an element */
void addElement(char* name, enumVarType type){

    Symbol element = createNewStructure(name, type);

    //checks for overflow
    checkArraySanity();

    symbolTable[currentIndex] = element;
    currentIndex ++;

    esp += memorySizes[type];

    if (VERBOSITY) {
        printf("\n\nAddElement %s", name);
        displayTable();
    }
}

/* Adds an element and returns the index of it */
int addElementAndGetAddress(char* name, enumVarType type){
    addElement(name,type);
    return getindex(name);
}

/* Adds a temporary Int element and returns the index of it */
int addTempINTAndGetAddress(){
    char name[NAME_MAX_LENGTH];
    if (tempCounter == 0){
        // we create the first temporary variable and use it
        addElement("0_TEMP_INT",INT);
        strcpy(name, "0_TEMP_INT");
    } else if (tempCounter == 1) {
        // we create the second temporary variable and use it
        addElement("1_TEMP_INT",INT);
        strcpy(name, "1_TEMP_INT");
    } else {
        // we use the right temporary variable
        sprintf(name, "%d_TEMP_INT", tempCounter % 2);
    }
    tempCounter++;
    return getindex(name);
}

/* removes all symbols */
void flushSymbolTable(){
    currentIndex = 0;
    checkArraySanity();
    if (VERBOSITY) {
        printf("\n\nflushSymbolTable::After");
        displayTable();
    }
}


/*Checks for the length of the array and reallocates if necessary*/
void checkArraySanity(){
    if (currentIndex == maxIndex){
        reallocateArray(maxIndex * 2);
    } else {
        if (currentIndex < maxIndex / 4 && maxIndex / 4 > START_TABLE_SIZE){
            reallocateArray(maxIndex / 2);
        }
    }
}

/*reallocates the array with the specified size*/
void reallocateArray(int size){
    Symbol *temp = (Symbol *)realloc(symbolTable, (sizeof(Symbol) * size));

    if (temp != NULL){
        symbolTable = temp;
    }
    else {
        error("Cannot allocate more memory.\n");
    }
}


/*increases the depth (i.e. when entering a block)*/
void increaseDepth(){
    currentDepth++;
}

/*decreases the depth (i.e. when leaving a block)*/
void decreaseDepth(){
    clearOutOfScopeVariable();
    currentDepth--;
}

/*displays the entire table at this moment including all information
 * regarding the symbols and the current depth*/
void displayTable(){
    printf("\n");
    doubleLine();
    printf("Table of Symbols, depth = %d, length = %d, ESP = %d, EBP = %d\n", currentDepth, currentIndex, esp ,ebp);
    printf("Name   | init?, varType, index, depth\n");
    doubleLine();
    for (int i = 0; i < currentIndex; ++i) {
        Symbol a = symbolTable[i];
        printf("%s | %d,   %d,   %d,   %d\n", a.name, a.init, a.varType, a.index, a.depth);
        if (i != currentIndex -1) {
            line();
        }
    }
    doubleLine();
}

/*removes all temporary variables used for INTs*/
void suppressTempINTElements(){
    if (tempCounter == 1){
        suppressElement("0_TEMP_INT");
        esp--;
    } else {
        if (tempCounter > 1){
            suppressElement("0_TEMP_INT");
            suppressElement("1_TEMP_INT");
            esp-= 2;
        }
    }
    tempCounter = 0;
}

/*removes one element*/
void suppressElement(char* name){
    for(int i = getIndex(name); i < (currentIndex - 1); i ++){
        symbolTable[i] = symbolTable[i+1];
    }
    currentIndex--;
    checkArraySanity();
}

void line(){
    printf("---------------------------------\n");
}
void doubleLine(){
    printf("============================================================\n");
}

/*removes all temporary variables used for CONDITIONS*/
void suppressCONDElements(){
    if (condCounter == 1){
        suppressElement("0_TEMP_COND");
        esp--;
    } else {
        if (condCounter > 1){
            suppressElement("0_TEMP_COND");
            suppressElement("1_TEMP_COND");
            esp-= 2;
        }
    }
    condCounter = 0;
}

/* Adds a temporary Conditional element and returns the index of it */
int addTempCONDAndGetAddress(){
    char name[NAME_MAX_LENGTH];
    if (condCounter == 0){
        // we create the first temporary variable and use it
        addElement("0_TEMP_COND",INT);
        strcpy(name, "0_TEMP_COND");
    } else if (condCounter == 1) {
        // we create the second temporary variable and use it
        addElement("1_TEMP_COND",INT);
        strcpy(name, "1_TEMP_COND");
    } else {
        // we use the right temporary variable
        sprintf(name, "%d_TEMP_COND", condCounter % 2);
    }
    condCounter++;
    return getindex(name);
}
