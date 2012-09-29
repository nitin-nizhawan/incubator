/*
ID: nitin.n1
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
char sym[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L'};
using namespace std;
void isPal(int n,int b,char rev[], char org[]){
    int size=0;
    while(n){
       rev[size]=sym[n%b];
       n/=b;
       size++;
    }
    int i=0;
    while(size--){
        org[i++]=rev[size];
    }
    org[i]=rev[i]='\0';
    
}
bool match(char a[], char b[]){
    int i=0;
    while(a[i]!='\0'&&b[i]!='\0'){
        if(a[i]!=b[i]) return false;
        i++;
    }
    return true;
}
int main() {
    ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");
    int b;
    fin >>b;
    for(int i=1;i<=300;i++){
        int sq = i*i;
        char  rsq[20],osq[20],oi[20],ri[20];
        
        isPal(i,b,ri,oi);
        isPal(sq,b,rsq,osq);
//    cout<<"i :"<<i<<" sq: "<<sq<<" rsq: "<<rsq<<" osq :"<<osq<<"\n"; 
        if(match(rsq,osq)){
            fout<<oi<<" "<<osq<<endl;
        }
    }
    return 0;
}

