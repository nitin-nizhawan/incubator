#include<stdio.h>
#include<stdlib.h>
#define NUM_PRIMES 9000
typedef unsigned long long ull;
typedef unsigned long long uint64;
typedef long long dll;
ull  primes[NUM_PRIMES];
int primes_cnt=0;
ull MOD = 500009;
int buckets[5000]={0}; // we need only about 1K buckets

dll min(dll a, dll b){
    return (a>b)?b:a;
}

uint64 gcd(uint64 u, uint64 v)
 {
     int shift;
 
     /* GCD(0,x) := x */
     if (u == 0 || v == 0)
       return u | v;
 
     /* Let shift := lg K, where K is the greatest power of 2
        dividing both u and v. */
     for (shift = 0; ((u | v) & 1) == 0; ++shift) {
         u >>= 1;
         v >>= 1;
     }
 
     while ((u & 1) == 0)
       u >>= 1;
 
     /* From here on, u is always odd. */
     do {
         while ((v & 1) == 0)  /* Loop X */
           v >>= 1;
 
         /* Now u and v are both odd, so diff(u, v) is even.
            Let u = min(u, v), v = diff(u, v)/2. */
         if (u < v) {
             v -= u;
         } else {
             uint64 diff = u - v;
             u = v;
             v = diff;
         }
         v >>= 1;
     } while (v != 0);
 
     return u << shift;
}
ull brent(ull N){
    if(N%2==0){
        return 2;
    }
    dll y,c,m;
    y = rand()%(N-1)+1; y = y*(ull(rand()%(N-1)+1));
    c = rand()%(N-1)+1; c = y*(ull(rand()%(N-1)+1));
    m = rand()%(N-1)+1; m = y*(ull(rand()%(N-1)+1));
    dll g=1,r=1,q=1;
    while(g==1){        
        dll x = y;
        for (ull i=0;i<r;i++){
            y = ((y*y)%N+c)%N;
        }
        dll k = 0;
        while (k<r && g==1){
            dll ys = y;
            for(ull i=0;i<min(m,r-k);i++){
                y = ((y*y)%N+c)%N;
                q = q*(abs(x-y))%N;
            }
            g = gcd(q,N);
            k = k + m;
        }
        r = r*2;
    }
    if (g==N){
        while(true){
            ys = ((ys*ys)%N+c)%N;
                g = gcd(abs(x-ys),N);
                if (g>1){
                    break;
                }
        }
    }

    return g;
}

ull num_factors(ull n){
    ull p = primes[0];
    int i=0;
    ull ans=1;
    while(p*p<=n){
        ull tmp=0;
        while(n%p==0){
            tmp++;
            n/=p;
        }
        ans = ans*(tmp+1);
        p = primes[++i];
    }
    if(n>1){
        ans = ans*2; // one last prime greater than sqrt
    }
    return ans;
}
bool isPrime(ull n){
    ull p = primes[0];
    int i=0;
    while(p*p<=n){
        if(n%p==0){
            return false;
        }
        p = primes[++i];
    }
    return true;
}
void init_primes(){
    primes[0]=2;
    primes_cnt=1;
    for(int i=3;primes_cnt<NUM_PRIMES;i+=2){
        if(isPrime(i)){
            primes[primes_cnt++]=i;
        }
    }
}
int main(int argc, char* argv[]){
    init_primes();
    printf("%llu\n", primes[NUM_PRIMES-1]);
    ull N;
    scanf("%llu",&N);
    ull ans=1;
    printf("Factor: %llu\n",brent(N));
    /*
    for(ull i=1;i<=N;i++){
        int n_factors = num_factors(i);
        buckets[n_factors-1]= (buckets[n_factors-1] + 1)%MOD;
        ans = (ans*buckets[n_factors-1])%MOD;
        printf("%10llu %10llu\n",i,ans);
    }
    */
}
