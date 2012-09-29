#include<stdio.h>
#include<queue>
#include<map>
#include<cmath>
#include<utility>
using namespace std;
typedef unsigned  long long ull;

map<ull,ull> cache;
map<ull,ull>::iterator p;
ull solve(ull N){
    if(N<=1){
        return 1;
    }
    p = cache.find(N);
    if(p!=cache.end()){
        return p->second;
    }
    int i=1;
    ull np1 = N+1;
    ull nby2 = np1/2;
    //double sqrt = pow(N+1,0.5);
    ull ans = 0;
    while(i*i<=np1){
        if((np1)%i==0){
            ans+= solve(i-1);
            ull i2 = (np1)/i;
            if(i!=i2&&i2<=nby2){
                ans+=solve(i2-1);
            }
        }
        i++;
    }
    cache.insert(pair<ull,ull>(N,ans));
    return ans;
}

int main(){

    int T;
    ull N;
    scanf("%d",&T);
    while(T--){
        scanf("%llu",&N);
       ull a =  solve(N);
        printf("%llu\n",a);
    }
   
}
