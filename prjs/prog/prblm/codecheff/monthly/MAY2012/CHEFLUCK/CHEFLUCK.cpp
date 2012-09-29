#include<stdio.h>
/**
 * algorithm
 * Let N be of form 7*k + R, and let R%4 = S
 * then f(N) = f(7*k + R), since we know that f(N) = f(N-4) and
 *  that f(7*a) = 7*a
 * f(7*k + 4 ) = f(7*k + 4 - 4) = f(7*k) = 7k
 * f(7*k + 1 ) = f(7*k + 1 - 4) = f(7*k - 3) = f(7*(k-1) + 4) = 7*(k-1) =7k-7
 * f(7*k + 5) = f(7*k + 1) = 7*(k-1) = 7*k - 7
 * f(7*k +2 ) = f(7*k - 2 ) = f(7*(k-1) + 5) = 7*(k-2) = 7*k - 7*2
 * f(7*k + 6) = f(7*k + 2) = 7*(k-2) = 7*k - 7*2
 * f(7*k + 3) = f(7*k - 1 ) = f(7*(k-1) + 6) = 7*(k-3) = 7*k - 3*7
 * general formula is 7k - 7*(R%4) = 7k - 7*((N%7)%4) = (N-(N%7))-7*((N%7)%4)
 */
int main(){
    int T;
    scanf("%d",&T);
    long long N;
    while(T--){
        scanf("%lld",&N);
        long long ans = (N - (N%7)) - ((N%7)%4)*7;
        printf("%lld\n",(ans>=0)?ans:-1);
    }
}
