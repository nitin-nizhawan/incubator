#include<stdio.h>
#include<algorithm>

using namespace std;
int S[9000];
int abs1(int a){
   if(a<0){
     a=0-a;
   }
   return a;
}
int main(){
  int T;
  scanf("%d",&T);
   while(T-->0){
       int N;
       scanf("%d",&N);
       for(int i=0;i<N;i++) scanf("%d",&S[i]);
       sort(S,S+N);
       int diff = 1000000001;
       for(int i=1;i<N;i++){
           if(abs1(S[i-1]-S[i])<diff){
               diff = abs1(S[i-1]-S[i]);
           }
       }
       printf("%d\n",diff);
   }
}


