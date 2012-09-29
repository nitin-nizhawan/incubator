#include<stdio.h>
#include<stdlib.h>
int main(int argc, char* argv[]){
    int T=20;
    printf("%d\n",T);
    while(T-->0){
        int N=rand()%atoi(argv[1]) + 1;
        int M=rand()%atoi(argv[2]) + 1;
        printf("%d %d\n",N,M);
        for(int i=0;i<M;i++){
            int w = rand()%2 + 1;
            int z = rand()%(atoi(argv[3])+1);
            int y = rand()%N + 1;
            int x = rand()%y + 1;
            printf("%d %d %d %d\n",w,x,y,z);
        }
    }
}
