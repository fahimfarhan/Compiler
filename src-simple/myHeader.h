/* Author : Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */


/* contents of the header file */
#include <bits/stdc++.h>

using namespace std;

class Token{
private:
    string TokenName, TokenAttr;
public:
    string value; // pore add kora hoise
    Token *Next;
    
    Token(){
        TokenName = "";
        TokenAttr = "";
        value = "";
        Next = NULL;
    }

    Token(Token& t){
        TokenName = t.getTokenName();
        TokenAttr = t.getTokenAttr();
        value = t.value;
        Next = t.Next;
    }

    // getter 
    string getTokenName(){  return TokenName;   }
    string getTokenAttr(){  return TokenAttr;   }
    // setter
    void setTokenName(const string& name){ TokenName = name;    }
    void setTokenAttr(const string& attr){ TokenAttr = attr;   }
    
    // destructor
    ~Token(){
        Next = NULL;
        /* if(!Next){
            try{
                delete Next;
            }catch(exception& e){
                cout << " Token Destructor Exception: "<< e.what() << "\n";
            }
        }*/
    }
};

class ScopeTable{
private:
    int N;
    Token **HashTable;
public:
    static int scopeTablePos1, scopeTablePos2;
    int id;
    ScopeTable *Parent;

    ScopeTable(const int& n=7){
        N = n;  Parent = NULL;  
        HashTable = new Token*[N+1];
        for(int i=0; i<=N; i++){    HashTable[i] = new Token;    } 
    }

    int HashFunction(string tattr){ 
        int ret = 0; 
        for(int i=0; i<tattr.size(); i++){  ret+=(int)tattr[i];  }
        //hashFuncCounter++;
        ret = ret%N;
        return ret;    
    }

    bool Insert(const string& tname,const string& tattr ){
        try{

            int i = HashFunction(tattr);
            Token *curr, *next;
            curr = HashTable[i];
            int j=1;
            while(curr->Next!=NULL){
                curr = curr->Next;
                j++;
            }

            Token *lastToken = new Token;
            lastToken->setTokenAttr(tattr);
            lastToken->setTokenName(tname);

            curr->Next = lastToken;
            curr = NULL;
            lastToken = NULL; // eta lagar kotha
            //cout<<i<<" , "<<j<<"\n";
            scopeTablePos1 = i; scopeTablePos2 = j;
            return true;    
        }
        catch(exception& x){
            cout<<"ScopeTable Insert Exception: "<<x.what()<<"\n";
            return false;
        }return false;

    }

    bool Insert(Token& token){
        try{
            int i = HashFunction(token.getTokenAttr());
            Token *curr, *next;
            curr = HashTable[i];
            
            int j=1;
            while(curr->Next!=NULL){
                curr = curr->Next;
                j++;
            }

            Token *lastToken = new Token(token);
            curr->Next = lastToken;
            curr = NULL;
            lastToken = NULL; // eta lagar kotha 
            //cout<<i<<" , "<<j<<"\n";
            scopeTablePos1 = i; scopeTablePos2 = j;
            return true;    
         }
        catch(exception& x){
            cout<<"ScopeTable Insert Exception: "<<x.what()<<"\n";
            return false;
        }return false;

    }

    
    Token* LookUp(string tokenAttr){
        int i = HashFunction(tokenAttr);

        Token *p;
        p = HashTable[i];
        int j=1;
        while(p!=NULL){
            if(p->getTokenAttr() == tokenAttr){ scopeTablePos1=0; scopeTablePos2=1; return p;   }
            p = p->Next;
            j++;
        }    
        return NULL;
    }

    bool Delete(string tokenAttr){
        Token *p = LookUp(tokenAttr);
        if(p == NULL){  return false;   }

        int i = HashFunction(tokenAttr);
        Token *curr;
        curr = HashTable[i];
        int j=1;
        while(curr->Next!=p){   curr = curr->Next; j++;  }
        curr->Next = p->Next;
        p->Next = NULL;
        delete p;
        scopeTablePos1=i; scopeTablePos2=j;
        return true;

    }

    void Print(){
        cout<<" ScopeTable # "<<id<<"\n";
        Token *temp;
        for(int i=0; i<N; i++){
            cout<<i<<" --> ";
            temp = HashTable[i];
            while(temp->Next!=NULL){
                temp = temp->Next;
                cout<<" < "<<temp->getTokenName()<<" : "<<temp->getTokenAttr()<<" > ";
            }
            cout<<"\n";
        }   
    
    }


    ~ScopeTable(){

        Token *curr, *next;
        for(int i=0; i<=N; i++){
            curr = HashTable[i];
            while(true){
                next = curr->Next;
                curr->Next = NULL;
                delete curr;
                if(next == NULL){   break;  }
            }
        }
        for(int i=0; i<=N; i++){    if(!HashTable[i])delete HashTable[i];   }
        delete[] HashTable;
    }


};



class SymbolTable{
private:
    ScopeTable *root, *curr;
    int N;
public:
    static int globalSopeNum;
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

    void destroySymbolTable(){  while(curr!=root){  ExitScope();    }   }

    ~SymbolTable(){    destroySymbolTable();    }
};