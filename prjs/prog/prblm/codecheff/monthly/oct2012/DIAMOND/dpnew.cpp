#include<stdio.h>
int main(){
int T;
    scanf("%d",&T);
     while(T-->0){
       int N;
       scanf("%d",&N);
       double ans=0.0;
       int a;
      double temp[3000];
      double sum = 0.0;
       for(int i=0;i<N;i++){
           scanf("%d",&a);
           temp[i]=a;
           ans+=temp[i];
       }
     //  ans=sum;
       for(int i=1;i<N;i++){
           sum=0.0;
           for(int j=0;j<N-i;j++){
               temp[j]=(temp[j]+temp[j+1])/2;
               ans+=(i%2==0?1:-1)*temp[j];
           }
         //  ans=ans+(i%2==0?1:-1)*sum;
       }
       printf("%lf\n",ans);
     }
}
