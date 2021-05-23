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
    SEMI = 259,                    /* SEMI  */
    COMMA = 260,                   /* COMMA  */
    FLOAT = 261,                   /* FLOAT  */
    DOUBLE = 262,                  /* DOUBLE  */
    STRING = 263,                  /* STRING  */
    NEWLINE = 264,                 /* NEWLINE  */
    KEYWORD = 265,                 /* KEYWORD  */
    INTCONST = 266,                /* INTCONST  */
    PUNCTUATOR = 267,              /* PUNCTUATOR  */
    IDENTIFIER = 268,              /* IDENTIFIER  */
    AMPER = 269,                   /* AMPER  */
    EXCLA = 270,                   /* EXCLA  */
    KEYWORD_RET = 271,             /* KEYWORD_RET  */
    KEYWORD_FUNC = 272,            /* KEYWORD_FUNC  */
    KEYWORD_VAR_TYPE = 273,        /* KEYWORD_VAR_TYPE  */
    PAR_START = 274,               /* PAR_START  */
    PAR_END = 275,                 /* PAR_END  */
    BRACE_START = 276,             /* BRACE_START  */
    BRACE_END = 277,               /* BRACE_END  */
    LOGICAL_OR = 278,              /* LOGICAL_OR  */
    LOGICAL_AND = 279,             /* LOGICAL_AND  */
    BRACKET_START = 280,           /* BRACKET_START  */
    BRACKET_END = 281,             /* BRACKET_END  */
    GREATER = 282,                 /* GREATER  */
    LESSER = 283,                  /* LESSER  */
    GREATER_EQ = 284,              /* GREATER_EQ  */
    LESSER_EQ = 285,               /* LESSER_EQ  */
    EQQ = 286,                     /* EQQ  */
    EQ = 287,                      /* EQ  */
    NEQ = 288,                     /* NEQ  */
    EQ_MULTI = 289,                /* EQ_MULTI  */
    EQ_DIV = 290,                  /* EQ_DIV  */
    EQ_PLUS = 291,                 /* EQ_PLUS  */
    EQ_MINUS = 292,                /* EQ_MINUS  */
    PLUS = 293,                    /* PLUS  */
    PLUSPLUS = 294,                /* PLUSPLUS  */
    MINUS = 295,                   /* MINUS  */
    MINUSMINUS = 296,              /* MINUSMINUS  */
    DIV = 297,                     /* DIV  */
    MOD = 298,                     /* MOD  */
    MULTI = 299,                   /* MULTI  */
    POW = 300                      /* POW  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 37 "bison-SA.y"

    int    ival;
    char*  sval;
    float  fval;
    double dval;

#line 116 "bison-SA.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BISON_SA_TAB_H_INCLUDED  */
