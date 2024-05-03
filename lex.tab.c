/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "lex.y"

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


#line 85 "lex.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "lex.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_tID = 3,                        /* tID  */
  YYSYMBOL_tNUMBER = 4,                    /* tNUMBER  */
  YYSYMBOL_tREAL = 5,                      /* tREAL  */
  YYSYMBOL_tINT = 6,                       /* tINT  */
  YYSYMBOL_tCHAR = 7,                      /* tCHAR  */
  YYSYMBOL_tFLOAT = 8,                     /* tFLOAT  */
  YYSYMBOL_tDIV = 9,                       /* tDIV  */
  YYSYMBOL_tMUL = 10,                      /* tMUL  */
  YYSYMBOL_tADD = 11,                      /* tADD  */
  YYSYMBOL_tSUB = 12,                      /* tSUB  */
  YYSYMBOL_tAFFECT = 13,                   /* tAFFECT  */
  YYSYMBOL_tLBRACE = 14,                   /* tLBRACE  */
  YYSYMBOL_tRBRACE = 15,                   /* tRBRACE  */
  YYSYMBOL_tLPAR = 16,                     /* tLPAR  */
  YYSYMBOL_tRPAR = 17,                     /* tRPAR  */
  YYSYMBOL_tVOID = 18,                     /* tVOID  */
  YYSYMBOL_tERROR = 19,                    /* tERROR  */
  YYSYMBOL_tSEMI = 20,                     /* tSEMI  */
  YYSYMBOL_tCOMMA = 21,                    /* tCOMMA  */
  YYSYMBOL_tMAIN = 22,                     /* tMAIN  */
  YYSYMBOL_tRETURN = 23,                   /* tRETURN  */
  YYSYMBOL_tCONST = 24,                    /* tCONST  */
  YYSYMBOL_tPRINTF = 25,                   /* tPRINTF  */
  YYSYMBOL_tIF = 26,                       /* tIF  */
  YYSYMBOL_tWHILE = 27,                    /* tWHILE  */
  YYSYMBOL_tELSE = 28,                     /* tELSE  */
  YYSYMBOL_tCOMPEQ = 29,                   /* tCOMPEQ  */
  YYSYMBOL_tCOMPL = 30,                    /* tCOMPL  */
  YYSYMBOL_tCOMPG = 31,                    /* tCOMPG  */
  YYSYMBOL_tCOMPLE = 32,                   /* tCOMPLE  */
  YYSYMBOL_tCOMPGE = 33,                   /* tCOMPGE  */
  YYSYMBOL_tCOMPNEQ = 34,                  /* tCOMPNEQ  */
  YYSYMBOL_YYACCEPT = 35,                  /* $accept  */
  YYSYMBOL_Input = 36,                     /* Input  */
  YYSYMBOL_Function = 37,                  /* Function  */
  YYSYMBOL_FunctionName = 38,              /* FunctionName  */
  YYSYMBOL_FunctionPara = 39,              /* FunctionPara  */
  YYSYMBOL_Parametre = 40,                 /* Parametre  */
  YYSYMBOL_Type = 41,                      /* Type  */
  YYSYMBOL_contenu = 42,                   /* contenu  */
  YYSYMBOL_43_1 = 43,                      /* $@1  */
  YYSYMBOL_excus = 44,                     /* excus  */
  YYSYMBOL_excu = 45,                      /* excu  */
  YYSYMBOL_Aff = 46,                       /* Aff  */
  YYSYMBOL_Print = 47,                     /* Print  */
  YYSYMBOL_Declaration = 48,               /* Declaration  */
  YYSYMBOL_49_2 = 49,                      /* $@2  */
  YYSYMBOL_50_3 = 50,                      /* $@3  */
  YYSYMBOL_MultipleDeclaration = 51,       /* MultipleDeclaration  */
  YYSYMBOL_AffectationDuringDeclaration = 52, /* AffectationDuringDeclaration  */
  YYSYMBOL_53_4 = 53,                      /* $@4  */
  YYSYMBOL_IfSequence = 54,                /* IfSequence  */
  YYSYMBOL_IfStatement = 55,               /* IfStatement  */
  YYSYMBOL_56_5 = 56,                      /* $@5  */
  YYSYMBOL_57_6 = 57,                      /* $@6  */
  YYSYMBOL_58_7 = 58,                      /* $@7  */
  YYSYMBOL_WhileStatement = 59,            /* WhileStatement  */
  YYSYMBOL_Condition = 60,                 /* Condition  */
  YYSYMBOL_E = 61                          /* E  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   158

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  128

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    46,    46,    46,    49,    51,    51,    53,    54,    55,
      56,    57,    60,    61,    62,    65,    66,    66,    70,    71,
      74,    75,    76,    77,    78,    80,    91,    93,    93,    94,
      94,    97,    98,   102,   101,   109,   111,   116,   114,   120,
     127,   120,   134,   137,   138,   139,   140,   141,   142,   143,
     150,   156,   162,   167,   168,   169,   170,   171,   172,   173,
     174
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "tID", "tNUMBER",
  "tREAL", "tINT", "tCHAR", "tFLOAT", "tDIV", "tMUL", "tADD", "tSUB",
  "tAFFECT", "tLBRACE", "tRBRACE", "tLPAR", "tRPAR", "tVOID", "tERROR",
  "tSEMI", "tCOMMA", "tMAIN", "tRETURN", "tCONST", "tPRINTF", "tIF",
  "tWHILE", "tELSE", "tCOMPEQ", "tCOMPL", "tCOMPG", "tCOMPLE", "tCOMPGE",
  "tCOMPNEQ", "$accept", "Input", "Function", "FunctionName",
  "FunctionPara", "Parametre", "Type", "contenu", "$@1", "excus", "excu",
  "Aff", "Print", "Declaration", "$@2", "$@3", "MultipleDeclaration",
  "AffectationDuringDeclaration", "$@4", "IfSequence", "IfStatement",
  "$@5", "$@6", "$@7", "WhileStatement", "Condition", "E", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-63)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      11,   -63,   -63,   -63,    30,    11,    -2,   -63,   -63,    16,
      16,     0,     4,   -63,   -63,    26,   -63,   -63,    36,    -8,
      52,   -63,    73,   -63,   -63,    11,   -63,    43,    11,    46,
      53,    53,   -63,    56,    73,   -63,   -63,   -63,   -63,   -63,
      67,    -1,   -63,    -1,    -1,   -63,     0,    70,   -63,   -63,
     -63,   -63,   -63,   -63,    -1,    48,    70,    94,    55,    88,
     -63,    62,    57,    98,    -1,    -1,    -1,    -1,   -63,    57,
      63,   -63,    -1,    -1,    -1,    -1,    -1,    -1,    73,   -63,
     -63,    70,    72,    -1,    -1,    -1,    -1,   -63,   -63,    42,
      42,    81,   -63,   107,   111,   120,   124,   133,   137,   -63,
      54,    -1,    57,   -63,    76,   108,    14,    33,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   112,   125,   146,   -63,   -63,
     -63,   -63,   -63,   -63,    73,   -63,   123,   -63
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    12,    14,    13,     0,     2,     0,     1,     3,     0,
       0,     0,     0,     6,     5,    16,     4,     7,     0,     0,
       0,    15,     0,     8,     9,     0,    10,     0,     0,     0,
       0,     0,    27,     0,    19,    20,    21,    22,    23,    24,
       0,     0,    29,     0,     0,    36,     0,     0,    17,    18,
      11,    50,    52,    51,     0,     0,     0,     0,     0,     0,
      42,    35,    32,     0,     0,     0,     0,     0,    25,    32,
       0,    49,     0,     0,     0,     0,     0,     0,     0,    39,
      33,     0,     0,     0,     0,     0,     0,    59,    57,    53,
      55,     0,    26,     0,     0,     0,     0,     0,     0,    37,
       0,     0,    32,    28,    59,    57,    53,    55,    30,    43,
      44,    45,    46,    47,    48,     0,     0,    34,    31,    60,
      58,    54,    56,    38,     0,    40,     0,    41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -63,   121,   -63,   -63,   130,   -63,    49,   105,   -63,   -34,
     -63,   -63,   -63,   -63,   -63,   -63,   -62,   -48,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   122,   -38
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,    11,    13,    19,    32,    16,    22,    33,
      34,    35,    36,    37,    47,    56,    82,    62,   101,    59,
      38,   115,   100,   126,    39,    45,    55
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      49,     9,    51,    52,    53,    57,    58,    91,    69,    24,
       1,     2,     3,    25,    15,    54,    63,     1,     2,     3,
      10,    17,    18,    64,    65,    79,    87,    88,    89,    90,
       7,   121,    12,   102,    93,    94,    95,    96,    97,    98,
     118,    21,    64,    65,    99,   104,   105,   106,   107,     6,
     122,    64,    65,    23,     6,    26,    41,    64,    65,    66,
      67,    20,    43,   117,    64,    65,    66,    67,    68,    44,
      50,    48,    71,    61,    40,    80,    27,    42,    81,     1,
       2,     3,   116,    92,    72,    73,    74,    75,    76,    77,
     125,    27,   103,   119,     1,     2,     3,    28,    29,    30,
      31,   108,    78,    64,    65,    66,    67,    83,    84,    85,
      86,    70,    28,    29,    30,    31,    64,    65,    66,    67,
      64,    65,    66,    67,   109,   120,     8,   123,   110,    64,
      65,    66,    67,    64,    65,    66,    67,   111,   127,   124,
      14,   112,    64,    65,    66,    67,    64,    65,    66,    67,
     113,    60,     0,    46,   114,    64,    65,    66,    67
};

static const yytype_int8 yycheck[] =
{
      34,     3,     3,     4,     5,    43,    44,    69,    56,    17,
       6,     7,     8,    21,    14,    16,    54,     6,     7,     8,
      22,    17,    18,     9,    10,    59,    64,    65,    66,    67,
       0,    17,    16,    81,    72,    73,    74,    75,    76,    77,
     102,    15,     9,    10,    78,    83,    84,    85,    86,     0,
      17,     9,    10,    17,     5,     3,    13,     9,    10,    11,
      12,    12,    16,   101,     9,    10,    11,    12,    20,    16,
       3,    15,    17,     3,    25,    13,     3,    28,    21,     6,
       7,     8,    28,    20,    29,    30,    31,    32,    33,    34,
     124,     3,    20,    17,     6,     7,     8,    24,    25,    26,
      27,    20,    14,     9,    10,    11,    12,     9,    10,    11,
      12,    17,    24,    25,    26,    27,     9,    10,    11,    12,
       9,    10,    11,    12,    17,    17,     5,    15,    17,     9,
      10,    11,    12,     9,    10,    11,    12,    17,    15,    14,
      10,    17,     9,    10,    11,    12,     9,    10,    11,    12,
      17,    46,    -1,    31,    17,     9,    10,    11,    12
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,     7,     8,    36,    37,    41,     0,    36,     3,
      22,    38,    16,    39,    39,    14,    42,    17,    18,    40,
      41,    15,    43,    17,    17,    21,     3,     3,    24,    25,
      26,    27,    41,    44,    45,    46,    47,    48,    55,    59,
      41,    13,    41,    16,    16,    60,    60,    49,    15,    44,
       3,     3,     4,     5,    16,    61,    50,    61,    61,    54,
      42,     3,    52,    61,     9,    10,    11,    12,    20,    52,
      17,    17,    29,    30,    31,    32,    33,    34,    14,    44,
      13,    21,    51,     9,    10,    11,    12,    61,    61,    61,
      61,    51,    20,    61,    61,    61,    61,    61,    61,    44,
      57,    53,    52,    20,    61,    61,    61,    61,    20,    17,
      17,    17,    17,    17,    17,    56,    28,    61,    51,    17,
      17,    17,    17,    15,    14,    44,    58,    15
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    36,    36,    37,    38,    38,    39,    39,    39,
      40,    40,    41,    41,    41,    42,    43,    42,    44,    44,
      45,    45,    45,    45,    45,    46,    47,    49,    48,    50,
      48,    51,    51,    53,    52,    52,    54,    56,    55,    57,
      58,    55,    59,    60,    60,    60,    60,    60,    60,    60,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     3,     2,     2,     2,     3,     3,
       2,     4,     1,     1,     1,     2,     0,     4,     2,     1,
       1,     1,     1,     1,     1,     4,     5,     0,     5,     0,
       6,     3,     0,     0,     4,     1,     0,     0,     7,     0,
       0,    10,     3,     5,     5,     5,     5,     5,     5,     3,
       1,     1,     1,     3,     5,     3,     5,     3,     5,     3,
       5
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 4: /* Function: Type FunctionName contenu  */
#line 49 "lex.y"
                                           { printf("main\n"); }
