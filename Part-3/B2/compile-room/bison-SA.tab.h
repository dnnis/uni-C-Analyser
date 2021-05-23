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
    COMMA = 261,                   /* COMMA  */
    FLOAT = 262,                   /* FLOAT  */
    DOUBLE = 263,                  /* DOUBLE  */
    STRING = 264,                  /* STRING  */
    NEWLINE = 265,                 /* NEWLINE  */
    KEYWORD = 266,                 /* KEYWORD  */
    INTCONST = 267,                /* INTCONST  */
    PUNCTUATOR = 268,              /* PUNCTUATOR  */
    IDENTIFIER = 269,              /* IDENTIFIER  */
    AMPER = 270,                   /* AMPER  */
    EXCLA = 271,                   /* EXCLA  */
    KEYWORD_RET = 272,             /* KEYWORD_RET  */
    KEYWORD_FUNC = 273,            /* KEYWORD_FUNC  */
    KEYWORD_VAR_TYPE = 274,        /* KEYWORD_VAR_TYPE  */
    PAR_START = 275,               /* PAR_START  */
    PAR_END = 276,                 /* PAR_END  */
    BRACE_START = 277,             /* BRACE_START  */
    BRACE_END = 278,               /* BRACE_END  */
    LOGICAL_OR = 279,              /* LOGICAL_OR  */
    LOGICAL_AND = 280,             /* LOGICAL_AND  */
    BRACKET_START = 281,           /* BRACKET_START  */
    BRACKET_END = 282,             /* BRACKET_END  */
    GREATER = 283,                 /* GREATER  */
    LESSER = 284,                  /* LESSER  */
    GREATER_EQ = 285,              /* GREATER_EQ  */
    LESSER_EQ = 286,               /* LESSER_EQ  */
    EQQ = 287,                     /* EQQ  */
    EQ = 288,                      /* EQ  */
    NEQ = 289,                     /* NEQ  */
    EQ_MULTI = 290,                /* EQ_MULTI  */
    EQ_DIV = 291,                  /* EQ_DIV  */
    EQ_PLUS = 292,                 /* EQ_PLUS  */
    EQ_MINUS = 293,                /* EQ_MINUS  */
    PLUS = 294,                    /* PLUS  */
    PLUSPLUS = 295,                /* PLUSPLUS  */
    MINUS = 296,                   /* MINUS  */
    MINUSMINUS = 297,              /* MINUSMINUS  */
    DIV = 298,                     /* DIV  */
    MOD = 299,                     /* MOD  */
    MULTI = 300,                   /* MULTI  */
    POW = 301                      /* POW  */
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

#line 117 "bison-SA.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BISON_SA_TAB_H_INCLUDED  */
