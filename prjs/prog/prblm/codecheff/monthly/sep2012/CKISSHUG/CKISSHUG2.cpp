#include<stdio.h>


long long N;
long long PRIME=1000000007;
long long solve(){
    long long N_1 = N-1;
    long long N_1_2 = N_1/2;
    long long ans=(N_1_2*(N_1_2+1));
printf("ans_i=%lld\n",ans);
     ans=(ans+(N));
     printf("ans_f=%lld\n",ans);
    if(N%2==0) ans=(ans+(N/2));
    printf("ans_g=%lld\n",ans);
    return (ans+1);
}
int main(){

    int T;
    scanf("%d",&T);
    while(T-->0){
      scanf("%lld",&N);
      printf("%lld\n",solve());
    }
}
