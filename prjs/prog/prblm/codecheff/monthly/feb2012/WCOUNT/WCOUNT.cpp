#include<stdio.h>
#define MOD 1000000007L
long long facts[5001];
long long invfact[5001];
long long cnt=0;
int alphab[128];
char inpstr[1000];
char unique[500];
char uniqueCnt=0;
long long egcd(long long A, long long B, long long *X, long long *Y){
    long long x, y, u, v, m, n, a, b, q, r;
 
    /* B = A(0) + B(1) */
    x = 0; y = 1;
 
    /* A = A(1) + B(0) */
    u = 1; v = 0;
 
    for (a = A, b = B; 0 != a; b = a, a = r, x = u, y = v, u = m, v = n)
    {
        /* b = aq + r and 0 <= r < a */
        q = b / a;
        r = b % a;
 
        /* r = Ax + By - aq = Ax + By - (Au + Bv)q = A(x - uq) + B(y - vq) */
        m = x - (u * q);
        n = y - (v * q); 
    }   
 
    /* Ax + By = gcd(A, B) */
    *X = x; *Y = y;
 
    return b;
}

long long  modinv(long long a, long long m){
    long long x ; long long y;
    long long g;
    g = egcd(a, m,&x,&y);
        return ((x % m)+m)%m;
}
long long cfact(long long n){
    if(n>cnt){
        for(int i=cnt;i<=n;i++){
            facts[i] = (facts[i-1]*i)%MOD;
            invfact[i]=(invfact[i-1]*modinv(i,MOD))%MOD;
        }
        cnt = n;
    }
    return facts[n];
}

void solve(){
   int i=0;
   for(int i=0;i<127;i++){
       alphab[i]=0;
   }
   uniqueCnt=0;
   int total=0;
   while(inpstr[total]!='\0'){
       if(alphab[inpstr[total]]<1){
          unique[uniqueCnt++]=inpstr[total];           
       }
       alphab[inpstr[total]]++;
       total++;
   }
   long long ans = cfact(total);
   for(int i=0;i<uniqueCnt;i++){
       ans = (ans * invfact[alphab[unique[i]]])%MOD;
   }
   printf("%lld\n",ans);
}
int main(){
facts[0]=1;
invfact[0]=1;
facts[1] = 1;
invfact[1] = (invfact[0]*modinv(1,MOD))%MOD;
cnt =1;
    int T;
    scanf("%d",&T);

    while(T--){
        scanf("%s",inpstr);
        solve();
    }
}


