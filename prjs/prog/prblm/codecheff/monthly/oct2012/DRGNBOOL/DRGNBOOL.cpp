#include<stdio.h>
int N,M;
int C[200];
int main(){
    int T;
    scanf("%d",&T);
    int ans=0;
    while(T-->0){
        ans=0;
        scanf("%d",&N);
        scanf("%d",&M);
        for(int i=0;i<=100;i++) C[i]=0;
       for(int i=0;i<N;i++){
          int c,l;
          scanf("%d",&c);
          scanf("%d",&l);
          C[l]+=c;
       }
       for(int i=0;i<M;i++){
          int c,l;
          scanf("%d",&c);
          scanf("%d",&l);
          if(C[l]<c){
            if(C[l]>0){
                ans+=(c-C[l]);
            } else {
                ans+=c;
            }
          }
          C[l]-=c;
       }
       printf("%d\n",ans);
    }
}
