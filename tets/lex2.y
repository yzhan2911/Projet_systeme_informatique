%define parse.error detailed

%{
#include <stdio.h>
#include <stdlib.h>
#include "table.h"
#include "operations.h"
#include "blocs.h"
#include "asmTable.h"

int t;
int labelWhileStart;
int labelWhileEnd;
int whileJumpAddr;
%}

%code provides{
int yylex (void);
void yyerror (const char *);
}

%union {char str[NAME_MAX_LENGTH]; int nbInt; int addr; enumVarType type; }
%token tELSE
%token tRETURN tPRINT
%token tFLOAT tINT tVOID
%left tSUB tADD
%left tMUL tDIV
%left tASSIGN
%left tLT tGT tNE tEQ tGE tLE
%left tAND tOR tNOT
%token tLBRACE tRBRACE tLPAR tRPAR tSEMI tCOMMA

 /*nametags and values*/
%token <str> tID
%token <nbInt> tNB


%type <type> Type
%type <addr> Expression
%type <addr> ConditionalExpression
%type <addr> Declaration
%type <addr> NbOrVariable
%type <nbInt> IfStatement1
%type <addr> Condition
%type <nbInt> InnerBlock

%token <nbInt> tIF
%token <nbInt> tWHILE

%start Program
%%

Program : FunctionDef
	| FunctionDef Program;

 /* Lines = Any line in the code that is not within an if/while statement*/
 Lines : Line
      | Line Lines;

Line : IfStatement
    | WhileStatement
    | Assignment
    | Declarations
    | FunctionCall
    | Return
    | Print;

/*Innerblock = the inside of an if/else/while statement = { ... } or function = f(){...}*/
InnerBlock : tLBRACE tRBRACE // a function or while loop can be empty cf GCC
           | tLBRACE {increaseDepth();} Lines tRBRACE {decreaseDepth();};


/*Condition = the evaluated boolean expression for an if or while = ( ... ) */
Condition : tLPAR ConditionalExpression tRPAR {$$ = $2;};

/*ConditionalExpression = expression that evaluates to a boolean*/
ConditionalExpression : tID { $$ = getindex($1);}
                      | tNB {$$ = operation_afc_nb_tmp($1);}
                      | tLPAR ConditionalExpression tRPAR  {$$ = $2;}// for cases like if((a or b) and (a or c)) where there are parenthesis inside
                      | NbOrVariable tLE NbOrVariable {$$ = cond_not(cond_sup($1, $3));}
                      | NbOrVariable tGE NbOrVariable {$$ = cond_not(cond_inf($1, $3));}
                      | NbOrVariable tEQ NbOrVariable {$$ = cond_eq($1, $3);}
                      | NbOrVariable tNE NbOrVariable {$$ = cond_not(cond_eq($1, $3));}
                      | NbOrVariable tLT NbOrVariable {$$ = cond_inf($1, $3);}
                      | NbOrVariable tGT NbOrVariable {$$ = cond_sup($1, $3);}
                      | tNOT ConditionalExpression {$$ = cond_not($2);}
                      | ConditionalExpression tOR ConditionalExpression {$$ = cond_or($1, $3);}
                      | ConditionalExpression tAND ConditionalExpression {$$ = cond_and($1, $3);};
                      /*end of added bloat*/


/*NbOrVariable is either a number or a variable of type int*/
NbOrVariable : tID { $$ = getindex($1);}
     | tNB {$$ = operation_afc_nb_tmp($1);};

 /*List of all numerical operators*/
 /*
NumericalOperator : tLE | tGE | tEQ | tNE | tLT | tGT;
*/

 /*any arithmetic operation
Operation: tADD | tMUL | tSUB | tDIV;
*/

IfStatement1 : %empty {
                      	int ligne =getCurrentLineNumber(); addLine("JMF"); $<nbInt>$ = ligne ;
                      };

IfStatement : tIF Condition IfStatement1 InnerBlock tELSE {
	setConditionAddr($3,$2); int current = getCurrentLineNumber(); printf("current Line %d", current); addLine("JMP"); $1 = current; setJumpLine($3, current+1);
}  InnerBlock {
	int current = getCurrentLineNumber() ; printf("%d, %d",$1, current);setJumpLine($1, current);
}
	   | tIF Condition IfStatement1 InnerBlock {
	setConditionAddr($3,$2); int current = getCurrentLineNumber();	 printf("current Line %d", current); setJumpLine($3, current);
};

WhileStatement : tWHILE {
	$1 = getCurrentLineNumber();
} Condition {
	int current = getCurrentLineNumber();
	addLine("JMF");
	setConditionAddr(current,$3);
	whileJumpAddr = current;
	suppressCONDElements();
} InnerBlock {
	addLine("JMP");
	int current = getCurrentLineNumber();
	setJumpLine(whileJumpAddr, current);
	setJumpLine(current-1, $1);
};

Assignment : tID tASSIGN Expression tSEMI {
		setInit($1); operation_copy(getindex($1),$3); suppressTempINTElements();
	};

 /*Expression operation applied on variables or values*/
Expression : NbOrVariable {$$ = $1;}
           | FunctionCall{$$ = 0;} // TODO : wait untile functions are implemented
           | tLPAR Expression tRPAR {$$ = $2;}
           /* replaced by the four following lines
           //| Expression Operation Expression
           */
           | Expression tADD Expression {$$ = operation_add($1, $3);}
           | Expression tSUB Expression {$$ = operation_sub($1, $3);}
           | Expression tMUL Expression {$$ = operation_mul($1, $3);}
           | Expression tDIV Expression {$$ = operation_divInt($1, $3);};
           /*end of added bloat*/

Expressions : Expression
            | Expression tCOMMA Expressions;

FunctionCall : tID tLPAR Expressions tRPAR;

FunctionDef : Type tID FunctionParams InnerBlock {resetSymboltable();}
	    | tVOID tID FunctionParams InnerBlock {resetSymboltable();};

 /*FunctionParams = the parameters of a function*/
FunctionParams : tLPAR tRPAR
               | tLPAR tVOID tRPAR
               | tLPAR VarsWithType tRPAR

VarsWithType : VarWithType
             | VarWithType tCOMMA VarsWithType;

 /*VarWithType = a variable associated to its type = int a*/
VarWithType : Type tID {addElement($2,$1);setInit($2);};

 /*the return type or argument type*/
Type : tINT {$$ = INT;}
     | tFLOAT {$$ = FLOAT;};


Declarations : Type { t = $1; } Declaration Declarations1 tSEMI ;

Declaration : tID {addElement($1, (enumVarType) t);}
            | tID {addElement($1, (enumVarType) t); setInit($1);} tASSIGN Expression {operation_copy(getindex($1),$4); suppressTempINTElements();} ;

Declarations1 : tCOMMA Declaration Declarations1 | %empty ;


Return : tRETURN Expression tSEMI {};

Print : tPRINT tLPAR Expression tRPAR tSEMI;

%%

void yyerror(const char *msg) {
	fprintf(stderr, "\033[1m\033[31m[/!\\]\033[0m Error : %s\n", msg);
	exit(1);
}

int main(void) {
	clearOp();
	initSymbolTable();
	initASMTable();
	yyparse();
	exportASMTable();
}
 // SI >> SC
