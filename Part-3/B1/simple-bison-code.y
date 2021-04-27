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
        #include <stdio.h>
        #include <stdlib.h>
        #include <math.h>
        int yylex(void);
        void yyerror(char *);
%}

/* Orismos twn anagnwrisimwn lektikwn monadwn. */
%token INTCONST VARIABLE PLUS MINUS DIV MULTI EQ SEMI NEWLINE POW

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
        program expression NEWLINE { printf("\t* Result: %d\n", $3); }
        |
        ;
expression:
          INTCONST                                 { $$ = $1;         }
        | VARIABLE                                 { $$ = $1;         }
        | VARIABLE VARIABLE                        { $$ = $1;         }
        | expression PLUS expression               { $$ = $1 + $3;    }
        | expression MINUS expression              { $$ = $1 - $3;    }
        | expression MULTI expression              { $$ = $1 * $3;    }
        | expression DIV expression                { $$ = $1 / $3;    }
        | expression POW expression                { $$ = pow($1,$3); }
        | expression expression EQ expression SEMI { $$ = $1 = $3;    }
        | expression EQ expression SEMI            { $$ = $1 = $3;    }
        ;

expr: expression '\n'

expressions: expressions expr
             | expr
             ;

%%

/* H synarthsh yylex ylopoiei enan autonomo lektiko analyth. Edw anagnwrizontai
   oi lektikes monades ths glwssas Uni-C */
int yylex() {
    char buf[100];
    char num = 0;
    int zero = 0;
    char c;

    // Diabase enan xarakthra apo thn eisodo
    c = getchar();

    // Ean o xarakthras einai keno h tab, agnohse ton kai diabase ton epomeno
    // Ομάδα 15: Για το συγκεκριμένο υποερώτημα (για απλές αριθμητικές πράξες), αγνοούνται οι χαρακτήρες "{","}","(",")","[","]" και \n
    while (c == ' ' || c == '\t' || c == '\n' || c == '(' || c == ')' || c == '[' || c ==']' || c == '{' || c == '}' )
    {
        yylval = 0;
        c = getchar();
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
        printf("\tScanner returned: VARIABLE (%s)\n", buf);
        return VARIABLE;
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
        printf("\tScanner returned: INTCONST (%d)\n", yylval);
        return INTCONST;
    }

    // Ομάδα 15: αν ο χαρακτήρας είναι το σύμβολο - πρόκειται για αφαίρεση.
    else if (c == '-')
    {
        printf("\tScanner returned: MINUS (%c)\n", c);
        return MINUS;
    }

    // Ean o xarakthras einai to symbolo + prokeitai gia prosthesh
    else if (c == '+')
    {
        printf("\tScanner returned: PLUS (%c)\n", c);
        return PLUS;
    }

    // Ean prokeitai gia ton eidiko xarakthra neas grammhs
    else if (c == '\n')
    {
        yylval = 0;
        printf("\tScanner returned: NEWLINE (\\n)\n");
        return NEWLINE;
    }

    // Ean prokeitai gia ton eidiko xarakthra telous arxeiou
    else if (c == EOF)
    {
        printf("\tScanner returned: EOF (EOF)\n");
        exit(0);
    }


    // Ομάδα 15: αν ο χαρακτήρας είναι το σύμβολο / πρόκειται για διαίρεση
    else if (c == '/')
    {
        printf("\tScanner returned: DIVISION (DIV)\n");
        return DIV;
    }

    // Ομάδα 15: αν ο χαρακτήρας είναι το σύμβολο * πρόκειται για πολλαπλασιασμό
    else if (c == '*')
    {
        printf("\tScanner returned: MULTIPLY (MULTI)\n");
        return MULTI;
    }

    else if (c == '^')
    {
        printf("\tScanner returned: POWER (POW)\n");
        return POW;
    }

    else if (c == '=')
    {
        printf("\tScanner returned: EQUALS (EQ)\n");
        return EQ;
    }

    else if (c == ';')
    {
        printf("\tScanner returned: SEMICOLON (SEMI)\n");
        return SEMI;
    }

    // Gia otidhpote allo kalese thn yyerror me mhnyma lathous
    yyerror("invalid character");
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
