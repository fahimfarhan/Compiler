%{
#ifndef MYHEADER
#define MYHEADER
/* contents of the header file */
    #include "myHeader.h"
#endif

#define YYSTYPE Token *   /* yyparse() stack type */

#define MYDEBUG true
extern FILE *yyin;
extern int LineNo;
extern int ErrorCount;

FILE *fin;
FILE *logfile;
FILE *errorfile;
FILE *tablefile;
ofstream logout("zlog.md");

SymbolTable *table;

void yyerror(const char *s){
	ErrorCount++;
	fprintf(errorfile, "yyError at Line %d: %s\n", LineNo, s);

}

void printer(string s){    logout<<"Line Number "<<LineNo<<": "<<s<<"\n";  }

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
// %token NEWLINE NUMBER ADDOP MULOP LPAREN RPAREN

%}


%token IF ELSE FOR WHILE DO BREAK INT CHAR FLOAT DOUBLE VOID RETURN 
%token SWITCH CASE DEFAULT CONTINUE NEWLINE WHITESPACE 
%token CONST_INT CONST_FLOAT SPECIAL_CONST_CHAR CONST_CHAR
%token RELOP ID STRING  
%token TOO_MANY_DOTS  OTHERS_DOT 
%token ILL_FORMED_FLOAT UnfinishedChar MultiCharacterConstantError UnfinishedString UnfinishedComment
%token ADDOP MULOP LPAREN RPAREN INCOP ASSIGNOP LOGICOP NOT LCURL RCURL LTHIRD RTHIRD 
%token COMMA SEMICOLON DECOP PRINTLN


%left '+' '-'
%left '*' '/'


%%

start 	: program	{printer("start : program");}
		;

program : program unit {printer("program :program unit");} 
	| unit {    printer("program :unit");  }
	;
	
unit : var_declaration { printer("unit : var_declaration"); table->PrintAllScopeTable();  }
     | func_declaration{ printer("unit : func_declaration"); }
     | func_definition { printer("unit : funnc_definition"); }
     ;
     
func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON {}
		 ;
		 
func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement {}
 		 ;
 		 
parameter_list  : parameter_list COMMA type_specifier ID {}
		| parameter_list COMMA type_specifier	 {}
 		| type_specifier ID 					{}
 		| type_specifier						{}
 		|										{}
 		;
 		
compound_statement : LCURL statements RCURL		{}
 		    | LCURL RCURL						{}
 		    ;
 		    
var_declaration : type_specifier declaration_list SEMICOLON		{
    printer("var_declaration : type_specifier declaration_list SEMICOLON");
    if($1->TokenName != "void"){
        string setTypeSpecifier=$1->TokenName;
        int dlsize = $2->declarationList.size();
        for(int i=0; i<dlsize; i++){
            $2->declarationList[i].TokenName = setTypeSpecifier;
            int resizevalue = $2->declarationList[i].ArraySize;
            if( resizevalue != 0){
                if(setTypeSpecifier == "int"){ $2->declarationList[i].intArray.resize(resizevalue+1);  }
                else{   $2->declarationList[i].floatArray.resize(resizevalue+1);  }
            }
            
            bool b = table->Insert($2->declarationList[i]);
            if(!b){
                ErrorCount++;
                fprintf(errorfile, ". Rule: yyError at Line %d: same variable declared multiple times\n", LineNo);
            
            }
        }
        
    }else{
        ErrorCount++;
        fprintf(errorfile, ". Rule: yyError at Line %d: variable type cannot be void\n", LineNo);
    }
}
 		 ;
 		 
type_specifier	: INT		{   printer("type_specifier :INT"); $$->TokenName ="int"; $$->TokenAttr ="int";   }
 		| FLOAT				{   printer("type_specifier :FLOAT"); $$->TokenName ="float"; $$->TokenAttr ="int";   }
 		| VOID				{   printer("type_specifier :void"); $$->TokenName ="void";$$->TokenAttr ="int";       }
 		;
 		
