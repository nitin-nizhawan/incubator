#include<stdio.h>
int a[100][100];
int b[100][100];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int N;
        scanf("%d",&N);
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                scanf("%d",&a[i][j]);
            }
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                scanf("%d",&b[i][j]);
            }
        }

        for(int i=0;i<N;i++){
            printf("%d ",i+1);
        }
        printf("\n");
        for(int i=0;i<N;i++){
            printf("%d ",i+1);
        }
        printf("\n");
    }
}
