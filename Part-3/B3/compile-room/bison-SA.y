/* Όνομα αρχείου:      bison-SA.y
   Περιγραφή:          Αυτό είναι το αρχείο με το οποίο ορίζουμε τις
                       λειτουργίες του συντακτικού μας αναλυτή,
                       υλοποιημένο σε GNU Bison.
   Συγγραφείς:         ΟΜΑΔΑ 15:
                        Διονύσης Νικολόπουλος
                        Αθανάσιος Αναγνωστόπουλος
                        Άριστείδης Αναγνωστόπουλος
                        Σπυρίδων Φλώρος
   Σχόλια:             Κάποια σχόλια έχουν γίνει πάνω στον κώδικα, αλλά ο
                       κώδικας επίσης εξηγήται στο PDF της εργασίας.
   Οδηγίες Εκτέλεσης:
*/

%{
/* Orismoi kai dhlwseis glwssas C. Otidhpote exei na kanei me orismo h
   arxikopoihsh metablhtwn & synarthsewn, arxeia header kai dhlwseis #define
   mpainei se auto to shmeio */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int yylex(void);
extern int yyparse(void);
void yyerror(char *);
void print_report(int,int);
void print_valid (char *);
// Αρχικοποιούμε τον pointer για τη εισαγωγή δεδομένων με αρχείο και όχι απο το
// stdin
extern FILE *yyin;
// Αρχικοποιούμε τις μεταβλητές για το άθροισμα των σωστών και λάθος εκφράσεων
int cor_expr  = 0;
int inc_expr  = 0;
// Για την γραμμή που αρχίζει μία συνάρτηση
int brack_start_line=0;

int function_start_line=0;
int function_started_flag=0;

int struct_start_line=0;
int struct_started_flag=0;
// Για την μέτρηση γραμμών
int line=1;
%}

/*TODO:
    1. DOCUMENTATION AND COMMENTS
    2. line counting etc?
*/

%union
{
    int    ival;
    char*  sval;
    float  fval;
    double dval;
}

// Ορισμός των λεκτικών μονάδων
%token EOP
    UNKNOWN
    <sval> DOT
    <sval> SEMI
    <sval> HASH
    <sval> COLON
    <sval> COMMA
    <sval> FLOAT
    <dval> DOUBLE
    <fval> STRING
    <sval> NEWLINE
    <sval> KEYWORD
    <ival> INTCONST
    <sval> IDENTIFIER
    <sval> KEYWORD_IF
    <sval> AMPER EXCLA
    <sval> KEYWORD_RET
    <sval> KEYWORD_FOR
    <sval> KEYWORD_STR
    <sval> KEYWORD_ELSE
    <sval> KEYWORD_SIZE
    <sval> KEYWORD_CONT
    <sval> KEYWORD_CASE
    <sval> KEYWORD_INCL
    <sval> KEYWORD_FUNC
    <sval> KEYWORD_SWITCH
    <sval> KEYWORD_VAR_TYPE
    <sval> PAR_START PAR_END
    <sval> BRACE_START BRACE_END
    <sval> LOGICAL_OR LOGICAL_AND
    <sval> BRACKET_START BRACKET_END
    <sval> GREATER LESSER GREATER_EQ LESSER_EQ
    <sval> EQQ EQ NEQ EQ_MULTI EQ_DIV EQ_PLUS EQ_MINUS
    <sval> PLUS PLUSPLUS MINUS MINUSMINUS DIV MOD MULTI POW

// Ορισμός προτεραιώτητας στα tokens
%left  POW
%left  PLUS MINUS
%left  DIV MULTI

%%

/* Orismos twn grammatikwn kanonwn. Kathe fora pou antistoixizetai enas
   grammatikos kanonas me ta dedomena eisodou, ekteleitai o kwdikas C pou
   brisketai anamesa sta agkistra. H anamenomenh syntaksh einai: onoma :
   kanonas { kwdikas C } */
program:
    program valid
    |
    ;


/* Εδώ ορίζεται το τι μπορεί να είναι κομμάτι μίας έκφρασης.
   Ένας χαρακτήρας ή ένας αριθμός */
expr_part:
      FLOAT
    | STRING
    | DOUBLE
    | KEYWORD
    | INTCONST
    | IDENTIFIER
    | UNKNOWN { printf("X\tLine:  %d \t",line); }
    ;

