#include<stdio.h>
#include<algorithm>
using namespace std;
int N,K;
long long A[200];
long long freq[200];
long long val[200];
long long distinct;
long long min(long long a, long long b){
    return a<b?a:b;
}
long long solveit(int start,int end,int broken,int K,long long diff,int freqdiff){
    long long ans=0;
    int total;
     broken = 0;
   for(int i=0;i<K;i++){
       ans+= val[start]*(N-broken);
       freq[start]--;
       if(freq[start]==0){
           start++;
           
       }
       broken++;
   }
   return ans;
}
void solve(){
    long long mineggs = solveit(0,distinct-1,0,K,0,0);
    printf("%lld\n",mineggs);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        scanf("%d",&K);
        for(int i=0;i<N;i++){
            scanf("%lld",&A[i]);
        }
        sort(A,A+N);
        val[0] = A[0];
        freq[0] =1;
        int cnt=1;
        for(int i=1;i<N;i++){
            if(A[i]!=A[i-1]){
                val[cnt++] = A[i];
                freq[cnt-1] =1;
            } else {
                freq[cnt-1]++;
            }
        }
        distinct  = cnt;
        solve();
    }
}
