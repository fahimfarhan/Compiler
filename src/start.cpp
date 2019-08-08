/* Author : Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */

#include "myheader.h"

void testDrivenDevelopment(){
    // 2 test per method. 1 positive, 1 negative
    cout<<"\n--------- Token -----------\n";
    Token token;
    token.setTokenName("INT");
    token.setTokenAttr("123");

    cout<<(token.getTokenName()=="INT")<<"\n";
    cout<<(token.getTokenAttr()=="123")<<"\n";
    
    Token token1;
    token1.setTokenName("CHAR");
    token1.setTokenAttr("B");

    token.Next = &token1;

    cout<<(token1.getTokenName()==token.Next->getTokenName())<<"\n";
    cout<<(token1.getTokenAttr()==token.Next->getTokenAttr())<<"\n";

    cout<<token1.getTokenName()<<" "<<token.Next->getTokenName()<<"\n";
    cout<<token1.getTokenAttr()<<" "<<token.Next->getTokenAttr()<<"\n";

    /*------------  SCOPE TABLE -------------*/ 

    ScopeTable scopeTable;
    // test insert
    cout<<"\n--------- Scope Table -----------\n";
    cout<<"Insert: "<<scopeTable.Insert(token.getTokenName(), token.getTokenAttr())<<"\n";
    
    cout<<"Insert: "<<scopeTable.Insert(token1)<<"\n";
    Token *temp = scopeTable.LookUp(token.getTokenAttr());
    bool b = (temp->getTokenAttr()==token.getTokenAttr());
    cout<<"LookUp: "<<b<<"\n";
    cout<<"LookUp: "<<(scopeTable.LookUp("lol")==NULL)<<"\n";
    cout<<"Print: \n-----------\n";
    scopeTable.Print();
    cout<<"\n-----------\n";
    cout<<"Delete: "<<(scopeTable.Delete("lol")==0)<<"\n";
    cout<<"Delete: "<<scopeTable.Delete(token1.getTokenAttr())<<"\n";
    cout<<"Print: \n-----------\n";
    scopeTable.Print();
    cout<<"\n-----------\n";

    cout<<"\n--------- Symbol Table ------------\n";
    SymbolTable *symbolTable;
    cout<<"ok0\n";
    symbolTable= new SymbolTable;
    symbolTable->EnterScope();
    cout<<"ok.5\n";
    string s1="Lol", s2="aaa";
    Token* token2;
    token2 = new Token;
    token2->setTokenAttr(s1);
    token2->setTokenName(s2);
    cout<<"ok1\n";
    symbolTable->Insert(*token2);
    cout<<"ok2\n";
    token2 = NULL;
    cout<<"Inserted in ScopeTable# "<<globalSopeNum<<" at position "<<pos1<<" , "<<pos2<<"\n";
    
}

void compilerPart1(){
    int n;
    cin>>n;
    SymbolTable *symbolTable = new SymbolTable(n);
    symbolTable->EnterScope();
    string s1, s2;
    char ch;
    while(cin>>ch){
        switch(ch){
            case 'I':{
                cin>>s1>>s2;
                cout<<ch<<" "<<s1<<" "<<s2<<"\n";
                Token* token;
                token = new Token;
                token->setTokenAttr(s1);
                token->setTokenName(s2);
                
                symbolTable->Insert(*token);
                token = NULL;
                cout<<"Inserted in ScopeTable# "<<globalSopeNum<<" at position "<<pos1<<" , "<<pos2<<"\n\n";
                break;
            }
            case 'L':{
                cin>>s1;
                cout<<ch<<" "<<s1<<"\n";
                if(symbolTable->LookUp(s1)!=NULL){
                    cout<<"Found in ScopeTable# "<<globalSopeNum<<" at position "<<pos1<<" , "<<pos2<<"\n\n";
                }
                break;
            }
            case 'D':{
                cin>>s1;
                cout<<ch<<" "<<s1<<"\n";
                if(symbolTable->Remove(s1)){
                    cout<<"Deleted ScopeTable# "<<globalSopeNum<<" at position "<<pos1<<" , "<<pos2<<"\n\n";
                }else{
                    cout<<"Not Found\n\n";
                }

                break;
            }
            case 'P':{
                char ch1;
                cin>>ch1;
                cout<<ch<<" "<<ch1<<"\n\n";

                if(ch1 == 'A'){ symbolTable->PrintAllScopeTable();  }
                else if(ch1 == 'C'){ symbolTable->PrintCurrScopeTable();  }
                break;
            }
            case 'S':{
                //cin>>s1;
                cout<<ch<<" "<<"\n\n";
                symbolTable->EnterScope();
                cout<<"\nNew ScopeTable with id "<<globalSopeNum<<" created\n\n";

                break;
            }
            case 'E':{
                cout<<ch<<" "<<"\n\n";
                symbolTable->ExitScope();
                cout<<"ScopeTable with id "<<globalSopeNum<<" removed\n\n";
                break;
            }
                
        }
    }
}

int main(){
    compilerPart1();
    //testDrivenDevelopment();
    return 0;
}