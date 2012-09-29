#include<stdio.h>

#include<stdlib.h>
#include<algorithm>
using namespace std;
int pip[50000][20];
int sz[50000];
void createRand(int n,char *buff){
    for(int i=0;i<n;i++){
        buff[i]=rand()%10+'a';
    }
    buff[n]='\0';
}
bool isAsc(int i,int msz,char *buff,int len){
    for(int k=1;k<msz;k++){
        if(buff[pip[i][k]]<buff[pip[i][k-1]]){
            return false;
        }
    }
    return true;
}
int solveLCS(char *a,int size){
    int dp[40][40];
    char c[40];
    for(int i=0;i<size;i++){
        c[i]=a[i];
        for(int j=0;j<size;j++){
            dp[40][40];
        }
    }
    c[size]='\0';
    sort(c,c+size);
    for(int i=0;i<size/2;i++){
        char tmp = c[i];
        c[i] = c[size - i-1];
        c[size - i -1]=tmp;
    }
    for(int i=0;i<=size;i++){
        for(int j=0;j<=size;j++){
            if(i==0||j==0){
                dp[i][j] = 0;
            } else if(a[i-1]==c[j-1]){
                dp[i][j] = dp[i-1][j-1] +1;
            } else if(dp[i-1][j]>=dp[i][j-1]){
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = dp[i][j-1];
            }
        }
    }
    return dp[size][size];
}
int solve(char *inp,char *ans,int len){
    int mask =0;
    int num=0;
    for(int i=0;i<(1<<len);i++){
        sz[num]=0;
        for(int j=0;j<len;j++){
            if(i&(1<<j)){
                pip[num][sz[num]++]=j;
            }
        }
        // check if it is ascending
        if(isAsc(num,sz[num],inp,len)){
            num++;
        }
    }

//    printf("reachedherer \n");
    int max=0;
    int mi=-1;
   for(int i=0;i<num;i++){
       int *inst = pip[i];
       bool isUsed[20];
       for(int p=0;p<len;p++){
           isUsed[p]=false;
       }
       for(int p=0;p<sz[i];p++){
           isUsed[inst[p]]=true;
       }
       char dec_inp[20]; 
       int d_cnt=0;
       for(int p=0;p<len;p++){
           if(!isUsed[p]){
               dec_inp[d_cnt++]=inp[p];
           }
       }
       int s = solveLCS(dec_inp,d_cnt);
       if(max<(s+sz[i])){
           max = s+sz[i];
           mi = i;
       }
   }
   int cnti=0;
   for(int i=0;i<sz[mi];i++){
       ans[cnti++]=inp[pip[mi][i]];
   }
   ans[cnti]='\0';
   return max;

}
int main(int argc,char *argv[]){
    char rndstr[3000];
    char ans[2005]={0};
    int T = atoi(argv[1]);
    for(int i=0;i<T;i++){
        createRand(12,rndstr);
        int ans_i = solve(rndstr,ans,12);
        printf("%s,  %s,  %d\n",rndstr,ans,ans_i);
    }
}
