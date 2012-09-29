#include<stdio.h>


int arr[1000000];
int main(){
    int T;
 scanf("%d",&T);
   while(T-->0){
       int N, M;
       scanf("%d",&N);
       scanf("%d",&M);
       for(int i=0;i<N;i++){
           arr[i]=i+1;
       }
       for(int i=0;i<M;i++){
           int w,x,y,z;
           scanf("%d",&w);
           scanf("%d",&x);
           scanf("%d",&y);
           scanf("%d",&z);
           for(int j=x;j<=y;j++){
               if(w==2){
                   arr[j-1]-=z;
               } else {
                   arr[j-1]+=z;
               }
           }
       }
       int min=arr[0],max=arr[0];
       for(int i=0;i<N;i++){
           if(arr[i]<min) min = arr[i];
           if(arr[i]>max) max = arr[i];
       }
       printf("%d\n",max-min);
   }
}
