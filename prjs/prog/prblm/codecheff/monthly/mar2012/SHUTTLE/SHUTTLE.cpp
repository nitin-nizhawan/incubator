#include<stdio.h>
long long gcd(long long a, long long b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}


int calc_phi(int N){
    int     ans=1;
    for(int i=2;i<N;i++){
        if(gcd(N,i)==1){
            ans++;
        }
    }
    return ans;
}
int main(){
    int T,N;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        printf("%d\n",calc_phi(N));
    }
}
