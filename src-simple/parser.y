%{
#ifndef MYHEADER
#define MYHEADER
/* contents of the header file */
    #include "myHeader.h"
#endif

#define YYSTYPE double //Token *      /* yyparse() stack type */

extern FILE *yyin;
extern int LineNo;
extern int ErrorCount;

FILE *fin;
FILE *logfile;
FILE *errorfile;
FILE *tablefile;


void yyerror(const char *s){
	ErrorCount++;
	fprintf(errorfile, "Error at Line %d: %s\n", LineNo, s);

}

int yylex(void);

%}

%token NEWLINE NUMBER PLUS MINUS SLASH ASTERISK LPAREN RPAREN


%%
input:              /* empty string */
    | input line
    ;
line: NEWLINE
    | expr NEWLINE           { fprintf(logfile,"\t%.10g\n",$1); }
    ;
expr: expr PLUS term         { $$ = $1 + $3; }
    | expr MINUS term        { $$ = $1 - $3; }
    | term                      { $$ = $1;      }
    ;
term: term ASTERISK factor   { $$ = $1 * $3; }
    | term SLASH factor      { $$ = $1 / $3; }
    | factor                { $$ = $1;      }
    ;
factor:  LPAREN expr RPAREN  { $$ = $2; }
      | NUMBER
      ;
%%
            
main()
{
    yyin = fopen("zin.c", "r");
    logfile = fopen("zlog.txt", "w");
    errorfile= fopen("zerror.txt", "w");
    tablefile= fopen("zsymtab.txt", "w");

    yyparse();

    fclose(yyin);
    fclose(logfile);
    fclose(errorfile);
    fclose(tablefile);

    exit(0);

}