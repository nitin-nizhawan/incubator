#include<stdio.h>

using namespace std;
typedef unsigned long long ull;
ull MOD=1000000007;
ull modular_pow(ull base,ull exponent){
    ull result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % MOD;
        }
        exponent = exponent >> 1;
        base = (base * base) % MOD;
    }
    return result;
}
ull solve(ull a, ull b){
    if(a==1||b==1) return 2;
    ull s = ((a>>1)<<2)%(MOD-1);
    ull  s2 = (b>>1)%(MOD-1);
    ull ans = modular_pow(2,(s*s2)%(MOD-1));
    if(a%2==0){
        return (ans<<(b%2))%MOD;
    } else {
        return (ans<<1)%MOD;
    }
}
int main(){
    long T;
    scanf("%ld",&T);
    ull a,b;
    while(T--){
        scanf("%llu",&a);
        scanf("%llu",&b);
        printf("%llu\n",solve(a,b));
    }
}
