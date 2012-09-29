#include<cstdio>
typedef unsigned long long ull;
ull gcd(ull m,ull n){
   ull r=n;
   while(n!=0){
       r = m%n;
       m=n;
       n=r;
   } 
   return m;
}
ull c(ull n,ull k){
    ull tmp = n-k;
    if(tmp<k){
        k = tmp;
        tmp = n-k;    
    }
    ull num=1;
    ull den = 1;
    for(ull i=tmp+1;i<=n;i++){
        num = num*i;
        if(k>1){
            den=den*k;
            k--;
        }
        tmp = gcd(num,den);
        if(tmp>1){
            den/=tmp;
            num/=tmp;
        } 
    }
    return num/den;
}
int main(){
    ull T;
    scanf("%llu",&T);
    ull n,k;
    while(T--){
        scanf("%llu %llu",&n,&k);
        printf("%llu\n",c(n-1,k-1));
    }
}
