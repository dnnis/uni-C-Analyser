/* A Bison parser, made by GNU Bison 3.7.6.  */

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
#define YYBISON 30706

/* Bison version string.  */
#define YYBISON_VERSION "3.7.6"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 15 "bison-SA.y"

/* Orismoi kai dhlwseis glwssas C. Otidhpote exei na kanei me orismo h
   arxikopoihsh metablhtwn & synarthsewn, arxeia header kai dhlwseis #define
   mpainei se auto to shmeio */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int yylex(void);
extern int yyparse(void);
void yyerror(char *);
void print_report(int,int,int,int);
// Αρχικοποιούμε τον pointer για τη εισαγωγή δεδομένων με αρχείο και όχι απο το
// stdin
extern FILE *yyin;
// Αρχικοποιούμε τις μεταβλητές για το άθροισμα των σωστών και λάθος εκφράσεων
// και λέξεων
int cor_words = 0;
int inc_words = 0;
int cor_expr  = 0;
int inc_expr  = 0;
// Για την γραμμή που αρχίζει μία συνάρτηση
int brack_start_line=0;
int brace_start_line=0;

int brace_started_flag=0;
// Για την μέτρηση γραμμών
int line=1;

#line 101 "bison-SA.tab.c"

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

#include "bison-SA.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_EOP = 3,                        /* EOP  */
  YYSYMBOL_UNKNOWN = 4,                    /* UNKNOWN  */
  YYSYMBOL_DOT = 5,                        /* DOT  */
  YYSYMBOL_SEMI = 6,                       /* SEMI  */
  YYSYMBOL_HASH = 7,                       /* HASH  */
  YYSYMBOL_COLON = 8,                      /* COLON  */
  YYSYMBOL_COMMA = 9,                      /* COMMA  */
  YYSYMBOL_FLOAT = 10,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 11,                    /* DOUBLE  */
  YYSYMBOL_STRING = 12,                    /* STRING  */
  YYSYMBOL_NEWLINE = 13,                   /* NEWLINE  */
  YYSYMBOL_KEYWORD = 14,                   /* KEYWORD  */
  YYSYMBOL_INTCONST = 15,                  /* INTCONST  */
  YYSYMBOL_IDENTIFIER = 16,                /* IDENTIFIER  */
  YYSYMBOL_KEYWORD_IF = 17,                /* KEYWORD_IF  */
  YYSYMBOL_AMPER = 18,                     /* AMPER  */
  YYSYMBOL_EXCLA = 19,                     /* EXCLA  */
  YYSYMBOL_KEYWORD_RET = 20,               /* KEYWORD_RET  */
  YYSYMBOL_KEYWORD_FOR = 21,               /* KEYWORD_FOR  */
  YYSYMBOL_KEYWORD_STR = 22,               /* KEYWORD_STR  */
  YYSYMBOL_KEYWORD_ELSE = 23,              /* KEYWORD_ELSE  */
  YYSYMBOL_KEYWORD_SIZE = 24,              /* KEYWORD_SIZE  */
  YYSYMBOL_KEYWORD_CONT = 25,              /* KEYWORD_CONT  */
  YYSYMBOL_KEYWORD_CASE = 26,              /* KEYWORD_CASE  */
  YYSYMBOL_KEYWORD_INCL = 27,              /* KEYWORD_INCL  */
  YYSYMBOL_KEYWORD_FUNC = 28,              /* KEYWORD_FUNC  */
  YYSYMBOL_KEYWORD_SWITCH = 29,            /* KEYWORD_SWITCH  */
  YYSYMBOL_KEYWORD_VAR_TYPE = 30,          /* KEYWORD_VAR_TYPE  */
  YYSYMBOL_PAR_START = 31,                 /* PAR_START  */
  YYSYMBOL_PAR_END = 32,                   /* PAR_END  */
  YYSYMBOL_BRACE_START = 33,               /* BRACE_START  */
  YYSYMBOL_BRACE_END = 34,                 /* BRACE_END  */
  YYSYMBOL_LOGICAL_OR = 35,                /* LOGICAL_OR  */
  YYSYMBOL_LOGICAL_AND = 36,               /* LOGICAL_AND  */
  YYSYMBOL_BRACKET_START = 37,             /* BRACKET_START  */
  YYSYMBOL_BRACKET_END = 38,               /* BRACKET_END  */
  YYSYMBOL_GREATER = 39,                   /* GREATER  */
  YYSYMBOL_LESSER = 40,                    /* LESSER  */
  YYSYMBOL_GREATER_EQ = 41,                /* GREATER_EQ  */
  YYSYMBOL_LESSER_EQ = 42,                 /* LESSER_EQ  */
  YYSYMBOL_EQQ = 43,                       /* EQQ  */
  YYSYMBOL_EQ = 44,                        /* EQ  */
  YYSYMBOL_NEQ = 45,                       /* NEQ  */
  YYSYMBOL_EQ_MULTI = 46,                  /* EQ_MULTI  */
  YYSYMBOL_EQ_DIV = 47,                    /* EQ_DIV  */
  YYSYMBOL_EQ_PLUS = 48,                   /* EQ_PLUS  */
  YYSYMBOL_EQ_MINUS = 49,                  /* EQ_MINUS  */
  YYSYMBOL_PLUS = 50,                      /* PLUS  */
  YYSYMBOL_PLUSPLUS = 51,                  /* PLUSPLUS  */
  YYSYMBOL_MINUS = 52,                     /* MINUS  */
  YYSYMBOL_MINUSMINUS = 53,                /* MINUSMINUS  */
  YYSYMBOL_DIV = 54,                       /* DIV  */
  YYSYMBOL_MOD = 55,                       /* MOD  */
  YYSYMBOL_MULTI = 56,                     /* MULTI  */
  YYSYMBOL_POW = 57,                       /* POW  */
  YYSYMBOL_YYACCEPT = 58,                  /* $accept  */
  YYSYMBOL_program = 59,                   /* program  */
  YYSYMBOL_expr_part = 60,                 /* expr_part  */
  YYSYMBOL_operator = 61,                  /* operator  */
  YYSYMBOL_in_de_crement_operator = 62,    /* in_de_crement_operator  */
  YYSYMBOL_expr_proc = 63,                 /* expr_proc  */
  YYSYMBOL_elements = 64,                  /* elements  */
  YYSYMBOL_in_brack = 65,                  /* in_brack  */
  YYSYMBOL_in_brace = 66,                  /* in_brace  */
  YYSYMBOL_arguments = 67,                 /* arguments  */
  YYSYMBOL_func_par = 68,                  /* func_par  */
  YYSYMBOL_declaration = 69,               /* declaration  */
  YYSYMBOL_assignment = 70,                /* assignment  */
  YYSYMBOL_return = 71,                    /* return  */
  YYSYMBOL_include = 72,                   /* include  */
  YYSYMBOL_cases = 73,                     /* cases  */
  YYSYMBOL_case_grammar = 74,              /* case_grammar  */
  YYSYMBOL_else_grammar = 75,              /* else_grammar  */
  YYSYMBOL_if_grammar = 76,                /* if_grammar  */
  YYSYMBOL_for_grammar = 77,               /* for_grammar  */
  YYSYMBOL_for_args = 78,                  /* for_args  */
  YYSYMBOL_struct = 79,                    /* struct  */
  YYSYMBOL_loops = 80,                     /* loops  */
  YYSYMBOL_half_expr = 81,                 /* half_expr  */
  YYSYMBOL_sizeof = 82,                    /* sizeof  */
  YYSYMBOL_conditionals = 83,              /* conditionals  */
  YYSYMBOL_valid = 84                      /* valid  */
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
typedef yytype_uint8 yy_state_t;

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

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   326

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  163

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   312


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   106,   106,   107,   113,   114,   115,   116,   117,   118,
     119,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   137,   138,   139,   144,   145,   146,   147,
     159,   160,   165,   169,   170,   171,   172,   177,   178,   179,
     184,   185,   190,   191,   192,   193,   194,   199,   202,   203,
     207,   208,   212,   213,   216,   217,   221,   224,   225,   229,
     230,   234,   235,   236,   237,   238,   239,   240,   244,   247,
     250,   251,   252,   253,   257,   258,   262,   263,   264,   269,
     270,   271,   272,   273,   274,   275,   276,   291,   306,   307,
     308,   309,   310
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
  "\"end of file\"", "error", "\"invalid token\"", "EOP", "UNKNOWN",
  "DOT", "SEMI", "HASH", "COLON", "COMMA", "FLOAT", "DOUBLE", "STRING",
  "NEWLINE", "KEYWORD", "INTCONST", "IDENTIFIER", "KEYWORD_IF", "AMPER",
  "EXCLA", "KEYWORD_RET", "KEYWORD_FOR", "KEYWORD_STR", "KEYWORD_ELSE",
  "KEYWORD_SIZE", "KEYWORD_CONT", "KEYWORD_CASE", "KEYWORD_INCL",
  "KEYWORD_FUNC", "KEYWORD_SWITCH", "KEYWORD_VAR_TYPE", "PAR_START",
  "PAR_END", "BRACE_START", "BRACE_END", "LOGICAL_OR", "LOGICAL_AND",
  "BRACKET_START", "BRACKET_END", "GREATER", "LESSER", "GREATER_EQ",
  "LESSER_EQ", "EQQ", "EQ", "NEQ", "EQ_MULTI", "EQ_DIV", "EQ_PLUS",
  "EQ_MINUS", "PLUS", "PLUSPLUS", "MINUS", "MINUSMINUS", "DIV", "MOD",
  "MULTI", "POW", "$accept", "program", "expr_part", "operator",
  "in_de_crement_operator", "expr_proc", "elements", "in_brack",
  "in_brace", "arguments", "func_par", "declaration", "assignment",
  "return", "include", "cases", "case_grammar", "else_grammar",
  "if_grammar", "for_grammar", "for_args", "struct", "loops", "half_expr",
  "sizeof", "conditionals", "valid", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312
};
#endif

