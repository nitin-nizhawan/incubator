#include<stdio.h>

bool v[2000];
char buff[2000];
int main(){
     int T;
scanf("%d",&T);
  while(T-->0){
      int N;
      scanf("%d",&N);
      for(int i=0;i<N;i++) v[i]=false;
      scanf("%s",buff);
      for(int i=0;i<N;i++){
         if(buff[i]=='1'){
          if(i>0){
              v[i-1]=true;
          }
          if((i+1)<N){
              v[i+1]=true;
          }
          v[i]=true;
        }
      }
      int ans=0;
      for(int i=0;i<N;i++) if(v[i]==false) ans++;
      printf("%d\n",ans);      
  }
}
