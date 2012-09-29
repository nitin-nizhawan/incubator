#include<stdio.h>
#include<algorithm>
using namespace std;

long long x[2000];
long long dx[2000];
long long dy[2000];
long long y[2000];
int n;
long long abs1(long long a){
    if(a<0){
        return 0-a;
    }
    return a;
}
void brf(){
    for(int i=0;i<n;i++){
            dx[i]=0;
            dy[i]=0;
        for(int j=0;j<n;j++){
            dx[i]+=abs1(x[i]-x[j]);
            dy[i]+=abs1(y[i]-y[j]);
        }
    }
    for(int i=0;i<n;i++){
        printf("(%lld,%lld) ",dx[i],dy[i]);
    }
    printf("\n");
}
long long solve(long long a[], long long  da[]){
    long long mind = (1LL<<62);
    da[0]=0;
    for(int i=1;i<n;i++){
        da[0]+=abs1(a[i]-a[0]);
    }
    if(da[0]<mind) mind=da[0];
    for(int i=1;i<n;i++){
        long long d=abs1(a[i-1]-a[i]);
        da[i] = da[i-1] - (n-i-1)*d + (i-1)*d;
        if(da[i]<mind){
            mind = da[i];
        }
    }

    long long mina=(1LL<<62),maxa=-1*(1LL<<62);
    for(int i=0;i<n;i++){
        if(da[i]==mind){
            if(a[i]<mina){
                mina=a[i];
            }
            if(a[i]>maxa){
                maxa=a[i];
            }
        }
    }
    return maxa-mina + 1;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%lld",&x[i]);
            scanf("%lld",&y[i]);
        }
        sort(x,x+n);
        sort(y,y+n);
//        brf();
        long long nx = solve(x,dx);
        long long ny = solve(y,dy);
/*    for(int i=0;i<n;i++){
        printf("t(%lld,%lld) ",dx[i],dy[i]);
    }
    printf("\n");*/
        printf("%lld\n",nx*ny);
    }
}