#line 1218 "lex.tab.c"
    break;

  case 12: /* Type: tINT  */
#line 60 "lex.y"
                   {(yyval.type)=(numberType)INT;}
#line 1224 "lex.tab.c"
    break;

  case 13: /* Type: tFLOAT  */
#line 61 "lex.y"
                    {(yyval.type)=(numberType)FLOAT;}
#line 1230 "lex.tab.c"
    break;

  case 14: /* Type: tCHAR  */
#line 62 "lex.y"
                   {(yyval.type)=(numberType)CHAR;}
#line 1236 "lex.tab.c"
    break;

  case 16: /* $@1: %empty  */
#line 66 "lex.y"
                     { printf("Entrez la nouvelle contenue");}
#line 1242 "lex.tab.c"
    break;

  case 25: /* Aff: tID tAFFECT E tSEMI  */
#line 81 "lex.y"
           {
                set_ini((yyvsp[-3].str));
                printf("element est: %s  ",(yyvsp[-3].str));
                add_instruction("COP", getIndex((yyvsp[-3].str)),(yyvsp[-1].number),0);
                  
                suprime_valeur_temporaire();
        
              printf("Affectation %s \n",(yyvsp[-3].str));
            }
#line 1256 "lex.tab.c"
    break;

  case 27: /* $@2: %empty  */
