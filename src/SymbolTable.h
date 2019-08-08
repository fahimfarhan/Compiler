/* Author : Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */

#ifndef INCLUDES
#define INCLUDES
/* contents of the header file */
    #include <bits/stdc++.h>
    using namespace std;

    int pos1, pos2;
#endif


#ifndef TOKEN
#define TOKEN
/* contents of the header file */
    #include "Token.h"
#endif

#ifndef SCOPETABLE
#define SCOPETABLE
/* contents of the header file */
    #include "ScopeTable.h"
#endif

int globalSopeNum;

class SymbolTable{
private:
    ScopeTable *root, *curr;
    int N;
public:
    SymbolTable(int n=7){  N = n;    root = NULL; curr = root;    } 
    void EnterScope(){
        ScopeTable *temp = new ScopeTable(N);
        temp->Parent = curr;
        curr = temp;
        temp = NULL;

        if(curr->Parent == root){   curr->id = 1;   }
        else{   curr->id = curr->Parent->id+1;    }
        globalSopeNum=curr->id;
    }

    void ExitScope(){
        globalSopeNum=curr->id;
        ScopeTable *temp;
        temp = curr;
        curr = curr->Parent;
        temp->Parent = NULL;
        delete temp;
    }

    bool Insert(Token& token){   
        //cout<<"Inserted in ScopeTable# "<<(curr->id)<<" at position \n";   
        globalSopeNum=curr->id; return curr->Insert(token);     
    }

    bool Remove(string& tokenAttr){  
        globalSopeNum=curr->id;
        return curr->Delete(tokenAttr);
    }
    
    Token* LookUp(string& tokenAttr){
        Token* ret;
        ret = NULL;
        ScopeTable *temp;
        temp = curr;
        
        while(temp!=root){
            ret = temp->LookUp(tokenAttr);
            if(ret!=NULL){       
                globalSopeNum=curr->id; //cout<<"Found in ScopeTable# "<<(curr->id)<<" at position \n";
                return ret;     
            }
            temp = temp->Parent;
        }
        temp = NULL;
        //cout<<"Not found\n";
        return NULL;    
    }
    void PrintCurrScopeTable(){    curr->Print();  }

    void PrintAllScopeTable(){
        ScopeTable *temp;
        temp = curr;
        while(temp!=root){
            temp->Print();
            temp = temp->Parent;
        }
    }

    ~SymbolTable(){     while(curr!=root){  ExitScope();    }   }
};