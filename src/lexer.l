%option noyywrap

%{

/* Author : Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */

#include "myheader.h"

//ifstream fin;
ofstream tout , logout;
SymbolTable *symbolTable;


int lineCount=0, errorCount=0;

void preprocess(){}
    
void insertToken(string s1, string s2){
    Token* token;
    token = new Token;
    token->setTokenAttr(s2);
    token->setTokenName(s1);
    
    symbolTable->Insert(*token);
    token = NULL;
}

void defaultToDo(string in){
    {
        tout<<"< "<<in<<" , "<<yytext<<" >\n";
        logout<<"Line No. "<<lineCount<<": Token <"<<in<<"> Lexeme "<<yytext<<" found\n";
        insertToken(in, yytext);
    }
}

void OpPunch(string in){
    {
        tout<<"< "<<in<<" , "<<yytext<<" >\n";
        logout<<"Line No. "<<lineCount<<": Token <"<<in<<"> Lexeme "<<yytext<<" found\n";
     //   insertToken(in, yytext);
    }
}

string strinngProcessor(string in){
    string out = "";

    return out;
}

%}

IF "if" 
ELSE "else"
FOR "for"
WHILE "while"
DO  "do"
BREAK "break"
INT "int" 
CHAR "char"
FLOAT "float" 
DOUBLE "double"
VOID "void"
RETURN "return"
SWITCH "switch" 
CASE "case"
DEFAULT "default" 
CONTINUE "continue"

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

SPECIAL_CONST_CHAR1 {singlequote}{backslash}{delimchar}{singlequote}|{singlequote}{backslash}{singlequote}

SPECIAL_CONST_CHAR '\\[ntafr"bv0]'
CONST_CHAR '{letter}'

