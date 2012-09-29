#include<stdio.h>


long long N,M;
long long solve(long long N,long long M){
    long long ans=0;
    for(int a=1;a<=N;a++){
        for(int b=1;b<a;b++){
            if((a+b)%M==0){
                ans++;
            }
        }
    }
    return ans;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%lld",&N);
        scanf("%lld",&M);
        printf("%lld\n",solve(N,M));

    }
}
