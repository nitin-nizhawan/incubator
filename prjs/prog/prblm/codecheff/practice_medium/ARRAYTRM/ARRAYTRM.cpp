#include<stdio.h>
int x[100];
void yes(){
    printf("YES\n");
}
void no(){
    printf("NO\n");
}
void solve(int n,int K){
    if(n<=2){
        yes();
        return;
    }
    int mf[12];
    for(int i=0;i<12;i++){
        mf[i]=0;
    }
    for(int i=0;i<n;i++){
        mf[x[i]%(K+1)]++;
    }
    int c=0;
    int f[12];
    for(int i=0;i<12;i++){
        if(mf[i]>0){
            f[c++]=i;
        }
    }
    if(c==1){
        yes();
        return;
    }
    if(c==2){
        
        if(mf[f[0]]==1||mf[f[1]]==1){
            yes();
            return;
        }
    }
    no();
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        int K;
        scanf("%d",&n);
        scanf("%d",&K);
        for(int i=0;i<n;i++){
            scanf("%d",&x[i]);
        }
        solve(n,K);
    }
}
