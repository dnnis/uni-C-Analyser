/* Onoma arxeiou:       simple-bison-code.y
   Perigrafh:           Ypodeigma gia anaptyksh syntaktikou analyth me xrhsh tou ergaleiou Bison
   Syggrafeas:          Ergasthrio Metaglwttistwn, Tmhma Mhxanikwn Plhroforikhs kai Ypologistwn,
                        Panepisthmio Dytikhs Attikhs
   Sxolia:              To paron programma ylopoiei (me th xrhsh Bison) enan aplo syntaktiko analyth
            pou anagnwrizei thn prosthesh akeraiwn arithmwn (dekadikou systhmatos) & metablhtwn
            kai ektypwnei to apotelesma sthn othonh (thewrontas oti oi metablhtes exoun
            panta thn timh 0). Leitourgei autonoma, dhladh xwris Flex kai anagnwrizei kena
            (space & tab), akeraious (dekadikou systhmatos) kai onomata metablhtwn ths glwssas
            Uni-C enw diaxeirizetai tous eidikous xarakthres neas grammhs '\n' (new line)
            kai 'EOF' (end of file). Kathara gia logous YYDEBUGging typwnei sthn othonh otidhpote
            epistrefei h synarthsh yylex().
   Odhgies ekteleshs:   Dinete "make" xwris ta eisagwgika ston trexonta katalogo. Enallaktika:
            bison -o simple-bison-code.c simple-bison-code.y
                        gcc -o simple-bison-code simple-bison-code.c
                        ./simple-bison-code
*/

%{
/* Orismoi kai dhlwseis glwssas C. Otidhpote exei na kanei me orismo h arxikopoihsh
   metablhtwn & synarthsewn, arxeia header kai dhlwseis #define mpainei se auto to shmeio */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int yylex(void);
extern int yyparse(void);
extern FILE *yyin;
void yyerror(char *);
int cor_words = 0;
int cor_expr = 0;
int inc_words = 0;
int inc_expr = 0;

%}

/*TODO:
    1. WRITE LOGIC FOR BRACKETS ( "[" and "]" )
    2. MAKE DEBUG MODE
    3. FLEX ANALYSES CHAR BY CHAR. MAKE CHANGES ON SA LOGIC (EQ_MINUS etc)
    4. DOCUMENTATION AND COMMENTS
*/

%union
{
    int    ival;
    char*  sval;
    float  fval;
    double dval;
}

/* Orismos twn anagnwrisimwn lektikwn monadwn. */
%token EOP
       <sval> SEMI
       <sval> COMMA
       <sval> FLOAT
       <dval> DOUBLE
       <fval> STRING
       <sval> NEWLINE
       <sval> KEYWORD
       <ival> INTCONST
       <sval> PUNCTUATOR
       <sval> IDENTIFIER
       <sval> AMPER EXCLA
       <sval> KEYWORD_RET
       <sval> KEYWORD_FUNC
       <sval> KEYWORD_VAR_TYPE
       <sval> PAR_START PAR_END
       <sval> BRACE_START BRACE_END
       <sval> LOGICAL_OR LOGICAL_AND
       <sval> BRACKET_START BRACKET_END
       <sval> GREATER LESSER GREATER_EQ LESSER_EQ
       <sval> EQQ EQ NEQ EQ_MULTI EQ_DIV EQ_PLUS EQ_MINUS
       <sval> PLUS PLUSPLUS MINUS MINUSMINUS DIV MOD MULTI POW
/* Orismos proteraiothtwn sta tokens */
%left  POW
%left  PLUS MINUS
%left  DIV MULTI

%%

/* Orismos twn grammatikwn kanonwn. Kathe fora pou antistoixizetai enas grammatikos
   kanonas me ta dedomena eisodou, ekteleitai o kwdikas C pou brisketai anamesa sta
   agkistra. H anamenomenh syntaksh einai: onoma : kanonas { kwdikas C } */
program:
        program valid
        |
        ;

// Εδώ ορίζεται το τι μπορεί να είναι κομμάτι μίας έκφρασης. Ένας χαρακτήρας ή ένας αριθμός
expr_part:
          FLOAT       { cor_words++; }
        | STRING      { cor_words++; }
        | DOUBLE      { cor_words++; }
        | KEYWORD     { cor_words++; }
        | INTCONST    { cor_words++; }
        | IDENTIFIER  { cor_words++; }
        ;

