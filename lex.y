%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #include <string.h>
     char* var;
      void yyerror (char const *s) {
        fprintf (stderr, "ERROR : %s\n", s);
    }

%}

%union{
    char* str;
    int number;
    float reel;
}

%token<number>  tNUMBER 
%token<reel> tREAL
%token<str> tVAR
%token  tDIV tMUL tADD tSUB  tAFFECT
%token  tLBRACE tRBRACE tLPAR tRPAR
%token  tINT tCHAR tVOID tERROR tFLOAT
%token  tSEMI tCOMMA
%token  tMAIN tRETURN tCONST tPRINTF
%token<number> tIF tWHILE tELSE
%token  tCOMPEQ tCOMPL tCOMPG tCOMPLE tCOMPGE tCOMPNEQ

%left tCOMMA 
%right tAFFECT tADD tSUB tMUL tDIV 
%left tCOMPEQ 
%left tCOMPL tCOMPG tCOMPLE tCOMPGE



%start Input 
%%

Input:      main
            ;

main:       tINT tMAIN tLPAR tRPAR contenu { printf("main\n"); }
            |
            ;

Type:       tINT 
            |tCHAR 
            ;

contenu:       tLBRACE {
                       printf("Entrez la nouvelle contenue");}
                       excus tRBRACE
            ;

excus:      excu excus
            |excu
            ;

excu :      Aff 
            |Print
            |Declaration
            |IfStatement
            |While
            ;

IfStatement:tIF{printf("if \n");} Condition tLBRACE  excus  tRBRACE Else {printf("end if\n");} 
            ;

Else:       tELSE{printf("else\n");} tLBRACE  excus             
            tRBRACE 
            |tELSE excu 
            |
            ;


While:      tWHILE  Condition contenu
            ;

Condition:  tLPAR E tCOMPEQ E tRPAR
            |tLPAR E tCOMPL E tRPAR
            |tLPAR E tCOMPG E tRPAR 
            |tLPAR E tCOMPLE E tRPAR 
            |tLPAR E tCOMPGE E tRPAR 
            |tLPAR E tCOMPNEQ E tRPAR 
            |tLPAR E 
            ;

Declaration:Type tVAR 
            {
             printf("Declaration 1\n");
            } AffectationDuringDeclaration MultipleDeclaration tSEMI
            | tCONST tINT tVAR 
            {
             printf("Declaration 1 constant\n");
            }AffectationDuringDeclaration MultipleDeclaration tSEMI
            ;

MultipleDeclaration: tCOMMA tVAR{
                        printf("Multiple declaration\n");
                    }AffectationDuringDeclaration MultipleDeclaration
                    | 
                    ;

AffectationDuringDeclaration: tAFFECT E 
                            |
                            ;

Print:      tPRINTF tLPAR tVAR    {printf("printf %s\n", $3);
                                } tRPAR tSEMI                        
            ;


Aff:        tVAR 
            {
                var=malloc(sizeof($1));
                strcpy(var,$1);
            } 
            tAFFECT E tSEMI 
            {
                printf("Affectation %s \n",var);
                 
                
            }
            ;

E:          tREAL       {
                        printf("float %f\n",$1);
                        }
                        
            |tNUMBER    {
                        printf("int %d\n",$1);
                        }
                        
            |tVAR       {
                        printf("tVAR= %s\n",$1);
                        }
                        
            |E tADD E 
           
            |E tSUB E 
            
            |E tMUL E

            |E tDIV E ;
           
%%
int main(void){    
    //yydebug = 1;
    yyparse();
    return 0;
}