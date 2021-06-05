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
    KEYWORD_FOR = 275,             /* KEYWORD_FOR  */
    KEYWORD_ELSE = 276,            /* KEYWORD_ELSE  */
    KEYWORD_CONT = 277,            /* KEYWORD_CONT  */
    KEYWORD_CASE = 278,            /* KEYWORD_CASE  */
    KEYWORD_INCL = 279,            /* KEYWORD_INCL  */
    KEYWORD_FUNC = 280,            /* KEYWORD_FUNC  */
    KEYWORD_SWITCH = 281,          /* KEYWORD_SWITCH  */
    KEYWORD_VAR_TYPE = 282,        /* KEYWORD_VAR_TYPE  */
    PAR_START = 283,               /* PAR_START  */
    PAR_END = 284,                 /* PAR_END  */
    BRACE_START = 285,             /* BRACE_START  */
    BRACE_END = 286,               /* BRACE_END  */
    LOGICAL_OR = 287,              /* LOGICAL_OR  */
    LOGICAL_AND = 288,             /* LOGICAL_AND  */
    BRACKET_START = 289,           /* BRACKET_START  */
    BRACKET_END = 290,             /* BRACKET_END  */
    GREATER = 291,                 /* GREATER  */
    LESSER = 292,                  /* LESSER  */
    GREATER_EQ = 293,              /* GREATER_EQ  */
    LESSER_EQ = 294,               /* LESSER_EQ  */
    EQQ = 295,                     /* EQQ  */
    EQ = 296,                      /* EQ  */
    NEQ = 297,                     /* NEQ  */
    EQ_MULTI = 298,                /* EQ_MULTI  */
    EQ_DIV = 299,                  /* EQ_DIV  */
    EQ_PLUS = 300,                 /* EQ_PLUS  */
    EQ_MINUS = 301,                /* EQ_MINUS  */
    PLUS = 302,                    /* PLUS  */
    PLUSPLUS = 303,                /* PLUSPLUS  */
    MINUS = 304,                   /* MINUS  */
    MINUSMINUS = 305,              /* MINUSMINUS  */
    DIV = 306,                     /* DIV  */
    MOD = 307,                     /* MOD  */
    MULTI = 308,                   /* MULTI  */
    POW = 309                      /* POW  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 51 "bison-SA.y"

    int    ival;
    char*  sval;
    float  fval;
    double dval;

#line 125 "bison-SA.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BISON_SA_TAB_H_INCLUDED  */