#define YYPACT_NINF (-126)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -126,   130,  -126,  -126,  -126,  -126,   -18,  -126,  -126,  -126,
     -24,  -126,  -126,   -22,    -1,    49,    13,    38,    38,    18,
       9,    21,    40,    41,  -126,  -126,  -126,   254,   110,    56,
    -126,  -126,    61,    63,    67,    69,  -126,  -126,  -126,  -126,
      71,  -126,    72,  -126,  -126,     0,  -126,    49,    49,  -126,
     254,  -126,    17,   -24,  -126,  -126,    50,    52,    49,   -33,
    -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,   110,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,  -126,    65,  -126,    53,   206,    78,    62,
      64,   110,   239,    83,   110,    49,    51,    59,    88,     4,
      49,    91,   219,     4,   269,    -6,    97,    84,    86,    95,
      85,  -126,   228,   110,   112,   122,  -126,  -126,    49,    49,
     132,   123,  -126,    31,  -126,   110,  -126,  -126,   139,   113,
     113,   110,  -126,   110,  -126,  -126,   116,  -126,  -126,  -126,
      49,  -126,  -126,  -126,  -126,  -126,  -126,   110,   141,   127,
     128,  -126,   131,  -126,  -126,  -126,   175,  -126,  -126,  -126,
     143,   113,  -126
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     1,    92,    91,    10,     0,     4,     6,     5,
      90,     7,     8,     9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    33,    35,    25,    24,    23,     0,     0,
      86,    88,     0,     0,     0,     0,    78,    77,    76,    69,
       0,    85,     0,    89,     2,     0,    36,     0,     0,     9,
      23,    48,     0,     0,    68,    56,     0,     0,     0,    42,
      34,    12,    11,    13,    21,    19,    20,    22,    16,    17,
      14,    18,    15,     0,    28,    29,    82,    84,    83,    79,
      81,    87,    80,    51,     0,    47,     0,     0,     0,     0,
       0,    39,     0,     0,     0,     0,    46,    27,     0,     0,
      67,     0,     0,     0,    74,     0,     0,     0,     0,    31,
       0,    43,     0,     0,     0,     0,    57,    66,    65,    64,
       0,     0,    59,     0,    75,     0,    41,    40,     0,     0,
       0,     0,    32,     0,    44,    26,     0,    58,    62,    63,
       0,    60,    73,    72,    71,    70,    38,     0,     0,     0,
       0,    30,     0,    50,    61,    37,     0,    55,    54,    45,
       0,    53,    52
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -126,  -126,   -15,    66,   -26,   -13,   -83,  -126,   -11,  -126,
    -126,  -126,  -126,  -126,  -126,  -125,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,  -126,  -126,  -126,     1
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    27,    73,    28,    29,   110,    96,    30,   106,
      31,    32,    33,    34,    35,   149,    36,    37,    38,    39,
      89,    40,    41,   124,    42,    43,    44
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      50,    74,    51,   125,    94,   150,    54,    55,     5,    45,
      46,    95,    83,    75,     7,     8,     9,    53,    11,    12,
      49,     5,    47,    87,    74,    57,   126,     7,     8,     9,
      48,    11,    12,    49,    85,    86,   162,    23,    24,    88,
      84,   142,   143,    92,    52,    93,   144,   145,   151,    56,
     152,    53,    58,     5,    60,    25,    59,    26,    97,     7,
       8,     9,    76,    11,    12,    49,    74,    77,    25,    78,
      26,    23,    24,    79,   101,    80,   105,    81,    82,   109,
      90,    98,   111,    91,   102,    99,   115,   117,   116,   120,
     121,   128,   122,   114,   103,   112,   104,   118,   135,   134,
      25,     5,    26,   113,   131,   138,   139,     7,     8,     9,
     146,    11,    12,    49,     5,   108,   109,   129,   109,   130,
       7,     8,     9,   132,    11,    12,    49,   154,   136,   127,
       2,     3,   155,     4,     5,   137,   141,     6,   140,   148,
       7,     8,     9,    10,    11,    12,    13,    14,   147,   156,
      15,    16,    17,    18,    19,   153,   161,   160,    20,    21,
      22,   157,   158,    23,    24,   159,     0,     0,     0,     0,
     123,     0,     0,     0,     0,     0,     3,     0,     4,     5,
       0,    25,     6,    26,     0,     7,     8,     9,    10,    11,
      12,    13,    14,     0,     0,    15,    16,    17,    18,    19,
       0,     0,     0,    20,    21,    22,     0,     0,    23,    24,
       5,     0,   100,     0,     0,     0,     7,     8,     9,     0,
      11,    12,    49,     5,     0,   119,    25,     0,    26,     7,
       8,     9,     5,    11,    12,    49,     0,     0,     7,     8,
       9,     0,    11,    12,    49,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    25,     0,    26,
       0,   133,     0,     0,     0,     0,     0,     0,     0,     0,
      25,   107,    26,     0,     0,     0,     0,     0,     0,    25,
       0,    26,    61,    62,    63,    64,    65,    66,    67,    68,
      25,    69,    26,    70,     0,    71,    72,    61,    62,    63,
      64,    65,    66,    67,    68,    25,    69,    26,    70,     0,
      71,    72,    61,    62,    63,    64,    65,    66,    67,    68,
       0,    69,     0,    70,     0,    71,    72
};

