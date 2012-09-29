#include<stdio.h>
const long long PRIME = 1000000007L;
const long long PRIME2 = 1000003L;

long long fact[1000001]={0};
int lfact=0;
long long invfact[1000001]={0};
long long p[1001][1001]={0};
long long modinv(long long , long long);
void gencnr(long long n){
    return;
    if(n<=lfact) return;
        for(int i=lfact+1;i<=n;i++){
            fact[i] = (fact[i-1]*i)%PRIME;
            invfact[i] = (invfact[i-1]*modinv(i,PRIME))%PRIME;
        }
        lfact = n;
}
long long cnr1(long long n, long long r){
    gencnr(n);
    return (((fact[n]*invfact[r])%PRIME)*invfact[n-r])%PRIME;
}

long long pnr1(long long n,long long r){
    return p[n][r];
}
long long pnr2(long long n,long long r){
    if(r<1||r>n){
        return  0;
    }
    if(r==1){
        p[n][r] =1;
    } else if(p[n][r]>0){
        return p[n][r];
    } else {
        p[n][r] = (r*((pnr1(n-1,r-1)+pnr1(n-1,r))%PRIME))%PRIME;
    }
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
      //  long long sdi = cnr1(m,i);
        sum+= (sdi2*pnr1(n,i))%PRIME;;
        long long den = i+1;
        long long num = m-i;
        /*long long g = egcd(num,den);
        den = den/g; num = num/g;
        g = egcd(sdi2,den);
        den/=g; sdi2/=g;*/
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
    fact[0]=1;
    invfact[0]=1;invfact[1]=1;
    gencnr(100000);
    genpnr();
    int T;
    scanf("%d",&T);
 
while(T--){
    long long n,m,k;
    scanf("%lld %lld %lld",&n,&m,&k);
    solve(n,m,k);
}
}
