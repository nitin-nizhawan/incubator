#include<cstdio>
typedef unsigned long long ull;
char num1[100004];
char num2[100004];
ull num1bits;
ull num2bits;
ull size;
void inp(){
scanf("%llu",&size);
scanf("%s",num1);
scanf("%s",num2);
}
ull sbitadd(ull b1,ull b2){
   if(b1==0&&b2
}
ull bitadd(ull b1, ull b2, ull c){
    b1= sbitadd(b1,b2);
}
void solve(){
  num1bits=num2bits=0;
  for(ull i=0;i<size;i++){
      if(num1[i]=='1'){
          num1bits++;
      }
      if(num2[i]=='1'){
          num2bits++;
      }
      // complement num1, we need to do subraction lateron
      num1[i]='1'-num[i]+'0';
  }
  // add 1 to calc 2's complement
  ull cnt = size-1;
   while(num1[cnt]=='1'){
     num1[cnt]='0';
     cnt--;
   }
  num1[cnt]='1';
  // subtract num1 from num2
  ull carry=0;
  for(ull i=size-1;i>=0;i++){
     bitadd(bit1,bit2,carry);     
  }
}
int main(){
   scanf("%d",&T);
   while(T--){
    inp();
    solve();
   }
}