static const yytype_int16 yycheck[] =
{
      15,    27,    15,     9,    37,   130,    17,    18,     4,    27,
      34,    44,    12,    28,    10,    11,    12,    13,    14,    15,
      16,     4,    44,     6,    50,    16,    32,    10,    11,    12,
      31,    14,    15,    16,    47,    48,   161,    33,    34,    52,
      40,    10,    11,    58,    31,    58,    15,    16,   131,    31,
     133,    13,    31,     4,    13,    51,    16,    53,    73,    10,
      11,    12,     6,    14,    15,    16,    92,     6,    51,     6,
      53,    33,    34,     6,    87,     6,    91,     6,     6,    94,
      30,    16,    95,    31,     6,    32,    99,   100,    99,   102,
     103,   106,   103,     5,    32,    44,    32,     6,   113,   112,
      51,     4,    53,    44,     9,   118,   119,    10,    11,    12,
     125,    14,    15,    16,     4,    32,   131,    33,   133,    33,
      10,    11,    12,    38,    14,    15,    16,   140,    16,    32,
       0,     1,   147,     3,     4,    13,    13,     7,     6,    26,
      10,    11,    12,    13,    14,    15,    16,    17,     9,     8,
      20,    21,    22,    23,    24,    39,    13,   156,    28,    29,
      30,    34,    34,    33,    34,    34,    -1,    -1,    -1,    -1,
     104,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,
      -1,    51,     7,    53,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    -1,    -1,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    28,    29,    30,    -1,    -1,    33,    34,
       4,    -1,     6,    -1,    -1,    -1,    10,    11,    12,    -1,
      14,    15,    16,     4,    -1,     6,    51,    -1,    53,    10,
      11,    12,     4,    14,    15,    16,    -1,    -1,    10,    11,
      12,    -1,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    53,
      -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    32,    53,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      -1,    53,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    56,    57,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    57,    43,    44,    45,    46,    47,    48,    49,    50,
      -1,    52,    -1,    54,    -1,    56,    57
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    59,     0,     1,     3,     4,     7,    10,    11,    12,
      13,    14,    15,    16,    17,    20,    21,    22,    23,    24,
      28,    29,    30,    33,    34,    51,    53,    60,    62,    63,
      66,    68,    69,    70,    71,    72,    74,    75,    76,    77,
      79,    80,    82,    83,    84,    27,    34,    44,    31,    16,
      60,    63,    31,    13,    66,    66,    31,    16,    31,    16,
      13,    43,    44,    45,    46,    47,    48,    49,    50,    52,
      54,    56,    57,    61,    62,    60,     6,     6,     6,     6,
       6,     6,     6,    12,    40,    63,    63,     6,    63,    78,
      30,    31,    60,    63,    37,    44,    65,    60,    16,    32,
       6,    63,     6,    32,    32,    60,    67,    32,    32,    60,
      64,    63,    44,    44,     5,    63,    66,    63,     6,     6,
      63,    63,    66,    61,    81,     9,    32,    32,    60,    33,
      33,     9,    38,    33,    63,    60,    16,    13,    63,    63,
       6,    13,    10,    11,    15,    16,    60,     9,    26,    73,
      73,    64,    64,    39,    63,    60,     8,    34,    34,    34,
      84,    13,    73
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    59,    59,    60,    60,    60,    60,    60,    60,
      60,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    62,    62,    62,    63,    63,    63,    63,
      64,    64,    65,    66,    66,    66,    66,    67,    67,    67,
      68,    68,    69,    69,    69,    69,    69,    70,    71,    71,
      72,    72,    73,    73,    74,    74,    75,    76,    76,    77,
      77,    78,    78,    78,    78,    78,    78,    78,    79,    80,
      81,    81,    81,    81,    82,    82,    83,    83,    83,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     1,     1,     5,     3,     2,     2,
       3,     1,     3,     1,     2,     1,     2,     4,     3,     0,
       5,     5,     2,     4,     5,     7,     3,     3,     2,     2,
       7,     3,     5,     4,     7,     7,     2,     5,     6,     5,
       6,     5,     4,     4,     3,     3,     3,     2,     2,     1,
       2,     2,     2,     2,     4,     5,     1,     1,     1,     2,
       2,     2,     2,     2,     2,     1,     1,     2,     1,     1,
       1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
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
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
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
  case 4: /* expr_part: FLOAT  */
#line 113 "bison-SA.y"
                  { cor_words++; }
#line 1333 "bison-SA.tab.c"
    break;

  case 5: /* expr_part: STRING  */
#line 114 "bison-SA.y"
                  { cor_words++; }
#line 1339 "bison-SA.tab.c"
    break;

  case 6: /* expr_part: DOUBLE  */
#line 115 "bison-SA.y"
                  { cor_words++; }
#line 1345 "bison-SA.tab.c"
    break;

  case 7: /* expr_part: KEYWORD  */
#line 116 "bison-SA.y"
                  { cor_words++; }
#line 1351 "bison-SA.tab.c"
    break;

  case 8: /* expr_part: INTCONST  */
#line 117 "bison-SA.y"
                  { cor_words++; }
#line 1357 "bison-SA.tab.c"
    break;

  case 9: /* expr_part: IDENTIFIER  */
#line 118 "bison-SA.y"
                  { cor_words++; }
#line 1363 "bison-SA.tab.c"
    break;

  case 10: /* expr_part: UNKNOWN  */
#line 119 "bison-SA.y"
                  { inc_words++; printf("O\tLine:  %d \t",line);}
#line 1369 "bison-SA.tab.c"
    break;

  case 11: /* operator: EQ  */
#line 123 "bison-SA.y"
                  { cor_words++; }
#line 1375 "bison-SA.tab.c"
    break;

  case 12: /* operator: EQQ  */
#line 124 "bison-SA.y"
                  { cor_words++; }
#line 1381 "bison-SA.tab.c"
    break;

  case 13: /* operator: NEQ  */
#line 125 "bison-SA.y"
                  { cor_words++; }
#line 1387 "bison-SA.tab.c"
    break;

  case 14: /* operator: DIV  */
#line 126 "bison-SA.y"
                  { cor_words++; }
#line 1393 "bison-SA.tab.c"
    break;

  case 15: /* operator: POW  */
#line 127 "bison-SA.y"
                  { cor_words++; }
#line 1399 "bison-SA.tab.c"
    break;

  case 16: /* operator: PLUS  */
#line 128 "bison-SA.y"
                  { cor_words++; }
#line 1405 "bison-SA.tab.c"
    break;

  case 17: /* operator: MINUS  */
#line 129 "bison-SA.y"
                  { cor_words++; }
#line 1411 "bison-SA.tab.c"
    break;

  case 18: /* operator: MULTI  */
#line 130 "bison-SA.y"
                  { cor_words++; }
#line 1417 "bison-SA.tab.c"
    break;

  case 19: /* operator: EQ_DIV  */
#line 131 "bison-SA.y"
                  { cor_words++; }
#line 1423 "bison-SA.tab.c"
    break;

  case 20: /* operator: EQ_PLUS  */
#line 132 "bison-SA.y"
                  { cor_words++; }
#line 1429 "bison-SA.tab.c"
    break;

  case 21: /* operator: EQ_MULTI  */
#line 133 "bison-SA.y"
                  { cor_words++; }
#line 1435 "bison-SA.tab.c"
    break;

  case 22: /* operator: EQ_MINUS  */
#line 134 "bison-SA.y"
                  { cor_words++; }
#line 1441 "bison-SA.tab.c"
    break;

  case 24: /* in_de_crement_operator: MINUSMINUS  */
#line 138 "bison-SA.y"
                  { cor_words++; }
#line 1447 "bison-SA.tab.c"
    break;

  case 25: /* in_de_crement_operator: PLUSPLUS  */
#line 139 "bison-SA.y"
                  { cor_words++; }
#line 1453 "bison-SA.tab.c"
    break;

  case 40: /* func_par: KEYWORD_FUNC IDENTIFIER PAR_START arguments PAR_END  */
#line 184 "bison-SA.y"
                                                          {cor_expr++; printf("O\tLine:  %d \tValid arguments\n",line); }
#line 1459 "bison-SA.tab.c"
    break;

  case 41: /* func_par: KEYWORD_FUNC IDENTIFIER PAR_START expr_part PAR_END  */
#line 185 "bison-SA.y"
                                                          {cor_expr++; printf("O\tLine:  %d \tValid argument\n" ,line); }
#line 1465 "bison-SA.tab.c"
    break;

  case 79: /* valid: return SEMI  */
#line 269 "bison-SA.y"
                      { cor_expr++; printf("O\tLine:  %d \tValid return statement!\n"    ,line);}
#line 1471 "bison-SA.tab.c"
    break;

  case 80: /* valid: sizeof SEMI  */
#line 270 "bison-SA.y"
                      { cor_expr++; printf("O\tLine:  %d \tValid sizeof statement!\n"    ,line);}
#line 1477 "bison-SA.tab.c"
    break;

  case 81: /* valid: include SEMI  */
#line 271 "bison-SA.y"
                      { cor_expr++; printf("O\tLine:  %d \tValid include statement!\n"   ,line);}
#line 1483 "bison-SA.tab.c"
    break;

  case 82: /* valid: expr_proc SEMI  */
#line 272 "bison-SA.y"
                      { cor_expr++; printf("O\tLine:  %d \tValid expression!\n"          ,line);}
#line 1489 "bison-SA.tab.c"
    break;

  case 83: /* valid: assignment SEMI  */
#line 273 "bison-SA.y"
                      { cor_expr++; printf("O\tLine:  %d \tValid assignment!\n"          ,line);}
#line 1495 "bison-SA.tab.c"
    break;

  case 84: /* valid: declaration SEMI  */
#line 274 "bison-SA.y"
                      { cor_expr++; printf("O\tLine:  %d \tValid declaration!\n"         ,line);}
#line 1501 "bison-SA.tab.c"
    break;

  case 85: /* valid: loops  */
#line 275 "bison-SA.y"
                      { cor_expr++; printf("O\tLine:  %d \tValid loop clause!\n"         ,line);}
#line 1507 "bison-SA.tab.c"
    break;

  case 86: /* valid: in_brace  */
#line 276 "bison-SA.y"
                      { cor_expr++;
                        if( brace_started_flag)
                        {
                          brace_started_flag=0;
                          if (line == brace_start_line)
                          {
                            printf("O\tLine:  %d \tValid function body!\n",brace_start_line);
                          } else if (line >= brace_start_line) { 
                            printf("O\tLines: %d-%d\tValid function body!\n",brace_start_line, line);
                          }
                        } else {
                          brace_started_flag=1;
                          brace_start_line=line;
                        }
                      }
#line 1527 "bison-SA.tab.c"
    break;

  case 87: /* valid: struct SEMI  */
#line 291 "bison-SA.y"
                      { cor_expr++;
                        if( brace_started_flag)
                        {
                          brace_started_flag=0;
                          if (line == brace_start_line)
                          {
                            printf("O\tLine:  %d \tValid struct statement!\n",brace_start_line);
                          } else if (line >= brace_start_line) { 
                            printf("O\tLines: %d-%d\tValid struct statement!\n",brace_start_line, line);
                          }
                        } else {
                          brace_started_flag=1;
                          brace_start_line=line;
                        }
                      }
#line 1547 "bison-SA.tab.c"
    break;

  case 88: /* valid: func_par  */
#line 306 "bison-SA.y"
                      { cor_expr++; printf("O\tLine:  %d \tValid function declaration!\n",line);}
#line 1553 "bison-SA.tab.c"
    break;

  case 89: /* valid: conditionals  */
#line 307 "bison-SA.y"
                      { cor_expr++; printf("O\tLine:  %d \tValid conditional clause!\n"  ,line);}
#line 1559 "bison-SA.tab.c"
    break;

  case 90: /* valid: NEWLINE  */
#line 308 "bison-SA.y"
                      { line++; }
#line 1565 "bison-SA.tab.c"
    break;

  case 91: /* valid: EOP  */
#line 309 "bison-SA.y"
                      { print_report(cor_words,cor_expr,inc_words,inc_expr); }
#line 1571 "bison-SA.tab.c"
    break;

  case 92: /* valid: error  */
#line 310 "bison-SA.y"
                      { inc_expr++; }
#line 1577 "bison-SA.tab.c"
    break;


#line 1581 "bison-SA.tab.c"

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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
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

#line 313 "bison-SA.y"


// Αυτή η συνάρτηση τυπώνει το πλήθος των σωστών και λάθος λέξεων και εκφράσεων
// Ενεργοποιήται μόλις ο bison δεχθεί token EOP
// (End of Parse, δίνεται στο τέλος του αρχείου)
void print_report (int cor_words, int cor_expr,int inc_words,int inc_expr) {
    printf("*---- RUN REPORT: ---------------------*\n"
           "| Number of  correct  words       : %d\n"
           "| Number of  correct  expressions : %d\n"
           "*--------------------------------------*\n"
           "| Number of incorrect words       : %d\n"
           "| Number of incorrect expressions : %d\n"
           "*--------------------------------------*\n"
           , cor_words, cor_expr, inc_words, inc_expr);
}

/* H synarthsh yyerror xrhsimopoieitai gia thn anafora sfalmatwn. Sygkekrimena kaleitai
   apo thn yyparse otan yparksei kapoio syntaktiko lathos. Sthn parakatw periptwsh h
   synarthsh epi ths ousias typwnei mhnyma lathous sthn othonh. */
void yyerror(char *s) {
    fprintf(stderr, "X\tLine:  %d \tError: %s\n",line, s);
}

/* H synarthsh main pou apotelei kai to shmeio ekkinhshs tou programmatos.
   Sthn sygkekrimenh periptwsh apla kalei thn synarthsh yyparse tou Bison
   gia na ksekinhsei h syntaktikh analysh. */
int main(void) {
    //Αναγκαίες εντολές για να γίνεται το debugging στον Bison
   // #ifdef YYDEBUG
   //   yydebug = 1;
   // #endif
    // Open a file handle to a particular file:
    FILE *myfile = fopen("input.txt", "r");
    // Make sure it is valid:
    if (!myfile)
    {
      printf("* Error: cannot open the \"input.txt\" file!");
      return -1;
    }
    // Set Flex to read from it instead of defaulting to STDIN:
    printf("\n*---- ANALYSIS: ---------------------*\n");
    yyin = myfile;
    yyparse();
    fclose(myfile);
}