#line 93 "lex.y"
                  {ty=(yyvsp[0].type);}
#line 1262 "lex.tab.c"
    break;

  case 29: /* $@3: %empty  */
#line 94 "lex.y"
                         {ty=(yyvsp[0].type);}
#line 1268 "lex.tab.c"
    break;

  case 33: /* $@4: %empty  */
#line 102 "lex.y"
                                    {ajoutTable((yyvsp[-1].str),ty,0);
                                set_ini((yyvsp[-1].str));}
#line 1275 "lex.tab.c"
    break;

  case 34: /* AffectationDuringDeclaration: tID tAFFECT $@4 E  */
#line 103 "lex.y"
                                                {  
                                int in= getIndex((yyvsp[-3].str));
                                printf("element est: %s  et index :%d",(yyvsp[-3].str),in);
                                add_instruction("COP",in,(yyvsp[0].number),0);
                                suprime_valeur_temporaire();
                                }
#line 1286 "lex.tab.c"
    break;

  case 35: /* AffectationDuringDeclaration: tID  */
#line 109 "lex.y"
                          {ajoutTable((yyvsp[0].str),ty,0);}
#line 1292 "lex.tab.c"
    break;

  case 36: /* IfSequence: %empty  */
#line 111 "lex.y"
                   {int indexASm=get_index_tab();
                    add_instruction("JMF",indexASm,0,0);
                    (yyval.number)=indexASm;}
