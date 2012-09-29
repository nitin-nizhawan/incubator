#include<stdio.h>
#include<algorithm>
using namespace std;
char inpstr[3000];
char decstr[3000];
char incstr[3000];
int dp[2005][2005];
int dp2[2005][2005];
int moves[2005][2005];
int size=0;
int max(int a,int b){
    return a>b?a:b;
}
void initotherstr(){
    size=0;
    while(inpstr[size]!='\0'){
        incstr[size]=inpstr[size];
        size++;
    }
    sort(incstr,incstr+size);
    for(int i=0;i<size;i++){
        decstr[size-i-1]=incstr[i];
    }
    decstr[size]=incstr[size]='\0';
//    printf("%s\n",inpstr);
//    printf("%s\n",incstr);
//    printf("%s\n",decstr);
}
int solveLCS(char *a,char* b,int *lcs,int msize){
    const int CONST_EQ=-1;
    const int CONST_J=-2;
    const int CONST_I = -3;
    for(int i=0;i<=msize;i++){
        for(int j=0;j<=msize;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            } else if(a[i-1]==b[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
                moves[i][j] = CONST_EQ;
            } else if(dp[i-1][j]>=dp[i][j-1]){
                dp[i][j] = dp[i-1][j];
                moves[i][j] = CONST_J;
            } else {
                dp[i][j] = dp[i][j-1];
                moves[i][j] = CONST_I;
            }
        }
    }
    int i=msize,j=msize;
    int pos=0;
    while(i>0&&j>0){
        switch(moves[i][j]){
            case CONST_EQ:
            lcs[pos++]=i-1;
            i--;j--;
            break;
            case CONST_I:
            j--;
            break;
            case CONST_J:
            i--;
            break;
        }
    }
/*    for(int i=0;i<pos/2;i++){
        int tmp=lcs[i];
        lcs[i] = lcs[pos-i-1];
        lcs[pos-i-1]=tmp;
    }*/
    return pos;
}
int solve1(){
    int lcs_inc[3000];
    int lcs_dec[3000];
    bool unique[3000];
    int inc_len = solveLCS(inpstr,incstr,lcs_inc,size);
    int dec_len = solveLCS(inpstr,decstr,lcs_dec,size);
    for(int i=0;i<size;i++){
        unique[i]=false;
    }
    for(int i=0;i<inc_len;i++){
        unique[lcs_inc[i]]=true;
    }
    for(int i=0;i<dec_len;i++){
        unique[lcs_dec[i]]=true;
    }
    int ans=0;
    for(int i=0;i<size;i++){
        if(unique[i]){
            ans++;
        }
    }
  /*  for(int i=0;i<inc_len;i++){
        printf("%d ",lcs_inc[i]);
    }
    printf("\n");
    for(int i=0;i<dec_len;i++){
        printf("%d ",lcs_dec[i]);
    }
    printf("\n");
  */
    return ans>0?ans:1;
}
int solve(){
    int lcs_inc[3000];
    int lcs_dec[3000];
    bool unique[3000];
    int inc_len = solveLCS(inpstr,incstr,lcs_inc,size);
    int cnt=0;
    for(int i=0;i<size;i++){
        unique[i]=false;
    }
    for(int i=0;i<inc_len;i++){
        printf("%c",inpstr[lcs_inc[i]]);
        unique[lcs_inc[i]]=true;
    }
    printf("\n");
    char remstr[3000];
    for(int i=0;i<size;i++){
        if(!unique[i]){
            remstr[cnt]=inpstr[i];
            decstr[cnt++]= inpstr[i];
        }
    }

    sort(decstr,decstr+cnt);
    for(int i=0;i<cnt/2;i++){
        char tmp = decstr[i];
        decstr[i] = decstr[cnt-i-1];
        decstr[cnt-i-1] = tmp;
    }
    int dec_len = solveLCS(remstr,decstr,lcs_dec,cnt);
    for(int i=0;i<dec_len;i++){
        printf("%c",remstr[lcs_dec[i]]);
    }
    printf("\n");
    int val1 = inc_len + dec_len;
    initotherstr();
     dec_len =solveLCS(inpstr,decstr,lcs_dec,size);
     for(int i=0;i<dec_len;i++){
         printf("%c",inpstr[lcs_dec[i]]);
     }
     printf("\n");
     cnt=0;
     for(int i=0;i<size;i++){
         unique[i]=false;
     }
     for(int i=0;i<dec_len;i++){
         unique[lcs_dec[i]]=true;
     }
     for(int i=0;i<size;i++){
         if(!unique[i]){
             remstr[cnt]=inpstr[i];
             incstr[cnt++]=inpstr[i];
         }
     }
     sort(incstr,incstr+cnt);
     inc_len = solveLCS(remstr,incstr,lcs_inc,cnt);
     for(int i=0;i<inc_len;i++){
         printf("%c",remstr[lcs_inc[i]]);
     }
     printf("\n");
     int val2 = inc_len + dec_len;

    return max(val1,val2);
}
int solve3(){
    bool t[2005][2005];
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            dp[i][j]  = 0;
            dp2[i][j] = 0;
            t[i][j]=false;
        }
    }
    for(int i=0;i<=size;i++){
        for(int j=0;j<=size;j++){
            int dj = size-j-1;
            if(i==0||j==0){
                dp[i][j]=0;
                dp2[i][j] = 0;
            } else if((inpstr[i-1]==incstr[dj+1]&&inpstr[i-1]==incstr[j-1])){
                  dp[i][j] = dp[i-1][j-1] + 1;
                  dp2[i][j] = max(dp2[i-1][j],dp2[i][j-1]);
            } else if(inpstr[i-1]==incstr[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                    dp2[i][j] = max(dp2[i-1][j],dp2[i][j-1]);
            } else if(inpstr[i-1]==incstr[dj+1]){
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                dp2[i][j] =dp2[i-1][j-1] +1;
            }else {
                int dv1 = dp[i-1][j];
                int dv2 = dp2[i-1][j];
                int val= dv1 + dv2;
                if(dp[i-1][j]+dp2[i][j-1]>val){
                    dv2 = dp2[i][j-1];
                    dv1 = dp[i-1][j];
                    val = dv1+dv2;
                } 
                if(dp[i][j-1]+dp2[i-1][j]>val){
                    dv1 =dp[i][j-1];
                    dv2 = dp2[i-1][j];
                    val = dv1 + dv2;
                }
                if(dp[i][j-1]+dp2[i][j-1]>val){
                    dv1 = dp[i][j-1];
                    dv2 = dp2[i-1][j];
                    val = dv1 + dv2;
                }
                dp[i][j] = dv1;
                dp2[i][j] = dv2;
               
            }
        }
    }
    printf("%d,%d\n",dp[size][size],dp2[size][size]);
    return dp[size][size]+dp2[size][size];
}

int solve4(){
    bool t[2005][2005];
    for(int i=0;i<=size;i++){
        for(int j=0;j<=size;j++){
            dp[i][j]  = 0;
            t[i][j]=false;
        }
    }
    for(int i=0;i<=size;i++){
        for(int j=0;j<=size;j++){
            int dj = size-j;
            if(i==0||j==0){
                dp[i][j]=0;
            } else if(inpstr[i-1]==incstr[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
            } else if(inpstr[i-1]==incstr[dj]){
                dp[i][j] =dp[i-1][j-1] +1;
            }else {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
               
            }
        }
    }
    printf("%d\n",dp[size][size]);
    return dp[size][size];
}


int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s",inpstr);
        initotherstr();
        printf("%d\n",solve4());
    }
}
