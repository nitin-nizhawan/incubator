#include<stdio.h>
#include<stdlib.h>

int main(){
    int T=100;
    long long m = 1000000;
    long long k = 1000;
    long long N = 1000;
    printf("%d\n",T);
    while(T--){
         long long r1 = rand()%10000;
         long long m1 = (r1*1000)%m;
         long long k1 = rand()%k;
         long long N1 = rand()%N;
         printf("%lld %lld %lld\n",N1,m1,k1);
    }
}
