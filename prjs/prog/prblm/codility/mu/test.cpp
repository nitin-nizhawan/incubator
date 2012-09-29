#include<stdio.h>
#define PRIME 1410000017
long long sol(long long N){
    if(N<1) return 1;
    long long correc = -1;
    long long cnst = 1;
    long long mult = 0;
    long long pow10 = 1;
    long long sum=0;
    long long lost=0;
    long long i=0;
    while(N){
        long long d = N%10;
        if(d>0){
            long long contrib = (cnst + (mult*(d-1))%PRIME)%PRIME;
            sum = (sum+contrib)%PRIME;
            // apply correction
            if(N/10>0){
                sum = (sum + correc)%PRIME;
            }
        } else {
            sum = (sum+lost)%PRIME;
        }
        // prepare for next iter
        lost = (lost + (pow10*d)%PRIME)%PRIME;
        cnst = ((cnst + (mult*9)%PRIME)+1)%PRIME;
        i=i+1;
        mult = (i*pow10)%PRIME;
        pow10 = (pow10*10)%PRIME;
        correc = (pow10 + correc -1)%PRIME;
        N = N/10;
    }
    return sum;
    
}
long long brute_force(long long N){
    long long sum=1;
    for(long long i=1;i<=N;i++){
        long long n = i;
        while(n){
            sum+=((n%10==0)?1:0);
            n/=10;
        }
    }
    return sum;
}
int main(){

    long long N;
    scanf("%lld",&N);
    printf("%lld   %lld\n",brute_force(N),sol(N));
}
