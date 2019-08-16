%x str
%{
	#include <iostream>
	#include<stdlib.h>
	#include<string.h>
	#include "y.tab.h"
	#include "compiler1.h"
	
	#define MAX_STR_CONST 1000

	using namespace std;
	//#define YYSTYPE SymbolInfo*
	extern YYSTYPE yylval;
	void yyerror(char *);
	
	int str_cmt_start=0;
	int LineNo = 1;
	int NumOfError=0;
	SymbolTable A;
	
	//FILE *foutLog;
	//FILE *foutToken;
	char string_buf[MAX_STR_CONST];
    	char *string_buf_ptr;

	
   
%}
COMMENT1  "/*"( [^*] | (\*+[^*/]) )*\*+\/
Alphabet [a-zA-Z]
AlphaNumeric [_a-z_A-Z_0-9_]
ID  [a-zA-Z][_a-z_A-Z_0-9_]*
WHITESPACE [ \t\f\r\v]+ 
LETTER [a-zA-Z]

NEWLINE \n

LITERAL   \\([nabfrtv\\0]|(''))|[^\\'\n]
CHAR_LITERAL '({LITERAL})'

Sign "+"|"-"|""
Num [0-9]
Expo [eE]{Sign}?{Num}+
Float {Sign}?({Num}*(\.?){Num}+)({Expo})?
Float2 {Sign}?({Num}*(\.?){Num}+)({Expo})
ERROR1 [0-9]*"."[0-9]*"."
ERROR2 {Float2}"."[0-9]*
ERROR3 [0-9]+{ID}
ERROR4 "'"{ID}"'"
ERROR5 ("'"[a-zA-Z]?)|([a-zA-Z]?"'")|("'\\'")

%%


{ERROR1}* { cout<<"ok e1"; NumOfError++;}//{ fprintf(foutLog,"\nError at line %d: Too many decimal point %s\n\n",LineNo, yytext);NumOfError++;}
{ERROR2}  { cout<<"ok e2";NumOfError++;}//{ fprintf(foutLog,"\nError at line %d: Ill formed number %s\n",LineNo, yytext);NumOfError++;}
{ERROR3}  { cout<<"ok e3";NumOfError++;}//{ fprintf(foutLog,"\nError at line %d:  Invalid prefix on ID or invalid suffix on Number  %s\n",LineNo, yytext);NumOfError++;}
{ERROR4}  { NumOfError++;}//{ fprintf(foutLog,"\nError at line %d:  Multi character constant error  %s\n",LineNo, yytext);NumOfError++;}
{ERROR5}  { NumOfError++;}//{ fprintf(foutLog,"\nError at line %d:  Unterminated character  %s\n",LineNo, yytext);NumOfError++;}

{NEWLINE} { LineNo++;}

{CHAR_LITERAL}		{
				A.Insert(yytext, "CONST_CHAR"); return CONST_CHAR;
			} 

{Float} 	{	A.Insert(yytext, "CONST_FLOAT"); return CONST_FLOAT; }
	
[0-9]+ 	{
				
				A.Insert(yytext, "CONST_INT");
				return CONST_INT;
				

			}

"if"		{  return IF;  }
"for"		{  return FOR;  }
"do"		{  return DO;  }
"int"		{  return INT;  }
"float"		{  return FLOAT;  }
"void"		{  return VOID;  }
"switch"	{  return SWITCH;  }
"default"	{  return DEFAULT;  }
"else"		{  return ELSE;  }
"while"		{  return WHILE;  }//{fprintf(foutToken, "<WHILE> "); 	fprintf(foutLog,"\nLine no %d: TOKEN <WHILE> Lexeme %s found\n",LineNo,yytext);}
"break"		{  return BREAK;  }//{fprintf(foutToken, "<BREAK> "); 	fprintf(foutLog,"\nLine no %d: TOKEN <BREAK> Lexeme %s found\n",LineNo,yytext);}
"char"		{  return CHAR;  }//{fprintf(foutToken, "<CHAR> "); 	fprintf(foutLog,"\nLine no %d: TOKEN <CHAR> Lexeme %s found\n",LineNo,yytext);}
"double"	{  return DOUBLE;  }//{	fprintf(foutToken, "<DOUBLE> "); 	fprintf(foutLog,"\nLine no %d: TOKEN <DOUBLE> Lexeme %s found\n",LineNo,yytext);}
"return"	{  return RETURN;  }//{	fprintf(foutToken, "<RETURN> "); 	fprintf(foutLog,"\nLine no %d: TOKEN <RETURN> Lexeme %s found\n",LineNo,yytext);}
"case"	        {  return CASE;  }    //{	fprintf(foutToken, "<CASE> "); 	fprintf(foutLog,"\nLine no %d: TOKEN <CASE> Lexeme %s found\n",LineNo,yytext);}
"continue"	{  return CONTINUE;  }//{fprintf(foutToken, "<CONTINUE> "); 	fprintf(foutLog,"\nLine no %d: TOKEN <CONTINUE> Lexeme %s found\n",LineNo,yytext);}


"+"		|

"-"		{	SymbolInfo *s= new  SymbolInfo(yytext, (char *)"ADDOP");
			yylval = (YYSTYPE)s;
			return ADDOP;
		}

"*" |
"/" |
"%" {	SymbolInfo *s= new  SymbolInfo(yytext, (char *)"MULOP");
	yylval = (YYSTYPE)s;
	return ADDOP;
    }					

"++"	{ return INCOP; }			


"--"	{ return DECOP; }						

">" |
"<" |
">=" |
"<=" |
"==" |
"!=" {
		SymbolInfo *s= new  SymbolInfo(yytext, (char *)"RELOP");
		yylval = (YYSTYPE)s;
		return RELOP;
	}

"="	{ return ASSIGNOP; }					

"&&"	|
"||"	{
			SymbolInfo *s= new  SymbolInfo(yytext, (char *)"LOGICOP");
			yylval = (YYSTYPE)s;
			return LOGICOP;
		}					

"!"	{ return NOT; }					

"("	{ return LPAREN; }					

")"	{ return RPAREN; }					
			
"{"	{ return LCURL; }					

"}"	{ return RCURL; }		


"["	{ return LTHIRD; }								
			

"]"	{ return RTHIRD; }					
			
","	{ return COMMA; }					
			
";"	{ return SEMICOLON; }			


{ID}	{ 
		cout<<"ok ID in .l"; A.Insert(yytext, "ID"); SymbolInfo *s= new  SymbolInfo(yytext, (char *)"ID");
		yylval = (YYSTYPE)s;
		return ID;
	}	 





"//".*                                    { /* DO NOTHING */ cout<<"sl cmnt deteted\n"; } 
[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]       { /* DO NOTHING */ cout<<"ml cmnt deteted\n"; }
	


\"              {  string_buf_ptr = string_buf; BEGIN(str); }
<str>\"        { /* saw closing quote - all done */
                    BEGIN(INITIAL);
                     *string_buf_ptr = '\0';
			return STRING;	
					 //fprintf(foutToken," <STRING,\""); StrPrinter(foutToken);fprintf(foutToken,"\" > "); 

					//fprintf(foutLog,"\nLine no %d: TOKEN <STRING> Lexeme \"", LineNo); StrPrinter(foutLog); fprintf(foutLog,"\" found\n");
				  //%s found\n",LineNo,yytext);


                     //int i52 = 0; while(string_buf[i52]!='\0'){	fprintf(); i52++;}
                    //cout<<yytext<<endl;
                    //cout<<*string_buf_ptr<<endl;
                   // printf("%s" , string_buf_ptr);    
                }


<str>\\n  *string_buf_ptr++ = '\n';
<str>\\t  *string_buf_ptr++ = '\t';
<str>\\r  *string_buf_ptr++ = '\r';
<str>\\b  *string_buf_ptr++ = '\b';
<str>\\f  *string_buf_ptr++ = '\f';
<str>\\a  *string_buf_ptr++ = '\a';
<str>\\v  *string_buf_ptr++ = '\v';

<str>\\(.|\n)  *string_buf_ptr++ = yytext[1];

<str>[^\\\n\"]+        {
        char *yptr = yytext;

        while ( *yptr )
                *string_buf_ptr++ = *yptr++;
        }

<str>\n        {
        /* error - unterminated string constant */
        /* generate error message */
		//fprintf(foutLog,"\nError at line %d: Unterminated string %s", LineNo, yytext);
        cout<<"error detected!";
        }


[\t]*      {/*Escape whitespace */}



			
%%


int yywrap(void)
{
	return 1;
}








