#include<stdio.h>
typedef unsigned long long ull;
ull MOD=1000000007;
ull expow(ull n){
    ull mat[2][2]={ 
                   {2,2},
                   {1,0}
            };
    ull uni[2][2] = {
        {1,0},
        {0,1}
    };
    ull t00,t01,t10,t11;
    while(n>0){
        if(n%2){
            t00 = (uni[0][0]*mat[0][0])%MOD + (uni[0][1]*mat[1][0])%MOD;
            t01 = (uni[0][0]*mat[0][1])%MOD + (uni[0][1]*mat[1][1])%MOD;
            t10 = (uni[1][0]*mat[0][0])%MOD + (uni[1][1]*mat[1][0])%MOD;
            t11 = (uni[1][0]*mat[0][1])%MOD + (uni[1][1]*mat[1][1])%MOD;
            uni[0][0] = t00%MOD; uni[1][0] = t10%MOD;
            uni[0][1] = t01%MOD; uni[1][1] = t11%MOD;
        }
            t00 = (mat[0][0]*mat[0][0])%MOD + (mat[0][1]*mat[1][0])%MOD;
            t01 = (mat[0][0]*mat[0][1])%MOD + (mat[0][1]*mat[1][1])%MOD;
            t10 = (mat[1][0]*mat[0][0])%MOD + (mat[1][1]*mat[1][0])%MOD;
            t11 = (mat[1][0]*mat[0][1])%MOD + (mat[1][1]*mat[1][1])%MOD;
            mat[0][0] = t00%MOD; mat[1][0] = t10%MOD;
            mat[0][1] = t01%MOD; mat[1][1] = t11%MOD;

        n/=2;
    }
    ull ini[2] = {3,1};        
    return ((uni[0][0]*3)%MOD + uni[0][1])%MOD;
}
ull solve(ull n){
    if(n==1) return 1;
    if(n==2) return 3;
    return expow(n-2);
}
int main(){
    int T;
    scanf("%d",&T);
    ull N;
    while(T--){
     scanf("%llu",&N);
     printf("%llu\n",solve(N));
    }
}
