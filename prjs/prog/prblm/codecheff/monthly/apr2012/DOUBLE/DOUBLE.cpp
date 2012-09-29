#include<stdio.h>

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
       long long a;
        scanf("%lld",&a);
        if(a%2==0){
            printf("%lld",a);
        } else {
            printf("%lld",a-1);
        }
        printf("\n");
    }
}
