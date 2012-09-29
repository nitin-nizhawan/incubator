#include<stdio.h>
int main(){
   int T,P,missing,L,F,R;
   long total_sum=0;
   long missum = 0;
   scanf("%d",&T);
   while(T--){
       scanf("%d",&P);
       scanf("%d",&F);
       missum = 0;
       while(F--){
           scanf("%d",&missing);
           missum+=missing;
      }
      scanf("%d",&R);
      int Pb2 = P>>1;
      float L = (P&1)?(Pb2+1):Pb2;
      total_sum = ((P*(P+1))>>1) - missum;
      printf("%0.4f\n",((L-R)*total_sum)/L);
   }
}
