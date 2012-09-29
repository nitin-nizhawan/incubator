#include<stdio.h>
#include<string.h>
int main(){
   int T,P,missing,L,F,R;
   long total_sum=0;
   long missum = 0;
   scanf("%d",&T);
   while(T--){
       scanf("%d",&P);
       scanf("%d",&F);
       total_sum=0;
       missum = 0;
       while(F--){
           scanf("%d",&missing);
           missum+=missing;
      }
      scanf("%d",&R);
      L = ((P%2==0)?P/2:((P/2)+1));
      total_sum = ((P*(P+1))/2) - missum;
      printf("%0.4f\n",((float)(L-R)*total_sum)/((float)L));
   }
}
