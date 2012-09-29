#include<stdio.h>
long long max(long long  a,long long b){
return a>b?a:b;
}
int main(){
    int N;
    long long a,b;
    long long ans=0;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%lld",&a);
        if(i){
            ans+=max(a,b);
        }
        b = a;
    }
    printf("%lld\n",ans);
}

