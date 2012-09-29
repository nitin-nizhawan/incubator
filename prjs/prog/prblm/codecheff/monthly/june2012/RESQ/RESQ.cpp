#include<stdio.h>

int main(){
    int T;
    long long N;
    scanf("%d",&T);
    while(T--){
     scanf("%lld",&N);
     long long mindiff=(1<<30);
     long long tmp ;
      for(int i=1;i*i<=N;i++){
          if(N%i==0){
             tmp = i-(N/i);
             if(tmp<0) {tmp = -1*tmp;}
             if(tmp<mindiff){
                 mindiff=tmp;
             }
          }
      }
      printf("%lld\n",mindiff);
    }
}
