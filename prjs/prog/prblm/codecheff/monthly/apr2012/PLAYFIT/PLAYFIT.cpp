#include<stdio.h>


int N;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
         scanf("%d",&N);
         int maxsum=0;
         int lastV=0,tmp,g;
         scanf("%d",&lastV);
         for(int i=0;i<(N-1);i++){
             scanf("%d",&g);
             tmp = g-lastV;
             if(tmp>maxsum){
                 maxsum = tmp;
             }
             if(tmp<=0){
                 lastV=g;
             }
         }
         if(maxsum<=0){
             printf("UNFIT\n");
         } else {
             printf("%d\n",maxsum);
         }
    }
}
