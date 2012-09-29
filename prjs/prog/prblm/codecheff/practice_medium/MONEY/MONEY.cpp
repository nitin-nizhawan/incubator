#include<stdio.h>
typedef unsigned long long ull;
ull N;
ull ans=0;
int rec(ull d,ull s){
    int ret=0;
    if(s==N){
        ans++;
        return 0;
    }
    if(s>N){
        return 0;
    }
    if((2*s+1)<=N){
        ret+=rec(s+1,s+s+1);
        ret+=rec(d,s+d);
    } else {
        if((N-s)%d==0){
            ans++;
        }
    }
    
    return ret;
}
void solve(ull N){
    ans=0;
    int s = rec(1,1);
    printf("%d\n",ans);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
       scanf("%llu",&N);
       solve(N);
    }
}
