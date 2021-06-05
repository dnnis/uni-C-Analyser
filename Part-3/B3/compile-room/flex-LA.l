/*
    * Ομάδα 15

    Όνομα αρχείου:      uni_c_analyser.c
    Περιγραφή:          Λεκτικός Αναλυτής για την γλώσσα προγραμματισμού Uni-C
    Συγγραφείς:         ΟΜΑΔΑ 15:
                        Διονύσης Νικολόπουλος
                        Αθανάσιος Αναγνωστόπουλος
                        Άριστείδης Αναγνωστόπουλος
                        Σπυρίδων Φλώρος
    Σχόλια:             Κάποια σχόλια έχουν γίνει πάνω στον κώδικα, αλλά ο
                        κώδικας επίσης εξηγήται στο PDF της εργασίας.
    Οδηγίες Εκτέλεσης:  Λόγω της υλοποίησης makefile, τρέχετε απλά την εντολή
                        make στον τρέχοντα κατάλογο που βρίσκεται το αρχέιο.
*/

/* H anagnwsh periorizetai se ena mono arxeio kai termatizei sto prwto EOF */
%option noyywrap

/* Kwdikas C gia orismo twn apaitoumenwn header files kai twn metablhtwn.
   Otidhpote anamesa sta %{ kai %} metaferetai autousio sto arxeio C pou
   tha dhmiourghsei to Flex. */

%{

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bison-SA.tab.h"

// Για να μετράμε τις κολόνες
int columns = 1;
// Για να καταφέρνουμε να δίνουμε στον χρήστη σωστό output.
char panic_cause_char[100];

%}
/* Onomata kai antistoixoi orismoi (ypo morfh kanonikhs ekfrashs).
   Meta apo auto, mporei na ginei xrhsh twn onomatwn (aristera) anti twn,
   synhthws idiaiterws makroskelwn kai dysnohtwn, kanonikwn ekfrasewn */

