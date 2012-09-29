#include<stdio.h>
#define MAXPRIME 1000000
long long primes[100000];
typedef long long int ull;
int primecnt=0;
bool isPrime(long long n){
    for(int i=0;primes[i]*primes[i]<=n;i++){
        if(n%primes[i]==0){
            return false;
        }
    }
    return true;
}
void genprimes(){
    primes[primecnt++]=2;
    for(int i=3;i<MAXPRIME;i+=2){
        if(isPrime(i)){
            primes[primecnt++]=i;
        }
    }
}

ull gcd(ull a, ull b){
    ull t = 0;
    while(b!=0){
       t=b;
       b=a%b;
       a=t;
    }
    return a;
}
long long getnumfactors(long long N){
    int cnt=0;
    long long ans=1;
    int i=0;
    while(N>1){
        cnt=0;
        while(N%primes[i]==0){
            cnt++;
            N/=primes[i];
        }
        ans*=(cnt+1);
        i++;
        if(primes[i]>=MAXPRIME){
             if(N>1) {
                   ans*=2;
             }
           break;
        }
    }
    return ans;
}
int main(){
    genprimes();
    long long N;
    scanf("%lld",&N);
    long long numfactors = getnumfactors(N);   
    printf("%lld\n",numfactors);
}
