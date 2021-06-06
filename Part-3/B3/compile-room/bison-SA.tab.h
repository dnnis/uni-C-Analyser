/* A Bison parser, made by GNU Bison 3.7.6.  */

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

#ifndef YY_YY_BISON_SA_TAB_H_INCLUDED
# define YY_YY_BISON_SA_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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
    EOP = 258,                     /* EOP  */
    UNKNOWN = 259,                 /* UNKNOWN  */
    DOT = 260,                     /* DOT  */
    SEMI = 261,                    /* SEMI  */
    HASH = 262,                    /* HASH  */
    COLON = 263,                   /* COLON  */
    COMMA = 264,                   /* COMMA  */
    FLOAT = 265,                   /* FLOAT  */
    DOUBLE = 266,                  /* DOUBLE  */
    STRING = 267,                  /* STRING  */
    NEWLINE = 268,                 /* NEWLINE  */
    KEYWORD = 269,                 /* KEYWORD  */
    INTCONST = 270,                /* INTCONST  */
    IDENTIFIER = 271,              /* IDENTIFIER  */
    KEYWORD_IF = 272,              /* KEYWORD_IF  */
    AMPER = 273,                   /* AMPER  */
    EXCLA = 274,                   /* EXCLA  */
    KEYWORD_RET = 275,             /* KEYWORD_RET  */
    KEYWORD_FOR = 276,             /* KEYWORD_FOR  */
    KEYWORD_STR = 277,             /* KEYWORD_STR  */
    KEYWORD_ELSE = 278,            /* KEYWORD_ELSE  */
    KEYWORD_SIZE = 279,            /* KEYWORD_SIZE  */
    KEYWORD_CONT = 280,            /* KEYWORD_CONT  */
    KEYWORD_CASE = 281,            /* KEYWORD_CASE  */
    KEYWORD_INCL = 282,            /* KEYWORD_INCL  */
    KEYWORD_FUNC = 283,            /* KEYWORD_FUNC  */
    KEYWORD_VOID = 284,            /* KEYWORD_VOID  */
    KEYWORD_SWITCH = 285,          /* KEYWORD_SWITCH  */
    KEYWORD_VAR_TYPE = 286,        /* KEYWORD_VAR_TYPE  */
    PAR_START = 287,               /* PAR_START  */
    PAR_END = 288,                 /* PAR_END  */
    BRACE_START = 289,             /* BRACE_START  */
    BRACE_END = 290,               /* BRACE_END  */
    LOGICAL_OR = 291,              /* LOGICAL_OR  */
    LOGICAL_AND = 292,             /* LOGICAL_AND  */
    BRACKET_START = 293,           /* BRACKET_START  */
    BRACKET_END = 294,             /* BRACKET_END  */
    GREATER = 295,                 /* GREATER  */
    LESSER = 296,                  /* LESSER  */
    GREATER_EQ = 297,              /* GREATER_EQ  */
    LESSER_EQ = 298,               /* LESSER_EQ  */
    EQQ = 299,                     /* EQQ  */
    EQ = 300,                      /* EQ  */
    NEQ = 301,                     /* NEQ  */
    EQ_MULTI = 302,                /* EQ_MULTI  */
    EQ_DIV = 303,                  /* EQ_DIV  */
    EQ_PLUS = 304,                 /* EQ_PLUS  */
    EQ_MINUS = 305,                /* EQ_MINUS  */
    PLUS = 306,                    /* PLUS  */
    PLUSPLUS = 307,                /* PLUSPLUS  */
    MINUS = 308,                   /* MINUS  */
    MINUSMINUS = 309,              /* MINUSMINUS  */
    DIV = 310,                     /* DIV  */
    MOD = 311,                     /* MOD  */
    MULTI = 312,                   /* MULTI  */
    POW = 313                      /* POW  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 46 "bison-SA.y"

    int    ival;
    char*  sval;
    float  fval;
    double dval;

#line 129 "bison-SA.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BISON_SA_TAB_H_INCLUDED  */
