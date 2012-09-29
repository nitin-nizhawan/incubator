#include<iostream>
using namespace std;

char str[150];
int strlen(char* str){
  int  len=0;
  while(str[len]!='\0'){len++;}
  return len;
}
int getVal(char * str){
int val=0;
int i=0;
  while(str[i]!='\0'){
      switch(str[i]){
          case 'I': val+=1; break;
          case 'V': val+=5; break;
          case 'X': val+=10; break;
          case 'L': val+=50; break;
          case 'C': val+=100; break;
          case 'D': val+=500; break;
          case 'M': val+=1000; break;
      }
      i++;
  }
return val;
}
void setChar(int &val, int denom,int &pos){
  while(val>=denom){
      val-=denom;
      pos++;
  }
}
int minRoman(int val){
    int pos=0; 
    setChar(val,1000,pos); 
    setChar(val,500,pos); 
    setChar(val,100,pos); 
    setChar(val,50,pos); 
    setChar(val,10,pos); 
    setChar(val,5,pos); 
    setChar(val,1,pos); 
    str[pos]='\0';
    return pos;
}
int main(){
  int sum=0;
  for(int i=0;i<1000;i++){
      cin>>str;
      int len=strlen(str);
      cout<<str;
      int saving =(len-minRoman(getVal(str)));
      cout<<"  saving : "<<saving<<endl;
      sum+=saving;
  }
  cout<<sum<<endl;
}
