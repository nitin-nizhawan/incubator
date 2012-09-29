#include<iostream>
#include<string>
using namespace std;

int strlen(char* str){
 int len=0;
 while(str[len++]!='\0');
 return len-1;
}
int naiveSearch(char* str,char* sstr){
    int pos = -1;
   
    int t_len = strlen(str);
    int s_len = strlen(sstr);
    int c=0;
   
    while(c<t_len-s_len){    
        int i=0;
        while(str[i+c]==sstr[i]&&sstr[i]!='\0'){
            i++;
        }
        if(i>=s_len){
         pos=c;
         break;
        }
        c++;
    }
    return pos;
}

void print_padding(int n){
  for(int i=0;i<n;i++) cout<<" ";
}
int main(){
 char str[100], sstr[100];
 while(cin>>str){
     cin>>sstr;
     cout<<str<<endl;
     int padding = naiveSearch(str,sstr);
     print_padding(padding);
     cout<<sstr<<endl<<endl;
 }
}
