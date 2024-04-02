//
// Created by chepycou on 4/14/23.
//

#include <stdio.h>
#include "table.h"
#include "operations.h"
#include "asmTable.h"

/*prints to the stdout and the out asm file*/
void printOp(char* s){
    //printf("%s",s);
    addLine(s);

    /*FILE* fp;
    fp = fopen("asm", "a");
    fputs(s, fp);
    fclose(fp);*/
}

/*clears the out asm file*/
void clearOp(){
    FILE* fp;
    fp = fopen("asm", "w");
    fclose(fp);
}

/*prints the ASM instruction for the addition computation
 * and returns the address of the temporary variable*/
int operation_add(int addr1, int addr2){
    int addr = addTempINTAndGetAddress();
    char s[ASM_TEXT_LEN];
    sprintf(s, "ADD %d %d %d", addr, addr1, addr2);
    printOp(s);
    return addr;
}

/*prints the ASM instruction for the subtraction computation
 * and returns the address of the temporary variable*/
int operation_sub(int addr1, int addr2){
    int addr = addTempINTAndGetAddress();
    char s[ASM_TEXT_LEN];
    sprintf(s, "SUB %d %d %d", addr, addr1, addr2);
    printOp(s);
    return addr;
}

/*prints the ASM instruction for the multiplication computation
 * and returns the address of the temporary variable*/
int operation_mul(int addr1, int addr2){
    int addr = addTempINTAndGetAddress();
    char s[ASM_TEXT_LEN];
    sprintf(s, "MUL %d %d %d", addr, addr1, addr2);
    printOp(s);
    return addr;
}

/*prints the ASM instruction for the integer division computation
 * and returns the address of the temporary variable*/
int operation_divInt(int addr1, int addr2){
    int addr = addTempINTAndGetAddress();
    char s[ASM_TEXT_LEN];
    sprintf(s, "DIV_INT %d %d %d", addr, addr1, addr2);
    printOp(s);
    return addr;
}

/*prints the ASM instruction for the remainder computation
 * and returns the address of the temporary variable*/
int operation_divRem(int addr1, int addr2){
    int addr = addTempINTAndGetAddress();
    char s[ASM_TEXT_LEN];
    sprintf(s, "DIV_REM %d %d %d", addr, addr1, addr2);
    printOp(s);
    return addr;
}

/*prints the ASM instruction for the affection of a variable
 *  EX :
 *      a = 2;
 */
void operation_afc_nb(int addr, int value){
    char s[ASM_TEXT_LEN];
    sprintf(s, "AFC %d %d", addr, value);
    printOp(s);
}

/*prints the ASM instruction for the affection of a temporary variable
 *  EX :
 *      "1_TEMP = 2"
 * and returns the address of the temp variable*/
int operation_afc_nb_tmp(int value){
    int addr = addTempINTAndGetAddress();
    operation_afc_nb(addr, value);
    return addr;
}


/*prints the ASM instruction for the affection of a temporary variable
 *  EX :
 *      a = b;
 */
void operation_copy(int addr1, int addr2){
    char s[ASM_TEXT_LEN];
    sprintf(s, "COP %d %d", addr1, addr2);
    printOp(s);
}

/*prints the ASM instruction for the inferior condition
 * and returns the address of the temporary variable*/
int cond_inf(int addr1, int addr2){
    int addr = addTempCONDAndGetAddress();
    char s[ASM_TEXT_LEN];
    sprintf(s, "INF %d %d %d", addr, addr1, addr2);
    printOp(s);
    return addr;
}

/*prints the ASM instruction for the superior condition
 * and returns the address of the temporary variable*/
int cond_sup(int addr1, int addr2){
    int addr = addTempCONDAndGetAddress();
    char s[ASM_TEXT_LEN];
    sprintf(s, "SUP %d %d %d", addr, addr1, addr2);
    printOp(s);
    return addr;
}

/*prints the ASM instruction for the equality condition
 * and returns the address of the temporary variable*/
int cond_eq(int addr1, int addr2) {
    int addr = addTempCONDAndGetAddress();
    char s[ASM_TEXT_LEN];
    sprintf(s, "EQ %d %d %d", addr, addr1, addr2);
    printOp(s);
    return addr;
}

/*prints the ASM instruction for the negation condition
 * and returns the address of the temporary variable*/
int cond_not(int addr1){
    int addr = addTempCONDAndGetAddress();
    char s[ASM_TEXT_LEN];
    sprintf(s, "NOT %d %d", addr, addr1);
    printOp(s);
    return addr;
}

/*prints the ASM instruction for the and condition
 * and returns the address of the temporary variable*/
int cond_and(int addr1, int addr2){
    int addr = addTempCONDAndGetAddress();
    char s[ASM_TEXT_LEN];
    sprintf(s, "AND %d %d %d", addr, addr1, addr2);
    printOp(s);
    return addr;
}

/*prints the ASM instruction for the or condition
 * and returns the address of the temporary variable*/
int cond_or(int addr1, int addr2){
    int addr = addTempCONDAndGetAddress();
    char s[ASM_TEXT_LEN];
    sprintf(s, "OR %d %d %d", addr, addr1, addr2);
    printOp(s);
    return addr;
}

