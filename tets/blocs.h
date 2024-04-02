//
// Created by chepycou on 4/18/23.
//

#ifndef PROJET_SYSTEMES_INFORMATIQUES_BLOCS_H
#define PROJET_SYSTEMES_INFORMATIQUES_BLOCS_H

#define LABEL_MAX_LENGTH 20

/*======================
    Label Management
 ======================*/

/*returns the next label*/
int getNextLabel();

// prints a new label and returns the index of it
int printNewLabel();

// prints a label and returns the index of it
void printLabel(int labelWhile);

// prints a jump to the label and returns the index of it
void printJumpToLabel(int labelWhile);

#endif //PROJET_SYSTEMES_INFORMATIQUES_BLOCS_H
