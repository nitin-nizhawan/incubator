#include<stdio.h>
#define getdp(a,b) (((b)<=((a)-1)/2)?dp[a][b]:dp[a][(a)-(b)-1])

double dp[2002][2002];
int ccal=2;
void init(int n){
    for(int i=ccal+1;i<=n;i++){
        //dp[i][0] = dp[i-1][0]+2.0*dp[i-2][0];
        dp[i][0] = (dp[i-1][0]+dp[i-2][0])/2.0;
       // dp[i][i-1] = dp[i][0];//(dp[i-1][0]+dp[i-2][0])/2.0;
    //    printf("%lf ",dp[i][0]);
          int maxj=(i-1)/2;
        for(int j=1;j<=maxj;j++){
      //   if(j<=(i-1)/2){
             dp[i][j] = getdp(i-2,j)+2*getdp(i-2,j-1);
             if(j-2>=0){
                 dp[i][j]+=getdp(i-2,j-2);
             }
             dp[i][j]/=4.0;
//             dp[i][i-j-1]=dp[i][j];
//        } else {
  //          dp[i][j]=dp[i][i-j-1];
    //    }
  //          printf("%lf ",dp[i][j]);
        }
//        printf("\n");
    }
    ccal=n;

}
int main(){
    dp[0][0]=0;
    dp[1][0]=1;
    //dp[2][0]=1;dp[2][1]=1;
    dp[2][0]=0.5;dp[2][1]=0.5;
//    init(10);
  //  init(15);
    int T;
//init(2000);
 /*for(int i=1;i<=15;i++){
      for(int j=0;j<i;j++){
          printf("%lf ",getdp(i,j));
      }
      printf("\n");
  }*/
    scanf("%d",&T);
     while(T-->0){
       int N;
       scanf("%d",&N);
       double ans=0.0;
       init(N);
       int a;
       int maxi=(N-1)/2;
       for(int i=0;i<=maxi;i++){
           scanf("%d",&a);
       //    if(i<=(N-1)/2){
	       ans+=dp[N][i]*((double)a);//getdp(N,i)*((double)a);
         //  } else {
	   //    ans+=dp[N][N-i-1]*((double)a);
         // }
       }
       for(int i=N-maxi-2;i>=0;i--){
           scanf("%d",&a);
              ans+=dp[N][i]*((double)a);
       }
         
       printf("%lf\n",ans);
     }
}
