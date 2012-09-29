#include<stdio.h>
long long max=10000LL;
bool isPDS(long long i){
    long long p=1;
    long long s=0;
    while(i>0){
        p*=(i%10);
        s+=(i%10);
        i/=10;
    }
    return p%s==0;
}
int main(){
    for(long long i=1;i<=max;i++){
        if(isPDS(i)){
            printf("%lld\n",i);
        }
    }
}
