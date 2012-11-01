#include<stdio.h>

int S[3000];
int E[3000];
int C[3000];
int N;
int dss[50][2500];
int dsc[50][2500];
int num[50];
int maxsofar[50];
int maxa(int a,int b){
    return a>b?a:b;
}
void solve(){
    for(int i=0;i<50;i++){
        int maxc = 0;
        if(i>0){ maxc = maxsofar[i-1];}
        for(int j=0;j<num[i];j++){
            int s = dss[i][j];
            maxc= maxa(maxsofar[s]+dsc[i][j],maxc);
        }
        maxsofar[i]=maxc;
    }
    printf("%d\n",maxsofar[48]);
}
int main(){
   int T;
   scanf("%d",&T);
  while(T-->0){
      int N;
      scanf("%d",&N);
      for(int i=0;i<50;i++) num[i]=0;
      for(int i=0;i<N;i++){
          scanf("%d",&S[i]);
          scanf("%d",&E[i]);
          scanf("%d",&C[i]);
          dss[E[i]][num[E[i]]]=S[i];
          dsc[E[i]][num[E[i]]]=C[i];
          num[E[i]]++;
      }
      solve();
  }
}
