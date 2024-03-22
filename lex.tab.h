/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_LEX_TAB_H_INCLUDED
# define YY_YY_LEX_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    tNUMBER = 258,                 /* tNUMBER  */
    tREAL = 259,                   /* tREAL  */
    tVAR = 260,                    /* tVAR  */
    tDIV = 261,                    /* tDIV  */
    tMUL = 262,                    /* tMUL  */
    tADD = 263,                    /* tADD  */
    tSUB = 264,                    /* tSUB  */
    tAFFECT = 265,                 /* tAFFECT  */
    tLBRACE = 266,                 /* tLBRACE  */
    tRBRACE = 267,                 /* tRBRACE  */
    tLPAR = 268,                   /* tLPAR  */
    tRPAR = 269,                   /* tRPAR  */
    tINT = 270,                    /* tINT  */
    tCHAR = 271,                   /* tCHAR  */
    tVOID = 272,                   /* tVOID  */
    tERROR = 273,                  /* tERROR  */
    tFLOAT = 274,                  /* tFLOAT  */
    tSEMI = 275,                   /* tSEMI  */
    tCOMMA = 276,                  /* tCOMMA  */
    tMAIN = 277,                   /* tMAIN  */
    tRETURN = 278,                 /* tRETURN  */
    tCONST = 279,                  /* tCONST  */
    tPRINTF = 280,                 /* tPRINTF  */
    tIF = 281,                     /* tIF  */
    tWHILE = 282,                  /* tWHILE  */
    tELSE = 283,                   /* tELSE  */
    tCOMPEQ = 284,                 /* tCOMPEQ  */
    tCOMPL = 285,                  /* tCOMPL  */
    tCOMPG = 286,                  /* tCOMPG  */
    tCOMPLE = 287,                 /* tCOMPLE  */
    tCOMPGE = 288,                 /* tCOMPGE  */
    tCOMPNEQ = 289                 /* tCOMPNEQ  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 13 "lex.y"

    char* str;
    int number;
    float reel;

#line 104 "lex.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_LEX_TAB_H_INCLUDED  */
