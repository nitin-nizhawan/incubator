#include<stdio.h>


long long N;
long long PRIME=1000000007;

long long pow2[32];
long long powme(long long base,long long exp){
    long long result = 1;
    while(exp>0){
        if(exp%2==1){
            result = (base*result)%PRIME;
            exp-=1;
        }
        base = (base*base)%PRIME;
        exp = exp/2;
    }
    return result;
}
int main(){
pow2[0]=1;
for(int i=1;i<32;i++){
    pow2[i] = (pow2[i-1]*2)%PRIME;
}
    int T;
    scanf("%d",&T);
    while(T-->0){
      scanf("%lld",&N);
      long long exp = (N/2);
//      printf("exp=%lld\n",exp);
      long long pow_2 = powme(2,exp)%PRIME;
       pow_2 = (pow_2*(3+(N%2)))%PRIME;
      long long ans = (pow_2-2 + PRIME)%PRIME;
      printf("%lld\n",ans);
    }
}