operator:
      EQ
    | EQQ
    | NEQ
    | DIV
    | POW
    | PLUS
    | MINUS
    | MULTI
    | EQ_DIV
    | EQ_PLUS
    | EQ_MULTI
    | EQ_MINUS
    ;

in_de_crement_operator:
    | MINUSMINUS
    | PLUSPLUS
    ;

// Εδώ ορίζονται ποιές είναι οι εκφράσεις υπο επεξεργασία
expr_proc:
      expr_part operator expr_part EQ expr_part
    | expr_part operator expr_part
    | expr_part in_de_crement_operator
    | in_de_crement_operator expr_part
    ;

/* Εδώ ορίζεται το "σώμα" του κώδικα, δηλαδή ένας αριθμός συντακτικά
   σωστών εκφράσεων. */
body:
    body valid
    | valid
    |
    ;

elements:
    expr_part COMMA elements
    | expr_part
    ;

// Εδώ ορίζεται τι μπορεί να βρίσκεται μέσα σε αγγύλες
in_brack:
    BRACKET_START elements BRACKET_END

// Εδώ ορίζεται τι μπορεί να βρίσκεται μέσα σε άγκυστρο
in_brace:
    BRACE_START body BRACE_END

struct:
      KEYWORD_STR IDENTIFIER in_brace
    | KEYWORD_STR IDENTIFIER NEWLINE in_brace
    ;

loops:
    for_grammar

// Εδώ ορίζεται τι μπορεί να είναι ορίσματα μιας συνάρτησης
arguments:
      arguments expr_part COMMA expr_part
    | expr_part COMMA expr_part
    |
    ;

// Εδώ ορίζεται τι θεωρείται ορισμός μιας συνάρτησης
func_par:
      KEYWORD_FUNC IDENTIFIER PAR_START arguments PAR_END {cor_expr++; print_valid("arguments"); }
    | KEYWORD_FUNC IDENTIFIER PAR_START expr_part PAR_END {cor_expr++; print_valid("argument"); }
    ;

// Εδώ ορίζεται τι θεωρείται ορισμός μιας μεταβλητής
declaration:
      KEYWORD_VAR_TYPE IDENTIFIER
    | KEYWORD_VAR_TYPE IDENTIFIER EQ expr_proc
    | KEYWORD_VAR_TYPE IDENTIFIER in_brack EQ expr_proc
    | KEYWORD_VAR_TYPE IDENTIFIER in_brack EQ BRACE_START elements BRACE_END
    | KEYWORD_VAR_TYPE IDENTIFIER in_brack
    ;

// Εδώ ορίζεται τι θεωρείται ανάθεση σε μεταβλητή
assignment:
    IDENTIFIER EQ expr_proc

return:
    KEYWORD_RET expr_proc
    | KEYWORD_RET expr_part
    ;

include:
    HASH KEYWORD_INCL LESSER IDENTIFIER DOT IDENTIFIER GREATER
    | HASH KEYWORD_INCL STRING
    ;

cases:
    KEYWORD_CASE COLON valid NEWLINE cases
    | KEYWORD_CASE COLON valid NEWLINE

case_grammar:
    KEYWORD_SWITCH PAR_START expr_proc PAR_END BRACE_START cases BRACE_END
    | KEYWORD_SWITCH PAR_START expr_part PAR_END BRACE_START cases BRACE_END
    ;

else_grammar:
    KEYWORD_ELSE in_brace

if_grammar:
      KEYWORD_IF PAR_START expr_proc PAR_END in_brace
    | KEYWORD_IF PAR_START expr_proc PAR_END expr_proc NEWLINE
    ;

for_grammar:
      KEYWORD_FOR PAR_START for_args PAR_END in_brace
    | KEYWORD_FOR PAR_START for_args PAR_END expr_proc NEWLINE
    ;

for_args:
      expr_proc SEMI expr_proc SEMI expr_proc
    | SEMI expr_proc SEMI expr_proc
    | expr_proc SEMI SEMI expr_proc
    | expr_proc SEMI SEMI
    | SEMI expr_proc SEMI
    | SEMI SEMI expr_proc
    | SEMI SEMI
    ;