SEMI                 ;
HASH                 #
TILDE                ~
NEQ                  !=
MOD                  \%
POW                  \^
COMMA                \,
COLON                \:
AMPER                \&
PAR_END              \)
PAR_START            \(
BRACE_END            \}
BRACE_START          \{
BRACKET_END          \]
BRACKET_START        \[
LOGICAL_OR           \|\|
TYPE_EQ              ==?
TYPE_DIV             \/=?
TYPE_MULTI           \*=?
TYPE_EXCLA           \!=?
TYPE_AMPER           \&\&
TYPE_LESSER          \<=?
TYPE_GREATER         \>=?
WHITESPACE           [ \t]
TYPE_PLUS            \+[\+=]?
TYPE_MINUS           \-[\-=]?
STRING               '.*'|\".*\"
INTCONST             0|[1-9]+[0-9]*
COMMENT              \/\*(.|\n)*?\*\/|\/\/.*
IDENTIFIER           [a-zA-Z_]([0-9_a-zA-Z]*)
FLOAT                [0-9]+\.[0-9]+|[0-9]+\.[0-9]+e[0-9]+

%x REALLYEND
%x PREPANIC
%x PANIC

/* Gia kathe pattern (aristera) pou tairiazei ekteleitai o antistoixos
   kwdikas mesa sta agkistra. H entolh return epitrepei thn epistrofh
   mias arithmhtikhs timhs mesw ths synarthshs yylex() */

/* Σχόλιο Ομάδας 15
    Σημείωσεις για:
    -{IDENTIFIER} : Ο λεκτικός μας αναλυτής, πρώτα ανιχνεύει την συμβολοσειρά
                    ως identifier, και μετά ξεκαθαρίζει άμα είναι keyword ή
                    απλά το όνομα μιας μεταβλητής ή συνάρτησης.
    -{.} :          Ο λεκτικός μας αναλυτής, εφόσον ανιχνεύσει τα στοιχεία τα
                    οποία είναι άγνωστα, τα αναφέρει, και παρακάτω αναμένουμε
                    τον συντακτικό αναλυτή να αναφέρει ολοκληρωμένες 
                    συμβολοσειρές που είναι λανθασμένες λόγω άγνωστου χαρακτήρα.
    -Σημεία Στίξης: Ο λεκτικός μας αναλυτής, ανιχνεύει επίσης και τα στοιχεία
                    στίξης, αυτά που είναι σημαντικότερα (παρενθέσεις, αγκύλες
                    κτλ.) τα επιτρέφει ως συγκεκριμένα token για ευκολία του
                    συντακτικού αναλυτή.  Τα υπόλοιπα τα αναφέρει απλά σαν
                    σημεία στίξης γιατί η κατανόηση της ορθότητας τους είναι
                    δουλειά που αναλαμβάνει ο συντακτικός αναλυτής, καθώς
                    απαιτεί συντακτική ανάλυση (επεξεργασία προηγούμενων και
                    επόμενων λέξεων, κτλ.)
    -Κενά:          Ο λεκτικός μας αναλυτής αγνοεί τα κενά και τις κενές
                    γραμμές, δεν επιτρέφει token για αυτά για το συντακτικό
                    αναλυτή. */
%%
{MOD}           {  columns++; return MOD;                     }
{POW}           {  columns++; return POW;                     }
{SEMI}          {  columns++; return SEMI;                    }
{COMMA}         {  columns++; return COMMA;                   }
{PAR_END}       {  columns++; return PAR_END;                 }
{PAR_START}     {  columns++; return PAR_START;               }
{BRACE_END}     {  columns++; return BRACE_END;               }
{LOGICAL_OR}    {  columns++; return LOGICAL_OR;              }
{BRACE_START}   {  columns++; return BRACE_START;             }
{BRACKET_END}   {  columns++; return BRACKET_END;             }
{BRACKET_START} {  columns++; return BRACKET_START;           }
{FLOAT}         {  columns += strlen(yytext); return FLOAT;   }
{STRING}        {  columns += strlen(yytext); return STRING;  }
{INTCONST}      {  columns += strlen(yytext); return INTCONST;}
{IDENTIFIER}    {
      if      ( !strcmp(yytext,"do"      ) ) { columns += strlen(yytext); return KEYWORD;}
      else if ( !strcmp(yytext,"void"    ) ) { columns += strlen(yytext); return KEYWORD;}
      else if ( !strcmp(yytext,"while"   ) ) { columns += strlen(yytext); return KEYWORD;}
      else if ( !strcmp(yytext,"break"   ) ) { columns += strlen(yytext); return KEYWORD;}
      else if ( !strcmp(yytext,"sizeof"  ) ) { columns += strlen(yytext); return KEYWORD;}
      else if ( !strcmp(yytext,"struct"  ) ) { columns += strlen(yytext); return KEYWORD;}
      else if ( !strcmp(yytext,"if"      ) ) { columns += strlen(yytext); return KEYWORD_IF;}
      else if ( !strcmp(yytext,"for"     ) ) { columns += strlen(yytext); return KEYWORD_FOR;}
      else if ( !strcmp(yytext,"return"  ) ) { columns += strlen(yytext); return KEYWORD_RET;}
      else if ( !strcmp(yytext,"case"    ) ) { columns += strlen(yytext); return KEYWORD_CASE;}
      else if ( !strcmp(yytext,"else"    ) ) { columns += strlen(yytext); return KEYWORD_ELSE;}
      else if ( !strcmp(yytext,"func"    ) ) { columns += strlen(yytext); return KEYWORD_FUNC;}
      else if ( !strcmp(yytext,"include" ) ) { columns += strlen(yytext); return KEYWORD_INCL;}
      else if ( !strcmp(yytext,"continue") ) { columns += strlen(yytext); return KEYWORD_CONT;}
      else if ( !strcmp(yytext,"switch"  ) ) { columns += strlen(yytext); return KEYWORD_SWITCH;}
      else if ( !strcmp(yytext,"int"     ) ) { columns += strlen(yytext); return KEYWORD_VAR_TYPE;}
      else if ( !strcmp(yytext,"long"    ) ) { columns += strlen(yytext); return KEYWORD_VAR_TYPE;}
      else if ( !strcmp(yytext,"short"   ) ) { columns += strlen(yytext); return KEYWORD_VAR_TYPE;}
      else if ( !strcmp(yytext,"float"   ) ) { columns += strlen(yytext); return KEYWORD_VAR_TYPE;}
      else if ( !strcmp(yytext,"const"   ) ) { columns += strlen(yytext); return KEYWORD_VAR_TYPE;}
      else if ( !strcmp(yytext,"double"  ) ) { columns += strlen(yytext); return KEYWORD_VAR_TYPE;}
      else                                   { columns += strlen(yytext); return IDENTIFIER;}
}
{TYPE_EXCLA}    { if (!strcmp(yytext, "!=")) { columns += 2; return NEQ;        } else    { columns++; return EXCLA;  }}
{TYPE_EQ}       { if (!strcmp(yytext, "==")) { columns += 2; return EQQ;        } else    { columns++; return EQ;     }}
{TYPE_DIV}      { if (!strcmp(yytext, "/=")) { columns += 2; return EQ_DIV;     } else    { columns++; return DIV;    }}
{TYPE_MULTI}    { if (!strcmp(yytext, "*=")) { columns += 2; return EQ_MULTI;   } else    { columns++; return MULTI;  }}
{TYPE_LESSER}   { if (!strcmp(yytext, "<=")) { columns += 2; return LESSER_EQ;  } else    { columns++; return LESSER; }}
{TYPE_GREATER}  { if (!strcmp(yytext, ">=")) { columns += 2; return GREATER_EQ; } else    { columns++; return GREATER;}}
{TYPE_AMPER}    { if (!strcmp(yytext, "&&")) { columns += 2; return LOGICAL_AND;} else    { columns++; return AMPER;  }}
{TYPE_MINUS}    { if (!strcmp(yytext, "--")) { columns += 2; return MINUSMINUS; } else if (!strcmp(yytext, "-=")) { columns+=2; return EQ_MINUS; } else { columns++; return MINUS;}}
{TYPE_PLUS}     { if (!strcmp(yytext, "++")) { columns += 2; return PLUSPLUS;   } else if (!strcmp(yytext, "+=")) { columns+=2; return EQ_PLUS;  } else { columns++; return PLUS; }}
{WHITESPACE}    { columns++; }
{COMMENT}       { /*Do nothing, comment*/ }
\n              { columns=1; /*Start from zero cols again*/ return NEWLINE; }
 /*Εδώ το flex "πιάνει" οποιονδήποτε άλλο χαρακτήρα που δεν περιγράφεται απο
  τις παραπάνω κανονικές εκφράσεις.*/
<INITIAL>.  { BEGIN(PREPANIC); strcpy(panic_cause_char,yytext); return UNKNOWN;}
<PREPANIC>. { BEGIN(PANIC); printf("Column: %d Unknown word: '%s%s",columns,panic_cause_char,yytext);}
<PANIC>{WHITESPACE} { columns++; printf("'\n"); BEGIN(INITIAL);}
<PANIC>\n           { columns=1; printf("'\n"); BEGIN(INITIAL);}
<PANIC>.            { ECHO; }
 /*Εδώ καλούμε ένα τμήμα κώδικα που μας βοηθά να δώσουμε ένα token στον bison
  για να δηλώσουμε το τέλος του αρχείου, αποτρέποντας όμως τον bison να
  τερματίζει άμεσα την εκτέλεση. Έτσι, καταφέρνουμε να εκτελούμε την συνάρτηση
  print_report() στο bison-SA.y, για να ανεφέρουμε τον αριθμό των σωστών και
  λανθασμένων λέξεων και εκφράσεων.*/
<INITIAL><<EOF>>  { BEGIN(REALLYEND); return EOP; }
 /*Εδώ, μετά την πάροδο των προηγούμενων, "πραγματικά" τερματίζουμε την
  εκτέλεση του flex, έχουμε ήδη τυπώσει την αναφορά με την print_report() με το
  bison, και αρχίζουμε να τερματίζουμε το πρόγραμμα συνολικά.*/
<REALLYEND><<EOF>> {yyterminate();}
%%
/* Το πρόγραμμα αυτό δεν έχει main(), καθώς δεν τρέχει αυτόνομα, είναι απλά ο
   λεκτικός αναλυτής, η συντακτική ανάλυση γίνεται από τον bison. */
