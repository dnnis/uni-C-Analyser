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
    STRING = 261,                  /* STRING  */
    NEWLINE = 262,                 /* NEWLINE  */
    KEYWORD = 263,                 /* KEYWORD  */
    INTCONST = 264,                /* INTCONST  */
    PUNCTUATOR = 265,              /* PUNCTUATOR  */
    IDENTIFIER = 266,              /* IDENTIFIER  */
    AMPER = 267,                   /* AMPER  */
    EXCLA = 268,                   /* EXCLA  */
    KEYWORD_FUNC = 269,            /* KEYWORD_FUNC  */
    LOG_OR = 270,                  /* LOG_OR  */
    LOG_AND = 271,                 /* LOG_AND  */
    KEYWORD_VAR_TYPE = 272,        /* KEYWORD_VAR_TYPE  */
    PAR_START = 273,               /* PAR_START  */
    PAR_END = 274,                 /* PAR_END  */
    BRACES_START = 275,            /* BRACES_START  */
    BRACES_END = 276,              /* BRACES_END  */
    BRACKETS_START = 277,          /* BRACKETS_START  */
    BRACKETS_END = 278,            /* BRACKETS_END  */
    GREATER = 279,                 /* GREATER  */
    LESSER = 280,                  /* LESSER  */
    GREATER_EQ = 281,              /* GREATER_EQ  */
    LESSER_EQ = 282,               /* LESSER_EQ  */
    EQQ = 283,                     /* EQQ  */
    EQ = 284,                      /* EQ  */
    NEQ = 285,                     /* NEQ  */
    EQ_MULTI = 286,                /* EQ_MULTI  */
    EQ_DIV = 287,                  /* EQ_DIV  */
    EQ_PLUS = 288,                 /* EQ_PLUS  */
    EQ_MINUS = 289,                /* EQ_MINUS  */
    PLUS = 290,                    /* PLUS  */
    PLUSPLUS = 291,                /* PLUSPLUS  */
    MINUS = 292,                   /* MINUS  */
    MINUSMINUS = 293,              /* MINUSMINUS  */
    DIV = 294,                     /* DIV  */
    MOD = 295,                     /* MOD  */
    MULTI = 296,                   /* MULTI  */
    POW = 297                      /* POW  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BISON_SA_TAB_H_INCLUDED  */
