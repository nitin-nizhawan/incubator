/*
ID: nitin.n1
PROG: calfflac
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class Node {
public:
  char ch;
  int pos;
};
char inp[22000]={'\0'};
int even[22000];
int odd[22000];
Node cnodes[22000];
int cnodes_size=0;
int size=0;
char tu(char a){
    if('a'<=a&&a<='z'){
        return a-32;
    }
    return a;
}
bool cim(char a,char b){
   return (tu(a)==tu(b));
}
int max_evn_palin(int i){
    int s=i-1; 
    int e=i+2;
    int l=2;
    while(s>=0&&e<cnodes_size&&cim(cnodes[s].ch,cnodes[e].ch)){
          l+=2;
          s-=1;
          e+=1;
    }
    return l;
}
int max_odd_palin(int i){
   int s=i-2;
   int e=i+2;
   int l=3;
//cout<<"i:"<<i<<" s:"<<s<<" e:"<<e<<" ch:s:"<<cnodes[s].ch<<" ch:e:"<<cnodes[e].ch<<endl;
   while(s>=0&&e<cnodes_size&&cim(cnodes[s].ch,cnodes[e].ch)){
//cout<<"i:"<<i<<" s:"<<s<<" e:"<<e<<" ch:s:"<<cnodes[s].ch<<" ch:e:"<<cnodes[e].ch<<endl;
       l+=2;
       s-=1; e+=1;
   }
   return l;
}
void solve(int &s,int &e, int &len){
   int odd_p=0,evn_p=0; // even add palindromes count
   int evn_len=2; // startin with two char palins
   len=1; 
   s=e=cnodes[0].pos;
// even palindromes
   for(int i=0;i<cnodes_size-1;i++){
       if(cim(cnodes[i].ch,cnodes[i+1].ch)){
           int l = max_evn_palin(i);
           if(l>len){
               len=l;
               s=cnodes[i-(l-2)/2].pos; e = cnodes[i+l/2].pos;
           }  
       }
   }
   for(int i=0;i<cnodes_size-2;i++){
       if(cim(cnodes[i].ch,cnodes[i+2].ch)){
           int l = max_odd_palin(i+1);
           if(l>len){
               len=l;
               s=cnodes[i-(l-3)/2].pos; e = cnodes[i+(l+1)/2].pos;
           }
       }
   }  
}
int main() {
    ofstream fout ("calfflac.out");
//    ifstream fin ("calfflac.in");
    FILE * fin = fopen ("calfflac.in","r");
    char buff[100];
    while(fgets(buff,98,fin)){
        int i=0;
   //cout<<buff<<endl; 
        while(buff[i]!='\0'){
            inp[size++]=buff[i];
            i++;
        }
        //inp[size++]='\n';
    } 
    inp[size-1]='\0';
    int i=0;
    while(inp[i]!='\0'){
      if(('A'<=inp[i]&&inp[i]<='Z')||('a'<=inp[i]&&inp[i]<='z')){
        cnodes[cnodes_size].ch = inp[i];
        cnodes[cnodes_size++].pos=i;
      }
        i++;
    }
    int s,e,len;
    solve(s,e,len);
    fout<<len<<endl;
    for(int i=s;i<=e;i++){
        fout<<inp[i];
    }
    fout<<"\n";
    return 0;
}

