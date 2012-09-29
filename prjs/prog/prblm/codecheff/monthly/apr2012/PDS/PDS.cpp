#include<stdio.h>

//1,2,3,4,5,6,7,8,9,10,20,22,30,36,40,44,50,60,63,66
long long table[10][9]={
{ 1, 2, 3, 4, 5, 6, 7, 8, 9},
{ 10, 12, 14, 16, 17, 20, 21, 23, 24},
{ 55, 88, 122, 157, 196, 230, 267, 299, 333},
{ 706, 1116, 1531, 1956, 2368, 2809, 3200, 3607, 4008},
{ 8619, 13428, 18332, 23197, 28159, 33167, 37956, 42751, 47470},
{ 100361, 154613, 209049, 263705, 319701, 374384, 428265, 481631, 534357},
{ 1118255, 1710151, 2301356, 2892673, 3501975, 4092976, 4685242, 5269113, 5845531},
{ 12130748, 18463923, 24795186, 31128599, 37651025, 43988394, 50422158, 56696848, 62955906},
{ 129867303, 197130768, 264413912, 331635763, 400677786, 468074642, 536609809, 603442754, 670349658},
{ 1000000023LL }// dummy
};

//Completed: 1999999999 , 1000000000
long long toScan(int a,int b){
    long long ans=b+1;
    while(a--){
        ans = ans*10+9;
    }
    return ans;
}
long long numPDS(int len,long long sum,long long prod,int last){
    long long ans=0;
    for(int i=last;i<=9;i++){
        ans+=numPDS(len-1,sum+i,prod*i,i);
    }
    return ans;
}
int main(){
    long long N;
    scanf("%lld",&N);
    int vi=0,vj=0,ni=0,nj=0;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            ni=i;nj=j+1;
            if(nj>=9){
                nj=0;
                ni++;
            } 
            if(N>table[i][j]&&N<=table[ni][nj]){
                vi=i;vj=j;
                break;
            }
        }
            if(N>=table[vi][vj]&&N<=table[ni][nj]){
                break;
            }
    }
    printf("test range %lld,%lld\n",toScan(vi,vj),toScan(ni,nj));
    int totalNumOfDigits = ni+1;
    char numStr[200];
    numStr[0]='0'+nj+1;
    for(int i=0;i<totalNumOfDigits;i++){
        
    }
}
