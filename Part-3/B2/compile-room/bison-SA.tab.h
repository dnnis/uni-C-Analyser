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
    EOP = 258,                     /* EOP  */
    UNKNOWN = 259,                 /* UNKNOWN  */
    SEMI = 260,                    /* SEMI  */
    HASH = 261,                    /* HASH  */
    COLON = 262,                   /* COLON  */
    COMMA = 263,                   /* COMMA  */
    FLOAT = 264,                   /* FLOAT  */
    DOUBLE = 265,                  /* DOUBLE  */
    STRING = 266,                  /* STRING  */
    NEWLINE = 267,                 /* NEWLINE  */
    KEYWORD = 268,                 /* KEYWORD  */
    INTCONST = 269,                /* INTCONST  */
    IDENTIFIER = 270,              /* IDENTIFIER  */
    KEYWORD_IF = 271,              /* KEYWORD_IF  */
    AMPER = 272,                   /* AMPER  */
    EXCLA = 273,                   /* EXCLA  */
    KEYWORD_RET = 274,             /* KEYWORD_RET  */
    KEYWORD_ELSE = 275,            /* KEYWORD_ELSE  */
    KEYWORD_CONT = 276,            /* KEYWORD_CONT  */
    KEYWORD_CASE = 277,            /* KEYWORD_CASE  */
    KEYWORD_INCL = 278,            /* KEYWORD_INCL  */
    KEYWORD_FUNC = 279,            /* KEYWORD_FUNC  */
    KEYWORD_SWITCH = 280,          /* KEYWORD_SWITCH  */
    KEYWORD_VAR_TYPE = 281,        /* KEYWORD_VAR_TYPE  */
    PAR_START = 282,               /* PAR_START  */
    PAR_END = 283,                 /* PAR_END  */
    BRACE_START = 284,             /* BRACE_START  */
    BRACE_END = 285,               /* BRACE_END  */
    LOGICAL_OR = 286,              /* LOGICAL_OR  */
    LOGICAL_AND = 287,             /* LOGICAL_AND  */
    BRACKET_START = 288,           /* BRACKET_START  */
    BRACKET_END = 289,             /* BRACKET_END  */
    GREATER = 290,                 /* GREATER  */
    LESSER = 291,                  /* LESSER  */
    GREATER_EQ = 292,              /* GREATER_EQ  */
    LESSER_EQ = 293,               /* LESSER_EQ  */
    EQQ = 294,                     /* EQQ  */
    EQ = 295,                      /* EQ  */
    NEQ = 296,                     /* NEQ  */
    EQ_MULTI = 297,                /* EQ_MULTI  */
    EQ_DIV = 298,                  /* EQ_DIV  */
    EQ_PLUS = 299,                 /* EQ_PLUS  */
    EQ_MINUS = 300,                /* EQ_MINUS  */
    PLUS = 301,                    /* PLUS  */
    PLUSPLUS = 302,                /* PLUSPLUS  */
    MINUS = 303,                   /* MINUS  */
    MINUSMINUS = 304,              /* MINUSMINUS  */
    DIV = 305,                     /* DIV  */
    MOD = 306,                     /* MOD  */
    MULTI = 307,                   /* MULTI  */
    POW = 308                      /* POW  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 44 "bison-SA.y"

    int    ival;
    char*  sval;
    float  fval;
    double dval;

#line 124 "bison-SA.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BISON_SA_TAB_H_INCLUDED  */
