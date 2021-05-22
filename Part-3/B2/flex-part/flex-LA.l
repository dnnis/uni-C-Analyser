/*
    Ομάδα 15

    Όνομα αρχείου:      uni_c_analyser.c
    Περιγραφή:          Λεκτικός Αναλυτής για την γλώσσα προγραμματισμού Uni-C 
    Συγγραφείς:         Διονύσης Νικολόπουλος
                        Αθανάσιος Αναγνωστόπουλος
                        Άριστείδης Αναγνωστόπουλος
                        Σπυρίδων Φλώρος
    Σχόλια:             Κάποια σχόλια έχουν γίνει πάνω στον κώδικα, αλλά ο κώδικας επίσης εξηγήται στο PDF της εργασίας.
    Οδηγίες Εκτέλεσης:  Λόγω της υλοποίησης makefile, τρέχετε απλά την εντολή make στον τρέχοντα κατάλογο που βρίσκεται το αρχέιο. Εναλλακτικά:
                        flex -o uni-c-analyser.c uni-c-analyser.l
                        gcc -o uni-c-analyser uni-c-analyser.c
                        ./uni-c-analyser
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

/* Orismos metrhth trexousas grammhs */
int line = 1;

%}
/* Onomata kai antistoixoi orismoi (ypo morfh kanonikhs ekfrashs).
   Meta apo auto, mporei na ginei xrhsh twn onomatwn (aristera) anti twn,
   synhthws idiaiterws makroskelwn kai dysnohtwn, kanonikwn ekfrasewn */

SEMI                 ;
NEQ                  !=
MOD                  \%
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
WHITESPACE           [ \t]+
TYPE_PLUS            \+[\+=]?
TYPE_MINUS           \-[\-=]?
STRING               '.*'|\".*\"
INTCONST             0|[1-9]+[0-9]*
PUNCTUATOR           #|\:|\~|\&|\^|\,
COMMENT              \/\*(.|\n)*?\*\/|\/\/.*
IDENTIFIER           [a-zA-Z_]([0-9_a-zA-Z]*)
FLOAT                [0-9]+\.[0-9]+|[0-9]+\.[0-9]+e[0-9]+

/* Gia kathe pattern (aristera) pou tairiazei ekteleitai o antistoixos
   kwdikas mesa sta agkistra. H entolh return epitrepei thn epistrofh
   mias arithmhtikhs timhs mesw ths synarthshs yylex() */

/* Σχόλιο Ομάδας 15
    Σημείωσεις για:
    -{IDENTIFIER} : Ο λεκτικός μας αναλυτής, πρώτα ανιχνεύει την συμβολοσειρά ως
                    identifier, και μετά ξεκαθαρίζει άμα είναι keyword ή απλά το
                    όνομα μιας μεταβλητής ή συνάρτησης.
    -{.} :          Ο λεκτικός μας αναλυτής, εφόσον ανιχνεύσει τα στοιχεία τα
                    οποία είναι άγνωστα, τα αναφέρει, και παρακάτω αναμένουμε
                    τον συντακτικό αναλυτή να αναφέρει ολοκληρωμένες συμβολοσειρές
                    που είναι λανθασμένες λόγω άγνωστου χαρακτήρα.
    -Σημεία Στίξης: Ο λεκτικός μας αναλυτής, ανιχνεύει επίσης και τα στοιχεία στίξης,
                    αυτά που είναι σημαντικότερα (παρενθέσεις, αγκύλες κτλ.) τα επιτρέφει
                    ως συγκεκριμένα token για ευκολία του συντακτικού αναλυτή.
                    Τα υπόλοιπα τα αναφέρει απλά σαν σημεία στίξης γιατί η κατανόηση
                    της ορθότητας τους είναι δουλειά που αναλαμβάνει ο συντακτικός αναλυτής,
                    καθώς απαιτεί συντακτική ανάλυση (επεξεργασία προηγούμενων και επόμενων
                    λέξεων, κτλ.) 
    -Κενά:          Ο λεκτικός μας αναλυτής αγνοεί τα κενά και τις κενές γραμμές, δεν
                    επιτρέφει token για αυτά για το συντακτικό αναλυτή. */
