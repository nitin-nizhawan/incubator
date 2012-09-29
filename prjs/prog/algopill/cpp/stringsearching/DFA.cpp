#include<iostream>
#include<string>
using namespace std;
#define MAX_STR 100
int dfa[MAX_STR+1][26];
int strlen(char* str){
 int len=0;
 while(str[len++]!='\0');
 return len-1;
}
int min(int a,int b){
	return a<b?a:b;
}
void strcpy(char* src,char *dest){
	int i=0;
	while(src[i]!='\0'){
		dest[i]=src[i];
		i++;
	}
		dest[i]=src[i];

}
bool PkisSuffixOfPqa(char* P,int k, int q, char a,char* Pqa,char* Pk){
	strcpy(P,Pqa);
	Pqa[q]=a;
	Pqa[q+1]='\0';
	strcpy(P,Pk);
	Pk[k]='\0';
	while(k>=0){
		if(Pqa[q+1]!=Pk[k]){
			return false;
		}
		k--;
		q--;
	}
	return true;
}	
void createDFA(char* P){
	int len = strlen(P);
	char Pqa[MAX_STR+2];
	char Pk[MAX_STR];
    for(int q=0;q<=len;q++){
        for(int a=0;a<26;a++){ // for each alphabet
		int k = min(len+1,q+2);
		while(!PkisSuffixOfPqa(P,k,q,a+'A',Pqa,Pk)){
                     k--;
		}
		dfa[q][a]=k;
	}
    }
}
void print_dfa(int m){
	cout<<"------------------"<<endl;
	for(int i=0;i<=m;i++){
		for(int j=0;j<26;j++){
			cout<<dfa[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"------------------"<<endl;
}
int dfaSearch(char* str,char* sstr){
	createDFA(sstr);
     int str_len = strlen(str);
     int m = strlen(sstr);
	print_dfa(m);
     int q=0;//initial state
    for(int i=0;i<str_len;i++){
	    if((q=dfa[q][str[i]-'A'])==m){
		    return i-(m-1);
	    }
    }  
    return -1;
}

void print_padding(int n){
  for(int i=0;i<n;i++) cout<<" ";
}
int main(){
 char str[MAX_STR], sstr[MAX_STR];
 while(cin>>str){
     cin>>sstr;
     cout<<str<<endl;
     int padding = dfaSearch(str,sstr);
     print_padding(padding);
     cout<<sstr<<endl<<endl;
 }
}
