#include<stdio.h>


int getdigit(long long n,int len,int i){
    int ri = len-i-1;
    if(ri<0){
        int doi=0;
        int pi = 1/doi;
    }
     long long pow10 = 1;
     for(int i=0;i<ri;i++){
         pow10=10*pow10;
     }
     return (n/pow10)%10;
}
long long floorit(long long n, int len, int i){
    int ri = len -i -1;
    if(ri<0){
        int doi = 0;
        int pi = 1/doi;
    }
    long long pow10 =1 ;
    for(int i=0;i<ri;i++){
        pow10 = pow10*10;
    }
    return (n/pow10)*pow10;
}
long long cielit(long long n,int len,int i1){
    int ri=len -i1 -1;
    if(ri<0){
        int doi=0;
        int pi=1/doi;
    }
    long long tmp = n;
    int len1=0;
    while(tmp>0){
        len1++;
        tmp/=10;
    }
    long long pow10 =1;
    long long s9 =9;
    for(int i=0;i<ri;i++){
        pow10 = 10*pow10;
        if(i<(ri-1)&&i<(len1-1)){
            s9 = s9*10+9;
        }
    }
    if(i1==len-1){
        s9=0;
    }
    return floorit(n,len,i1) + s9;
}
int main(){
    long long n;
    int len,i;
    scanf("%lld",&n);
    scanf("%d",&len);
    scanf("%d",&i);
    printf("digit= %d\n",getdigit(n,len,i));
    printf("floor = %d\n",floorit(n,len,i));
    printf("ciel = %d\n",cielit(n,len,i));
}
