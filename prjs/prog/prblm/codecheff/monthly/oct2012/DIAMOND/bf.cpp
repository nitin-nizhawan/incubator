#include<stdio.h>


int dimc[500];
int cnt[501];
int ALICE=1;
int play(int turn,int beg,int end){
   int ret=0;
   int d;
    if(beg<end){
        d=play(1-turn,beg+1,end);
        if(turn==ALICE){
            cnt[dimc[beg]]+=1<<(end-beg-1);
        }
        ret+=d+1;
        d=play(1-turn,beg,end-1);
        if(turn==ALICE){
            cnt[dimc[end]]+=1<<(end-beg-1);
        }
        ret+=d+1;
    } else if(turn==ALICE){
        cnt[dimc[beg]]++;
        ret=1;
    }
    return ret;
}
int main(){
   int n;
   scanf("%d",&n);
   for(int i=0;i<=n;i++){
       cnt[i]=0;
   }
   for(int i=0;i<n;i++){
       dimc[i]=i+1;
   }
   play(ALICE,0,n-1);
  for(int i=0;i<=n;i++){
    printf("%d ",cnt[i]);
  }
  printf("\n");
}
