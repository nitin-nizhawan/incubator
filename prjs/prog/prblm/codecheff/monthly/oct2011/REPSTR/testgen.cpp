#include<stdio.h>
#include<stdlib.h>

char buff[100001];
int main(int argc, char *argv[]){
    
    int tests=15;
    int maxlen=100000;
    if(argc>1){
        tests = atoi(argv[1]);
        
    }
    if(argc>2){
        maxlen = atoi(argv[2]);
    }
    for(int i=0;i<tests;i++){
        int len = rand()%(maxlen-1)+1;
        for(int j=0;j<len;j++){
            buff[j]= (rand()%26)+'a';
        }
        buff[len]='\0';
        int H = rand()%len+1;
        int L = (rand()%H) +1;
        printf("%d %d\n",L,H);
        printf("%s\n",buff);
    }
    printf("0 0");
}
