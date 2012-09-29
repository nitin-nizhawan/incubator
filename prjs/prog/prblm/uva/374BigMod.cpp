#include<cstdio>
//#include<iostream>
typedef unsigned long long ull;

ull fastExp(ull p,ull n,ull mod){
   ull result=1;
    while(n){
        if(n&1){
            n-=1;
            result=(result*p)%mod;
        }
        n>>=1;
        p=(p*p)%mod;
    }
    return result%mod;
}
int main(){
ull T;
//scanf("%llu",&T);
ull B,P,M;
while(scanf("%llu",&B)>0){
    scanf("%llu",&P);
    scanf("%llu",&M);
//     std::cout<<"b :"<<B<<" , P="<<P<<" , M="<<M<<std::endl;
    printf("%llu\n",fastExp(B,P,M));
}
}
