#include<stdio.h>
#include<stdlib.h>

int main(int argc,char* argv[]){
    int P=atoi(argv[1]);
    printf("%d\n",P);
    while(P--){
        if(P%3==0){
            printf("%d\n",2);
        } else {
            printf("%d %d\n",1,(rand()%P)+1);
        }
    }
}
