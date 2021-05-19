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
FLOAT                [0-9]+\.[0-9]+|[0-9]+\.[0-9]+e[0-9]+
INTCONST             0|[1-9]+[0-9]*
STRING               '.*'|\".*\"
IDENTIFIER           [a-zA-Z_]([0-9_a-zA-Z]*)
COMMENT              \/\*(.|\n)*?\*\/|\/\/.*
GREATER              \>
LESSER               \<
GREATER_EQ           \>=
LESSER_EQ            \<=
PLUS                 \+
MINUS                \-
MINUSMINUS           \-\-
EQQ                  ==
EQ                   =
EQ_MULTI             \*=
EQ_DIV               \/=
EQ_PLUS              \+=
EQ_MINUS             \-=
NEQ                  !=
PLUSPLUS             \+\+
MULTI                \*
LOG_OR               \|\|
LOG_AND              \&\&
AMPER                \&
EXCLA                \!
DIV                  \/
MOD                  \%
WHITE_SPACES         [ \t]+
BRACKETS_START       \[
BRACKETS_END         \]
BRACES_START         \{
BRACES_END           \}
PAR_START            \(
PAR_END              \)
PUNCTUATOR           #|\:|\~|\&|\^|\,

/* Gia kathe pattern (aristera) pou tairiazei ekteleitai o antistoixos
   kwdikas mesa sta agkistra. H entolh return epitrepei thn epistrofh
   mias arithmhtikhs timhs mesw ths synarthshs yylex() */

/* Σχόλιο Ομάδας 15
    Σημείωσεις για:
    - {IDENTIFIER} : Ο λεκτικός μας αναλυτής, πρώτα ανιχνεύει την συμβολοσειρά ως
                     identifier, και μετά ξεκαθαρίζει άμα είναι keyword ή απλά το
                     όνομα μιας μεταβλητής ή συνάρτησης.
    - {.} :          Ο λεκτικός μας αναλυτής, εφόσον ανιχνεύσει τα στοιχεία τα
                     οποία είναι άγνωστα, τα αναφέρει, και παρακάτω αναμένουμε
                     τον συντακτικό αναλυτή να αναφέρει ολοκληρωμένες συμβολοσειρές
                     που είναι λανθασμένες λόγω άγνωστου χαρακτήρα.
    - Σημεία Στίξης: Ο λεκτικός μας αναλυτής, ανιχνεύει επίσης και τα στοιχεία στίξης,
                     αυτά που είναι σημαντικότερα (παρενθέσεις, αγκύλες κτλ.) τα επιτρέφει
                     ως συγκεκριμένα token για ευκολία του συντακτικού αναλυτή.
                     Τα υπόλοιπα τα αναφέρει απλά σαν σημεία στίξης γιατί η κατανόηση
                     της ορθότητας τους είναι δουλειά που αναλαμβάνει ο συντακτικός αναλυτής,
                     καθώς απαιτεί συντακτική ανάλυση (επεξεργασία προηγούμενων και επόμενων
                     λέξεων, κτλ.) 
    - Κενά:          Ο λεκτικός μας αναλυτής αγνοεί τα κενά και τις κενές γραμμές, δεν
                     επιτρέφει token για αυτά για το συντακτικό αναλυτή. */
%%

{SEMI}          { return SEMI;      }
{FLOAT}         { return FLOAT;     }
{STRING}        { return STRING;    }
{INTCONST}      { return INTCONST;  }

