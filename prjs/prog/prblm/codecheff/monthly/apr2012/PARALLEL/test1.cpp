#include<stdio.h>
#include<stdlib.h>
int dp_s[1005][1005];
int dp_p[1005][1005];
int max(int a,int b){
    return a>b?a:b;
}
void init(){
    for(int i=1;i<=1000;i++){
        dp_s[i][1]=i-1;dp_p[i][1]=i-1;
        dp_s[i][i]=i-1;dp_p[i][i]=i-1;
        for(int j=2;j<i;j++){
            int chunk_size = j;
            int no_of_chunks = i/chunk_size + ((i%chunk_size)?1:0);
            int s_v = no_of_chunks  - 1;
            int p_v = (i/chunk_size - 1)*chunk_size + i%chunk_size;           
            dp_s[i][j] = s_v + max(dp_s[chunk_size][chunk_size],dp_s[i%chunk_size][i%chunk_size]);
            dp_p[i][j] = p_v + (i/chunk_size)*dp_p[chunk_size][chunk_size]+dp_p[i%chunk_size][i%chunk_size];
            if(dp_p[i][j]<=2*i&&dp_s[i][j]<dp_s[i][i]){
                dp_p[i][i] = dp_p[i][j]; dp_s[i][i] = dp_s[i][j];
            }
        }
    }
}
bool rec(int N,int S,int P,int *s,int *p){
    if(N<2){
        return true;
    }
    if(S<1||P<1){
        return false;
    }
    for(int i=1;i<N;i++){
        int chunk_size = i;
        int no_of_chunks = N/chunk_size + ((N%chunk_size)?1:0);
        int s_v = no_of_chunks  - 1;
        int p_v = (N/chunk_size - 1)*i + N%chunk_size;
        if(s_v<=S&&p_v<=P&&rec(i,P-p_v,S-s_v,s,p)){
            printf("chunk_size=%d\n",i);
            return true;
        }
    }
    return false;
}
int main(){
    init();
    int p,s,N;
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=i;j++){
            printf("(%d,%d)  ",dp_s[i][j],dp_p[i][j]);
        }
        printf("\n");
    }
  //  rec(N,2*N,20,&p,&s);
//    printf("p=%d,s=%d\n",p,s);
}
