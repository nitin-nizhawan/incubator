#include<stdio.h>

typedef unsigned long long ull;

ull A,B,C,D,K;
ull gcd(ull a, ull b){
    ull t = 0;
    while(b!=0){
       t=b;
       b=a%b;
       a=t;
    }
    return a;
}
ull solve(){
    ull gcd1 = gcd(A,B);
    ull gcd2 = gcd(C,D);
    ull gcd12 = gcd(gcd1,gcd2);
    ull lcmp1 = gcd1/gcd12;
    ull lcmp2 = gcd2;
    ull ans = (K/lcmp1)/lcmp2;
    return (2*ans)+1;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%llu",&A);
        scanf("%llu",&B);
        scanf("%llu",&C);
        scanf("%llu",&D);
        scanf("%llu",&K);
        printf("%llu\n",solve());
    }
}
