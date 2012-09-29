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
long long solveit(int start,int end,int broken,int K,long long diff,int freqdiff1,int freqdiff2){
    if(start==end){
        return (K-broken)*val[start];
    }
    if(broken>=K){
        return 0;
    }
    long long cost1 = (val[start]-diff)*(N-broken-freq[start]+freqdiff1+1);
    if(freq[start]-freqdiff1>1){
         solveit(start,end,broken +1,K,(start>0)?val[start-1]:0,freqdiff1+1,freqdiff2);
    } else {
         solveit(start+1,end,broken +1,K,val[start],0,freqdiff2);
    }
    long long cost2 = (val[end]-diff);
    if((freq[end]-freqdiff2)>1){
        cost2 += solveit(start,end,broken+1,K,diff,freqdiff1,freqdiff2+1);
    } else {
        cost2 += solveit(start,end-1,broken+1,K,diff,freqdiff1,0);
    }
    return min(cost1,cost2);
}
void solve(){
    long long mineggs = solveit(0,distinct-1,0,K,0,0,0);
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