#line 1300 "lex.tab.c"
    break;

  case 37: /* $@5: %empty  */
#line 116 "lex.y"
                  {
                setInstruTR1((yyvsp[-2].number)+1,get_index_tab());
                }
#line 1308 "lex.tab.c"
    break;

  case 39: /* $@6: %empty  */
#line 120 "lex.y"
                                            {
                int current =get_index_tab();
                setInstruTR1((yyvsp[-1].number)+1,current);
                add_instruction("JMF",(yyvsp[-1].number)+1,0,0);
                (yyvsp[-3].number) = current;
                }
#line 1319 "lex.tab.c"
    break;

  case 40: /* $@7: %empty  */
#line 127 "lex.y"
                  {
                int current = (yyvsp[-7].number);
                setInstruTR1(current+1,get_index_tab());}
#line 1327 "lex.tab.c"
    break;

  case 43: /* Condition: tLPAR E tCOMPEQ E tRPAR  */
#line 137 "lex.y"
                                       {(yyval.number)=add_condition("==",(yyvsp[-3].number),(yyvsp[-1].number));}
#line 1333 "lex.tab.c"
    break;

  case 44: /* Condition: tLPAR E tCOMPL E tRPAR  */
#line 138 "lex.y"
                                       {(yyval.number)=add_condition("<",(yyvsp[-3].number),(yyvsp[-1].number));}
#line 1339 "lex.tab.c"
    break;

  case 45: /* Condition: tLPAR E tCOMPG E tRPAR  */
#line 139 "lex.y"
                                       {(yyval.number)=add_condition(">",(yyvsp[-3].number),(yyvsp[-1].number));}
