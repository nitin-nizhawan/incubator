#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;
typedef unsigned long long ull;
ull tenpow[11]={1,10,100,1000,10000,100000,1000000ULL,10000000ULL,100000000ULL,1000000000ULL,10000000000ULL};
ull fastExp(ull n,ull mod){
   ull p = n;
   ull result=1;
    while(n){
        if(n&1){
            n-=1;
            result=(result*p)%mod;
        }
        n>>=1;
        p=(p*p)%mod;
    }
    return result;
}
void printFirstk(ull n, ull k){
    long double rep = n*log10((long double)n);
    long long intd = rep;
    long double decm = rep - (long double)intd;
    long double val= pow(10,decm);
    int d1;
    int mind =k;
     if((intd+1)<mind){
        mind = intd+1;
     }
    for(int i=0;i<mind;i++){
        d1 = val;
        printf("%d",d1);
        val  = val - (long double) d1;
        val=val*10;
    }
    printf("%c",' ');
 
}
void printLastk(ull n,ull k){
    char out[10];
    ull ans = fastExp(n,tenpow[k]);
    for(int i=k-1;i>=0;i--){
        out[i]='0'+ans%10;
        ans/=10ULL;
    }   
    for(int i=0;i<k;i++){
        printf("%c",out[i]);
    }
 //   printf("%llu",fastExp(n,tenpow[k]));
    printf("%c",'\n');
    
}
void solveTest(ull n,ull k){
    printFirstk(n,k);
    printLastk(n,k);
}
int main(){

    long T;
     scanf("%ld",&T);
     ull n, k;
     while(T--){
      scanf("%llu %llu",&n,&k);
      solveTest(n,k);
     }

    
}
