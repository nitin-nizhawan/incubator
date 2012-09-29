#include<stdio.h>
#include<stdlib.h>

long long getrand(int s){
    long long val = 0;
    int n = rand()%s + 1;
    for(int i=0;i<n;i++){
        int prob = rand()%100;
        if(prob<50){
            val = val*10 + (prob<25?4:7);
        } else {
            val = val*10 + rand()%10;
        }
    }
    return val;
}
int main(int argc,char* argv[]){
    int T = atoi(argv[1]);
    int n  = atoi(argv[2]);
    int s  = atoi(argv[3]);
    printf("%d\n",T);
    int max=1000000000;
    while(T--){
        int ni = n;//rand()%n + 1;
        printf("%d\n",ni);
        printf("%d",rand()%max + 1);
        for(int i=1;i<ni;i++){
            printf(" %ld",getrand(s));
        }
        printf("\n");
    }
}
