%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<fstream>
//#include "SymbolTable.h"
#include "compiler1.h"

#define YYSTYPE SymbolInfo*

using namespace std;

extern int yylex();
void yyerror(const char *s);
extern FILE *yyin;
extern int LineNo;
extern int NumOfError;


int labelCount=0;
int tempCount=0;


char *newLabel()
{
	char *lb= new char[4];
	strcpy(lb,"L");
	char b[3];
	sprintf(b,"%d", labelCount);
	labelCount++;
	strcat(lb,b);
	return lb;
}

char *newTemp()
{
	char *t= new char[4];
	strcpy(t,"t");
	char b[3];
	sprintf(b,"%d", tempCount);
	tempCount++;
	strcat(t,b);
	return t;
}

//SymbolTable *table= new SymbolTable(31);

%}

%error-verbose

%token IF ELSE FOR WHILE DO INT FLOAT DOUBLE CHAR RETURN VOID BREAK SWITCH CASE DEFAULT CONTINUE ADDOP MULOP ASSIGNOP RELOP CONST_CHAR STRING 
%token LOGICOP SEMICOLON COMMA LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD INCOP DECOP CONST_INT CONST_FLOAT ID NOT PRINTLN MAIN

%nonassoc THEN
%nonassoc ELSE

%%
Program : compound_statement {
	ofstream fout;
	fout.open("code.asm");
	fout<<"TITLE: CODE GENERATION\n";
	fout<<"ORG 100H\n";fout<<".STACK 100H\n";
	fout<<".MODEL SMALL\n";fout<<".DATA\n";fout<<".CODE\n";
	fout<<"\nMAIN PROC\n\n";

	fout << $1->code;
	
	fout<<"\nMAIN ENDP\n";fout<<"END MAIN\n";
}
;
compound_statement	: LCURL statements RCURL
						{	
							$$=$2;
						}
					| LCURL RCURL
						{
							$$=new SymbolInfo("compound_statement","dummy");
						}
					;


statements : statement {
				$$=$1;
			}
	       | statements statement {
				$$=$1;
				$$->code += $2->code;
				delete $2;
			}
	       ;


statement 	: 	expression_statement {
					$$=$1;
				}
			| 	compound_statement {
					$$=$1;
				}
			|	FOR LPAREN expression_statement expression_statement expression RPAREN statement {			
					/*
						$3's code at first, which is already done by assigning $$=$3
						create two labels and append one of them in $$->code
						compare $4's symbol with 0
						if equal jump to 2nd label
						append $7's code
						append $5's code
						append the second label in the code
					*/
					$$=$3;
					char *lbl1 = newLabel(); char *lbl2 = newLabel();//
					$$->code+=string(lbl1)+":\n";//
					$$->code += "MOV AX, 0;\n";//
					$$->code += "CMP AX, "+$4->GetName()+"\n"; //
					$$->code+="JE "+string(lbl2)+"\n";//
					$$->code+=$7->code;//
					$$->code+=$5->code;//
					$$->code+=string(lbl2)+":\n";//
					//
				}
			|	IF LPAREN expression RPAREN statement %prec THEN {
					$$=$3;
					
					char *label=newLabel();
					$$->code+="mov ax, "+$3->GetName()+"\n";
					$$->code+="cmp ax, 0\n";
					$$->code+="je "+string(label)+"\n";
					$$->code+=$5->code;
					$$->code+=string(label)+":\n";
					
					$$->SetName("if");//not necessary
				}
			|	IF LPAREN expression RPAREN statement ELSE statement {
					$$=$3;
					//similar to if part
					char *lbl1 = newLabel(); char *lbl2 = newLabel();
					$$->code += "MOV AX, "+$3->GetName()+"\n";
					$$->code+="CMP AX, 0\n";//
					$$->code+="JE "+string(lbl1)+"\n";//
					$$->code+=$5->code;
					$$->code+="JE "+string(lbl2)+"\n";
					$$->code+=string(lbl1)+":\n";
					$$->code+=$7->code;//
					$$->code+=string(lbl2)+":\n";//
					//	
				}
			|	WHILE LPAREN expression RPAREN statement {
					$$=$3;
					
					// should be easy given you understood or implemented for loops part
					char *lbl1 = newLabel(); char *lbl2 = newLabel();//
					$$->code+=string(lbl1)+":\n";//
					$$->code += "MOV AX, 0;\n";//
					$$->code += "CMP AX, "+$3->GetName()+"\n";//
					$$->code+="JE "+string(lbl2)+"\n";
					$$->code+=$5->code;//
					$$->code+=string(lbl2)+":\n";//
					//
					//
				}
			|	PRINTLN LPAREN ID RPAREN SEMICOLON {
					// write code for printing an ID. You may assume that ID is an integer variable.
					$$=new SymbolInfo("println","nonterminal");
				}
			| 	RETURN expression SEMICOLON {
					// write code for return.
					$$=$1;
				}
			;
		
