#include<stdio.h>
typedef long long lld;
lld ans[200000]={0};
lld storage[200000]={0};
int zero_idx = 100000;
int ans_cnt=0;

int n_d_s(lld a, int z){
    int ans=0;
    while(a>0){
        int d = a%10;
        if(d==z){
            ans++;
        }
        a/=10;
    }
    return ans;
}


void  calc(lld n){
    for(int i=ans_cnt+1;i<=n;i++){
       int diff = n_d_s(i,4) - n_d_s(i,7);
       zero_idx=zero_idx-diff;
       storage[zero_idx+diff]++;
       ans[i]=ans[i-1]+storage[zero_idx];
    }
    ans_cnt=n;
}
lld solve(lld N){
   if(N>ans_cnt){
       calc(N);
   }
   return ans[N];
}
int main(){
    int T;
    scanf("%d",&T);
    ans[0]=0;ans_cnt=0;
    while(T--){
        lld N;
        scanf("%lld",&N);
        printf("%lld\n",solve(N));
    }
}
