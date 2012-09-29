#include<stdio.h>
#include<stdlib.h>
int main(){
    int Q = rand()%100+1;
    int N= rand()%200 +1
    scanf("%d",&Q);
    printf("%d %d\n",N,Q);
    while(Q--){
        int t=rand()%2,b=rand()%N,a=rand()%b;
        printf("%d %d %d\n",t,a,b);
    }
}



