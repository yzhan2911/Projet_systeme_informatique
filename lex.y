%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #include "table_symbole.h"
    #include "table_instruction.h"
    numberType ty;
     int yylex(void);
      void yyerror (char const *s) {
        fprintf (stderr, "ERROR : %s\n", s);
    }

%}

%union{
    char* str;
    int type;
    int number;
    float reel;
}
%token <str> tID 
%token <number> tNUMBER
%token <reel> tREAL 
%token <type>  tINT tCHAR tFLOAT 
%type <type> Type
%type <number> E
%type <number> Condition
%type <number> IfSequence
%token  tDIV tMUL tADD tSUB  tAFFECT
%token  tLBRACE tRBRACE tLPAR tRPAR
%token  tVOID tERROR 
%token  tSEMI tCOMMA
%token  tMAIN tRETURN tCONST tPRINTF
%token<number> tIF tWHILE tELSE
%token  tCOMPEQ tCOMPL tCOMPG tCOMPLE tCOMPGE tCOMPNEQ

%left tSUB tADD
%left tMUL tDIV
%left tAFFECT
%left tCOMPEQ tCOMPL tCOMPG tCOMPLE tCOMPGE tCOMPNEQ


%start Input 
%%

Input:      Function|Function Input
            ;

Function:       Type FunctionName  contenu { printf("main\n"); }
            ;
FunctionName : tMAIN FunctionPara| tID FunctionPara;

FunctionPara: tLPAR tRPAR
            |tLPAR tVOID tRPAR
            |tLPAR Parametre tRPAR;
Parametre : Type tID 
            |Parametre tCOMMA Type tID;
            

Type:       tINT   {$$=(numberType)INT;}
            |tFLOAT {$$=(numberType)FLOAT;}
            |tCHAR {$$=(numberType)CHAR;}
            ;

contenu:    tLBRACE tRBRACE
            |tLBRACE { printf("Entrez la nouvelle contenue");}
            excus tRBRACE 
            ;

excus:      excu excus
            |excu
            ;

excu :      Aff 
            |Print
            |Declaration
            |IfStatement
            |WhileStatement
            ;
Aff:        tID tAFFECT E tSEMI 
           {
                set_ini($1);
                printf("element est: %s  ",$1);
                add_instruction("COP", getIndex($1),$3,0);
                  
                suprime_valeur_temporaire();
        
              printf("Affectation %s \n",$1);
            }
            ;
Print:      tPRINTF tLPAR E tRPAR tSEMI  ;

Declaration:Type  {ty=$1;} AffectationDuringDeclaration MultipleDeclaration tSEMI
            |tCONST Type {ty=$2;} AffectationDuringDeclaration MultipleDeclaration tSEMI
            ;

MultipleDeclaration: tCOMMA AffectationDuringDeclaration MultipleDeclaration
                    | %empty 
                    ;

AffectationDuringDeclaration: tID {ajoutTable($1,ty,0);
                                set_ini($1);
                                $<str>1=$1}
                            tAFFECT E {  
                                int in= getIndex($<str>1);
                                printf("element est: %s  et index :%d",$1,in);
                                add_instruction("COP",in,$2,0);
                                suprime_valeur_temporaire();
                                }
                    | tID {ajoutTable($1,ty,0);}
                    ;
IfSequence: %empty {int indexASm=get_index_tab();
                    add_instruction("JMF",indexASm,0,0);
                    $$=indexASm;};
IfStatement:tIF Condition IfSequence
            tLBRACE 
            excus {
                setInstruTR1($3+1,get_index_tab());
                } 
            tRBRACE
            |tIF Condition IfSequence excus {
                int current =get_index_tab();
                setInstruTR1($3+1,current);
                add_instruction("JMF",$3+1,0,0);
                $<number>1 = current;
                }
            tELSE tLBRACE    
            excus {
                int current = $<number>1;
                setInstruTR1(current+1,get_index_tab());} 
            tRBRACE 
            ;


WhileStatement:tWHILE Condition contenu
            ;

Condition:  tLPAR E tCOMPEQ E tRPAR    {$$=add_condition("==",$2,$4);}
            |tLPAR E tCOMPL E tRPAR    {$$=add_condition("<",$2,$4);}
            |tLPAR E tCOMPG E tRPAR    {$$=add_condition(">",$2,$4);}
            |tLPAR E tCOMPLE E tRPAR   {$$=add_condition("<=",$2,$4);}
            |tLPAR E tCOMPGE E tRPAR   {$$=add_condition(">=",$2,$4);}
            |tLPAR E tCOMPNEQ E tRPAR  {$$=add_condition("!=",$2,$4);}
            |tLPAR E tRPAR {$$=$2;}
            ;




E:          
            tID     {
                    printf("element est: %s  ",$1);
                    int indexE=getIndex($1);
                    int add=creation_valeur_temporaire();
                    add_instruction("COP",add,indexE,0);
                    $$=add;} 
            |tREAL       {
                        int add=creation_valeur_temporaire();
                         add_instruction("AFC",add,$1,0);
                        $$=add;
                        }
                        
            |tNUMBER    {
                       int add=creation_valeur_temporaire();
                         add_instruction("AFC",add,$1,0);
                        $$=add;
                        }
            |E tADD E  {$$=excu_op ("ADD",$1,$3);}
            | tLPAR E tADD E tRPAR {$$=excu_op ("ADD",$2,$4);}
            |E tSUB E {$$=excu_op ("SUB",$1,$3);}
            | tLPAR E tSUB E tRPAR {$$=excu_op ("SUB",$2,$4);}
            |E tMUL E {$$=excu_op ("MUL",$1,$3);}
            | tLPAR E tMUL E tRPAR {$$=excu_op ("MUL",$2,$4);}
            |E tDIV E {$$=excu_op ("DIV",$1,$3);}
            | tLPAR E tDIV E tRPAR {$$=excu_op ("DIV",$2,$4);};
           
%%
int main(void){    
    //yydebug = 1;
    ini_table();
    ini_table_instruction();
    yyparse();
    exportASMTable();
    exportTableSymbole();
    return 0;
}