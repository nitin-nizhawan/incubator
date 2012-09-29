#include<stdio.h>
#include<stdlib.h>
int dfs(int a,int sum){
 
}
int findans(int a, int sum){
  int ans =  0;
  int bitvec=0;
  int maxvec = 1<<a;
  while(bitvec<maxvec){
      int tsum=0;
      for(int i=0;i<a;i++){
          int mask = 1<<i;
          if(bitvec&mask){
              tsum+=i+1;
          }
      }
      if(tsum==sum){
          ans++;
      }
      bitvec++;
  }
  return ans/2;
}
void printans(int ans){
    printf("%d\n",ans);
}
int main(int argc, char* argv[]){
    int a = atoi(argv[1]);
    int sum = a*(a+1)/2;
    if(sum%2==0){
        printans(findans(a,sum/2));
    } else {
        printans(-1);
    }
}
