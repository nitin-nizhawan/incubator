/*
ID: nitin.n1
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class Name {
  public:
  char name[15];
};
int strcmp(char s[],char t[]){
   int l1=0,l2=0;
    while(s[l1++]!='\0');
    while(t[l2++]!='\0');
    if(l1!=l2) return -1;
    int i=0;
    while(s[i]!='\0'){
        if(s[i]!=t[i]) return 1;
      i++;
    }
     return 0;
}
int find(Name & tmp,Name names[],int n){
    for(int i=0;i<n;i++){
        if(!strcmp(tmp.name,names[i].name)){
            return i;
        }
    }
    return -1;
}
int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    int given[10], recieved[10];
    
    int NP;
    Name tmp;
    Name fnames[10];
    fin>>NP;    
    for(int i=0;i<NP;i++){
        given[i]=0;
        recieved[i]=0;
        fin>>fnames[i].name;
    }
    for(int i=0;i<NP;i++){
        fin>>tmp.name;
        int C,f;
        int g = find(tmp,fnames,NP);
        fin>>C>>f;
        int part = 0; 
        if(f>0){
           part =  C/f;
        }

         for(int k=0;k<f;k++){
             fin>>tmp.name;
             int r = find(tmp,fnames,NP);
             recieved[r]+=part;
             given[g]+=part;
         }
    }
    for(int i=0;i<NP;i++){
       fout<<fnames[i].name<<" "<<recieved[i]-given[i]<<endl;
    }
    return 0;
}

