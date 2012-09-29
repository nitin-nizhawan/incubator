#include<stdio.h>
int K;
char buff[200];
int len;
void input(){
  scanf("%d",&K);
  scanf("%s",buff);
  len =0;
  while(buff[len]!='\0') len++;
}
int solve(char *buff,int K,int len){
    for(int i=0;i<len;i++){
        if(buff[i]=='?'){
            for(int k=0;k<K;k++){
                char c = k+'0';
                if(buff[(i-1+len)%len]!=c&&buff[(i+1)%len]!=c){
                    buff[i]=c;
                    break;
                }
            }
            if(buff[i]=='?'){
                return -1;
            }
        }
    }
    for(int i=0;i<len;i++){
        if(buff[i]==buff[(i+1)%len]){
            return -1;
        }
    }
    printf("%s\n",buff);
    return 1;
}
void solve1(char * b,int K, int len){
    int ret = solve(b,K,len);
    if(ret<0){
        printf("NO\n");
    }
}
char buff1[200];
void cpy(){
    for(int i=0;i<=len;i++){
        buff1[i]=buff[i];
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        input();
        //printf("%s==> ",buff);
        if(len==1){
            if(buff[0]=='?'){
                buff[0]='0';
            }
            printf("%s\n",buff);
        } else if(K==2){
          if(len%2==0){
              if(buff[0]=='?'){
                  cpy();
                  buff1[0]='0';
                 int ret =  solve(buff1,K,len);
                 if(ret<0){
                     cpy();
                     buff1[0]='1';
                     ret = solve(buff1,K,len);
                     if(ret<0){
                         printf("NO\n");
                     }
                 }
                    
              } else {
                  solve1(buff,K,len);
              }
          } else {
              printf("%s\n","NO");
          }
        } else {
            solve1(buff,K,len);
        }
    }
}
