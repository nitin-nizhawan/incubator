#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;
const long MOD=1000000007L;

class Cook{
public:
    int x,y;
};
bool mycomp(Cook a, Cook b){
    return a.x<b.x;
}
vector<Cook> cooks;
long dp_rec[101][101]={-1};
long dp[101][101];
long n,m;

long recurse(int m,int n){
    if(m==1){
        if(cooks[0].x<=n&&cooks[0].y>=n){
            return 1;
        } else {
            return 0;
        }
    }
    if(n>=0&&m>=0&&dp_rec[n][m]>-1){
        return dp_rec[n][m];
    }
    Cook cook = cooks[m-1];
    long sum =0;
    for(int i=cook.x;i<=cook.y;i++){
        if((n-i)>=0&&(m-1)>=0){
            long tmp = recurse(m-1,n-i);
            dp_rec[n-i][m-1]=tmp;
            sum = (sum+tmp)%MOD;
        }
    }
    return sum;
}
long solve_rec(){
//   sort(cooks.begin(),cooks.begin()+m,mycomp);
   // reset dp
   for(int i=0;i<=n;i++){
       for(int j=0;j<=m;j++){
           dp_rec[i][j]=-1;
       }
   }
   return recurse(m,n);
}

long solve(){
    long minsum=0,maxsum=0;
    for(int i=0;i<m;i++){
        minsum = minsum + cooks[i].x;
        maxsum = maxsum + cooks[i].y;
    }
    int a =1;
    if(minsum>n||maxsum<n){
        
        return 0;
    }
    for(int i=0;i<m;i++){
        cooks[i].y = cooks[i].y - cooks[i].x;
        cooks[i].x = 0;
    }
    n = n- minsum;
    if(n==0){
       return 1;
    } 
    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        dp[i][0]=dp[i-1][0] +(i<=cooks[0].y?1:0);
    }
    for(int i=0;i<m;i++){
        dp[0][i]=1;
    }

    for(int i=1;i<m;i++){
        for(int j=1;j<=n;j++){
            long sum = dp[j][i-1];
            if((j-cooks[i].y-1)>=0){
                sum = sum - dp[j-cooks[i].y-1][i-1];
            }
            dp[j][i] = (dp[j-1][i] + sum)%MOD;
        }
    }
   long ret = dp[n][m-1]-dp[n-1][m-1];
   return (ret+MOD)%MOD;
}

void tester(){
    int T = 150;
    while(T--){
        n = rand()%100+1;
        m = rand()%100+1;
        if(m>n){
          int   tmp = m;
            m = n;
             n = tmp;
        }
        for(int i=0;i<m;i++){
            cooks[i].x = rand()%100;
            cooks[i].y = rand()%100;
            if(cooks[i].x>cooks[i].y){
               int tmp = cooks[i].x;
               cooks[i].x = cooks[i].y;
               cooks[i].y = tmp;
            }
        }
        //printf("b : %ld, s: %ld \n",solve_rec(),solve());
    }
}


int main(){
    cooks.resize(101);
int T;
 scanf("%d",&T);
 while(T--){

    scanf("%ld",&n);
    scanf("%ld",&m);
    for(int i=0;i<m;i++){
        scanf("%d",&(cooks[i].x));
        scanf("%d",&(cooks[i].y));
    }
    ////printf("%d",solve());
        printf("b : %ld, s: %ld \n",solve_rec(),solve());
}
/*n=100;
m=100;
printf("1\n");
printf("100 100");
for(int i=0;i<m;i++){
    cooks[i].x=rand()%2;
    cooks[i].y=100;
    printf("%d %d\n",cooks[i].x,cooks[i].y);
}

        ////printf("b : %ld, s: %ld \n",solve_rec(),solve());
        */
//tester();
return 0;
}

