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
        int yylex(void);
        void yyerror(char *);
%}

/* Orismos twn anagnwrisimwn lektikwn monadwn. */
%token INTCONST ID PLUS MINUS DIV MULTI EQ SEMI COMMA NEWLINE PAR_START PAR_END BRA_START BRA_END KEYWORD_VAR_TYPE KEYWORD_FUNC POW

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
        | ID
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
        BRA_START body BRA_END

// Εδώ ορίζεται τι μπορεί να είναι ορίσματα μιας συνάρτησης
arguments:
           arguments expr_part COMMA expr_part
         | expr_part COMMA expr_part
         |
         ;

// Εδώ ορίζεται τι θεωρείται ορισμός μιας συνάρτησης
func_par: 
          KEYWORD_FUNC ID PAR_START arguments PAR_END      { printf("Valid arguments\n"); }
        | KEYWORD_FUNC ID PAR_START expr_part PAR_END      { printf("Valid argument\n" ); }
        ;

// Εδώ ορίζεται τι θεωρείται ορισμός μιας μεταβλητής
declaration: 
          KEYWORD_VAR_TYPE ID                { $$ = $1; }
        | KEYWORD_VAR_TYPE ID EQ expr_part   { $$ = $1; }
        | KEYWORD_VAR_TYPE ID EQ expr_proc   { $$ = $1; }
        ;

// Εδώ ορίζεται τι θεωρείται ανάθεση σε μεταβλητή
assignment:
          ID EQ expr_proc { $$ = $1; };

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

void print_scanner_ret(int line) {
    printf("Line %d: Scanner returned token: ",line);
}


/* H synarthsh yylex ylopoiei enan autonomo lektiko analyth. Edw anagnwrizontai
   oi lektikes monades ths glwssas Uni-C */
