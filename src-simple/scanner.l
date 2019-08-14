%option noyywrap

%{
#ifndef MYHEADER
#define MYHEADER
/* contents of the header file */
    #include "myHeader.h"
#endif

#define YYSTYPE Token *
extern SymbolTable *table;
void yyerror(char *);

#include "y.tab.h"

int LineNo=0, ErrorCount=0;

%}


WS [ \t]+
DIGIT [0-9]
NUMBER [-]?{DIGIT}+(\.{DIGIT}+)?

%%

{NUMBER}  {
      //sscanf(yytext,"%lf", &yylval);
	    string s = yytext;
      Token *token = new Token;
        token->setTokenName("NUMBER");
        token->setTokenAttr(s);
        token->setValue();

        yylval = (YYSTYPE)token;

      return NUMBER;
	  }
"+" |
"-"         {   string s = yytext;
                Token *token = new Token;
                token->setTokenName("ADDOP");
                token->setTokenAttr(s);
                yylval = (YYSTYPE)token;
                return ADDOP; 
            }
"/"  |
"*"       { string s = yytext;
            Token *token = new Token;
            token->setTokenName("MULOP");
            token->setTokenAttr(s);
            yylval = (YYSTYPE)token;
            return MULOP; 
          }
"("       {     return LPAREN; }
")"       { 
                return RPAREN; 
            }
"\n"      { return NEWLINE; }
.       { /* No action and no return */}
%%