#include<stdio.h>
typedef long long int ull;
long long N;
long long Q;
ull gcd(ull a, ull b){
    ull t = 0;
    while(b!=0){
       t=b;
       b=a%b;
       a=t;
    }
    return a;
}
long long ps[500];
long long as[500];
long long fcnt=1;
long long pcnt=0;
void init(){
    long long x = N;
    for(long long i=2;i*i<=N;i++){
      if(x%i==0){
        while(x%i==0){
            as[pcnt]++;
            x/=i;
        }
        fcnt*=(as[pcnt]+1);
        ps[pcnt++]=i;
      }
    }
    if(x>1){
      as[pcnt]=1;
      ps[pcnt++]=x;
      fcnt*=2;
    }
    
}
long long factors(long long n){
    long long ans=1;
    int tcnt=0;
    for(int i=0;i<pcnt;i++){
        tcnt=0;
        while(n%ps[i]==0){
            tcnt++;
            n/=ps[i];
        }
        ans*=(tcnt+1);
    }
    return ans;
}
void printans(long long n){
   printf("%lld\n",n);
}
void solve1(long long n){
    long long gcd1 = gcd(N,n);
    long long ans = factors(gcd1);
    printans(ans);
}
void solve2(long long n){
    if(N%n>0){ printans(0); return; };
    long long  ans = factors(N/n);
    printans(ans);
}

void solve3(long long n){
    if(N%n>0) { printans(fcnt); return; }
    long long ans = factors(N/n);
    printans(fcnt-ans);
}
int main(){
    scanf("%lld",&N);
    scanf("%lld",&Q);
    int T;
     long long n;
     init();
    while(Q-->0){
        scanf("%d",&T);
	scanf("%lld",&n);
        if(T==1){
           solve1(n);
        } else if(T==2){
           solve2(n);
        } else {
           solve3(n);
        }
    }
}
