/* Author : Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */

#ifndef INCLUDES
#define INCLUDES
/* contents of the header file */
    #include <bits/stdc++.h>
    using namespace std;

    int scopeTablePos1, scopeTablePos2;
#endif

class Token{
private:
    string TokenName, TokenAttr;
public:
    string value;
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