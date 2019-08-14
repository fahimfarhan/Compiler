%option noyywrap

%{
#ifndef MYHEADER
#define MYHEADER
/* contents of the header file */
    #include "myHeader.h"
#endif

#include "y.tab.h"

int LineNo=0, ErrorCount=0;

%}


WS [ \t]+
DIGIT [0-9]
NUMBER [-]?{DIGIT}+(\.{DIGIT}+)?

%%

{NUMBER}  {
  sscanf(yytext,"%lf", &yylval);
	     return NUMBER;
	  }
"+"       { return PLUS; }
"-"       { return MINUS; }
"/"       { return SLASH; }
"*"       { return ASTERISK; }
"("       { return LPAREN; }
")"       { return RPAREN; }
"\n"      { return NEWLINE; }
.       { /* No action and no return */}
%%