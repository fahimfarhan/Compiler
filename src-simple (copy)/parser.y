%{
#ifndef MYHEADER
#define MYHEADER
/* contents of the header file */
    #include "myHeader.h"
#endif

#define YYSTYPE Token *   /* yyparse() stack type */

extern FILE *yyin;
extern int LineNo;
extern int ErrorCount;

FILE *fin;
FILE *logfile;
FILE *errorfile;
FILE *tablefile;

SymbolTable *table;

void yyerror(const char *s){
	ErrorCount++;
	fprintf(errorfile, "Error at Line %d: %s\n", LineNo, s);

}

int yylex(void);

string calc(string s1, string sign, string s2){
    int n1 = stoi(s1);
    int n2 = stoi(s2);

    if(sign == "+"){    n1+=n2; }
    else if(sign == "-"){   n1-=n2; }
        else if(sign == "*"){   n1+=n2; }
    else if(sign == "/"){   n1/=n2; }

    string ret = to_string(n1);
    return ret;
}

/*
%union{
Token *token;
}
*/

%}



%token NEWLINE NUMBER ADDOP MULOP LPAREN RPAREN


%%
input:              /* empty string */
    | input line
    ;
line: NEWLINE
    | expr NEWLINE          { 
                                fprintf(logfile,"\t%.10g\n",$1->value);
                                //if($1->getTokenAttr()=="double"){fprintf(logfile,"\t%.10g\n",$1->value);} 
                                //else{fprintf(logfile,"\t%d\n",$1->value);}        
                            }
    ;
expr: expr ADDOP term           { 
                                    $$ = new Token;
                                    if($3->getTokenName()=="int" && $1->getTokenName()=="int"){
                                        $$->setTokenName("int");
                                    }else{
                                        $$->setTokenName("double");
                                    }
                                    if($2->getTokenAttr() == "+"){
                                        $$->value = $1->value + $3->value;
                                    }else if($2->getTokenAttr() == "-"){
                                        $$->value = $1->value - $3->value;
                                    }
                                    /*
                                    string s1 = $1->getTokenAttr(); 
                                    string sign = $2->getTokenAttr();
                                    string s2 = $3->getTokenAttr();

                                    $$ = new Token;
                                    $$->setTokenName($1->getTokenName());
                                    $$->setTokenAttr(calc(s1, sign, s2));
                                    */
                                    //$$ = $1 + $3; 
                                }
    | term                      { $$ = $1;      }
    ;
term: term MULOP factor   { 
                                    $$ = new Token;
                                    $$ = new Token;
                                    if($3->getTokenName()=="int" && $1->getTokenName()=="int"){
                                        $$->setTokenName("int");
                                    }else{
                                        $$->setTokenName("double");
                                    }
                                    if($2->getTokenAttr() == "*"){
                                        $$->value = $1->value * $3->value;
                                    }else if($2->getTokenAttr() == "/"){
                                        $$->value = $1->value / $3->value;
                                    }

                                /*
                                    string s1 = $1->getTokenAttr(); 
                                    string sign = $2->getTokenAttr();
                                    string s2 = $3->getTokenAttr();

                                    $$ = new Token;
                                    $$->setTokenName($1->getTokenName());
                                    $$->setTokenAttr(calc(s1, sign, s2));*/
                                     //    $$ = $1 * $3; 
                            }
    | factor                { $$ = $1;      }
    ;
factor:  LPAREN expr RPAREN  { $$ = $2; }
      | NUMBER              { $$ = $1;      }
      ;
%%
            
main()
{
    table = new SymbolTable;
    table->EnterScope();
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