int yylex() {
    char buf[100];
    char num = 0;
    int zero = 0;
    // Για τον έλεγχο του αν βρίσκεται ο ΣΑ μέσα σε αγκύλες
    int in_bracket = -1;
    // Για τον έλεγχο του αν βρίσκεται ο ΣΑ μέσα σε παρενθέσεις
    int in_parentheses = 0;
    // Ο χαρακτήρας τον οποίο ελέγχει αυτή την στιγμή ο ΣΑ
    char c;
    // Για τον αριθμό γραμμών
    int line = 1;

    // Diabase enan xarakthra apo thn eisodo
    c = getchar();

    // Ean o xarakthras einai keno h tab, agnohse ton kai diabase ton epomeno
    while (c == ' ' || c == '\t')
    {
        yylval = 0;
        c = getchar();
    }


    /* ----------- Στάδιο αναγνώρισης θέσης ---------------- */ 
    switch (c)
    {
        case '{': 
            in_bracket = 1;
            break;
        case '}': 
            in_bracket = 0;
            break;
        case '(':
            in_parentheses = 1;
            break;
        case ')':
            in_parentheses = 0;
            break;
    }

    // An brethei enas xarakthras A-Z, a-z h _ tote prokeitai gia metablhth
    if ((c >= 'A' && c <= 'Z') ||
        (c >= 'a' && c <= 'z') ||
        (c == '_'))
    {
        sprintf(buf, "%c", c);
        c = getchar();
        // O epomenos xarakthras meta ton prwto mporei na einai kai pshfio 0-9
        while((c >= 'A' && c <= 'Z') ||
              (c >= 'a' && c <= 'z') ||
              (c >= '0' && c <= '9') ||
              (c == '_'))
        {
            sprintf(buf, "%s%c", buf, c);
            c = getchar();
        }
        ungetc(c, stdin);
        yylval = 0;

        if ( !strcmp(buf,"int")    ||
             !strcmp(buf,"float")  ||
             !strcmp(buf,"double") ||
             !strcmp(buf,"char")   ||
             !strcmp(buf,"long")   ||
             !strcmp(buf,"short"))
        {
            print_scanner_ret(line);
            printf("KEYWORD_VAR_TYPE (%s)\n", buf);
            return KEYWORD_VAR_TYPE;
        } else if ( !strcmp(buf,"func") ) {
            print_scanner_ret(line);
            printf("KEYWORD_FUNC (%s)\n", buf);
            return KEYWORD_FUNC;
        } else {
            print_scanner_ret(line);
            printf("ID (%s)\n", buf);
            return ID;
        }
    } 

    // Gia kathe xarakthra pou einai arithmos ginetai h topothethsh tou sthn yylval
    while (c >= '0' && c <= '9')
    {
        if (zero > 0) 
        {
            zero = 0;
            yyerror("integer starting with zero"); 
            exit(1);
        }
        // Ομάδα 15: Bugfix: "&& num == 0" διότι ο αρχικός κώδικα δεν δεχόταν αριθμούς όπως 100,101,342301 (που περιείχαν γενικά "0")
        if (c == '0' && num == 0) zero++;
        if (num == 0) yylval = 0;
        yylval = (yylval * 10) + (c - '0');
        num = 1;
        c = getchar();
    }

    if (num)
    {
        ungetc(c, stdin);
        print_scanner_ret(line);
        printf("INTCONST (%d)\n", yylval);
        return INTCONST;
    } else {
        switch (c)
        {
            // Ομάδα 15: αν ο χαρακτήρας είναι το σύμβολο ',' πρόκειται για κόμμα.
            case ',':
                print_scanner_ret(line);
                printf("COMMA (%c)\n", c);
                return COMMA;
            // Ομάδα 15: αν ο χαρακτήρας είναι το σύμβολο '-' πρόκειται για αφαίρεση.
            case '-':
                print_scanner_ret(line);
                printf("MINUS (%c)\n", c);
                return MINUS;
            // Ean o xarakthras einai to symbolo + prokeitai gia prosthesh
            case '+':
                print_scanner_ret(line);
                printf("PLUS + (%c)\n", c);
                return PLUS;
            // Ean prokeitai gia ton eidiko xarakthra neas grammhs
            case '\n':
                yylval = 0;
                //Αυξάνουμε τον μετρητή γραμμής
                line++;
                print_scanner_ret(line);
                printf("NEWLINE (\\n)\n",line);
                return NEWLINE;
            // Ean prokeitai gia ton eidiko xarakthra telous arxeiou
            case EOF:
                print_scanner_ret(line);
                printf("EOF (EOF)\n");
                exit(0);
            // Ομάδα 15: αν ο χαρακτήρας είναι το σύμβολο / πρόκειται για διαίρεση
            case '/':
                print_scanner_ret(line);
                printf("DIVISION (DIV)\n");
                return DIV;
            // Ομάδα 15: αν ο χαρακτήρας είναι το σύμβολο * πρόκειται για πολλαπλασιασμό
            case '*':
                print_scanner_ret(line);
                printf("MULTI (*)\n");
                return MULTI;
            case '=':
                print_scanner_ret(line);
                printf("EQ (=)\n");
                return EQ;
            case ';':
                print_scanner_ret(line);
                printf("SEMI (;)\n");
                return SEMI;
            case '(':
                print_scanner_ret(line);
                printf("PAR_START ( ( )\n");
                return PAR_START;
            case ')':
                print_scanner_ret(line);
                printf("PAR_END ( ) )\n");
                return PAR_END;
            case '{':
                print_scanner_ret(line);
                printf("BRA_START ( { )\n");
                return BRA_START;
            case '}':
                print_scanner_ret(line);
                printf("BRA_END ( } )\n");
                return BRA_END;
            case '^':
                print_scanner_ret(line);
                printf("POW ( ^ )\n");
                return POW;
            default:
                // Gia otidhpote allo kalese thn yyerror me mhnyma lathous
                yyerror("invalid character");
        }
    }
}


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
