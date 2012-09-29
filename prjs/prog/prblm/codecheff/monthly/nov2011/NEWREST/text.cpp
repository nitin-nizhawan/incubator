#include<stdio.h>
const long long PRIME = 1000000007L;
long long fact[1000001]={0};
long long invfact[1000001]={0};
int factc=0;
long long p[1001][1001]={0};
int lpn=0;
int lpr=0;
//long long c[1001][1001];
//long long cook[1001][1001];
long long modinv(long long , long long);
long long power[1001][1001];
long long cook1[1001];
long long cnr(long long n,long long r){
    long long tmp = n>r?n:r;
    tmp = tmp>(n-r)?tmp:(n-r);
    if(tmp>factc){
        for(int i=factc+1;i<=tmp;i++){
            fact[i] = (fact[i-1]*i)%PRIME;
            invfact[i] = (invfact[i-1]*modinv(i,PRIME))%PRIME;
        }
        factc=tmp;
    }
    return (((fact[n]*invfact[r])%PRIME)*invfact[n-r])%PRIME;
}
long long cnr1(long long n, long long r){
    return (((fact[n]*invfact[r])%PRIME)*invfact[n-r])%PRIME;
}

long long pnr1(long long n,long long r){
    return p[n][r];
}
long long pnr(long long n,long long r){
    if(n>lpn){
        for(int n1=lpn+1;n1<=n;n1++){
            for(int r1=1;r1<=n;r1++){
                if(r1==1){
                    p[n1][r1] = 1;
                } else {
                    p[n1][r1] = (r1*((p[n1-1][r1-1] + p[n1-1][r1])%PRIME))%PRIME;
                }
            }
        }
    }
    lpn=n;
    lpr=r;
    return p[n][r];
}
void solve(int n, int m, int k){
    long long sum = 0;
    cook1[1] = 1;
   // long long pow[10001];
   // pow[0]=1;
   // pow[1]=n;
   /*
    for(int i=2;i<=k;i++){
        long long sum1=power[n][i];
        for(int j=i-1;j>=1;j--){
            long long a = cnr(i,j);
           sum1 = ((sum1- (a*cook1[j])%PRIME)+PRIME)%PRIME;
        }
        cook1[i]=sum1;
    }
    */
    for(int i=1;i<=k;i++){
        long long sdi = cnr1(m,i);
        sum+= (sdi*pnr1(n,i))%PRIME;;
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
    cnr(1000000,2);
    pnr(1000,1000);
//    pnr(1000,1000);
   /* for(int i=1;i<=1000000;i++){
        fact[i]= (fact[i-1]*i)%PRIME;
        invfact[i]=modinv(fact[i],PRIME);
    }*/
  /*  for(int i=0;i<15;i++){
        printf("%lld ",(fact[i]*invfact[i])%PRIME);
    }
    printf("\n");
    */
    int T;
    scanf("%d",&T);
 
/*   for(int n=1;n<=1000;n++){
       for(int r=0;r<=n;r++){
           if(n==1){
               c[n][r] = 1;
           } else if(r==0){
               c[n][r] = 1;
           } else if(r==1){
               c[n][r] = n;
           } else {
               c[n][r] = (c[n-1][r-1] + c[n-1][r])%PRIME;
           }
       }
   }*/
  /* for(int n=1;n<=1000;n++){
       for(int i=1;i<=n;i++){
           if(n==1){
          //     cook[n][i] = 1;
               power[n][i]=i;
           } else if(i==1){
               power[n][i] = 1;
        //       cook[n][i] = 1;
           } else {
               power[n][i] = (power[n-1][i]*i)%PRIME;
      //         cook[n][i] = power[n][i]; */
            /*   for(int k=i-1;k>=1;k--){
                   cook[n][i] = ((cook[n][i] - c[i][k]*cook[n][k])+PRIME)%PRIME;
               }*/
          /* }
       }
   }*/
   /*
for(int i=1;i<=1000;i++){
    for(int j=1;j<=1000;j++){
        if(i==1){
            power[i][j] = j;

        } else if(j==1){
            power[i][j] = 1;
        } else {
            power[i][j] = (power[i-1][j]*j)%PRIME;
        }
    }
}
*/
while(T--){
    long long n,m,k;
    scanf("%lld %lld %lld",&n,&m,&k);
    solve(n,m,k);
}
/*
   printf("\n");
   for(int i=1;i<10;i++){
       for(int j=1;j<10;j++){
           printf("%8lld ",p[i][j]);
       }
       printf("\n");
   }
   printf("\n");
   */
// solve now
// int n,m,k;
/*
 solve(1,1,1);
 solve(2,2,2);
 solve(4,3,2);
 solve(5,7,3);
*/
}
