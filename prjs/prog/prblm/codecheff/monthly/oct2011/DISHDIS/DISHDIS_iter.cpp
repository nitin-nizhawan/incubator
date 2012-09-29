#include<stdio.h>
#include<stdlib.h>

const long MOD=1000000007L;

class Cook {
    public:
    long x,y;
};
Cook cooks[101];
long dp[101][101];
long n,m;


long solve(){
    long minsum=0,maxsum=0;
    for(int i=1;i<=m;i++){
        minsum = minsum + cooks[i].x;
        maxsum = maxsum + cooks[i].y;
    }
    if(minsum>n||maxsum<n){
        return 0;
    }
    for(int i=1;i<=m;i++){
        cooks[i].y = cooks[i].y - cooks[i].x;
        cooks[i].x = 0;
    }
    n = n- minsum;
    dp[0][1] = 1;
    for(int i=1;i<=n;i++){
        dp[i][1]=dp[i-1][1] +(i<=cooks[1].y?1:0);
    }
    for(int i=0;i<=m;i++){
        dp[0][i]=1;
    }

    for(int i=2;i<=m;i++){
        for(int j=1;j<=n;j++){
            long sum = dp[j][i-1];
            if((j-cooks[i].y-1)>=0){
                sum = sum - dp[j-cooks[i].y-1][i-1];
            }
            dp[j][i] = (dp[j-1][i] + sum)%MOD;
        }
    }
   long ret = dp[n][m]-dp[n-1][m];
   return (ret+MOD)%MOD;
}



int main(){
int T;
 scanf("%d",&T);
 while(T--){

    scanf("%ld",&n);
    scanf("%ld",&m);
    for(int i=1;i<=m;i++){
        scanf("%ld",&(cooks[i].x));
        scanf("%ld",&(cooks[i].y));
    }
        printf("%ld\n",solve());
}

return 0;
}

