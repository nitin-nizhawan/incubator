#include<stdio.h>
#include<stdlib.h>

int main(){
    int T=20;
    printf("%d\n",T);
    while(T--){
        printf("%d %d\n",rand()%100+1,rand()%100+2);
    }
}
