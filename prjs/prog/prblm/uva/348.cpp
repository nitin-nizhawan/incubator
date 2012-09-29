#include<cstdio>
int p[40];
int m[40][40];
int s[40][40];
int N;
void inputProb(){
    scanf("%d",&N);
    int x,y;
    scanf("%d %d",&x,&y);
    p[0]=x;p[1]=y;
    for(int i=1;i<N;i++){
    scanf("%d %d",&x,&y);
     p[i+1]=y;
    }
     
}
void solve(){
    inputProb();
    int mink,k,minval;
    for(int i=0;i<N;i++) m[i][i]=0;
    for(int i=0;i<N-1;i++) m[i][i+1]=p[i]*p[i+1]*p[i+2];
    for(int incre=2;incre<N;incre++){
        for(int i=0;i<N-incre;i++){
               mink = 0; k=0;
               m[i][i+incre] = m[i][i+k]+m[i+k+1][i+incre] + p[i-1]*p[i+k]*p[i+incre];
               s[i][i+incre]=0;
            for(k=1;k<i+incre;k++){
               minval = m[i][i+k]+m[i+k+1][i+incre] + p[i-1]*p[i+k]*p[i+incre];
               if (minval < m[i][i+incre]){
                   s[i][i+incre]=k;
                   m[i][i+incre]=minval;
               }
            }
        }
    }
}
int main(){
   int T;
   scanf("%d",&T);
   while(T--){
   solve();
   }
}
