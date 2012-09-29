#include<stdio.h>
long long tolls[102][102];
long long C[102][102];
long long mincost[102][102];
int m,n,D;
long long solve(){
    //special case
    long long min = tolls[0][0];
    for(int i=1;i<m;i++){
        if(min>tolls[i][0]){
            min = tolls[i][0];
        }
    }
    if(n==1){
        return min;
    }
    for(int i=0;i<(n-1);i++){
        for(int j=0;j<m;j++){
            mincost[j][i] =  tolls[j][i];
            if(i>0){
                mincost[j][i] += mincost[j][i-1];
            }
           for(int k=0;k<m;k++){
               long long cst = tolls[k][i] + C[k][j];
               if(i>0){
                   cst += mincost[k][i-1];
               }
               if(cst<mincost[j][i]){
                   mincost[j][i] = cst;
               }
           }
        }
    }
    min = mincost[0][n-2]+tolls[0][n-1];
    for(int i=0;i<m;i++){
        if(min>(mincost[i][n-2] + tolls[i][n-1])){
            min = mincost[i][n-2] + tolls[i][n-1];
        }
    }
    return min;
}
   //general case
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&D);
        scanf("%d",&n);
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                scanf("%lld",&tolls[i][j]);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                scanf("%lld",&C[i][j]);
            }
        }
        long long ans = D-solve();
        if(ans<0){
            printf("-1\n");
        } else {
            printf("%lld\n",ans);
        }
    }
}
