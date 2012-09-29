#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
    int l = atoi(argv[1]);
    long long max = 1LL<<l;
    for(long long i=0;i<max;i++){
        int cnt1=0;
        for(int s=0;s<l;s++){
             if(i&(1LL<<s)){
                 cnt1++;
             }
        }
        printf("%d,",cnt1*(l-cnt1));
    }
    printf("\n");
}
