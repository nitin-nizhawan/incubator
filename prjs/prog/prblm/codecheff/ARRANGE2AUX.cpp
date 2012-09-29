#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

unsigned long long ul[11]={5,50,500,5000,50000LLU,500000LLU,5000000LLU,50000000LLU,500000000LLU,5000000000LLU,50000000000LLU};
unsigned long long nn[11]={9,99,999,9999,99999LLU,999999LLU,9999999LLU,99999999LLU,999999999LLU,9999999999LLU,99999999999LLU};
unsigned long long calc(unsigned long long l, unsigned long long m){
     if(l%9>0){
        l=l+9-l%9;
     }
     if(m%9>0){
        m=m-m%9;
     }
     unsigned long long i2,i1,tmp=l,nd=0,count=0;
     int vec1[10]={0},nb = sizeof(int)*10,i;
     while(tmp){
      tmp/=10; nd++;
     }
     nd--;
     for(;l<=m;l+=9){
         if(l>=ul[nd]){
             l=nn[nd++]+9;
         }
         i1=l;
         i2 = i1<<1;
         while(i1){
             vec1[i1%10]++;
             i1/=10;
         }
         while(i2){
           int i = i2%10;
           if(vec1[i]<1){
              break;
           } else {
              vec1[i]--;
           }
           i2/=10;
        }
        if(i2<1){ count++;
        cout<<"[{"<<l<<"}]"<<endl;
        }
        memset(vec1,0,nb);    
     }
     return count; 
}
int main(){
 unsigned long long powv[5]={1000ULL,10000ULL,100000ULL,1000000ULL,10000000ULL};
 unsigned long long start = 100000ULL;
 unsigned long long inc = 1000ULL;
// cout<<"100000:"<<0<<" ";
//cout<<"unsigned long long abc[500][6]={"<<endl;
 unsigned long long last = 0;
for(int j=0;j<5;j++,inc*=10ULL){
  unsigned long long tmp =calc(start+1,start+inc);
  last = last + tmp; start+=inc;
 // if(j>0) { cout<<","; }
 // cout<<"{"<<last;
 for(int i=1;i<400;i++){
     tmp = calc(start+1,start+inc);
     last = last+tmp;
     start+=inc;
  //   cout<<","<<last;
 }
  start=start+inc*500;
  
//  cout<<"}"<<endl;
}
//cout<<"};"<<endl;


}