expression_statement	: SEMICOLON	{
							$$=new SymbolInfo(";","SEMICOLON");
							$$->code="";
						}			
					| expression SEMICOLON {
							$$=$1;
						}		
					;
						
variable	: ID {
				
				$$= new SymbolInfo($1);
				$$->code="";
				$$->SetType("notarray");
		}		
		| ID LTHIRD expression RTHIRD {
				
				$$= new SymbolInfo($1);
				$$->SetType("array");
				

				$$->code=$3->code+"mov bx, " +$3->GetName() +"\nadd bx, bx\n";
				
				delete $3;
		}	
		;
			
expression : logic_expression {
			$$= $1;
		}	
		| variable ASSIGNOP logic_expression {
				$$=$1;
				$$->code=$3->code+$1->code;
				$$->code+="mov ax, "+$3->GetName()+"\n";
				if($$->GetType()=="notarray"){ 
					$$->code+= "mov "+$1->GetName()+", ax\n";
				}
				
				else{
					$$->code+= "mov  "+$1->GetName()+"[bx], ax\n";
				}
				delete $3;
			}	
		;
			
logic_expression : rel_expression {
					$$= $1;		
				}	
		| rel_expression LOGICOP rel_expression {
					$$=$1;
					$$->code+=$3->code;
					
					if($2->GetName()=="&&"){
						/* 
						Check whether both operands value is 1. If both are one set value of a temporary variable to 1
						otherwise 0
						*/
						//if(($1->GetName() == "0") || ($3->GetName() == "0"))
						//{ char *temp=newTemp(); 
						//  $$->code += "MOV AX, 0\n";
						//  $$->code += "MOV "+string(temp)+", AX\n";		
						//}else{ char *temp=newTemp(); 
						//  $$->code += "MOV AX, 1\n";
						 // $$->code += "MOV "+string(temp)+", AX\n";		
						//}cout<<"Success in AND logic! :D";
					}
					else if($2->GetName()=="||"){
						//if(($1->GetName() == "0") && ($3->GetName() == "0"))
						//{ char *temp=newTemp(); 
						//  $$->code += "MOV AX, 0\n";
						//  $$->code += "MOV "+string(temp)+", AX\n";		
						//}else{ char *temp=newTemp(); 
						//  $$->code += "MOV AX, 1\n";
						//  $$->code += "MOV "+string(temp)+", AX\n";		
						//}
						//cout<<"Success! in OR logic :D";
						
					}
					
					delete $3;
				}	
			;
			
rel_expression	: simple_expression {
				$$= $1;
			}	
		| simple_expression RELOP simple_expression {
				$$=$1;
				$$->code+=$3->code;
				$$->code+="mov ax, " + $1->GetName()+"\n";
				$$->code+="cmp ax, " + $3->GetName()+"\n";
				char *temp=newTemp();
				char *label1=newLabel();
				char *label2=newLabel();
				if($2->GetName()=="<"){
					$$->code+="jl " + string(label1)+"\n";
				}
				else if($2->GetName()=="<="){
				}
				else if($2->GetName()==">"){
				}
				else if($2->GetName()==">="){
				}
				else if($2->GetName()=="=="){
				}
				else{
				}
				
				$$->code+="mov "+string(temp) +", 0\n";
				$$->code+="jmp "+string(label2) +"\n";
				$$->code+=string(label1)+":\nmov "+string(temp)+", 1\n";
				$$->code+=string(label2)+":\n";
				$$->SetName(temp);
				delete $3;
			}	
		;
				
