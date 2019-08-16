//#pragma once
#include<iostream>
//#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<iostream>
using namespace std;

class SymbolInfo {
private:
	string Name;
	string Type;
public:
	//bool operator==(SymbolInfo obj) { return(this->Name == obj.Name && this->Type == obj.Type); }
	 string code;
	SymbolInfo *next;
	int x, y;
	void PosXY() { cout << x << "," << y; }
	SymbolInfo() {  code="";  Name = ""; Type = ""; next = NULL; x = -1; y = -1; }
	 SymbolInfo(string symbol, string type){
            this->Name=symbol;
            this->Type=type;
            code="";
        }
        SymbolInfo(char *symbol, char *type){
            this->Name=string(symbol);
            this->Type= string(type);
            code="";
        }

        SymbolInfo(const SymbolInfo *sym){
         	Name=sym->Name;
         	Type=sym->Type;
         	code=sym->code;
        }
	string GetName() { return Name; }
	string GetType() { return Type; }
	void SetName(const string &s) { this->Name = s; }
	void SetType(const string &t) { this->Type = t; }
	~SymbolInfo() { next = NULL;/*if (next != NULL) delete next;*/ } // ei line e something jhamela kore... 

};

class ScopeTable {
private:

public:
	SymbolInfo **p;
	int N, pos, id; string s;
	int i1, j1;
	ScopeTable *parentScope;


	//int HashFunc(){ return (pos+1)%N;	}

	ScopeTable(int n = 7) {
		//id = UniqueId;
		N = n;
		pos = 0;
		parentScope = NULL;
		p = new SymbolInfo*[N];
		for (int i = 0; i<N; i++) {
			p[i] = NULL;
		}

	}

	void Seti1j1(int i, int j) { i1 = i; j1 = j; }

	SymbolInfo* LookUp(string s) {
		SymbolInfo *q;
		bool b = false;
		for (int i = 0; i<N; i++) {
			q = p[i];
			int j = 0;
			while (q != NULL) {
				if (q->GetName() == s) { Seti1j1(i, j); b = true;	return q; }
				else { q = q->next; j++; }
			}
		}
		if (b == false) return NULL;
	}

	bool Insert(string s, string t) {
		bool b = false;
		if (LookUp(s) != NULL) { return b; }// ei line n

		pos = (pos + 1) % N;// hash func
		if (p[pos] == NULL) {
			SymbolInfo *q;
			q = new SymbolInfo; q->SetName(s); q->SetType(t);
			p[pos] = q;
			q = NULL;
			b = true;
		}
		else {
			SymbolInfo *Next;
			Next = p[pos];
			while (Next->next != NULL) {
				Next = Next->next;
			}
			SymbolInfo *q; q = new SymbolInfo; q->SetName(s); q->SetType(t);
			Next->next = q;
			b = true;
			Next = NULL; q = NULL;
		}
		SymbolInfo *g;
		g = LookUp(s);
		g->x = i1; g->y = j1;
		return b;
	}

	void Print(FILE *ptr) {
		
		FILE *fptr; fptr = ptr;
		for (int i = 0; i<N; i++) {
			SymbolInfo *curr;
			curr = p[i];
			bool b;
			if (curr == NULL) { b = false; }	else { b = true; }
			if(b==false) continue;
			else if(b==true){
					fprintf(fptr,"%d-->", i);
				//cout << "A[" << i << "]-->";
				while (b) {
					string s1, s2;
					s1 = curr->GetName();
					s2 = curr->GetType();
					char ch;	
					fprintf(fptr,"< ");	
					int len = s1.length();
					for(int i=0; i<len; i++){ ch = s1[i]; fprintf(fptr, "%c", ch); }
					fprintf(fptr," : ");		
					len = s2.length();
					for(int i=0; i<len; i++){ ch = s2[i]; fprintf(fptr, "%c", ch); }
					fprintf(fptr," > ");
					// fprintf(fptr,"< %s : %s > ",s1 ,s2 );
					//cout << "< " << curr->GetName() << " : " << curr->GetType() << " >  ";
					curr = curr->next;
					if (curr == NULL)break;
				}
				fprintf(fptr,"\n");
				//cout << " \n";
			}			
		}//for 
		fprintf(fptr,"\n");
			//cout<<"\n";
			fptr = NULL;
		
		
		/*************
		for (int i = 0; i<N; i++) {
			SymbolInfo *curr;
			curr = p[i];
			bool b;
			if (curr == NULL) { b = false; }
			else { b = true; }
			cout << "A[" << i << "]-->";
			while (b) {
				cout << "< " << curr->GetName() << " : " << curr->GetType() << " >  ";
				curr = curr->next;
				if (curr == NULL)break;
			}
			cout << " \n";
		}
		cout<<"\n";
		************/
	}


