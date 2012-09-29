#include<stdio.h>
#include<stdlib.h>
int T;
void randgen(){
 int S=15;
    printf("%d\n",T);
    while(T--){
        int K = rand()%10+1;
        printf("%d\n",K);
        for(int i=0;i<S;i++){
            int flip = rand()%(rand()%3+2);
            if(flip){
                printf("%d",rand()%K);
            } else {
                printf("?");
            }
        }
        printf("\n");
    }

}
int main(int argc,char* argv[]){
    T=atoi(argv[1]);
    for(int k=1;k<=5;k++){
        for(int s=1;s<=10;s++){

        }
    }
}
