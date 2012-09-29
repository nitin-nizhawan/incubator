#include<stdio.h>

long long PRIME=1000000007LL;
long long dp[1005][1005]={0};
long long cum[1005]={0};
int n;
void init(){
    int N = 1001;
  for(int i=1;i<=N;i++){
          for(int j=1;j<=i;j++){
              if(i==1||j==1){
                  dp[i][j]=1;
              } else {
                  dp[i][j] = (((dp[i-1][j]*j)%PRIME)+dp[i-1][j-1])%PRIME; 
              }
              cum[i]+=dp[i][j];
          }
      }
}
int brute_force(int n,int d){
    int sum =1;
    if(d>1){
        sum=0;
        for(int i=1;i<=(n+1);i++){
            sum+=brute_force(i,d-1);
        }
    }
    return sum;
}
int main(){
  int T;
  scanf("%d",&T);
  init();
  while(T--){
      scanf("%d",&n);
          //printf("%d %d  %d\n",n,dp[n-1][0],brute_force(1,n));
          printf("%lld\n",cum[n]%PRIME);
  }

}
