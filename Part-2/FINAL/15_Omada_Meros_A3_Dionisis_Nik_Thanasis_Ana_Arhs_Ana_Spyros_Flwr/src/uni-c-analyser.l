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

/* Header file pou periexei lista me ola ta tokens */
#include "token.h"

/* Orismos metrhth trexousas grammhs */
int line = 1;

%}


/* Onomata kai antistoixoi orismoi (ypo morfh kanonikhs ekfrashs).
   Meta apo auto, mporei na ginei xrhsh twn onomatwn (aristera) anti twn,
   synhthws idiaiterws makroskelwn kai dysnohtwn, kanonikwn ekfrasewn */

DELIMITER            ;
FLOAT                [0-9]+\.[0-9]+|[0-9]+\.[0-9]+e[0-9]+
INTCONST             0|[1-9]+[0-9]*
STRING               '.*'|\".*\"
IDENTIFIER           [a-zA-Z_]([0-9_a-zA-Z]*)
COMMENT              \/\*(.|\n)*?\*\/|\/\/.*
OPERATOR             \+|\-|==|!=|\+\+|\*|\|\||\!|\&|\/|\%|=|\*=|\/=|\&\&|\-\-|\<|\>|\<=|\>=|\+=|\-=
WHITE_SPACES         [ \t]+
OPEN_BRACKETS        \[
CLOSE_BRACKETS       \]
OPEN_BRACES          \{
CLOSE_BRACES         \}
OPEN_PARENTHESES     \(
CLOSE_PARENTHESES    \)
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

{DELIMITER}     { return DELIMITER; }
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

{OPERATOR}           { return OPERATOR;                     }
{WHITE_SPACES}       { /*Do nothing, white space(s)*/       }
{COMMENT}            { /*Do nothing, comment detected*/     }
{OPEN_BRACKETS}      { return OPEN_BRACKETS;                }
{CLOSE_BRACKETS}     { return CLOSE_BRACKETS;               }
{OPEN_BRACES}        { return OPEN_BRACES;                  }
{CLOSE_BRACES}       { return CLOSE_BRACES;                 }
{OPEN_PARENTHESES}   { return OPEN_PARENTHESES;             }
{CLOSE_PARENTHESES}  { return CLOSE_PARENTHESES;            }
{PUNCTUATOR}         { return PUNCTUATOR;                   }
\n                   { line++;                              }
<<EOF>>              { printf("#END-OF-FILE#\n"); exit(0);  }
.                    { 
                     fprintf(yyout, "Line=%d, UNKNOWN TOKEN, value=\"%s\"\n", line, yytext);
                     }
%%

/* Pinakas me ola ta tokens se antistoixia me tous orismous sto token.h */
char *tname[16] = {"DELIMITER","INTCONST","FLOAT", "STRING", "IDENTIFIER" , "COMMENT", "WHITE_SPACES", "OPERATOR", "KEYWORD", "OPEN_BRACKETS", "CLOSE_BRACKETS", "OPEN_BRACES", "CLOSE_BRACES", "OPEN_PARENTHESES", "CLOSE_PARENTHESES", "PUNCTUATOR"};


/* H synarthsh main: O kwdikas autos tha topotheththei autousios sto
   programma C pou tha dhmiourghsei to Flex kai tha apotelesei to arxiko
   shmeio ekteleshs ths efarmoghs tou lektikou analyth. */

int main(int argc, char **argv){
        int token;

        /* Ginetai o elegxos twn orismatwn ths grammhs entolwn. Ean ta
           orismata einai 3, to programma diabazei apo to arxeio tou 2ou
           orismatos kai grafei sto arxeio tou 3ou. Ean ta orismata einai
           2 diabazei apo to arxeio tou 2ou kai grafei sthn othonh.
           Ypenthymizetai oti to 1o orisma (argv[0]) sth C einai to onoma
           tou idiou tou ektelesimou arxeiou. */

        if(argc == 3){
                if(!(yyin = fopen(argv[1], "r"))) {
                        fprintf(stderr, "Cannot read file: %s\n", argv[1]);
                        return 1;
                }
                if(!(yyout = fopen(argv[2], "w"))) {
                        fprintf(stderr, "Cannot create file: %s\n", argv[2]);
                        return 1;
                }
        }
        else if(argc == 2){
                if(!(yyin = fopen(argv[1], "r"))) {
                        fprintf(stderr, "Cannot read file: %s\n", argv[1]);
                        return 1;
                }
        }

        /* H synarthsh yylex diabazei xarakthres apo thn eisodo kai prospathei
           na angnwrisei tokens. Ta tokens pou anagnwrizei einai auta pou exoun
           oristei sto paron arxeio, anamesa sta %% kai %%. An o kwdikas pou
           antistoixei se kapoio pattern periexei thn entolh 'return TIMH', h
           yylex() epistrefei thn timh auth h opoia kai apothhkeyetai sth
           metablhth token. */

        while( (token=yylex()) >= 0){
                /* Gia kathe token pou anagnwristhke, ektypwnetai h grammh pou auto
                   brethhke kathws kai to onoma tou mazi me thn timh tou. */
                fprintf(yyout, "Line=%d, token=%s, value=\"%s\"\n", line, tname[token-1], yytext);
        }
        return 0;
}
