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
    tID = 258,                     /* tID  */
    tNUMBER = 259,                 /* tNUMBER  */
    tREAL = 260,                   /* tREAL  */
    tINT = 261,                    /* tINT  */
    tCHAR = 262,                   /* tCHAR  */
    tFLOAT = 263,                  /* tFLOAT  */
    tDIV = 264,                    /* tDIV  */
    tMUL = 265,                    /* tMUL  */
    tADD = 266,                    /* tADD  */
    tSUB = 267,                    /* tSUB  */
    tAFFECT = 268,                 /* tAFFECT  */
    tET = 269,                     /* tET  */
    tLBRACE = 270,                 /* tLBRACE  */
    tRBRACE = 271,                 /* tRBRACE  */
    tLPAR = 272,                   /* tLPAR  */
    tRPAR = 273,                   /* tRPAR  */
    tVOID = 274,                   /* tVOID  */
    tERROR = 275,                  /* tERROR  */
    tSEMI = 276,                   /* tSEMI  */
    tCOMMA = 277,                  /* tCOMMA  */
    tMAIN = 278,                   /* tMAIN  */
    tRETURN = 279,                 /* tRETURN  */
    tCONST = 280,                  /* tCONST  */
    tPRINTF = 281,                 /* tPRINTF  */
    tIF = 282,                     /* tIF  */
    tWHILE = 283,                  /* tWHILE  */
    tELSE = 284,                   /* tELSE  */
    tCOMPEQ = 285,                 /* tCOMPEQ  */
    tCOMPL = 286,                  /* tCOMPL  */
    tCOMPG = 287,                  /* tCOMPG  */
    tCOMPLE = 288,                 /* tCOMPLE  */
    tCOMPGE = 289,                 /* tCOMPGE  */
    tCOMPNEQ = 290                 /* tCOMPNEQ  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 15 "lex.y"

    char* str;
    int type;
    int number;
    float reel;

#line 106 "lex.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_LEX_TAB_H_INCLUDED  */
