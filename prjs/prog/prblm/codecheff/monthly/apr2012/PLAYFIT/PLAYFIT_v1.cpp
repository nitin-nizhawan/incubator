#include<stdio.h>


int g[100005];
int N;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
         scanf("%d",&N);
         int maxsum=0;
         int last=0,tmp;
         for(int i=0;i<N;i++){
             scanf("%d",&g[i]);
             tmp = g[i]-g[last];
             if(tmp>maxsum){
                 maxsum = tmp;
             }
             if(tmp<=0){
                 last=i;
             }
         }
         if(maxsum<=0){
             printf("UNFIT\n");
         } else {
             printf("%d\n",maxsum);
         }
    }
}
