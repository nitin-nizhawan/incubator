#include<stdio.h>
/*
parallel  prefix sum algosequence
1,2  3,4  5,6  7,8  9,10 11,12  13,14  15,16
2,4 6,8 10,12 14,16
4,8 12,16
8,16
8,12
4,6 8,10 12,14
2,3 4,5 6,7 8,9 10,11 12,13 14,15

*/

class Action {
    public:
    int a,b;

};

//(a,b);
int a[20][1024];
int b[20][1024];
int counts[20];
int pow2[]={1,2,4,8,16,32,64,128,256,512,1024,2048};
int powd[]={3,6,12,24,48,96,192,384,768,1536,3072};
int actuall_counts[20];


int main(){
    int N;
    scanf("%d",&N);
    int nbits=0;
    int tmp = N;
    while(tmp>0){
        tmp = tmp>>1;
        nbits++;
    }
    int C;
    if((N-1)&N){
        C = (1<<nbits);
    } else {
        C = N;
    }
   
   int steps=0;
   int steps1=0,steps2=0;
   for(int i=1;pow2[i]<=N;i++) steps1++;
   for(int i=0;powd[i]<=N;i++) steps2++;
   printf("%d\n",steps1+steps2);
   for(int i=0;i<steps1;i++){
       int popts = (N-pow2[i+1])/pow2[i+1]+1;
       printf("%d ",popts);
       for(int j=0,k=pow2[i];j<popts;j++){
           printf("%d+%d=%d ",k,k+pow2[i],k+pow2[i]);
           k+=pow2[i+1];
       }
       printf("\n");
   }
   for(int i=0;i<steps2;i++){
       int popts = (N-powd[steps2-i-1])/pow2[steps2-i] + 1;
       printf("%d ",popts);
       for(int j=0,k=pow2[steps2-i];j<popts;j++){
           printf("%d+%d=%d ",k,k+pow2[steps2-i-1],k+pow2[steps2-i-1]);
           k+=pow2[steps2-i];
       }
       printf("\n");
   }
}
