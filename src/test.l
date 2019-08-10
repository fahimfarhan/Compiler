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

bs92    '{backslash}{backslash}'


NEWLINE [\n]
WHITESPACE [ \t\v\f\r]+


stringContent ({letter}|{digit}|{WHITESPACE})*

SINGLE_LINE_STR \"({stringContent})\"
MULTI_LINE_STR1 \"({stringContent}{backslash})+\"

MULTI_LINE_STR  \"(([^\"\n])|({backslash}{NEWLINE}))*\"

COMMENT1 //(([^\n])|(\\\n))*

MULTI_COMMENT_BEGIN /*
MULTI_COMMENT_END */

COMMENT2 {MULTI_COMMENT_BEGIN}(.*){MULTI_COMMENT_END}


COMMENT {COMMENT1}|{COMMENT2}
%%



{MULTI_LINE_STR}    {
                        tout<<"< STRING , "<<yytext<<" >";
                        logout<<"Line No. : Token <STRING> Lexeme "<<yytext<<" found\n";
                    }

{COMMENT}           {

                        logout<<"Line No. : Token <COMMENT> Lexeme "<<yytext<<" found\n";
    
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
