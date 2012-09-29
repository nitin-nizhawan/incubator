#include<stdio.h>
#include<algorithm>
using namespace std;

class Node {
    public:
    long long val;
    long long idx;
};
Node nodes[100009];
bool mycomp(Node a,Node b){
    return a.val<b.val;
}
int main(){
    long long N,K;
    scanf("%lld",&N);
    scanf("%lld",&K);
    for(int i=0;i<N;i++){
        scanf("%lld",&nodes[i].val);
        nodes[i].idx=i;
    }
    stable_sort(nodes,nodes+N,mycomp);
    long long prev=-1;
    int start =0;
    long long count=0;
    for(int i=0;i<N;i++){
        if(prev!=nodes[i].val){
           count++;
           start=nodes[i].idx;
        }
        if(i>0){
            if(prev==nodes[i].val){
                if(nodes[i].idx-start+1>K){
                    start=nodes[i].idx;
                    count++;
                }
            }
        }
        prev = nodes[i].val;
    }
  /*  long long prev=-1;
    long long mn,mx;
    long long count=0;
    for(int i=0;i<N;i++){
        if(nodes[i].val!=prev){
            if(i>0){
                count+= opereq(mn,mx,K);//((mx-mn)/K) + 1;
            }
            mn=mx=nodes[i].idx;
        } else {
            if(nodes[i].idx<mn){
                mn = nodes[i].idx;
            }
            if(nodes[i].idx>mx){
                mx = nodes[i].idx;
            }
        }
        prev=nodes[i].val;
    }
    if(N>0){
        count+= opreq(mn,mx,K);
     }*/
    printf("%lld\n",count);
}
