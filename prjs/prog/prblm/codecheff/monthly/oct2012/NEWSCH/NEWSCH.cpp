#include<stdio.h>
#define pm(a,b) ((a*b)%PRIME)
int n;
int cnt=0;
long long PRIME=1000000007;
long long minus1=PRIME-1;
long long t11,t12,t21,t22;
long long r11,r12,r21,r22;
long long b11,b12,b21,b22;
void baseWithResult(){
    t11 = pm(b11,r11) + pm(b12,r21);
    t12 = pm(b11,r12) + pm(b12,r22);
    t21 = pm(b21,r11) + pm(b22,r21);
    t22 = pm(b21,r12) + pm(b22,r22);
    r11=t11%PRIME;r12=t12%PRIME;r21=t21%PRIME;r22=t22%PRIME;
   
}
void baseWithBase(){
    t11 = pm(b11,b11) + pm(b12,b21);
    t12 = pm(b11,b12) + pm(b12,b22);
    t21 = pm(b21,b11) + pm(b22,b21);
    t22 = pm(b21,b12) + pm(b22,b22);
    b11=t11%PRIME;b12=t12%PRIME;b21=t21%PRIME;b22=t22%PRIME;
     
}
void raisePow(long long n){
   r11=1;r12=0;r21=0;r22=1;
   b11=3;b12=minus1;b21=0;b22=minus1;
   while(n>0){
       if(n%2==1){
           baseWithResult();
           n-=1;
       }
       baseWithBase();
       n/=2;
   } 
}
void solve(long long n){
    raisePow(n-2);
    //printf("%lld,%lld,%lld,%lld\n",r11,r12,r21,r22);
    printf("%lld\n",((r11*12LL)%PRIME+(r12*12LL)%PRIME)%PRIME);
}
int main(){
    int T;
    scanf("%d",&T);
    long long n;
    while(T-->0){
        scanf("%lld",&n);
       if(n==1) printf("4\n");
       else if(n==2) printf("12\n");
       else if(n==3) printf("24\n");
       else solve(n);
    }
}
