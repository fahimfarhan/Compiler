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


class ScopeTable{
private:
    int N;
    Token **HashTable;
public:
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
        /* ret = abs(ret);
        ret = (int)ret;
        cout<<N<<"\n";
        cout<<ret<<"\n";*/
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
            pos1 = i; pos2 = j;
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
            pos1 = i; pos2 = j;
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
            if(p->getTokenAttr() == tokenAttr){ pos1=0; pos2=1; return p;   }
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
        pos1=i; pos2=j;
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