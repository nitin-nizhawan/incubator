#include<stdio.h>
const long long PRIME = 1000000007L;
long long p[1001][1001]={0};
//protottype
long long  modinv(long long, long long);

long long pnr(long long n,long long r){
    return p[n][r];
}
void genpnr(){
        for(int n1=1;n1<=1000;n1++){
            for(int r1=1;r1<=n1;r1++){
                if(r1==1){
                    p[n1][r1] = 1;
                } else {
                    p[n1][r1] = (r1*((p[n1-1][r1-1] + p[n1-1][r1])%PRIME))%PRIME;
                }
            }
        }
}
void solve(int n, int m, int k){
    long long sum = 0;
    long long sdi2 = m;
    for(int i=1;i<=k;i++){
        sum+= (sdi2*pnr(n,i))%PRIME;;
        long long den = i+1;
        long long num = m-i;
        sdi2 = (sdi2*num)%PRIME;
        sdi2 = (sdi2*modinv(den,PRIME))%PRIME;

    }
    printf("%ld\n",(sum+PRIME)%PRIME);
}

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






int main(){
    genpnr();
    int T;
    scanf("%d",&T);
 
while(T--){
    long long n,m,k;
    scanf("%lld %lld %lld",&n,&m,&k);
    solve(n,m,k);
}
}
