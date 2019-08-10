#include <bits/stdc++.h>
using namespace std;

string stringProcessor(string in){
    string out = "";
    char next = 0;
    for(int i=0; i<in.size()-1; i++){
        if(in[i]=='\\'){
            char ch = in[i+2];
            switch(ch){
                case 'n': { next='\n'; i++; break;  }
                case 't': { next='\t'; i++; break;  }
                case 'a': { next='\a';  i++; break;  }
                case 'f': { next='\f'; i++; break;  }
                case 'r': { next='\r'; i++; break;  }
                case '"': { next='\"'; i++; break;  }
                //case '\\': { next='\\'; cout<<"\nhere\n"; break;  }
                case 'b': { next='\b'; i++; break;  }
                case 'v': { next='\v'; i++; break;  }
                case '0': { next='\0'; i++; break;  }
            }
            out+=next;
        }else{
            out+=in[i];
        }
    }
    return out;
}

int main(){

    char ch = '\\';

    cout<<ch<<" "<<(int)ch<<"\n";
    return 0;
}