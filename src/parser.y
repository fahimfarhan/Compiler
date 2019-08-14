%{
#include <bits/stdc++.h>

#include "Token.h"
#include "ScopeTable.h"
#include "SymbolTable.h"

#define YYSTYPE Token*

using namespace std;

int yyparse(void);
int yylex(void);
extern FILE *yyin;
FILE *fp, *ferror, *flog, *fsymtab;

SymbolTable *table;


void yyerror(string e)
{
	//write your code
	cerr<<"Error : "<<e<<"\n";
}


%}

%token IF ELSE FOR WHILE DO BREAK INT CHAR FLOAT DOUBLE VOID RETURN SWITCH CASE DEFAULT CONTINUE 
%token NEWLINE WHITESPACE CONST_INT CONST_FLOAT SPECIAL_CONST_CHAR CONST_CHAR LITERAL RELOP IDENTIFIER
%token STRING ILL_FORMED_FLOAT MultiCharacterConstantError UnfinishedChar UnfinishedString

%left 
%right

%nonassoc 



%%

start : program
	{
		//write your code in this block in all the similar blocks below
	}
	;

program : program unit
	{

	} 
	| 
	unit
	{

	}
	;
	
unit : var_declaration
	{

	}
     	| 
     	func_declaration
     	{

     	}
     	| 
     	func_definition
     	{

     	}
     	;
     
func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON
			{

			}
		 	;
		 
func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement
			{

			}
 		 	;
 		 
parameter_list  : parameter_list COMMA type_specifier ID
		| parameter_list COMMA type_specifier	 
 		| type_specifier ID
 		| type_specifier
 		|
 		;
 		
compound_statement : LCURL statements RCURL
 		    | LCURL RCURL
 		    ;
 		    
var_declaration : type_specifier declaration_list SEMICOLON
 		 ;
 		 
type_specifier	: INT
 		| FLOAT
 		| VOID
 		;
 		
declaration_list : declaration_list COMMA ID
 		  | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD
 		  | ID
 		  | ID LTHIRD CONST_INT RTHIRD
 		  ;
 		  
statements : statement
	   | statements statement
	   ;
	   
statement : var_declaration
	  | expression_statement
	  | compound_statement
	  | FOR LPAREN expression_statement expression_statement expression RPAREN statement
	  | IF LPAREN expression RPAREN statement
	  | IF LPAREN expression RPAREN statement ELSE statement
	  | WHILE LPAREN expression RPAREN statement
	  | PRINTLN LPAREN ID RPAREN SEMICOLON
	  | RETURN expression SEMICOLON
	  ;
	  
expression_statement 	: SEMICOLON			
			| expression SEMICOLON 
			;
	  
variable : ID 		
	 | ID LTHIRD expression RTHIRD 
	 ;
	 
 expression : logic_expression	
	   | variable ASSIGNOP logic_expression 	
	   ;
			
logic_expression : rel_expression 	
		 | rel_expression LOGICOP rel_expression 	
		 ;
			
rel_expression	: simple_expression 
		| simple_expression RELOP simple_expression	
		;
				
simple_expression : term 
		  | simple_expression ADDOP term 
		  ;
					
term :	unary_expression
     |  term MULOP unary_expression
     ;

unary_expression : ADDOP unary_expression  
		 | NOT unary_expression 
		 | factor 
		 ;
	
factor	: variable 
	| ID LPAREN argument_list RPAREN
	| LPAREN expression RPAREN
	| CONST_INT 
	| CONST_FLOAT
	| CONST_CHAR
	| variable INCOP 
	| variable DECOP
	;
	
argument_list : argument_list COMMA logic_expression
	      | logic_expression
	      |
	      ;
 

%%
int main(int argc,char *argv[])
{

	if((fp=fopen(argv[1],"r"))==NULL)
	{
		printf("Cannot Open Input File.\n");
		exit(1);
	}

	ferror = fopen(argv[2],"w");
	fclose(fp2);
	flog = fopen(argv[3],"w");
	fclose(fp3);
	
	fp2= fopen(argv[2],"a");
	fp3= fopen(argv[3],"a");
	

	yyin=fp;
	yyparse();
	

	fclose(fp2);
	fclose(fp3);
	
	return 0;
}