simple_expression : term {
				$$= $1;
			}
		| simple_expression ADDOP term {
				$$=$1;
				$$->code+=$3->code;
				
		// move one of the operands to a register, perform addition or subtraction with the other operand and move the result in a temporary variable 
				 
				char *temp=newTemp();
				if($2->GetName()=="+"){
					$$->code += "MOV AX,"+$1->GetName()+"\n";
					$$->code +="ADD AX, "+$3->GetName()+"\n";
					$$->code += "MOV "+ string(temp) + ", AX\n";
				}
				else{
					$$->code += "MOV AX,"+$1->GetName()+"\n";
					$$->code += "SUB AX,"+$3->GetName()+"\n";
					$$->code += "MOV "+ string(temp) + ", AX\n";
				}
				delete $3;
				cout << endl;
			}
				;
				
term :	unary_expression {
						$$= $1;
						}
	 | 	term MULOP unary_expression {
						$$=$1;
						$$->code += $3->code;
						$$->code += "MOV AX, 0\n";
							$$->code += "MOV BX, 0\n";
						$$->code += "mov ax, "+ $1->GetName()+"\n";
						$$->code += "mov bx, "+ $3->GetName() +"\n";
						char *temp=newTemp();
						if($2->GetName()=="*"){
							$$->code += "mul bx\n";
							$$->code += "mov "+ string(temp) + ", ax\n";
						}
						else if($2->GetName()=="/"){
							 //clear dx, perform 'div bx' and mov ax to temp
							$$->code += "DIV BX";
							char *temp=newTemp();
							$$->code += "MOV "+ string(temp) + ", AX\n";
						}
						else{
							// clear dx, perform 'div bx' and mov dx to temp
							// eki jinish abar?
						}
						$$->SetName(temp);
						cout << endl << $$->code << endl;
						delete $3;
						}
	 ;

unary_expression 	:	ADDOP unary_expression  {
							$$=$2;
							// Perform NEG operation if the symbol of ADDOP is '-'
							if($1->GetName() == "-"){
								$$->code+="MOV AX, 0\n";
								$$->code+="MOV BX, "+$2->GetName()+"\n";
								$$->code+="SUB AX,BX\n";
								$$->code+="MOV "+$2->GetName()+", AX\n";
							}
						}
					|	NOT unary_expression {
							$$=$2;
							char *temp=newTemp();
							$$->code="mov ax, " + $2->GetName() + "\n";
							$$->code+="not ax\n";
							$$->code+="mov "+string(temp)+", ax";
						}
					|	factor {
							$$=$1;
						}
					;
	
factor	: variable {
			$$= $1;
			
			if($$->GetType()=="notarray"){
				
			}
			
			else{
				char *temp= newTemp();
				$$->code+="mov ax, " + $1->GetName() + "[bx]\n";
				$$->code+= "mov " + string(temp) + ", ax\n";
				$$->SetName(temp);
			}
			cout<<"ok variable";
			}
	| LPAREN expression RPAREN {
			$$= $2;
			cout<<"ok l exp r";
			}
	| CONST_INT {
			$$= $1;cout<<"ok const int in f:var";
			}
	| CONST_FLOAT {
			$$= $1; cout<<"ok const float in f:var";
			}
	| variable INCOP {
			$$=$1; cout<<"ok inc op in f:var";
			// perform incop depending on whether the varaible is an array or not
			if($$->GetType() == "notarray"){
				$$->code+="MOV CX,"+$1->GetName()+"\n";	
				$$->code+="ADD CX, 1\n"; 
				$$->code+= "MOV "+$1->GetName()+" , CX\n";	
				}else{}
			}
	| variable DECOP {
			$$=$1; cout<<"ok inc op in f:var";
			// perform incop depending on whether the varaible is an array or not
			if($$->GetType() == "notarray"){
				$$->code+="MOV CX,"+$1->GetName()+"\n";	
				$$->code+="SUB CX, 1\n"; 
				$$->code+= "MOV "+$1->GetName()+" , CX\n";	
				}else{}
			}
	;
		
		


%%


void yyerror(const char *s){
	cout << "Error at line no " << LineNo << " : " << s << endl;
}

int main(int argc, char * argv[]){
	if(argc!=2){
		printf("Please provide input file name and try again\n");
		return 0;
	}
	
	FILE *fin=fopen(argv[1],"r");
	if(fin==NULL){
		printf("Cannot open specified file\n");
		return 0;
	}
	
	

	yyin= fin;
	yyparse();
	cout << endl;
	cout << endl << "\t\tsymbol table: " << endl;
	//table->dump();
	
	printf("\nTotal Lines: %d\n",LineNo);
	printf("\nTotal Errors: %d\n",NumOfError);
	
	printf("\n");
	return 0;
}




