#include<stdio.h>
#include<stdlib.h>
int main(int argc,const char* argv[]){
    int N;
    int T;

    long long maxA;
//    scanf("%d",&T);
    T = atoi(argv[1]);
    //scanf("%d",&N);
    N = atoi(argv[2]);
//    scanf("%lld",&maxA);
    maxA = atoi(argv[3]);
    printf("%d\n",T);
    while(T--){
        int n = rand()%N +1;
        int k = rand()%n +1;
        printf("%d %d\n",n,k);
        while(n--){
            printf("%lld ",rand()%maxA+1);
        }
        printf("\n");
    }
}
