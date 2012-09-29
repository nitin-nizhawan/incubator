#include<stdio.h>
#include<stdlib.h>
int N;
long long A[2000];
int ans[2000];
void randomize(){
    long long tmp=0;
    int p;
    for(int i=0;i<N;i++){
        p = rand()%(N-i);
        tmp = A[i];
        A[i] = A[i+p];
        A[i+p]=tmp;
    }
}
int solve(){
    long long acc=0;
    int set=1;
    for(int i=0;i<N;i++){
       acc^=A[i];
       ans[i]=set;
       if(acc==0){
          set++;
       }
    }  
    return set; 
}
int main(){
   int T;
   scanf("%d",&T);
   while(T-->0){
      scanf("%d",&N);
      for(int i=0;i<N;i++){
          scanf("%lld",&A[i]);
      }
      int numbits=0;
      int Nc=N;
      while(Nc>0){ numbits++; Nc/=2;}
      int attempts=10000*numbits;
      while(attempts-->0&&solve()<3){
         randomize();
      }
      for(int i=0;i<N;i++){
          if(i>0) printf(" ");
          printf("%d",ans[i]);
      }
      printf("\n");
   } 
}
