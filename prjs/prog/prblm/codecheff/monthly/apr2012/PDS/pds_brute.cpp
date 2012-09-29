#include<stdio.h>
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
    long long N;
    scanf("%lld",&N);
    long long cnt=0;
    for(long long i=1;;i++){
        if(isPDS(i)){
            cnt++;
        }
        if(cnt==N){
            printf("%lld\n",i);
            break;
        }
    }
}
