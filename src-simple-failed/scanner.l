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
extern  FILE *errorfile;

void defaultDo(string in){
  string s = yytext;
  Token *token = new Token;
  token->setTokenName(in);
  token->setTokenAttr(s);
  token->setValue();
  yylval = (YYSTYPE)token;
}

void opPunch(string in){
  string s = yytext;
  Token *token = new Token;
  token->setTokenName(in);
  token->setTokenAttr(s);
  token->setValue();
  yylval = (YYSTYPE)token;
}

/*

WS [ \t]+
DIGIT [0-9]
NUMBER [-]?{DIGIT}+(\.{DIGIT}+)?

*/
%}

NEWLINE [\n]
WHITESPACE [ \t\v\f\r]+

digit [0-9]
digits {digit}+

letter [A-Za-z]
letters {letter}+

CONST_INT {digit}+

CONST_FLOAT1 {CONST_INT}(\.{CONST_INT})?(E[+-]?{CONST_INT})?
CONST_FLOAT2 {CONST_INT}?\.{CONST_INT}(E[+-]?{CONST_INT})?

CONST_FLOAT {CONST_FLOAT1}|{CONST_FLOAT2}

backslash \\
singlequote '
doublequote "
delimchar [ntafr"bv0]


SPECIAL_CONST_CHAR1 '\\[ntafr"bv0]'
bs92    '{backslash}{backslash}'

SPECIAL_CONST_CHAR {SPECIAL_CONST_CHAR1}|{bs92}

CONST_CHAR '{letter}'

LITERAL   \\([nabfrtv\\0]|(''))|[^\\'\n]
CHAR_LITERAL '({LITERAL})'


RELOP <|<=|>|>=|==|!=

IDENTIFIER ({letter}|_)({letter}|{digit}|_)*

stringContent ({letter}|{digit}|{WHITESPACE})*

SINGLE_LINE_STR \"({stringContent})\"
MULTI_LINE_STR \"({stringContent}\\\n)+\"

STRING \"(([^\"\n])|(\\\n))*\"

TOO_MANY_DOTS ({CONST_INT}?\.{CONST_INT}?)+

CONST_FLOAT1ill {CONST_INT}(\.{CONST_INT})?(E[+-]?{CONST_FLOAT})?
CONST_FLOAT2ill {CONST_INT}?\.{CONST_INT}(E[+-]?{CONST_FLOAT})?

ILL_FORMED_FLOAT {CONST_FLOAT1ill}|{CONST_FLOAT2ill}

MultiCharacterConstantError '{IDENTIFIER}'

UnfinishedChar          '{letter}|'{digit}|'{backslash}'|'{backslash}{backslash}

UnfinishedString  \"(([^\"\n])|(\\\n))*

commentEnd [*][/]



%%

"if"  { return IF;  }
"else"  { return ELSE;  }
"for"   { return FOR; }
"while" { return WHILE; }
"do"  { return DO;  }
"break" { return BREAK; }
"int"   { return INT; }
"char"  { return CHAR;  }
"float" { return FLOAT; }
"double" {  return DOUBLE;  }
"void"  { return VOID;  }
"return"  { return RETURN;  }
"switch"  { return SWITCH;  }
"case"  { return CASE;  }
"default" { return DEFAULT; }
"continue"  { return CONTINUE;  }


{CONST_INT}  {
	    string s = yytext;
      Token *token = new Token;
        token->setTokenName("CONST_INT");
        token->setTokenAttr(s);
        token->setValue();

        yylval = (YYSTYPE)token;

      return CONST_INT;
	  }

{CONST_FLOAT}  {
	    string s = yytext;
      Token *token = new Token;
        token->setTokenName("CONST_FLOAT");
        token->setTokenAttr(s);
        token->setValue();

        yylval = (YYSTYPE)token;

      return CONST_FLOAT;
	  }

{SPECIAL_CONST_CHAR}  {
    char ch = yytext[2];
    char detectedChar=0;
    // ntafr"bv0
    switch(ch){
        case 'n': { detectedChar='\n';  break;  }
        case 't': { detectedChar='\t';  break;  }
        case 'a': { detectedChar='\a';  break;  }
        case 'f': { detectedChar='\f';  break;  }
        case 'r': { detectedChar='\r';  break;  }
        case '"': { detectedChar='\"';  break;  }
        //case '\\': { detectedChar='\\'; cout<<"\nhere\n"; break;  }
        case 'b': { detectedChar='\b';  break;  }
        case 'v': { detectedChar='\v';  break;  }
        case '0': { detectedChar='\0';  break;  }
        default:{   break;  }
        
    }
	    string temp = ""; temp+=detectedChar;
        Token *token = new Token;
        token->setTokenName("SPECIAL_CONST_CHAR");
        token->setTokenAttr(temp);
        token->setValue();

        yylval = (YYSTYPE)token;

      return SPECIAL_CONST_CHAR;
	  }

{CONST_CHAR}  {
	    string s = yytext;
      Token *token = new Token;
        token->setTokenName("CONST_CHAR");
        token->setTokenAttr(s);
        token->setValue();

        yylval = (YYSTYPE)token;

      return CONST_CHAR;
	  }

"+" |
"-"    {
            opPunch("ADDOP");
            return ADDOP;
        }

"*" |
"/" |
"%"   {
            opPunch("MULOP");
            return MULOP;
        }

"++"  |
"--"    {
            // opPunch("INCOP");
            return INCOP;
        }


{RELOP}  {
            opPunch("RELOP");
            return RELOP;
        }

"="    {
            opPunch("ASSIGNOP");
            return ASSIGNOP;
        }

"&&"  |
"||"    {
            opPunch("LOGICOP");
            return LOGICOP;
        }

"!"      {
            opPunch("NOT");
            return NOT;
        }

"("      {
            opPunch("LPAREN");
            return LPAREN;
        }

")"      {
            opPunch("RPAREN");
            return RPAREN;
        }

"{"      {
            opPunch("LCURL");
            return LCURL;
        }


"}"      {
            opPunch("RCURL");
            return RCURL;
        }

"["      {
            opPunch("LTHIRD");
            return LTHIRD;
        }

"]"      {
            opPunch("RTHIRD");
            return RTHIRD;
        }

","      {
            opPunch("COMMA");
            return COMMA;
        }

";"      {
            opPunch("SEMICOLON");
            return SEMICOLON;
        }

{IDENTIFIER}  {
                  defaultDo("ID");
                  return ID;
              } 

{STRING}      {
                  defaultDo("STRING");
                  return STRING;
            }

"//".*                                    { /* DO NOTHING */  } 
[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]       { /* DO NOTHING */  }

{WHITESPACE}    {  /* DO NOTHING */  }
{NEWLINE}       {   LineNo++;        }


{TOO_MANY_DOTS} {
                    ErrorCount++;
                    fprintf(errorfile, "Error at Line %d: %s\n", LineNo, yytext);
                    return TOO_MANY_DOTS;
                }

{ILL_FORMED_FLOAT}  {       
                    ErrorCount++;
                    fprintf(errorfile, "Error at Line %d: %s\n", LineNo, yytext);
                    return ILL_FORMED_FLOAT;
                    }

{MultiCharacterConstantError}   {
                                ErrorCount++;
                                fprintf(errorfile, "Error at Line %d: %s\n", LineNo, yytext);            
                                 return MultiCharacterConstantError; 
                                }

{UnfinishedChar}    {
                    ErrorCount++;
                    fprintf(errorfile, "Error at Line %d: %s\n", LineNo, yytext);
                      return UnfinishedChar;
                    }

{UnfinishedString}  {
                      ErrorCount++;
                      fprintf(errorfile, "Error at Line %d: %s\n", LineNo, yytext); 
                      return UnfinishedString;

                    }

[/][*][^*]*[*]+([^*/])*    {
                    // failed 
                    ErrorCount++;
                    fprintf(errorfile, "Error at Line %d: %s\n", LineNo, yytext);
                     return UnfinishedComment; 
                    }
.                   {
                        ErrorCount++;
                        //logout<<"Line No. "<<lineCount<<" : Error No. "<<errorCount<<": Unknown Character/Others Error "<<yytext<<"\n"; 
                        fprintf(errorfile, "Error at Line %d: %s\n", LineNo, yytext);
                        return OTHERS_DOT;
                    }




%%


/*
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
*/
