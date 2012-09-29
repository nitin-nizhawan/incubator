#include<stdio.h>


int main(){
    long long A,B,X,Y,Z,P,N;
    scanf("%lld",&A);
    scanf("%lld",&B);
    scanf("%lld",&X);
    scanf("%lld",&Y);
    scanf("%lld",&Z);
    scanf("%lld",&P);
    scanf("%lld",&N);
    long long t1 = A;
    long long t2 = B;
    for(int i=1;i<=N;i++){
        if(i==1){
            printf("%lld ",A);
        } else {
            long long C  = (((X*B)%P) + ((Y*A)%P) + Z)%P;
            A = B;
            B = C;
            printf("%lld ",A);
        }
    }
    printf("\n");
}
