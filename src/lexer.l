%option noyywrap

%{

/* Author : Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */

#include "myheader.h"

//ifstream fin;
ofstream tout , logout;
SymbolTable *symbolTable;
map<string, char > mp;

void preprocess(){
    // ntafrbv0
    mp["\'\\n\'"] = '\n';
    mp["\'\\t\'"] = '\t';
    mp["\'\\a\'"] = '\a';
    mp["\'\\f\'"] = '\f';
    mp["\'\\r\'"] = '\r';
    mp["\'\\b\'"] = '\b';
    mp["\'\\v\'"] = '\v';
    mp["\'\\0\'"] = '\0';
}
    
void insertToken(string s1, string s2){
    Token* token;
    token = new Token;
    token->setTokenAttr(s1);
    token->setTokenName(s2);
    
    symbolTable->Insert(*token);
    token = NULL;
    logout<<"Inserted in ScopeTable# "<<globalSopeNum<<" at position "<<scopeTablePos1<<" , "<<scopeTablePos2<<"\n\n";
    
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


digit [0-9]
letter [A-Za-z]
CONST_INT {digit}+

CONST_FLOAT1 {CONST_INT}(\.{CONST_INT})?(E[+-]?{CONST_INT})?
CONST_FLOAT2 {CONST_INT}?\.{CONST_INT}(E[+-]?{CONST_INT})?

CONST_FLOAT {CONST_FLOAT1}|{CONST_FLOAT2}

backslash \\
singlequote '
doublequote "
delimchar [ntafr"bv0]

SPECIAL_CONST_CHAR1 {singlequote}{backslash}{delimchar}{singlequote}|{singlequote}{backslash}{singlequote}

SPECIAL_CONST_CHAR '\\[ntafr"bv0]'|'\\'
CONST_CHAR '{letter}'

LITERAL   \\([nabfrtv\\0]|(''))|[^\\'\n]
CHAR_LITERAL '({LITERAL})'

%%

{IF}        {  tout<<"<IF>\n";          } 
{ELSE}      {  tout<<"<ELSE>\n";        }
{FOR}       {  tout<<"<FOR>\n";         }
{WHILE}     {  tout<<"<WHILE>\n";       }
{DO}        {  tout<<"<DO>\n";          }
{BREAK}     {  tout<<"<BREAK>\n";       }
{INT}       {  tout<<"<INT>\n";         } 
{CHAR}      {  tout<<"<CHAR>\n";        }
{FLOAT}     {  tout<<"<FLOAT>\n";       }  
{DOUBLE}    {  tout<<"<DOUBLE>\n";      }
{VOID}      {  tout<<"<VOID>\n";        }
{RETURN}    {  tout<<"<RETURN>\n";      }
{SWITCH}    {  tout<<"<SWITCH>\n";      } 
{CASE}      {  tout<<"<CASE>\n";        }
{DEFAULT}   {  tout<<"<DEFAULT>\n";     } 
{CONTINUE}  {  tout<<"<CONTINUE>\n";    }

{CONST_INT}     {   
                    tout<<"< CONST_INT , "<<yytext<<" >\n";
                    insertToken("CONST_INT", yytext);
                }
{CONST_FLOAT}   {   
                    tout<<"< CONST_FLOAT , "<<yytext<<" >\n"; 
                    insertToken("CONST_FLOAT", yytext);      
                }
{SPECIAL_CONST_CHAR} {
                    tout<<"< CONST_CHAR , "<<yytext<<" >\n"; 
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
                        case '\\': { detectedChar='\\'; cout<<"\nhere\n"; break;  }
                        case 'b': { detectedChar='\b';  break;  }
                        case 'v': { detectedChar='\v';  break;  }
                        case '0': { detectedChar='\0';  break;  }
                        default:{   break;  }
                        
                    }
                    string s123 = ""; s123+=detectedChar;
                    cout<<(int)detectedChar<<"";
                    yytext[0] = detectedChar;
                    yytext[1] = '\0';
                    insertToken("CONST_CHAR", s123);
                }
{CONST_CHAR}        {
                    tout<<"< CONST_CHAR , "<<yytext<<" >\n";
                    insertToken("CONST_INT", yytext);
                }


%%

int main(int argc, char **argv){
    
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