LITERAL   \\([nabfrtv\\0]|(''))|[^\\'\n]
CHAR_LITERAL '({LITERAL})'

bs92    '{backslash}{backslash}'

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



{IF}        {   tout<<"<IF>\n";
                logout<<"Line No. "<<lineCount<<": Token <IF> Lexeme "<<yytext<<" found\n";
            } 
{ELSE}      {  tout<<"<ELSE>\n";
                logout<<"Line No. "<<lineCount<<": Token <ELSE> Lexeme "<<yytext<<" found\n";
            }
{FOR}       {  tout<<"<FOR>\n";         
                logout<<"Line No. "<<lineCount<<": Token <FOR> Lexeme "<<yytext<<" found\n";
            }
{WHILE}     {  tout<<"<WHILE>\n";
                logout<<"Line No. "<<lineCount<<": Token <WHILE> Lexeme "<<yytext<<" found\n";
           }
{DO}        {  tout<<"<DO>\n";          
                logout<<"Line No. "<<lineCount<<": Token <DO> Lexeme "<<yytext<<" found\n";
            }
{BREAK}     {  tout<<"<BREAK>\n";       
                logout<<"Line No. "<<lineCount<<": Token <BREAK> Lexeme "<<yytext<<" found\n";
            }
{INT}       {  tout<<"<INT>\n";         
                logout<<"Line No. "<<lineCount<<": Token <INT> Lexeme "<<yytext<<" found\n";
            } 
{CHAR}      {  tout<<"<CHAR>\n";        
                logout<<"Line No. "<<lineCount<<": Token <CHAR> Lexeme "<<yytext<<" found\n";
            }
{FLOAT}     {  tout<<"<FLOAT>\n";       
                logout<<"Line No. "<<lineCount<<": Token <FLOAT> Lexeme "<<yytext<<" found\n";
            }  
{DOUBLE}    {  tout<<"<DOUBLE>\n";      
                logout<<"Line No. "<<lineCount<<": Token <DOUBLE> Lexeme "<<yytext<<" found\n";
            }
{VOID}      {  tout<<"<VOID>\n";        
                logout<<"Line No. "<<lineCount<<": Token <VOID> Lexeme "<<yytext<<" found\n";
            }
{RETURN}    {  tout<<"<RETURN>\n";      
                logout<<"Line No. "<<lineCount<<": Token <RETURN> Lexeme "<<yytext<<" found\n";
            }
{SWITCH}    {  tout<<"<SWITCH>\n";      
                logout<<"Line No. "<<lineCount<<": Token <SWITCH> Lexeme "<<yytext<<" found\n";
            } 
{CASE}      {  tout<<"<CASE>\n";        
                logout<<"Line No. "<<lineCount<<": Token <CASE> Lexeme "<<yytext<<" found\n";
            }
{DEFAULT}   {  tout<<"<DEFAULT>\n";     
                logout<<"Line No. "<<lineCount<<": Token <DEFAULT> Lexeme "<<yytext<<" found\n";
            } 
{CONTINUE}  {  tout<<"<CONTINUE>\n";
            logout<<"Line No. "<<lineCount<<": Token <CONTINUE> Lexeme "<<yytext<<" found\n";
    }

{CONST_INT}     {   
                    tout<<"< CONST_INT , "<<yytext<<" >\n";
                    logout<<"Line No. "<<lineCount<<": Token <CONST_INT> Lexeme "<<yytext<<" found\n";
                    insertToken("CONST_INT", yytext);
                }
{CONST_FLOAT}   {   
                    tout<<"< CONST_FLOAT , "<<yytext<<" >\n"; 
                    logout<<"Line No. "<<lineCount<<": Token <CONST_FLOAT> Lexeme "<<yytext<<" found\n";

                    insertToken("CONST_FLOAT", yytext);      
                }

{bs92}          {
                    tout<<"< CONST_CHAR , "<<yytext<<" >\n";
                    logout<<"Line No. "<<lineCount<<": Token <CONST_CHAR> Lexeme "<<yytext<<" found\n";

                    char ch = 92;
                    string s = "";
                    s = s+ch;
                    // tout<<"< bs92 , "<<s<<" >\n"; // eta hobe na
                    insertToken("CONST_CHAR", s);
                }

{SPECIAL_CONST_CHAR} {
                    tout<<"< CONST_CHAR , "<<yytext<<" >\n"; 
                    logout<<"Line No. "<<lineCount<<": Token <CONST_CHAR> Lexeme "<<yytext<<" found\n";

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
                    // cout<<(int)detectedChar<<"";
                    // yytext[0] = detectedChar;
                    // yytext[1] = '\0';
                    insertToken("CONST_CHAR", temp);
                }
{CONST_CHAR}        {
                    tout<<"< CONST_CHAR , "<<yytext<<" >\n";
                    logout<<"Line No. "<<lineCount<<": Token <CONST_CHAR> Lexeme "<<yytext<<" found\n";

                    insertToken("CONST_INT", yytext);
                }

[+-]           { OpPunch("ADDOP"); }

[*/%]           {   OpPunch("MULOP");  }
"++"|"--"       {   OpPunch("INCOP");  }

{RELOP}         {   OpPunch("RELOP");  }

"="             {   OpPunch("ASSIGNOP");  }
"&&"|"||"       {   OpPunch("LOGICOP");  }
"!"             {    OpPunch("NOT");                }
"(" {   OpPunch("LPAREN");  }
")"              {   OpPunch("RPAREN");  }
"{"              {   OpPunch("LCURL");  }
"}"              {   OpPunch("RCURL");  }
"["              {   OpPunch("LTHIRD");  }
"]"              {   OpPunch("RTHIRD");  }
","              {   OpPunch("COMMA");  }
";"              {   OpPunch("SEMICOLON");  }

{IDENTIFIER}    {   defaultToDo("IDENTIFIER");  }   

{STRING}        {
                    tout<<"< STRING , "<<yytext<<" >\n";
                    logout<<"Line No. "<<lineCount<<": Token <STRING> Lexeme "<<yytext<<" found\n";
                }


"//".*                                    { /* DO NOTHING */  } 
[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]       { /* DO NOTHING */  }

{WHITESPACE}    {                       }
{NEWLINE}       {   lineCount++;        }

{TOO_MANY_DOTS} {
                    errorCount++;
                    logout<<"Line No. "<<lineCount<<" : Error No. "<<errorCount<<": Too many dots in "<<yytext<<"\n"; 
                }

{ILL_FORMED_FLOAT}  {       
                    errorCount++;
                    logout<<"Line No. "<<lineCount<<" : Error No. "<<errorCount<<": Ill formed float "<<yytext<<"\n"; 
                    }

{MultiCharacterConstantError}   {
                                errorCount++;
                    logout<<"Line No. "<<lineCount<<" : Error No. "<<errorCount<<": Multi Character Constant Error "<<yytext<<"\n"; 
                                
                                }

{UnfinishedChar}    {
                    errorCount++;
                    logout<<"Line No. "<<lineCount<<" : Error No. "<<errorCount<<": Unfinished Character Error "<<yytext<<"\n"; 
                    }

{UnfinishedString}  {
                    errorCount++;
                    logout<<"Line No. "<<lineCount<<" : Error No. "<<errorCount<<": Unfinished String Error "<<yytext<<"\n"; 
                    }

[/][*][^*]*[*]+([^*/])*    {
                    // failed 
                    errorCount++;
                    logout<<"Line No. "<<lineCount<<" : Error No. "<<errorCount<<": Unfinished Comment Error "<<yytext<<"\n"; 
                    

                    }
.                   {
                        errorCount++;
                        logout<<"Line No. "<<lineCount<<" : Error No. "<<errorCount<<": Unknown Character/Others Error "<<yytext<<"\n"; 
                    
                    }

%%

int main(int argc, char **argv){
// 
     
    if(argc!=3){
		printf("Please provide input file name and try again\n");
		return 0;
	}

    //freopen("input.txt","r",stdin);
    //freopen("zlog.txt","w",stdout);
    

    FILE *fin=fopen(argv[1],"r");
    
    tout.open(argv[2]);
    logout.open("zlog.txt");

    yyin= fin;
    
    symbolTable = new SymbolTable(7);
    symbolTable->EnterScope();

    yylex();

    logout.close();
    tout.close();
    fclose(fin);

    symbolTable->PrintAllScopeTable();
    // symbolTable->destroySymbolTable();
    if(!symbolTable){   delete symbolTable; }
}
