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
    numberType type;
}
%token <str> tID
%token <type> Type
%token  tDIV tMUL tADD tSUB  tAFFECT
%token  tLBRACE tRBRACE tLPAR tRPAR
%token  tINT tCHAR tVOID tERROR tFLOAT
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

Function:       Type tID FunctionName  contenu { printf("main\n"); }
            |
            ;
FunctionName: tLPAR tRPAR
            |tLPAR tVOID tRPAR
            |tLPAR Parametre tRPAR;
Parametre : Type tID 
            |Parametre tCOMMA Parametre;
            

Type:       tINT   {$$=INT;}
            |tFLOAT {$$=FLOAT;}
            |tCHAR {$$=CHAR;}
            ;

contenu:    tLBRACE tRBRACE
            |tLBRACE {augmenDepth();
                       printf("Entrez la nouvelle contenue");}
            excus tRBRACE { diminuDepth();}
            ;

excus:      excu excus
            |excu
            ;

excu :      Aff 
            |Print
            |Declaration
            |IfStatement
            |WhileStatement
            |AppelFunction
            |Return
            ;

Aff:        tID tAFFECT E tSEMI 
            {  
                set_ini($1);
                reset_index_temporaire();
                addTemp=creation_valeur_temporaire();
                add_instruction("AFC",addTemp,$3,0);
                add_instruction("COP", getIndex($1),addTemp,0);
                suprime_valeur_temporaire();
              printf("Affectation %s \n",$1);
            }
            ;
Print:      tPRINTF tLPAR E tRPAR tSEMI  ;

Declaration:Type  {ty=$1} AffectationDuringDeclaration MultipleDeclaration tSEMI
            | tCONST Type {ty=$2} AffectationDuringDeclaration MultipleDeclaration tSEMI
            ;

MultipleDeclaration: tCOMMA AffectationDuringDeclaration MultipleDeclaration
                    | 
                    ;

AffectationDuringDeclaration: tID tAFFECT E {  
                                ajoutTable($1,ty);
                                reset_index_temporaire();
                                int add1 = creation_valeur_temporaire(); 
                                add_instruction("AFC",add1,$2,0); 
                                add_instruction("COP",getIndex($1),add1,0);
                                suprime_valeur_temporaire();}
                    | tID {ajoutTable($1,ty);}
                    ;

IfStatement:tIF Condition IfSequence
            tLBRACE {augmenDepth();} 
            excus {
                instruT[indexASm+1].r1=get_index_tab();
                } 
            tRBRACE{diminuDepth();} 
            |tIF Condition IfSequence excus {
                int current =get_index_tab();
                instruT[indexASm+1].r1=current;
                add_instruction("JMF",indexASm+1,0,0);
                }
            tELSE tLBRACE  {augmenDepth();}  
            excus {instruT[current+1].r1=get_index_tab();} 
            tRBRACE {diminuDepth();}
            ;

IfSequence: %empty {int indexASm=get_index_tab();add_instruction("JMF",indexASm,0,0);}
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





E:          tREAL       {
                        reset_index_temporaire();
                        add_instruction("COP",creation_valeur_temporaire(),$1)
                        suprime_valeur_temporaire();
                        }
                        
            |tNUMBER    {
                        reset_index_temporaire();
                        add_instruction("COP",creation_valeur_temporaire(),$1)
                        suprime_valeur_temporaire();
                        }
                        
            |tVAR       {
                       reset_index_temporaire();
                        add_instruction("COP",creation_valeur_temporaire(),$1)
                        suprime_valeur_temporaire();
                        }
                        
            |E tADD E  {$$=excu_op ("ADD",$1,$3);}
            | tLPAR E tADD E tRPAR {$$=excu_op ("ADD",$1,$3);}
            |E tSUB E {$$=excu_op ("SUB",$1,$3);}
            | tLPAR E tSUB E tRPAR {$$=excu_op ("SUB",$1,$3);}
            |E tMUL E {$$=excu_op ("MUL",$1,$3);}
            | tLPAR E tMUL E tRPAR {$$=excu_op ("MUL",$1,$3);}
            |E tDIV E {$$=excu_op ("DIV",$1,$3);}
            | tLPAR E tDIV E tRPAR {$$=excu_op ("DIV",$1,$3);};
           
%%
int main(void){    
    //yydebug = 1;
    ini_table();
    ini_table_instruction();
    yyparse();
    return 0;
}