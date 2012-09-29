#include<iostream>
#include<string>
using namespace std;

int strlen(char* str){
 int len=0;
 while(str[len++]!='\0');
 return len-1;
}
long long strhash(char * str,int len){
    // only for uppercase alphabets
  long long base = 26;
  long long retVal = 0;
  for(int i=0;i<len;i++){
   retVal = retVal*base + (long long)(str[i]-'A');
  }
  return retVal;
}
long long intPow(long long base,long long pow){
  long long retVal = 1;
   while(pow-->0){retVal*=base;}
  return retVal;
}
long long roll_hash(char *str,long long hashVal,int i,int len){
    long long base = 26;
    long long remVal = ((long long)(str[i-len]-'A'))*intPow(base,len-1);
    return (hashVal-remVal)*base+(long long)(str[i]-'A');
}
int rabinKarpSearch(char* str,char* sstr){
    int pos = -1;
     
    int t_len = strlen(str);
    int s_len = strlen(sstr);
    long long hstr = strhash(str,s_len); // only first s_len chars
    long long hsstr = strhash(sstr,s_len);
  
    for(int i=0;i<t_len-s_len;i++){
        if(hstr==hsstr){
            bool flag=true;
            for(int j=0;j<s_len;j++){
                if(sstr[j]!=str[i+j]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                return i;
            }
            
        }
        hstr = roll_hash(str,hstr,i+s_len,s_len);
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
     int padding = rabinKarpSearch(str,sstr);
     print_padding(padding);
     cout<<sstr<<endl<<endl;
 }
}
