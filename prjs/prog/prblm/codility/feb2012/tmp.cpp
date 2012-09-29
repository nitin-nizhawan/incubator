#include<stdio.h>


int main(){
    unsigned long long f =1, s = 1, tmp;
    unsigned long long MOD = 10000103;
    for(unsigned long long i=1;1;i++){
        if(f==5&&s==8)
        printf("%llu , %llu\n",f%MOD,i);
        tmp = f; f =  s; s = (tmp +f)%MOD;
    }
}
