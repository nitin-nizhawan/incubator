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
bool canBreak(long long mid,int N, int K,long long A[],int st=0){
    if(K<=0&&mid>=0){
        return true;
    } else if(K>0&&mid<=0){
        return false;
    } else {
    for(int i=st;i<N;i+=(i+1)%N){
        if(!canBreak(mid-A[i],N-1,K-1,A,(i+1)%N)){
            return false;
        }
     }
    }
    return true;
}
long long binsearch(long long start,long long end,int N,int K, long long A[]){
    while(start<end){
    long long mid = start + (end - start)/2;
        if(canBreak(mid,N,K,A,0)){
            end = mid;
        } else {
            start = mid + 1;
        }
    }
    return start;
}
int main(int argc, char* argv[])
{
    int T;
    scanf("%d",&T);


    while(T--){
        scanf("%d",&N);
        scanf("%d",&K);
        long long suma=0;
        for(int i=0;i<N;i++){
            scanf("%lld",&A[i]);
            suma+=A[i];
        }
        long long max = suma;
        long long start=0;
        long long end=2*max;
        printf("%lld\n",binsearch(start,end,N,K,A));
        /*
        sortit(A,N);
        calcfreq(A,N,freq);
        solvedp();
        
        long long minv=0;
        long long maxv=0;
        for(int i=0;i<K;i++){
            minv+=A[i];
            maxv+=A[N-i-1];
        }
        long long greater=0;
        long long lesseq=0;
        for(int i=0;i<N;i++){
            if(A[i]>A[K-1]){
                greater++;
            }
            if(A[i]<=A[K-1]){
                lesseq++;
            }
        }
       long long        minv2 =0;
        for(int i=lesseq-1;i>=(lesseq-K);i--){
             minv2+=A[i];
        }

        printf("%lld\n",min(dp[0][N-1],min(minv2+greater*A[K-1],maxv)));
        */
    }


    return 0;
}


