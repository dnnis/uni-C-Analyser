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
    SEMI = 258,                    /* SEMI  */
    COMMA = 259,                   /* COMMA  */
    FLOAT = 260,                   /* FLOAT  */
    DOUBLE = 261,                  /* DOUBLE  */
    STRING = 262,                  /* STRING  */
    NEWLINE = 263,                 /* NEWLINE  */
    KEYWORD = 264,                 /* KEYWORD  */
    INTCONST = 265,                /* INTCONST  */
    PUNCTUATOR = 266,              /* PUNCTUATOR  */
    IDENTIFIER = 267,              /* IDENTIFIER  */
    AMPER = 268,                   /* AMPER  */
    EXCLA = 269,                   /* EXCLA  */
    KEYWORD_RET = 270,             /* KEYWORD_RET  */
    KEYWORD_FUNC = 271,            /* KEYWORD_FUNC  */
    KEYWORD_VAR_TYPE = 272,        /* KEYWORD_VAR_TYPE  */
    PAR_START = 273,               /* PAR_START  */
    PAR_END = 274,                 /* PAR_END  */
    BRACE_START = 275,             /* BRACE_START  */
    BRACE_END = 276,               /* BRACE_END  */
    LOGICAL_OR = 277,              /* LOGICAL_OR  */
    LOGICAL_AND = 278,             /* LOGICAL_AND  */
    BRACKET_START = 279,           /* BRACKET_START  */
    BRACKET_END = 280,             /* BRACKET_END  */
    GREATER = 281,                 /* GREATER  */
    LESSER = 282,                  /* LESSER  */
    GREATER_EQ = 283,              /* GREATER_EQ  */
    LESSER_EQ = 284,               /* LESSER_EQ  */
    EQQ = 285,                     /* EQQ  */
    EQ = 286,                      /* EQ  */
    NEQ = 287,                     /* NEQ  */
    EQ_MULTI = 288,                /* EQ_MULTI  */
    EQ_DIV = 289,                  /* EQ_DIV  */
    EQ_PLUS = 290,                 /* EQ_PLUS  */
    EQ_MINUS = 291,                /* EQ_MINUS  */
    PLUS = 292,                    /* PLUS  */
    PLUSPLUS = 293,                /* PLUSPLUS  */
    MINUS = 294,                   /* MINUS  */
    MINUSMINUS = 295,              /* MINUSMINUS  */
    DIV = 296,                     /* DIV  */
    MOD = 297,                     /* MOD  */
    MULTI = 298,                   /* MULTI  */
    POW = 299                      /* POW  */
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

#line 115 "bison-SA.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BISON_SA_TAB_H_INCLUDED  */
