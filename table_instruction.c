#include "table_instruction.h"
#include "table_symbole.h"
#define MAX_TABLE_SIZE 2000
static instruction* instruT;
static int index_instruction=0;
static int index_excu=0;
static int index_a_jump[10];
static int current_size_jump=0;

void ini_table_instruction(){
    instruT =malloc(sizeof(instruction)*MAX_TABLE_SIZE);
}
void setInstruTR1(int index,int var,int registre){
    if(registre ==0) {
        instruT[index].r0=var;
    }else if(registre==1){ 
        instruT[index].r1=var;
    }else if(registre==2){
        instruT[index].r2=var;
    }
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
  
    int add1=creation_valeur_temporaire(get_valeur(r1));
    int add2=creation_valeur_temporaire(get_valeur(r2));
    add_instruction("COP",add1,r1,0);
    add_instruction("COP",add2,r2,0);
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
            int val3=creation_valeur_temporaire(0);
            add_instruction("INF",val3 ,add1,add2); 
            add_instruction("SUP",add1 ,add1,add2); 
            add_instruction("ADD",add1 ,add1,val3); 
            suprime_valeur_temporaire();
        }
        else if(strcmp(op,">=")==0){
            int val3=creation_valeur_temporaire(0);
            add_instruction("EQU",val3 ,add1,add2); 
            add_instruction("SUP",add1 ,add1,add2); 
            add_instruction("ADD",add1 ,add1,val3); 
            suprime_valeur_temporaire();
        }
        else if(strcmp(op,"<=")==0){
           int val3=creation_valeur_temporaire(0);
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
    
     add_instruction(op,r1,r1,r2);
     suprime_valeur_temporaire();
    return r1; 
    }

void exportASMTable(){
    FILE* fp;
    fp = fopen("asm", "a");
    for (int i = 0; i < index_instruction; ++i) {
        fprintf(fp,"%s %d %d %d\n", instruT[i].operation, instruT[i].r0, instruT[i].r1 , instruT[i].r2);
    }
    fclose(fp);
}
void ajout_index_jump(int a){
    if(current_size_jump<10){
        index_a_jump[current_size_jump]=a;
        current_size_jump++;
    }
}
void MAJ_JMP(int a){
    for (int i=0;i<current_size_jump;i++){
        int index=index_a_jump[i];
        setInstruTR1(index,a,0);
    }
}