{IDENTIFIER}    { 
                    if      ( !strcmp(yytext,"break"   ) )    return KEYWORD;
                    else if ( !strcmp(yytext,"case"    ) )    return KEYWORD;
                    else if ( !strcmp(yytext,"func"    ) )    return KEYWORD;
                    else if ( !strcmp(yytext,"const"   ) )    return KEYWORD;
                    else if ( !strcmp(yytext,"continue") )    return KEYWORD;
                    else if ( !strcmp(yytext,"do"      ) )    return KEYWORD;
                    else if ( !strcmp(yytext,"double"  ) )    return KEYWORD;
                    else if ( !strcmp(yytext,"else"    ) )    return KEYWORD;
                    else if ( !strcmp(yytext,"float"   ) )    return KEYWORD;
                    else if ( !strcmp(yytext,"for"     ) )    return KEYWORD;
                    else if ( !strcmp(yytext,"if"      ) )    return KEYWORD;
                    else if ( !strcmp(yytext,"int"     ) )    return KEYWORD;
                    else if ( !strcmp(yytext,"long"    ) )    return KEYWORD;
                    else if ( !strcmp(yytext,"return"  ) )    return KEYWORD;
                    else if ( !strcmp(yytext,"short"   ) )    return KEYWORD;
                    else if ( !strcmp(yytext,"sizeof"  ) )    return KEYWORD;
                    else if ( !strcmp(yytext,"struct"  ) )    return KEYWORD;
                    else if ( !strcmp(yytext,"switch"  ) )    return KEYWORD;
                    else if ( !strcmp(yytext,"void"    ) )    return KEYWORD;
                    else if ( !strcmp(yytext,"while"   ) )    return KEYWORD;
                    else return IDENTIFIER;
                }

{GREATER}            { return GREATER   ;                   }
{LESSER}             { return LESSER    ;                   }
{LESSER_EQ}          { return LESSER_EQ ;                   }
{GREATER_EQ}         { return GREATER_EQ;                   }
{PLUS}               { return PLUS      ;                   }
{PLUSPLUS}           { return PLUSPLUS  ;                   }
{MINUS}              { return MINUS     ;                   }
{MINUSMINUS}         { return MINUSMINUS;                   }
{EQ}                 { return EQ        ;                   }
{NEQ}                { return NEQ       ;                   }
{EQQ}                { return EQQ       ;                   }
{EQ_DIV}             { return EQ_DIV    ;                   }
{EQ_PLUS}            { return EQ_PLUS   ;                   }
{EQ_MINUS}           { return EQ_MINUS  ;                   }
{EQ_MULTI}           { return EQ_MULTI  ;                   }
{MULTI}              { return MULTI     ;                   }
{LOG_OR}             { return LOG_OR    ;                   }
{LOG_AND}            { return LOG_AND   ;                   }
{AMPER}              { return AMPER     ;                   }
{EXCLA}              { return EXCLA     ;                   }
{DIV}                { return DIV       ;                   }
{MOD}                { return MOD       ;                   }
{WHITE_SPACES}       { /*Do nothing, white space(s)*/       }
{COMMENT}            { /*Do nothing, comment detected*/     }
{BRACKETS_START}     { return BRACKETS_START;               }
{BRACKETS_END}       { return BRACKETS_END;                 }
{BRACES_START}       { return BRACES_START;                 }
{BRACES_END}         { return BRACES_END;                   }
{PAR_START}          { return PAR_START;                    }
{PAR_END}            { return PAR_END;                      }
{PUNCTUATOR}         { return PUNCTUATOR;                   }
\n                   { line++;                              }
<<EOF>>              { printf("#END-OF-FILE#\n"); exit(0);  }
.                    {
                     fprintf(yyout, "Line=%d, UNKNOWN TOKEN, value=\"%s\"\n", line, yytext);
                     }
%%

/* H synarthsh main: O kwdikas autos tha topotheththei autousios sto
   programma C pou tha dhmiourghsei to Flex kai tha apotelesei to arxiko
   shmeio ekteleshs ths efarmoghs tou lektikou analyth. */

int main(int argc, char **argv){
        int token;

        /* H synarthsh yylex diabazei xarakthres apo thn eisodo kai prospathei
           na angnwrisei tokens. Ta tokens pou anagnwrizei einai auta pou exoun
           oristei sto paron arxeio, anamesa sta %% kai %%. An o kwdikas pou
           antistoixei se kapoio pattern periexei thn entolh 'return TIMH', h
           yylex() epistrefei thn timh auth h opoia kai apothhkeyetai sth
           metablhth token. */

        while( (token=yylex()) >= 0 ){
                /* Gia kathe token pou anagnwristhke, ektypwnetai h grammh pou auto
                   brethhke kathws kai to onoma tou mazi me thn timh tou. */
                fprintf(yyout, "* From FLEX: Line=%d, value=\"%s\"\n", line, yytext);
        }
        return 0;
}
