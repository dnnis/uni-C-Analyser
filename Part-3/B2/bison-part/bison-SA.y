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
            kai 'EOF' (end of file). Kathara gia logous debugging typwnei sthn othonh otidhpote
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
        void yyerror(char *);
%}

/*TODO: 
    1. WRITE LOGIC FOR BRACKETS ( "[" and "]" )
    2. MAKE DEBUG MODE
    3. FLEX ANALYSES CHAR BY CHAR. MAKE CHANGES ON SA LOGIC (EQ_MINUS etc)
*/ 

/* Orismos twn anagnwrisimwn lektikwn monadwn. */
%token SEMI
       COMMA
       FLOAT 
       STRING
       NEWLINE
       KEYWORD
       INTCONST
       PUNCTUATOR
       IDENTIFIER
       AMPER EXCLA
       KEYWORD_FUNC
       LOG_OR LOG_AND
       KEYWORD_VAR_TYPE
       PAR_START PAR_END
       BRACES_START BRACES_END
       BRACKETS_START BRACKETS_END
       GREATER LESSER GREATER_EQ LESSER_EQ
       EQQ EQ NEQ EQ_MULTI EQ_DIV EQ_PLUS EQ_MINUS
       PLUS PLUSPLUS MINUS MINUSMINUS DIV MOD MULTI POW
/* Orismos proteraiothtwn sta tokens */
%left POW
%left PLUS MINUS
%left DIV MULTI
%right EQ

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
          INTCONST
        | IDENTIFIER
        ;

// Εδώ ορίζονται ποιές είναι οι εκφράσεις υπο επεξεργασία
expr_proc:
          expr_part expr_part EQ expr_part { $$ = $1 = $3;    }
        | expr_part PLUS expr_part         { $$ = $1 + $3;    }
        | expr_part MINUS expr_part        { $$ = $1 - $3;    }
        | expr_part MULTI expr_part        { $$ = $1 * $3;    }
        | expr_part DIV expr_part          { $$ = $1 / $3;    }
        | expr_part EQ expr_part           { $$ = $1 = $3;    }
        | expr_part POW expr_part          { $$ = pow($1,$3); }
        ;

// Εδώ ορίζεται το "σώμα" του κώδικα, δηλαδή ένας αριθμός συντακτικά σωστών εκφράσεων.
body:
        body valid
        | valid
        ;

// Εδώ ορίζεται τι μπορεί να βρίσκεται μέσα σε αγκύλες
in_bra:
        BRACES_START body BRACES_END

// Εδώ ορίζεται τι μπορεί να είναι ορίσματα μιας συνάρτησης
arguments:
           arguments expr_part COMMA expr_part
         | expr_part COMMA expr_part
         |
         ;

// Εδώ ορίζεται τι θεωρείται ορισμός μιας συνάρτησης
func_par: 
          KEYWORD_FUNC IDENTIFIER PAR_START arguments PAR_END      { printf("Valid arguments\n"); }
        | KEYWORD_FUNC IDENTIFIER PAR_START expr_part PAR_END      { printf("Valid argument\n" ); }
        ;

// Εδώ ορίζεται τι θεωρείται ορισμός μιας μεταβλητής
declaration: 
          KEYWORD_VAR_TYPE IDENTIFIER                { $$ = $1; }
        | KEYWORD_VAR_TYPE IDENTIFIER EQ expr_part   { $$ = $1; }
        | KEYWORD_VAR_TYPE IDENTIFIER EQ expr_proc   { $$ = $1; }
        ;

// Εδώ ορίζεται τι θεωρείται ανάθεση σε μεταβλητή
assignment:
          IDENTIFIER EQ expr_proc { $$ = $1; };

// Εδώ ορίζεται τι θεωρείται συντακτικά σώστο
valid:
          expr_proc   SEMI { printf("Valid expression!\n");           }
        | declaration SEMI { printf("Valid declaration!\n");          }
        | assignment  SEMI { printf("Valid assignment!\n" );          }
        | func_par         { printf("Valid function declaration!\n"); }
        | in_bra           { printf("Valid function body!\n");        }
        | NEWLINE
        ;

%%

/*
void print_scanner_ret(int line) {
    printf("Line %d: Scanner returned token: ",line);
}
*/

/* H synarthsh yyerror xrhsimopoieitai gia thn anafora sfalmatwn. Sygkekrimena kaleitai
   apo thn yyparse otan yparksei kapoio syntaktiko lathos. Sthn parakatw periptwsh h
   synarthsh epi ths ousias typwnei mhnyma lathous sthn othonh. */
void yyerror(char *s) {
        fprintf(stderr, "Error: %s\n", s);
}


/* H synarthsh main pou apotelei kai to shmeio ekkinhshs tou programmatos.
   Sthn sygkekrimenh periptwsh apla kalei thn synarthsh yyparse tou Bison
   gia na ksekinhsei h syntaktikh analysh. */
int main(void)  {
        yyparse();
        return 0;
}
