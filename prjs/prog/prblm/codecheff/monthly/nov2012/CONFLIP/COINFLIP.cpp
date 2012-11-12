#include<stdio.h>
int main(){
    int T;
    scanf("%d",&T);
    while(T-->0){
        int G;
        scanf("%d",&G);
        while(G-->0){
    int I;scanf("%d",&I);
        long long N;
        scanf("%lld",&N);
        
        int Q;scanf("%d",&Q);
          if(N%2==0){
              printf("%lld\n",N/2);
          } else {
              if(Q==I){
                 printf("%lld\n",(N-1)/2);
              } else {
                 printf("%lld\n",N-(N/2));
              }
          }
          }
    }
    return 0;
}
