#include<stdio.h>


long long N,M;
long long min1(long long a,long long b){
    return a<b?a:b;
}
long long sum1(long long p){
    return (p*(p+1))/2;
}
long long sumAP(long long ft,long long n,long long intv){
        return (n*(2*ft + (n-1)*intv))/2;
}
long long solve(long long N,long long M){
    if(M%2==0){
        long long kmax = (2*N-1)/M;
        long long k1 = N/M;
        long long p1 = (M/2)*sum1(k1)  - k1;
        long long k_dash = kmax - k1;
        long long p2 = k_dash*N - (M/2)*(k1*k_dash + sum1(k_dash));
        return p1+p2;
    } else {
        long long kmax = (2*N-1)/M;
        long long k1 = N/M;
        long long n_odd1 = (k1+1)/2;
        long long p1 = M*sum1(k1/2) -(k1/2) + sumAP(M-1,n_odd1,2*M)/2; // n_odd1* (((M-1) + 2*M*(n_odd1-1))/2)
        //------------------------
        long long n_e,n_o;
        long long ft_e,ft_o;
        long long kn  = kmax-k1;
        if((k1+1)%2==0){
            ft_e = (k1+1);
            ft_o = (k1+2);
            n_e = (kn+1)/2;
            n_o = kn/2;
        } else {
            ft_o =  k1+1;
            ft_e = k1+2;
            n_e = kn/2;
            n_o = (kn+1)/2;
        }
        long long p2 = N*kn - sumAP(M*ft_e,n_e,2*M)/2 - sumAP(M*ft_o-1,n_o,2*M)/2;
        return p1+p2;
    }
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
