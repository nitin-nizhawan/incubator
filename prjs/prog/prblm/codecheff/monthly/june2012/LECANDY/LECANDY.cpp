#include<stdio.h>

int main(){
    int T;
    long long C;
    int N;
    long long sum;
    long long inp;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        scanf("%lld",&C);
        sum=0;
        while(N--){
          scanf("%lld",&inp);
          sum+=inp;
        }
        if(sum<=C){
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
}
