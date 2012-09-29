#include<stdio.h>
int C,T;
int n,m;
int main(){
    scanf("%d",&T);
    unsigned int grundy=0;
    while(T--){
        scanf("%d",&C);
        grundy=0;
        for(int i=0;i<C;i++){
            scanf("%d %d",&n,&m);
            grundy^=((n+m-2)%3);
        }
        if(grundy>0){
             printf("MasterChef\n");
        } else {
             printf("Football\n");
        }

    }
}