	void DeleteAll() {
		SymbolInfo *curr, *q;
		for (int i = 0; i<N; i++) {
			if (p[i] != NULL) {// r o kisu hobe
				q = p[i];
				p[i] = NULL;
				while (true) {
					curr = q;
					q = q->next;
					delete curr;
					if (q == NULL) break;

				}


				//delete p[i];
			}

		}
	}

	~ScopeTable() {
		DeleteAll();
		//Print();
		delete p;
	}

	bool Delete(string s) {
		bool b = false;
		SymbolInfo *prev, *curr;
		curr = LookUp(s);
		if (curr == NULL) return b;
		else {

			int i2 = i1; int j2 = j1;
			if (j2 == 0) {
				p[i2] = curr->next;
				curr->next = NULL;
				delete curr;
				b = true;
			}
			else {
				prev = p[i2];
				j2 -= 1;
				while (j2--) {
					prev = prev->next;
				}
				// now we've got prev and curr '
				prev->next = curr->next;
				curr->next = NULL;
				delete curr;
				b = true;
				prev = NULL;
			}
		}
		return b;
	}

};


class SymbolTable {
public:
	ScopeTable *curr;
	int id;
	int Size;

	//void Getxy() { if (curr != NULL) x = curr->i1; y = curr->j1; }

	SymbolTable(int n = 8) { curr = NULL; id = 0; Size = n; EnterScope(); }
	~SymbolTable() {
		while (curr != NULL) {
			ExitScope();
		}
	}

	void EnterScope() {
		id++;
		ScopeTable *p;
		p = new ScopeTable(Size);
		p->id = id;
		//if (curr != NULL) {
		p->parentScope = curr;
		curr = p;
		//}

	}

	void ExitScope() {
		if (curr != NULL) {
			ScopeTable *p;
			p = curr;
			curr = curr->parentScope;
			p->parentScope = NULL;
			//p->~ScopeTable();//ei 2 line e jhamela korte pare!!!
			delete p;
			id--;
		}

	}
	bool Insert(string s, string t) {
		bool b = false;
		if (curr != NULL) {
			b = curr->Insert(s, t);
			//if (b == true) {
			//Getxy();//x = curr->i1; y = curr->j1;
			//}//cout<<" in current scope#"<<id<<endl;
			//b=true;
		}
		return b;
	}

	bool Remove(string s) {
		bool b = false;
		if (curr != NULL) {
			b = curr->Delete(s);
		}
		return b;
	}

	SymbolInfo* LookUp(string s) {
		ScopeTable *p; SymbolInfo *result;
		result = NULL;
		p = curr;
		while (p != NULL) {
			result = p->LookUp(s);
			if (result == NULL) p = p->parentScope;
			else { return result; }
		}
		return result;
	}
	void PrintCurrentScopeTable(FILE *ptr) {
		FILE *fptr; fptr = ptr;  
		//cout << "\nScope#" << curr->id << "\n\n"; 
		fprintf(fptr,"\nScopeTable#%d\n\n", curr->id);		
		curr->Print(fptr); 	fptr = NULL;
	}

	void PrintAllScopeTable(FILE *ptr) {
		FILE *fptr; fptr = ptr; 
		ScopeTable *p;
		p = curr;
		while (p != NULL) {
			//cout << "\nScope#" << p->id << "\n\n";
			fprintf(fptr,"\nScopeTable#%d\n\n", p->id);
			p->Print(fptr);
			p = p->parentScope;
		}
		fptr = NULL;
	}

};