half_expr:
      operator IDENTIFIER
    | operator INTCONST
    | operator DOUBLE
    | operator FLOAT
    ;

sizeof:
      KEYWORD_SIZE PAR_START KEYWORD_VAR_TYPE PAR_END
    | KEYWORD_SIZE PAR_START KEYWORD_VAR_TYPE PAR_END half_expr
    ;

conditionals:
      if_grammar
    | else_grammar
    | case_grammar
    ;

// Εδώ ορίζεται τι θεωρείται συντακτικά σώστο
valid:
     return      SEMI { cor_expr++; print_valid("return");}
   | sizeof      SEMI { cor_expr++; print_valid("sizeof");}
   | include     SEMI { cor_expr++; print_valid("include");}
   | expr_proc   SEMI { cor_expr++; print_valid("expression");}
   | assignment  SEMI { cor_expr++; print_valid("assignment");}
   | declaration SEMI { cor_expr++; print_valid("declaration");}
   | loops            { cor_expr++; print_valid("loop clause");}
   | in_brace         { cor_expr++;
                        if( function_started_flag)
                        {
                            function_started_flag=0;
                            if (line == function_start_line)
                            {
                               printf("O\tLine:  %d \tValid function body!\n",function_start_line);
                            } else if (line >= function_start_line) {
                               printf("O\tLines: %d-%d\tValid function body!\n",function_start_line, line);
                            }
                        } else {
                            function_started_flag=1;
                            function_start_line=line;
                        }
                      }
   | struct SEMI      { cor_expr++;
                        if( struct_started_flag)
                        {
                            struct_started_flag=0;
                            if (line == struct_start_line)
                            {
                                printf("O\tLine:  %d \tValid struct statement!\n",struct_start_line);
                            } else if (line >= struct_start_line) {
                                printf("O\tLines: %d-%d\tValid struct statement!\n",struct_start_line, line);
                            }
                        } else {
                            struct_started_flag=1;
                            struct_start_line=line;
                        }
                      }
   | func_par         { cor_expr++; print_valid("function declaration");}
   | conditionals     { cor_expr++; print_valid("conditional clause");  }
   | NEWLINE          { line++; }
   | EOP              { print_report(cor_expr,inc_expr); }
   | error            { inc_expr++;}
   ;

%%

void print_valid (char * type) {
    printf("O\tLine:  %d \tValid %s!\n"    ,line, type);
}
// Αυτή η συνάρτηση τυπώνει το πλήθος των σωστών και λάθος λέξεων και εκφράσεων
// Ενεργοποιήται μόλις ο bison δεχθεί token EOP
// (End of Parse, δίνεται στο τέλος του αρχείου)
void print_report (int cor_expr,int inc_expr) {
    printf("|- Expressions:\n"
           "| Number of  correct  expressions : %d\n"
           "| Number of incorrect expressions : %d\n"
           "*--------------------------------------*\n"
           ,cor_expr, inc_expr);
}

/* H synarthsh yyerror xrhsimopoieitai gia thn anafora sfalmatwn. Sygkekrimena kaleitai
   apo thn yyparse otan yparksei kapoio syntaktiko lathos. Sthn parakatw periptwsh h
   synarthsh epi ths ousias typwnei mhnyma lathous sthn othonh. */
void yyerror(char *s) {
    fprintf(stderr, "X\tLine:  %d \tError: %s\n",line, s);
}

//Αναγκαίες εντολές για να γίνεται το debugging στον Bison
#ifdef YYDEBUG
  yydebug = 1;
#endif

/* H synarthsh main pou apotelei kai to shmeio ekkinhshs tou programmatos.
   Sthn sygkekrimenh periptwsh apla kalei thn synarthsh yyparse tou Bison
   gia na ksekinhsei h syntaktikh analysh. */
int main(void) {
    // Open a file handle to a particular file:
    FILE *myfile = fopen("input.txt", "r");
    // Make sure it is valid:
    if (!myfile)
    {
      printf("* Error: cannot open the \"input.txt\" file!");
      return -1;
    }
    // Set Flex to read from it instead of defaulting to STDIN:
    printf("\n*---- ANALYSIS: ---------------------*\n");
    yyin = myfile;
    yyparse();
    fclose(myfile);
}
