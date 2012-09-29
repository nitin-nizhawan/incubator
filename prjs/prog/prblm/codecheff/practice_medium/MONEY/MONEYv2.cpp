#include<stdio.h>
#include<queue>
#include<utility>
#define MAX 2147483647
using namespace std;
typedef unsigned long long ull;

ull ans=0;
ull dp[2]={0};
int lastComp=0;
void solve(ull N){
    ans =0;
    queue< pair<ull,ull> >  q;
    q.push(make_pair(1,1));
    pair<ull,ull>* tmp;
    while(!q.empty()){
        tmp = & (q.front()); 
        q.pop();
        if(tmp->second<=N){
            // first branch
            ull sum;
            sum = 2*(tmp->second)+1;
            if(sum>=N){
                if(sum==N){
                    ans++;
                }
                if( (N-tmp->second)%tmp->first==0){
                    ans++;
                }
            } else if(sum<N) {
                q.push(make_pair(tmp->second+1,sum));
                q.push(make_pair(tmp->first,tmp->first+tmp->second));
            }


        }
    }
   // printf("%llu\n",ans);
}
int main(){
/*    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%llu",&N);
        solve(N);
    }
 */  
 for(int i=1;i<400;i++){
     solve(i);
     ull ans1 = ans;
     if(i%2){
          solve(i/2);
     } else {
          ans =0;
     }
     printf("%d : %llu : %llu\n",i,ans1, ans1 - ans -1 );
 }
}
