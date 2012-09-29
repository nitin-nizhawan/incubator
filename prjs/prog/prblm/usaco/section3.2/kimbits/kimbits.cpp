/*
ID: nitin.n1
PROG: kimbits
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
long long cn[40][40];
ofstream fout ("kimbits.out");

// returns 
// number of integers less than or equal to n,
// with b or less bits set to 1
long long fnd_2pow(int n,int b){
    if(b==0) return 0;
    if(b==1){
        return n+1;
    }
    return cn[n][b];    

}
long long fnd(long long n,int b){
   long long tmp = n;
   int len =0;
   long long ans=0;
   while(tmp>0){len++;tmp/=2;}
   for(int i=len-1;i>=0&&b>=0;i--){
       if(n&(1<<i)){
    //printf("fnd_2pow(n=%d,b=%d)=%d\n",i,b,fnd_2pow(i,b));
           ans+=(fnd_2pow(i,b));
           b--;
       }
   }
   return ans+1;
}
int nbits(int n){
    int ans=0;
    while(n>0){
        if(n%2==1){
            ans++;
        }
        n/=2;
    }
    return ans;
}
bool check(long long n,long long I,int L){
    return fnd(n,L)>=I;
}
long long binary_search(long long lo,long long hi,long long I,int L){
    long long mid;
   while( lo < hi){
         mid = lo + (hi-lo)/2;
         if(check(mid,I,L) == true){
              hi = mid;
         }
         else {
              lo = mid+1;
         }
                                      
/*        if(check(lo,I,L) == false){
            int a=1;
              a=1/(a-1);
        }
        */
   }                                                   
  return lo;
}
int bf(int n,int b){
    int ans=0;
    for(int i=0;i<=n;i++){
         if(nbits(i)<=b){
             ans++;
         }
    }
    return ans;
}
long long fnd2(long long n,int b){
    if(n==1){
        return 0;
    }
    long long low = 0;
    long long high=1;
    while(fnd(high,b)<=n){
        high = high<<1;
    }
    high = high<<1;
    return binary_search(low,high,n,b);
}
long long bf2(long long n,int b){
    long long  ans=0;
    long long idx=0;
    while(true){
        if(nbits(ans)<=b){
            idx++;
        }
        if(idx==n){
            return ans;
        }
        ans++;
    }
}
int main() {
    ifstream fin ("kimbits.in");
    long long N,L,I;
    fin >>N>>L>>I;
    for(int i=0;i<=N;i++){
        for(int j=0;j<=i;j++){
            if(i==0&&j==0){
                cn[i][j]=1;
            } else if(j==0){
                cn[i][j]=1;
            } else {
                cn[i][j] = cn[i-1][j] + cn[i-1][j-1];
            }
        }
    }
    for(int i=0;i<=N;i++){
        for(int j=1;j<=N;j++){
            cn[i][j]=cn[i][j-1]+cn[i][j];
        }
    }
/*    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            printf("%lld ",cn[i][j]);
        }
        printf("\n");
    }
    */
    //printf("\n"); 
   // printBits(N,L,I);
   // fout<<"\n";
  //  fout << a+b << endl;
    long long ans = fnd2(I,L);
    for(int i=N-1;i>=0;i--){
        if(ans&(1<<i)){
            fout<<"1";
        } else {
            fout<<"0";
        }
    }
    fout<<"\n";
    //printf("%lld\n");//,fnd2(I,L),bf2(I,L));
    return 0;
}

