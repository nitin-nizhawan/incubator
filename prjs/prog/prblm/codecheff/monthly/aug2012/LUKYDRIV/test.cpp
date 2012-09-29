#include<stdio.h>
#define FOR(a) for(int a=0;a<10;a++)
int recsum(int a, int b){
    if(a+b<10){
       return (a+b);
    }
    int d1 = (a+b)%10;
    int d2 = (a+b)/10;
    return (d1+d2);
}
int main(){
    printf(" Two Digits\n");
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(recsum(i,j)==9){
                printf("%d%d ,",i,j);
            }
        }
    }
    printf("\n");
    printf(" Three Digits \n");
   for(int i=0;i<10;i++){
        for(int j=i;j<10;j++){
            for(int k=j;k<10;k++){
                if(recsum(i,recsum(j,k))==9){
                    if(i==j&&j==k){
                        printf("c3(f[%d]) , ",i);
                    } else if(i==j){
                        printf("c2(f[%d])*f[%d] , ",i,k);
                    } else {
                        printf("f[%d]*f[%d]*f[%d] , ",i,j,k);
                    }
                }
            }
        }
    }
    printf("\n");
    FOR(i)
    for(int j=i;j<10;j++)
    for(int k=j;k<10;k++)
    for(int l=k;l<10;l++)
    if(recsum(i,recsum(j,recsum(k,l)))==9) {
        if(i==j&&j==k&&k==l){
            printf("c4(f[%d]) ,",i);
        } else if(i==j&&j==k){
            printf("c3(f[%d])*f[%d] , ",i,l);
        } else if(i==j&&k==l){
            printf("c2(f[%d])*c2(f[%d]) , ",i,k);
        } else if(j==k&&){
            
        }
    }
    printf("\n");

}