#line 1345 "lex.tab.c"
    break;

  case 46: /* Condition: tLPAR E tCOMPLE E tRPAR  */
#line 140 "lex.y"
                                       {(yyval.number)=add_condition("<=",(yyvsp[-3].number),(yyvsp[-1].number));}
#line 1351 "lex.tab.c"
    break;

  case 47: /* Condition: tLPAR E tCOMPGE E tRPAR  */
#line 141 "lex.y"
                                       {(yyval.number)=add_condition(">=",(yyvsp[-3].number),(yyvsp[-1].number));}
#line 1357 "lex.tab.c"
    break;

  case 48: /* Condition: tLPAR E tCOMPNEQ E tRPAR  */
#line 142 "lex.y"
                                       {(yyval.number)=add_condition("!=",(yyvsp[-3].number),(yyvsp[-1].number));}
#line 1363 "lex.tab.c"
    break;

  case 49: /* Condition: tLPAR E tRPAR  */
#line 143 "lex.y"
                           {(yyval.number)=(yyvsp[-1].number);}
#line 1369 "lex.tab.c"
    break;

  case 50: /* E: tID  */
#line 150 "lex.y"
                    {
                    printf("element est: %s  ",(yyvsp[0].str));
                    int indexE=getIndex((yyvsp[0].str));
                    int add=creation_valeur_temporaire();
                    add_instruction("COP",add,indexE,0);
                    (yyval.number)=add;}
#line 1380 "lex.tab.c"
    break;

  case 51: /* E: tREAL  */
#line 156 "lex.y"
                         {
                        int add=creation_valeur_temporaire();
                         add_instruction("AFC",add,(yyvsp[0].reel),0);
                        (yyval.number)=add;
                        }
#line 1390 "lex.tab.c"
    break;

  case 52: /* E: tNUMBER  */
#line 162 "lex.y"
                        {
                       int add=creation_valeur_temporaire();
                         add_instruction("AFC",add,(yyvsp[0].number),0);
                        (yyval.number)=add;
                        }
#line 1400 "lex.tab.c"
    break;

  case 53: /* E: E tADD E  */
#line 167 "lex.y"
                       {(yyval.number)=excu_op ("ADD",(yyvsp[-2].number),(yyvsp[0].number));}
#line 1406 "lex.tab.c"
    break;

  case 54: /* E: tLPAR E tADD E tRPAR  */
#line 168 "lex.y"
                                   {(yyval.number)=excu_op ("ADD",(yyvsp[-3].number),(yyvsp[-1].number));}
#line 1412 "lex.tab.c"
    break;

  case 55: /* E: E tSUB E  */
#line 169 "lex.y"
                      {(yyval.number)=excu_op ("SUB",(yyvsp[-2].number),(yyvsp[0].number));}
#line 1418 "lex.tab.c"
    break;

  case 56: /* E: tLPAR E tSUB E tRPAR  */
#line 170 "lex.y"
                                   {(yyval.number)=excu_op ("SUB",(yyvsp[-3].number),(yyvsp[-1].number));}
#line 1424 "lex.tab.c"
    break;

  case 57: /* E: E tMUL E  */
#line 171 "lex.y"
                      {(yyval.number)=excu_op ("MUL",(yyvsp[-2].number),(yyvsp[0].number));}
#line 1430 "lex.tab.c"
    break;

  case 58: /* E: tLPAR E tMUL E tRPAR  */
#line 172 "lex.y"
                                   {(yyval.number)=excu_op ("MUL",(yyvsp[-3].number),(yyvsp[-1].number));}
#line 1436 "lex.tab.c"
    break;

  case 59: /* E: E tDIV E  */
#line 173 "lex.y"
                      {(yyval.number)=excu_op ("DIV",(yyvsp[-2].number),(yyvsp[0].number));}
#line 1442 "lex.tab.c"
    break;

  case 60: /* E: tLPAR E tDIV E tRPAR  */
#line 174 "lex.y"
                                   {(yyval.number)=excu_op ("DIV",(yyvsp[-3].number),(yyvsp[-1].number));}
#line 1448 "lex.tab.c"
    break;


#line 1452 "lex.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 176 "lex.y"

int main(void){    
    //yydebug = 1;
    ini_table();
    ini_table_instruction();
    yyparse();
    exportASMTable();
    exportTableSymbole();
    return 0;
}