declaration_list : declaration_list COMMA ID 		{
             	printer("declaration_list : declaration_list COMMA ID");
             	$$ = $1;
                $$->declarationList.push_back(*$3);
             	
}
 		  | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD 	{
 		  
 		    printer("declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD");
 		    $5->setValue();
 		    $3->ArraySize = $5->value;
 		    $3->isArray = true;
 		    $1->declarationList.push_back(*$3);
 		    $$ = $1;
 		  
 		  }
 		  | ID													{
             	printer("declaration_list : ID");
             	
             	$$->declarationList.push_back(*$1);	  
 		  }
 		  | ID LTHIRD CONST_INT RTHIRD							{
 		    printer("declaration_list : ID LTHIRD CONST_INT RTHIRD");
 		    $3->setValue();
 		    $1->ArraySize = $3->value;
 		    $1->isArray = true;
 		    $$ = $1;
 		  }
 		  ;
 		  
statements : statement								{}
	   | statements statement						{}
	   ;
	   
statement : var_declaration					{}
	  | expression_statement				{}
	  | compound_statement					{}
	  | FOR LPAREN expression_statement expression_statement expression RPAREN statement	{}
	  | IF LPAREN expression RPAREN statement												{}
	  | IF LPAREN expression RPAREN statement ELSE statement								{}
	  | WHILE LPAREN expression RPAREN statement											{}
	  | PRINTLN LPAREN ID RPAREN SEMICOLON													{}
	  | RETURN expression SEMICOLON															{}
	  ;
	  
expression_statement 	: SEMICOLON						{}
			| expression SEMICOLON 						{}
			;
	  
variable : ID 							{}
	 | ID LTHIRD expression RTHIRD 		{}
	 ;
	 
 expression : logic_expression			{}
	   | variable ASSIGNOP logic_expression		{} 	
	   ;
			
logic_expression : rel_expression 	{}
		 | rel_expression LOGICOP rel_expression	{} 	
		 ;
			
rel_expression	: simple_expression 		{}
		| simple_expression RELOP simple_expression		{}	
		;
				
simple_expression : term 					{}
		  | simple_expression ADDOP term 	{}
		  ;
					
term :	unary_expression					{}
     |  term MULOP unary_expression			{}
     ;

unary_expression : ADDOP unary_expression  {}
		 | NOT unary_expression 			{}
		 | factor 							{}
		 ;
	
factor	: variable 							{}
	| ID LPAREN argument_list RPAREN		{}
	| LPAREN expression RPAREN				{}
	| CONST_INT 							{}
	| CONST_FLOAT							{}
	| CONST_CHAR							{}
	| variable INCOP 						{}
	| variable DECOP						{}
	;
	
argument_list : argument_list COMMA logic_expression	{}
	      | logic_expression							{}
	      |				{}			
	      ;
 

%%
            
main()
{
    table = new SymbolTable;
    table->EnterScope();
    yyin = fopen("zin.c", "r");
    //logfile = fopen("zlog.txt", "w");
    errorfile= fopen("zerror.txt", "w");
    //tablefile= fopen("zsymtab.txt", "w");
    freopen("zsymtab.txt","w",stdout);
    yyparse();
    table->PrintAllScopeTable();
    fclose(yyin);

    fclose(errorfile);
    logout.close();

    exit(0);

}

