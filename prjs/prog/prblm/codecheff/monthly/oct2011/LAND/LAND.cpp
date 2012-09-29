#include<stdio.h>
int x,y;
int a[102][102];
void solve(){
    int min =100;
    
      for(int i=0;i<y;i++){
          for(int j=0;j<x;j++){
              if(a[i][j]){
                 if(min>a[i][j]){
                     min = a[i][j];
                 }
              }
          }
      }

      for(int i=0;i<y;i++){
          for(int j=0;j<x;j++){
              if(!a[i][j]){
                 a[i][j] = min;
              }
          }
      }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
      scanf("%d",&y);
      scanf("%d",&x);
      for(int i=0;i<y;i++){
          for(int j=0;j<x;j++){
              scanf("%d",&a[i][j]);
          }
      }
      solve();
      for(int i=0;i<y;i++){
          for(int j=0;j<x;j++){
              printf("%d%s",a[i][j],((j==(x-1))?"":" "));
          }
          printf("\n");
      }
      printf("\n");
    }
    return 0;
}
