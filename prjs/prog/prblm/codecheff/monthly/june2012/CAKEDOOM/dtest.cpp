#include<stdio.h>
#include<stdlib.h>
char buff[200];
int mpow(int B,int P){
    int ans=1;
    for(int i=1;i<=P;i++){
        ans*=B;
    }
    return ans;
}
void solve(char * b,int K,int S){
    printf("%d\n",K);
    printf("%s",b);
    printf("\n");

}
int main(int argc,char* argv[]){
    int K = atoi(argv[1]);
    int S = atoi(argv[2]);
    buff[S]='\0';
    int max = mpow(K+1,S);
    printf("%d\n",max);

    for(int i=0;i<S;i++) buff[i]='0';
    int cnt=0;
    do{
    solve(buff,K,S);
    char maxchar='0'+K-1;
    int carry=1;
    int pos=0;
    do{
           carry=0;
           if(buff[pos]=='?'){
               buff[pos++]='0';
               carry=1;
           } else if(buff[pos]==maxchar){
               buff[pos]='?';
           } else {
               buff[pos]++;
           }
    }while(carry);
    cnt++;
    }while(cnt<max);
}
