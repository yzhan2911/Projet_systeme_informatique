#include "table_instruction.h"
#define MAX_TABLE_SIZE 2000
static instruction* instruT;
static int index_instruction=0;
static int index_excu=0;
void ini_table_instruction(){
    instruT =malloc(sizeof(instruction)*MAX_TABLE_SIZE);
}

void add_instruction(char * op, int r0,int r1,int r2){

    struct instruction newInstr = {
        .operation = op,  
        .r0 = r0,
        .r1 = r1,
        .r2 = r2
    };
    instruT[index_instruction]=newInstr;
    index_instruction++;
}

int get_index_tab(){
    return index_instruction;
}

int get_index_current(){
    return index_excu;
}

int add_condition(char* op,int r1, int r2){
    reset_index_temporaire();
    int add1=creation_valeur_temporaire();
    int add2=creation_valeur_temporaire();
    add_instruction("AFC",add1,r1,0);
    add_instruction("AFC",add2,r2,0);
        if(strcmp(op,"==")==0) {      
            add_instruction("EQU",add1 ,add1,add2); 
        }
        else if(strcmp(op,"<")==0){
            add_instruction("INF",add1 ,add1,add2); 
        }
          else if(strcmp(op,">")==0){
            add_instruction("SUP",add1 ,add1,add2); 
        }
        
        else if(strcmp(op,"!=")==0){
            int val3=creation_valeur_temporaire();
            add_instruction("INF",val3 ,add1,add2); 
            add_instruction("SUP",add1 ,add1,add2); 
            add_instruction("ADD",add1 ,add1,val3); 
            suprime_valeur_temporaire();
        }
        else if(strcmp(op,">=")==0){
            int val3=creation_valeur_temporaire();
            add_instruction("EQU",val3 ,add1,add2); 
            add_instruction("SUP",add1 ,add1,add2); 
            add_instruction("ADD",add1 ,add1,val3); 
            suprime_valeur_temporaire();
        }
        else if(strcmp(op,"<=")==0){
           int val3=creation_valeur_temporaire();
            add_instruction("INF",val3 ,add1,add2); 
            add_instruction("EQU",add1 ,add1,add2); 
            add_instruction("ADD",add1 ,add1,val3); 
            suprime_valeur_temporaire();
        }
      
        suprime_valeur_temporaire();
        suprime_valeur_temporaire();
        return add1;
    }
int excu_op (char* op,int r1, int r2){
     reset_index_temporaire();
     int add = creation_valeur_temporaire();
     add_instruction(op,add,r1,r2); 
     suprime_valeur_temporaire();
    return add; 
    }