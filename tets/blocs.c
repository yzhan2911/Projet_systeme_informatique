//
// Created by chepycou on 4/18/23.
//

#include "blocs.h"
#include "operations.h"
#include <stdio.h>
#include <string.h>

/*TODO on écrit tout dans un fichier asm extérieur puis on :
 * - fait un parcours pour stocker dans une liste chaînée par exemple les valeur de ligne des labels
 * - faire un parcours pour retirer les labels au début des lignes
 * - faire un parcours pour remplacer les labels par leur valeur
 * */
/*
int labelCount = 0;

int getNextLabel(){
    return(labelCount++);
}


void printLabel(int labelWhile){
    char label[LABEL_MAX_LENGTH];
    sprintf(label,"%d_LABEL\n",labelWhile);
    printf("%s",label);
    FILE* fp;
    fp = fopen("asm", "a");
    fputs(label, fp);
    fclose(fp);
}

int printNewLabel(){
    int l = getNextLabel();
    printLabel(l);
    return l;
}

void printJumpToLabel(int labelWhile) {
    char instr[ASM_TEXT_LEN];
    sprintf(instr,"JMP %d_LABEL\n",labelWhile);
    printf("%s",instr);
    FILE* fp;
    fp = fopen("asm", "a");
    fputs(instr, fp);
    fclose(fp);
}

void printJumpFToLabel(int labelWhile) {
    char label[LABEL_MAX_LENGTH];
    sprintf(label,"%d_LABEL\n",labelWhile);
    printf("JMF %s",label);
    FILE* fp;
    fp = fopen("asm", "a");
    fputs(label, fp);
    fclose(fp);
}*/


