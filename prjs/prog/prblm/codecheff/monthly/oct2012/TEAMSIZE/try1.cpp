#include<stdio.h>
int N;
long long C;
int Q;
long long A,B,D;
long long skill[500005];
long long cand[500005];
long long mind[500005];
long long maxd[500005];
long long MOD=1<<30;

long long mina(long long a, long long b){
    return a<b?a:b;
}
long long maxa(long long a,long long b){
    return a>b?a:b;
}
void prob(){
   scanf("%d",&N);
   scanf("%lld",&C);
   scanf("%d",&Q);
   scanf("%lld",&A);
   scanf("%lld",&B);
   scanf("%lld",&D);
   for(int i=0;i<N;i++){
       if(i<10000){
          scanf("%lld",&skill[i]);
       } else {
          skill[i] = (((A*skill[i-1])%MOD + (B*skill[i-2])%MOD)%MOD + D)%MOD;
       }
       cand[i]=0;
       for(int j=i;j>=0;j--){
           if(j==0){
                mind[j] = maxd[j] = skill[i];
                cand[j]++;
           } else {
                mind[j] = mina(skill[i],mind[j-1]);
                maxd[j] = maxa(skill[i],maxd[j-1]);
                if((maxd[j]-mind[j])<=C){
                    cand[j]++;
                }
           }
       }
   }
   for(int k=0;k<N;k++){
      printf("%lld ",cand[k]);
   }
   printf("\n");
   for(int i=0;i<Q;i++){
      // for each query do a linear search
      long long M;
      scanf("%lld",&M);
      for(int j=0;j<N;j++){
          if(cand[j]<=M){
              printf("%d %lld\n",j+1,cand[j]);
              break;
          }
      }
   }
}
int main(){
   int T;
   scanf("%d",&T);
   while(T-->0){
       prob();
   }
}
