//
// Created by chepycou on 4/14/23.
//

#ifndef PROJET_SYSTEMES_INFORMATIQUES_OPERATIONS_H
#define PROJET_SYSTEMES_INFORMATIQUES_OPERATIONS_H

#define ASM_TEXT_LEN 40

/*clears the out asm file*/
void clearOp();

/*prints to the stdout and the out asm file*/
void printOp(char* s);

/*prints the ASM instruction for the addition computation
 * and returns the address of the temporary variable*/
int operation_add(int addr1, int addr2);

/*prints the ASM instruction for the subtraction computation
 * and returns the address of the temporary variable*/
int operation_sub(int addr1, int addr2);

/*prints the ASM instruction for the multiplication computation
 * and returns the address of the temporary variable*/
int operation_mul(int addr1, int addr2);

/*prints the ASM instruction for the integer division computation
 * and returns the address of the temporary variable*/
int operation_divInt(int addr1, int addr2);

/*prints the ASM instruction for the remainder computation
 * and returns the address of the temporary variable*/
int operation_divRem(int addr1, int addr2);

/*prints the ASM instruction for the affection of a variable
 *  EX :
 *      a = 2;
 */
void operation_afc_nb(int addr, int value);

/*prints the ASM instruction for the affection of a temporary variable
 *  EX :
 *      "1_TEMP = 2"
 * and returns the address of the temp variable*/
int operation_afc_nb_tmp(int value);

/*prints the ASM instruction for the affection of a temporary variable
 *  EX :
 *      a = b;
 */
void operation_copy(int addr1, int addr2);

/*prints the ASM instruction for the inferior condition
 * and returns the address of the temporary variable*/
int cond_inf(int addr1, int addr2);

/*prints the ASM instruction for the superior condition
 * and returns the address of the temporary variable*/
int cond_sup(int addr1, int addr2);

/*prints the ASM instruction for the equality condition
 * and returns the address of the temporary variable*/
int cond_eq(int addr1, int addr2);

/*prints the ASM instruction for the negation condition
 * and returns the address of the temporary variable*/
int cond_not(int addr1);

/*prints the ASM instruction for the and condition
 * and returns the address of the temporary variable*/
int cond_and(int addr1, int addr2);

/*prints the ASM instruction for the or condition
 * and returns the address of the temporary variable*/
int cond_or(int addr1, int addr2);

#endif //PROJET_SYSTEMES_INFORMATIQUES_OPERATIONS_H
