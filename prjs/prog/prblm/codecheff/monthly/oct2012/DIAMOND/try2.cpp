#include<stdio.h>
double dp3[2005][2005];
int clc=1;
void init(int n){
    if(n<=clc) return;
    for(int i=clc+1;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp3[i][j]=1-(dp3[i-1][j-1]+dp3[i-1][j])/2;
        }
    }
    clc=n;
}
int main(){
dp3[1][1]=1.0;
int T;
    scanf("%d",&T);
     while(T-->0){
       int N;
       scanf("%d",&N);
       double ans=0.0;
       int a;
      double temp[3000];
      double sum = 0.0;
       init(N);
       for(int i=0;i<N;i++){
           scanf("%d",&a);
           ans+=dp3[N][i+1]*a;
       }
     //  ans=sum;
       printf("%lf\n",ans);
     }
}
