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
    KEYWORD_ELSE = 277,            /* KEYWORD_ELSE  */
    KEYWORD_CONT = 278,            /* KEYWORD_CONT  */
    KEYWORD_CASE = 279,            /* KEYWORD_CASE  */
    KEYWORD_INCL = 280,            /* KEYWORD_INCL  */
    KEYWORD_FUNC = 281,            /* KEYWORD_FUNC  */
    KEYWORD_SWITCH = 282,          /* KEYWORD_SWITCH  */
    KEYWORD_VAR_TYPE = 283,        /* KEYWORD_VAR_TYPE  */
    PAR_START = 284,               /* PAR_START  */
    PAR_END = 285,                 /* PAR_END  */
    BRACE_START = 286,             /* BRACE_START  */
    BRACE_END = 287,               /* BRACE_END  */
    LOGICAL_OR = 288,              /* LOGICAL_OR  */
    LOGICAL_AND = 289,             /* LOGICAL_AND  */
    BRACKET_START = 290,           /* BRACKET_START  */
    BRACKET_END = 291,             /* BRACKET_END  */
    GREATER = 292,                 /* GREATER  */
    LESSER = 293,                  /* LESSER  */
    GREATER_EQ = 294,              /* GREATER_EQ  */
    LESSER_EQ = 295,               /* LESSER_EQ  */
    EQQ = 296,                     /* EQQ  */
    EQ = 297,                      /* EQ  */
    NEQ = 298,                     /* NEQ  */
    EQ_MULTI = 299,                /* EQ_MULTI  */
    EQ_DIV = 300,                  /* EQ_DIV  */
    EQ_PLUS = 301,                 /* EQ_PLUS  */
    EQ_MINUS = 302,                /* EQ_MINUS  */
    PLUS = 303,                    /* PLUS  */
    PLUSPLUS = 304,                /* PLUSPLUS  */
    MINUS = 305,                   /* MINUS  */
    MINUSMINUS = 306,              /* MINUSMINUS  */
    DIV = 307,                     /* DIV  */
    MOD = 308,                     /* MOD  */
    MULTI = 309,                   /* MULTI  */
    POW = 310                      /* POW  */
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

#line 126 "bison-SA.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BISON_SA_TAB_H_INCLUDED  */
