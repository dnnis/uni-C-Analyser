%{
        #include <stdio.h>
        int yylex(void);
        void yyerror(char *);
%}

%token DIGIT NEWLINE CAPITAL

%%

program:
        program expr DIGIT NEWLINE   {printf("Got a digit!")}
        program expr CAPITAL NEWLINE {printf("Got a capital letter!")}
        |
        ;
expr:
        DIGIT          { $$ = $1; }
        ;
%%

yylex() {
        char c;
        c = getchar();

        // Process all digits
        if (c >= '0' && c <= '9')
        {
                yylval = c - '0';
                fprintf(stdout, "\nDigit is %c\n",&c);
                return DIGIT;
        }
        if (c == '\n') return NEWLINE;
        yyerror("invalid character");
}

void yyerror(char *s) {
        fprintf(stderr, "%s\n", s);
}

int main(void)  {
        yyparse();
        return 0;
}
