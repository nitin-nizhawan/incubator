#include<stdio.h>
#include<algorithm>
using namespace std;
char inpstr[3000];
int dp[2005][2005];
int max_inc[27][2005];
int max_dec[27][2005];
int nochar_inc[2005];
int nochar_dec[2005];
int size=0;
int maxf(int a,int b){
    return a>b?a:b;
}
int solvefast(){
    int max = 1;
    for(int j=0;j<=size;j++){
        for(int i=0;i<=26;i++){
            max_inc[i][j]=0;
            max_dec[i][j]=0;
        }
    }
    for(int i=0;i<size;i++){
        int cc=inpstr[i]-'a';
        for(int k=0;k<=i;k++){
            int m_i = maxf(max_inc[26][k],max_inc[cc][k]);
            for(int j=cc;j>=0;j--){
                if(max_inc[j][k]>m_i){
                    m_i=max_inc[j][k];
                }
            }
            /*
            // first largest char , that is no zero
            int j_tmp = cc-1;
            while(j_tmp>=0&&max_inc[j_tmp][k]==0){ j_tmp--; }
            if(j_tmp>=0) { m_i = maxf(m_i,max_inc[j_tmp][k]);}
           */
            max_inc[cc][k]=m_i+1;
            int o_char = k>0?(inpstr[k-1]-'a'):26;
            if(max_inc[cc][k]>max){
                max = max_inc[cc][k];
            }
            if(max_dec[o_char][i+1]<(m_i+1)){
                max_dec[o_char][i+1]=m_i+1;
            }
            //-----------------------------------------

            m_i=maxf(max_dec[26][k],max_dec[cc][k]);
            for(int j=cc;j<26;j++){
                if(max_dec[j][k]>m_i){
                    m_i=max_dec[j][k];
                }
            }
            /*
            // first smallest char, that is non zero
            j_tmp = cc+1;
            while(j_tmp<26&&max_inc[j_tmp]==0) { j_tmp++; }
            if(j_tmp<26) { m_i = maxf(m_i,max_dec[j_tmp][k]); }
            */
            max_dec[cc][k]=m_i+1;
            if(max_inc[o_char][i+1]<(m_i+1)){
                max_inc[o_char][i+1]=m_i+1;
            }
            if(max_dec[cc][k]>max){
                max = max_dec[cc][k];
            }
        }
    }
    return max;
}

int solveme(){
    size=0;
    while(inpstr[++size]!='\0');
    for(int i=0;i<=size;i++){
        for(int j=0;j<=size;j++){
            dp[i][j]=0;
        }
    }
    for(int i=0;i<size;i++){
        dp[0][i+1]=1;
        dp[i+1][0]=1;
        for(int j=0;j<i;j++){
            if(inpstr[j]>=inpstr[i]){
                if(dp[0][j+1]+1>dp[0][i+1]){
                    dp[0][i+1] = dp[0][j+1]+1;
                }
            }
            if(inpstr[j]<=inpstr[i]){
                if(dp[j+1][0]+1>dp[i+1][0]){
                    dp[i+1][0]=dp[j+1][0]+1;
                }
            }
        }
    }
    for(int i=0;i<size;i++){
        for(int j=0;j<i;j++){
            // find max
            int max = dp[j+1][0];
            for(int k=1;k<=i;k++){
                if(dp[j+1][k]>max&&inpstr[k-1]>=inpstr[i]){
                    max = dp[j+1][k];
                }
            }
            dp[j+1][i+1] = max+1;
            max = dp[0][j+1];
            for(int k=1;k<=i;k++){
                if(dp[k][j+1]>max&&inpstr[k-1]<=inpstr[i]){
                    max = dp[k][j+1];
                }
            }
            dp[i+1][j+1] = max+1;
        }
    }
    /*    for(int i=0;i<=size;i++){
          for(int j=0;j<=size;j++){
          printf("%5d",dp[i][j]);
          }
          printf("\n");
          }*/
    int max = 1;
    for(int i=0;i<=size;i++){
        for(int j=0;j<=size;j++){
            if(dp[i][j]>max){
                max = dp[i][j];
            }
        }
    }
    return max;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s",inpstr);
        //        initotherstr();
        size=0;
        while(inpstr[++size]!='\0');
        printf("%d\n",solvefast());

    }
}
