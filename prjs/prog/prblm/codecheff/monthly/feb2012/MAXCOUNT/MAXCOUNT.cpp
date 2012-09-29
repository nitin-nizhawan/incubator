#include<stdio.h>
#include<algorithm>
using namespace std;
int a[200];
int n;
void solve(){
    sort(a,a+n);
    // add a sentinel 
    a[n]=a[n-1]+1;
    n= n+1;
    int maxcount =-1;
    int maxint = a[0];
    int last=-1;
    int repcount=0;
    for(int i=0;i<n;i++){
         if(a[i]!=last){
             if(repcount>maxcount){
                 maxcount=repcount;
                 if(i>0){
                     maxint = a[i-1];
                 }
             }
             repcount=1;
         } else {
             repcount++;
         }
         last=a[i];
    }
    printf("%d %d\n",maxint,maxcount);
}
int main(){
  int T;
  scanf("%d",&T);
  while(T--){
      scanf("%d",&n);
      for(int i=0;i<n;i++){
          scanf("%d",&a[i]);
      }
      solve();
  }
}