operator:
          EQ          { cor_words++; }
        | EQQ         { cor_words++; }
        | NEQ         { cor_words++; }
        | DIV         { cor_words++; }
        | POW         { cor_words++; }
        | PLUS        { cor_words++; }
        | MINUS       { cor_words++; }
        | MULTI       { cor_words++; }
        | EQ_DIV      { cor_words++; }
        | EQ_PLUS     { cor_words++; }
        | EQ_MULTI    { cor_words++; }
        | EQ_MINUS    { cor_words++; }
        ;

in_de_crement_operator:
        | MINUSMINUS  { cor_words++; }
        | PLUSPLUS    { cor_words++; }
        ;

// Εδώ ορίζονται ποιές είναι οι εκφράσεις υπο επεξεργασία
expr_proc:
          expr_part operator expr_part EQ expr_part
        | expr_part operator expr_part
        | expr_part in_de_crement_operator
        | in_de_crement_operator expr_part
        | KEYWORD_RET expr_part
        ;

// Εδώ ορίζεται το "σώμα" του κώδικα, δηλαδή ένας αριθμός συντακτικά σωστών εκφράσεων.
body:
        body valid
        | valid
        |
        ;

// Εδώ ορίζεται τι μπορεί να βρίσκεται μέσα σε αγκύλες
in_bra:
        BRACE_START body BRACE_END

// Εδώ ορίζεται τι μπορεί να είναι ορίσματα μιας συνάρτησης
arguments:
           arguments expr_part COMMA expr_part
         | expr_part COMMA expr_part
         |
         ;

// Εδώ ορίζεται τι θεωρείται ορισμός μιας συνάρτησης
func_par:
          KEYWORD_FUNC IDENTIFIER PAR_START arguments PAR_END {cor_expr++; printf("Valid arguments\n"); }
        | KEYWORD_FUNC IDENTIFIER PAR_START expr_part PAR_END {cor_expr++; printf("Valid argument\n" ); }
        ;

// Εδώ ορίζεται τι θεωρείται ορισμός μιας μεταβλητής
declaration:
          KEYWORD_VAR_TYPE IDENTIFIER
        | KEYWORD_VAR_TYPE IDENTIFIER EQ expr_proc
        ;

// Εδώ ορίζεται τι θεωρείται ανάθεση σε μεταβλητή
assignment:
          IDENTIFIER EQ expr_proc

// Εδώ ορίζεται τι θεωρείται συντακτικά σώστο
valid:
          expr_proc   SEMI { cor_expr++; printf("Valid expression!\n");           }
        | assignment  SEMI { cor_expr++; printf("Valid assignment!\n");           }
        | declaration SEMI { cor_expr++; printf("Valid declaration!\n");          }
        | in_bra           { cor_expr++; printf("Valid function body!\n");        }
        | func_par         { cor_expr++; printf("Valid function declaration!\n"); }
        | NEWLINE
        | EOP { print_report(cor_words,cor_expr); }
        ;

%%

/*
void print_scanner_ret(int line) {
    printf("Line %d: Scanner returned token: ",line);
}
*/

void print_report (int cor_words, int cor_expr) {
    printf(" /------- RUN REPORT: ------/\n"
           "* Number of correct words: %d\n"
           "* Number of correct expressions: %d\n"
           "* Number of incorrect words: %d\n"
           "* Number of incorrect expressions: %d\n"
           , cor_words, cor_expr, inc_words, inc_expr);
}

/* H synarthsh yyerror xrhsimopoieitai gia thn anafora sfalmatwn. Sygkekrimena kaleitai
   apo thn yyparse otan yparksei kapoio syntaktiko lathos. Sthn parakatw periptwsh h
   synarthsh epi ths ousias typwnei mhnyma lathous sthn othonh. */
void yyerror(char *s) {
    inc_words++;
    fprintf(stderr, "Error: %s\n", s);
}

/* H synarthsh main pou apotelei kai to shmeio ekkinhshs tou programmatos.
   Sthn sygkekrimenh periptwsh apla kalei thn synarthsh yyparse tou Bison
   gia na ksekinhsei h syntaktikh analysh. */
int main(void)  {
    //Αναγκαίες εντολές για να γίνεται το debugging στον Bison
    #ifdef YYDEBUG
      yydebug = 1;
    #endif
    // Open a file handle to a particular file:
    FILE *myfile = fopen("input.txt", "r");
    // Make sure it is valid:
    if (!myfile) {
      printf("* Error: cannot open the \"input.txt\" file!");
      return -1;
    }
    // Set Flex to read from it instead of defaulting to STDIN:
    yyin = myfile;
    yyparse();
    fclose(myfile);
}
