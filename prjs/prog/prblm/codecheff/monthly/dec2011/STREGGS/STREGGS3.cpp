#include<stdio.h>
#include<algorithm>

using namespace std;

// variables
long long dp[1000][1000];
int N,K;
long long A[1000];
long long freq[1000];

// functions 
void printit(long long *a,int n){
    printf("\n%lld",a[0]);
    for(int i=1;i<n;i++){
        printf(" %lld",a[i]);
    }
    printf("\n");
}
void sortit(long long *a,int n){
    sort(a,a+n);
    //printit(a,n);
}
void calcfreq(long long *a, int n,long long *f){
    f[0] =1;
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]){
            f[i] = f[i-1]+1;
        } else {
            f[i] =1;
        }
    }
    for(int i=n-2;i>=0;i--){
        if(a[i]==a[i+1]){
            f[i] = f[i+1];
        }
    }
    //printit(f,n);
}
long long min(long long a, long long b){
    return a<b?a:b;
}
void solvedp(){
    for(int i=N-freq[N-1];i>=0;i-=((i>0)?freq[i-1]:1)){
        for(int j=0;j<N;j++){
                if(i>0&&A[i]==A[i-1]){
                    //
                }
            int broken = N - (j - i +1);
            int k = K - broken;
            if( k<=0){
                dp[i][j] = 0;
            } else if(A[i] == A[j]){
                dp[i][j] = (A[i]-((i>0)?A[i-1]:0))*min(k,(j-i+1));
            } else {
                long long cost1 = A[j] - ((i>0)?A[i-1]:0)  + dp[i][j-1];
                long long incr =  A[i] - ((i>0)?A[i-1]:0);
                long long cost2 = incr*min(k,freq[i]) + incr*((j -i +1) - freq[i]) + ((k>freq[i])?dp[i+freq[i]][j]:0);
                if(cost1>cost2){
                 //   printf("debug :break largeest one %d\n",j);
                } else {
                  //  printf("debug :break smallest from ith  %d\n",i);
                }
                dp[i][j] = min(cost2,cost1);
            }
        }
    }
}
int main(int argc, char* argv[])
{
    int T;
    scanf("%d",&T);


    while(T--){
        scanf("%d",&N);
        scanf("%d",&K);
        for(int i=0;i<N;i++){
            scanf("%lld",&A[i]);
        }
        sortit(A,N);
        calcfreq(A,N,freq);
        solvedp();
        printf("%lld\n",dp[0][N-1]);
    }


    return 0;
}


