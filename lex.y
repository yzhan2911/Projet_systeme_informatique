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
%token  tDIV tMUL tADD tSUB  tAFFECT tET
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

Function:       Type FunctionName  contenuFunction { printf("main\n"); }
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
contenuFunction:tLBRACE tRBRACE
                |tLBRACE excus tRBRACE { MAJ_JMP(get_index_tab());}

contenu:    tLBRACE tRBRACE
            |tLBRACE { printf("Entrez la nouvelle contenue");}
            excus tRBRACE 
            ;

excus:      excu excus
            |excu
            ;

excu :      Aff 
          // |Print
          // |Printerror
            |Declaration
            |IfStatement
            |WhileStatement
            |Return
            |PointerStatement
            ;
Aff:        tID tAFFECT E tSEMI 
           {
                set_ini($1);
                printf("element est: %s  ",$1);
                add_instruction("COP", getIndex($1),$3,0);
                   
                suprime_valeur_temporaire();
        
              printf("Affectation %s \n",$1);
            } ;

Declaration:Type  {ty=$1;} AffectationDuringDeclaration MultipleDeclaration tSEMI
            |tCONST Type {ty=$2;} AffectationDuringDeclaration MultipleDeclaration tSEMI
            ;

MultipleDeclaration: tCOMMA AffectationDuringDeclaration MultipleDeclaration
                    | %empty 
                    ;

AffectationDuringDeclaration: tID 
                            tAFFECT {ajoutTable($1,ty,0);
                                    set_ini($1);} 
                            E {  
                                int in= getIndex($1);
                                printf("element est: %s  et index :%d\n",$1,in);
                                add_instruction("COP",in,$4,0);
                               
                                suprime_valeur_temporaire();
                                }
                    | tID {ajoutTable($1,ty,0); }
                    ;
IfStatement:tIF ifS1
            tLBRACE
            excus
            tRBRACE tELSE tLBRACE   {
                add_instruction("JMP",0,0,0);
                  $<number>1 =get_index_tab();
                 
                } 
            excus
            tRBRACE  {
                setInstruTR1($<number>2, $<number>1,1); 
                 setInstruTR1( $<number>1-1,get_index_tab(),0);
                 printf("index table est %d ",get_index_tab());} ;

            |tIF ifS1
            tLBRACE 
            excus 
            tRBRACE {setInstruTR1($<number>2,get_index_tab(),1);} 
            ;
ifS1:Condition   {   suprime_valeur_temporaire();
                            add_instruction("JMF",$1,0,0);
                            $<number>$ = get_index_tab()-1;} ;




WhileStatement:tWHILE {$<number>1=get_index_tab();
                    }
                Condition{ 
                    suprime_valeur_temporaire();
                    $<number>2=get_index_tab();
                    add_instruction("JMF",$3,0,0);
                }contenu{
                    add_instruction("JMP",$<number>1,0,0);
                    setInstruTR1($<number>2,get_index_tab(),1);
                }
            ;

Condition:  tLPAR E tCOMPEQ E tRPAR    {$$=add_condition("==",$2,$4); suprime_valeur_temporaire();}
            |tLPAR E tCOMPL E tRPAR    {$$=add_condition("<",$2,$4); suprime_valeur_temporaire();}
            |tLPAR E tCOMPG E tRPAR    {$$=add_condition(">",$2,$4); suprime_valeur_temporaire();}
            |tLPAR E tCOMPLE E tRPAR   {$$=add_condition("<=",$2,$4); suprime_valeur_temporaire();}
            |tLPAR E tCOMPGE E tRPAR   {$$=add_condition(">=",$2,$4); suprime_valeur_temporaire();}
            |tLPAR E tCOMPNEQ E tRPAR  {$$=add_condition("!=",$2,$4); suprime_valeur_temporaire();}
            |tLPAR E tRPAR {$$=$2;}
            ;




E:          
            tID     {
                    int indexE=getIndex($1);
                    int add=creation_valeur_temporaire();
                    add_instruction("COP",add,indexE,0);
                    printf("element est: %s ,index est  %d \n ",$1,indexE);
                    $$=add;
                   } 
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

Return: tRETURN E tSEMI{ajoutTable("return",INT,0);
                        int index = getIndex("return");
                        add_instruction("COP",index,$2,0);
                        suprime_valeur_temporaire();
                        
                        int index_return =get_index_tab();
                        ajout_index_jump(index_return);
                        add_instruction("JMP",0,0,0);
                        }

        // int *ptr;   ptr=&a;   *ptr=40;
PointerStatement: Type tMUL tID tSEMI {ajoutTable($3,$1,0);
                                        int index=getIndex($3);
                                        add_instruction("AFC",index,0,0);
                                        printf("ajouter ptr dans table synbole,et son index est:%d \n",index);
                                        }
                | tID tAFFECT tET tID tSEMI{ int indexPtr=getIndex($1);
                                             int index=getIndex($4);
                                             printf("msj adresse de ptr,ptr=%d,varaible:%d \n",indexPtr,index);
                                             set_valeur(indexPtr,index);
                                             add_instruction("AFC",indexPtr,index,0);
                                             }
                | tMUL tID tAFFECT E tSEMI{ int indexptr=getIndex($2);
                                            add_instruction("COP",get_valeur(indexptr),$4,0);
                                            printf("modifier la valeur de index %d vers valeur de index %d\n",get_valeur(indexptr),$4);
                                            suprime_valeur_temporaire();
                                            };


%%
int main(void){    
   // yydebug = 1;
    ini_table();
    ini_table_instruction();
    yyparse();
    exportASMTable();
    exportTableSymbole();
    return 0;
}