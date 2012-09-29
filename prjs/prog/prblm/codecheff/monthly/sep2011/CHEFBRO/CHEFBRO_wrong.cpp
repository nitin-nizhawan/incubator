#include<stdio.h>
int C;
int T;


int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&C);
        int f=0,s=0,n,m;
        for(int i=0;i<C;i++){
            scanf("%d",&n);
            scanf("%d",&m);
            if((n+m-2)%3){
                f++;
            }
        }
        if(f%2){
             printf("MasterChef\n");
        } else {
             printf("Football\n");
        }
       
    }
}
