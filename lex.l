%{
    #include <stdlib.h>
    #include "lex.tab.h"
%}

SPACE       [" "]+
TAB         [\t]+
NEWLINE     [\n]+
NUMBER      [0-9]+
EXP         [eE][+-]?{NUMBER}
REAL        {NUMBER}("."{NUMBER})?{EXP}?
ALPHABET    [A-Za-z]
ALPHANUM    {ALPHABET}({ALPHABET}|{NUMBER}|"_")*?

%%
{SPACE}     {}
{TAB}       {}
{NEWLINE}   {}


"main"      {return (tMAIN);}
"{"         {return (tLBRACE);}
"}"         {return (tRBRACE);}
"("         {return (tLPAR);}
")"         {return (tRPAR);}
"int"       {return (tINT);}
"const"     {return (tCONST);}
"char"      {return (tCHAR);}
"float"     {return (tFLOAT);}
"void"      {return (tVOID);}
"+"         {return (tADD);}
"-"         {return (tSUB);}
"*"         {return (tMUL);}
"/"         {return (tDIV);}
"="         {return (tAFFECT);}
"if"        {return (tIF);}
"else"      {return (tELSE);}
"while"     {return (tWHILE);}
"return"    {return (tRETURN);}
"=="        {return (tCOMPEQ);}
","         {return (tCOMMA);}
";"         {return (tSEMI);}
"<"         {return (tCOMPL);}
">"         {return (tCOMPG);}
"<="        {return (tCOMPLE);}
">="        {return (tCOMPGE);}
"!="        {return (tCOMPNEQ);}
"printf"    {return (tPRINTF);}

{NUMBER}    {yylval.number=atoi(yytext);
             return (tNUMBER);}
{REAL}      {yylval.reel=atof(yytext);
             return (tREAL);} 
{ALPHANUM}  {yylval.str=yytext;
             return (tID);}


.           {return (tERROR);}

%%
int yywrap(void){
    return 1;
}