/*

start 	: program	{}
		;

program : program unit {} 
	| unit {}
	;
	
unit : var_declaration {}
     | func_declaration {}
     | func_definition {}
     ;
     
func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON {}
		 ;
		 
func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement {}
 		 ;
 		 
parameter_list  : parameter_list COMMA type_specifier ID {}
		| parameter_list COMMA type_specifier	 {}
 		| type_specifier ID 					{}
 		| type_specifier						{}
 		|										{}
 		;
 		
compound_statement : LCURL statements RCURL		{}
 		    | LCURL RCURL						{}
 		    ;
 		    
var_declaration : type_specifier declaration_list SEMICOLON		{}
 		 ;
 		 
type_specifier	: INT		{}
 		| FLOAT				{}
 		| VOID				{}
 		;
 		
declaration_list : declaration_list COMMA ID 		{}
 		  | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD 	{}
 		  | ID													{}
 		  | ID LTHIRD CONST_INT RTHIRD							{}
 		  ;
 		  
statements : statement								{}
	   | statements statement						{}
	   ;
	   
statement : var_declaration					{}
	  | expression_statement				{}
	  | compound_statement					{}
	  | FOR LPAREN expression_statement expression_statement expression RPAREN statement	{}
	  | IF LPAREN expression RPAREN statement												{}
	  | IF LPAREN expression RPAREN statement ELSE statement								{}
	  | WHILE LPAREN expression RPAREN statement											{}
	  | PRINTLN LPAREN ID RPAREN SEMICOLON													{}
	  | RETURN expression SEMICOLON															{}
	  ;
	  
expression_statement 	: SEMICOLON						{}
			| expression SEMICOLON 						{}
			;
	  
variable : ID 							{}
	 | ID LTHIRD expression RTHIRD 		{}
	 ;
	 
 expression : logic_expression			{}
	   | variable ASSIGNOP logic_expression		{} 	
	   ;
			
logic_expression : rel_expression 	{}
		 | rel_expression LOGICOP rel_expression	{} 	
		 ;
			
rel_expression	: simple_expression 		{}
		| simple_expression RELOP simple_expression		{}	
		;
				
simple_expression : term 					{}
		  | simple_expression ADDOP term 	{}
		  ;
					
term :	unary_expression					{}
     |  term MULOP unary_expression			{}
     ;

unary_expression : ADDOP unary_expression  {}
		 | NOT unary_expression 			{}
		 | factor 							{}
		 ;
	
factor	: variable 							{}
	| ID LPAREN argument_list RPAREN		{
	                                            printer("factor : ID LPAREN argument_list RPAREN");
                                                Token *temp = table->LookUp($1->TokenAttr);
                                                if( (temp!=NULL) && ($1->idtype == "FUNCTION") ){
                                                    vector<string> *declared_arguments = temp->arglist;
				                                    int size1 = declared_arguments->size();
				                                    int size2 = $3->arglist->size();
				                                    if(size1 != size2) {
				                                        ErrorCount++;
				                                        fprintf(errorfile, "BisonError at Line %d: %s\n", LineNo, yytext);
                     
				                                    }else{
				                                        for(int i = 0; i < size1; ++i){
				                                            if(declared_arguments[i] != ($3)->arglist[i]){
				                                                error_count++;
				    fprintf(errorfile, "Error at Line %d: %dth argument mismatch in func %s\n", line_count, i+1, temp->getname().c_str());
				    break;
				                                            }
				                                        }
				                                        $$->TokenName = temp->functionreturn;
				                                    }
                                                }   
                                            }
	| LPAREN expression RPAREN				{
	                                            printer("factor : LPAREN expression RPAREN");
                                                $$ = $2;   
                                            }
	| CONST_INT 							{
	                                            printer("factor : CONST_INT");
                                                $$ = $1;   
                                            }
	| CONST_FLOAT							{   
	                                            printer("factor : CONST_FLOAT");
                                                $$ = $1;    
                                        	}
	| CONST_CHAR							{
                printer("factor : CONST_CHAR");
                $$ = $1;    
            }
	| variable INCOP 						{
        printer("factor : INCOP");
        $1->value = $1->value-1;
    }
	| variable DECOP						{
        printer("factor : DECOP");
        $1->value = $1->value-1;
    }
	;

	
argument_list : argument_list COMMA logic_expression	{
            printer("argument_list : argument_list COMMA logic_expression\n");
			$$ = $1;
			$$->arglist->push_back($3->TokenName);
                                        }
	      | logic_expression	{
                                    printer("argument_list : logic_expression\n");
                                    vector<string> *temp = new vector<string>();
                                    $$->arglist = temp;
                                    $$->arglist->push_back($1->TokenName);
                                }
	      |     {   
                    printer("argument_list");
                    vector<string> *temp = new vector<string>();
                    $$->arglist = temp;
                            
                }
	      ;

 */