%%
{MOD}           {   return MOD;            }
{SEMI}          {   return SEMI;           }
{FLOAT}         {   return FLOAT;          }
{STRING}        {   return STRING;         }
{PAR_END}       {   return PAR_END;        }
{INTCONST}      {   return INTCONST;       }
{PAR_START}     {   return PAR_START;      }
{BRACE_END}     {   return BRACE_END;      }
{LOGICAL_OR}    {   return LOGICAL_OR;     }
{PUNCTUATOR}    {   return PUNCTUATOR;     }
{BRACE_START}   {   return BRACE_START;    }
{BRACKET_END}   {   return BRACKET_END;    }
{BRACKET_START} {   return BRACKET_START;  }
{IDENTIFIER}    {
                    if      ( !strcmp(yytext,"if"      ) ) return KEYWORD;
                    else if ( !strcmp(yytext,"do"      ) ) return KEYWORD;
                    else if ( !strcmp(yytext,"for"     ) ) return KEYWORD;
                    else if ( !strcmp(yytext,"int"     ) ) return KEYWORD;
                    else if ( !strcmp(yytext,"case"    ) ) return KEYWORD;
                    else if ( !strcmp(yytext,"long"    ) ) return KEYWORD;
                    else if ( !strcmp(yytext,"void"    ) ) return KEYWORD;
                    else if ( !strcmp(yytext,"while"   ) ) return KEYWORD;
                    else if ( !strcmp(yytext,"break"   ) ) return KEYWORD;
                    else if ( !strcmp(yytext,"float"   ) ) return KEYWORD;
                    else if ( !strcmp(yytext,"const"   ) ) return KEYWORD;
                    else if ( !strcmp(yytext,"short"   ) ) return KEYWORD;
                    else if ( !strcmp(yytext,"double"  ) ) return KEYWORD;
                    else if ( !strcmp(yytext,"return"  ) ) return KEYWORD;
                    else if ( !strcmp(yytext,"sizeof"  ) ) return KEYWORD;
                    else if ( !strcmp(yytext,"struct"  ) ) return KEYWORD;
                    else if ( !strcmp(yytext,"switch"  ) ) return KEYWORD;
                    else if ( !strcmp(yytext,"continue") ) return KEYWORD;
                    else if ( !strcmp(yytext,"func"    ) ) return KEYWORD_FUNC;
                    else return IDENTIFIER;
                }
{TYPE_EXCLA}    {
                    if (!strcmp(yytext, "!=")) return NEQ;
                    else return EXCLA;
                }
{TYPE_EQ}       {
                    if (!strcmp(yytext, "==")) return EQQ;
                    else return EQ;
                }
{TYPE_DIV}      {
                    if (!strcmp(yytext, "/=")) return EQ_DIV;
                    else return DIV;
                }
{TYPE_MULTI}    {
                    if (!strcmp(yytext, "*=")) return EQ_MULTI;
                    else return MULTI;
                }
{TYPE_LESSER}   {
                    if (!strcmp(yytext, "<=")) return LESSER_EQ;
                    else return LESSER;
                }
{TYPE_GREATER}  {
                    if (!strcmp(yytext, ">=")) return GREATER_EQ;
                    else return GREATER;
                }
{TYPE_AMPER}    {
                    if (!strcmp(yytext, "&&")) return LOGICAL_AND;
                    else return AMPER;
                }
{TYPE_MINUS}    {
                    if      (!strcmp(yytext, "--")) return MINUSMINUS;
                    else if (!strcmp(yytext, "-=")) return EQ_MINUS;
                    else return MINUS;
                }
{TYPE_PLUS}     {
                    if      (!strcmp(yytext, "++")) return PLUSPLUS;
                    else if (!strcmp(yytext, "+=")) return EQ_PLUS;
                    else return EQ_PLUS;
                }
{WHITESPACE}    { /*Do nothing, whitespace*/ }
{COMMENT}       { /*Do nothing, comment*/    }
\n              { line++;                    }
<<EOF>>         { printf("#END-OF-FILE#\n"); exit(0); }
.               { fprintf(yyout, "Line=%d, UNKNOWN TOKEN, value=\"%s\"\n", line, yytext); }
%%

/* H synarthsh main: O kwdikas autos tha topotheththei autousios sto
   programma C pou tha dhmiourghsei to Flex kai tha apotelesei to arxiko
   shmeio ekteleshs ths efarmoghs tou lektikou analyth. 
int main (int argc, char **argv)
{
    int token;
    while( (token=yylex()) >= 0 )
    {
        fprintf(yyout, "* From FLEX: Line=%d, value=\"%s\"\n", line, yytext);
    }
    return 0;
}
*/
