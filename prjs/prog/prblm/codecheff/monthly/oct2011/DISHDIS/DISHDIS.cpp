#include<stdio.h>
#include<stdlib.h>

const long MOD=1000000007L;
class Cook {
    public:
    long long x,y;
};
Cook cooks[101];
long long dp[101][101];
long long n,m;


long long  brute_force(){
    int ps[101];
    long long count =0;
    // set all to minimum;
    for(int i=1;i<=m;i++){
        ps[i]=cooks[i].x;
    }
    long long maxPossible  = 1;
    for(int i=1;i<=m;i++){
        maxPossible = maxPossible*(cooks[i].y-cooks[i].x+1);
    }
    do{
      
       //check if valid
       bool valid = true;
       long long sum = 0;
       for(int i=1;i<=m;i++){
           if(ps[i]>cooks[i].y||ps[i]<cooks[i].x){
               valid = false;
           }
           sum +=ps[i];
       }
       if(sum!=n){
           valid=false;
       }
       if(valid){
           count++;
       }

       // increment to get next config
        int cnt=1;
        while(ps[cnt]==cooks[cnt].y){ //is max
            ps[cnt]=cooks[cnt].x; // set to min
            cnt++;
        }
        if(cnt<=m){
        ps[cnt]++;
        } else {
            break; // we are done;
        }
       

    }while(true);
        
    return count;
}

long long solve(){
    long long minsum=0,maxsum=0;
    for(int i=1;i<=m;i++){
        minsum = minsum + cooks[i].x;
        maxsum = maxsum + cooks[i].y;
    }
    if(minsum>n||maxsum<n){
        return 0;
    }
    for(int i=1;i<=m;i++){
        cooks[i].y = cooks[i].y - cooks[i].x;
        cooks[i].x = 0;
    }
    n = n- minsum;
    dp[0][1] = 1;
    for(int i=1;i<=n;i++){
        dp[i][1]=dp[i-1][1] +(i<=cooks[1].y?1:0);
    }
    for(int i=0;i<=m;i++){
        dp[0][i]=1;
    }

    for(int i=2;i<=m;i++){
        for(int j=1;j<=n;j++){
            long long sum = dp[j][i-1];
            if((j-cooks[i].y-1)>=0){
                sum = sum - dp[j-cooks[i].y-1][i-1];
            }
            dp[j][i] = (dp[j-1][i] + sum)%MOD;
        }
    }
   long ret = dp[n][m]-dp[n-1][m];
   return (ret+MOD)%MOD;
}

void tester(){
    int T = 5;
    while(T--){
        n = rand()%25+1;
        m = rand()%25+1;
        if(m>n){
          int   tmp = m;
            m = n;
             n = tmp;
        }
        for(int i=1;i<=m;i++){
            cooks[i].x = rand()%10;
            cooks[i].y = rand()%10;
            if(cooks[i].x>cooks[i].y){
               int tmp = cooks[i].x;
               cooks[i].x = cooks[i].y;
               cooks[i].y = tmp;
            }
        }
        printf("b : %Ld, s: %Ld \n",brute_force(),solve());
    }
}
int main(){
int T;
 scanf("%d",&T);
 while(T--){

    scanf("%Ld",&n);
    scanf("%Ld",&m);
    for(int i=1;i<=m;i++){
        scanf("%Ld",&(cooks[i].x));
        scanf("%Ld",&(cooks[i].y));
    }
        printf("b : %Ld, s: %Ld \n",0,solve());
}
n=100;m=100;
for(int i=1;i<=100;i++){
    cooks[i].x = 0;
    cooks[i].y =100;
}

printf("b : %Ld, s: %Ld \n",0,solve());
//tester();


return 0;
}
