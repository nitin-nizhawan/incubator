#include<stdio.h>

int N,M,A[200000],B[200000],C[200000];

void brute_force(){
    int tmp[200000];
    int cA[200000];
    int cB[200000];
    int cC[200000];
    int a,b,c;
    for(int i=0;i<N;i++){
        tmp[i]=i+1;
    }
    for(int i=0;i<M;i++){
        a = A[i];
        b = B[i];
        c = C[i];
         // copy A;
         for(int j=0;j<a;j++){
             cA[j] = tmp[j];
         }
         // take B;
         for(int j=a;j<(a+b);j++){
             cB[j-a] = tmp[j];
         }
         //place A;
         for(int j=0;j<a;j++){
             tmp[j+b] = cA[j];
         }
         //take C;
         for(int j=b;j<(b+c);j++){
             cC[j-b]=tmp[j];
         }
         //place B in reverse;
         for(int j=0;j<b;j++){
             tmp[b+c-1-j] = cB[j];
         }
         //place C
         for(int j=0;j<c;j++){
             tmp[j]= cC[j];
         }
    }
    printf("%d",tmp[0]);
    for(int i=1;i<N;i++){
        printf(" %d",tmp[i]);
    }
    printf("\n");
}
int main(){
        scanf("%d",&N);
        scanf("%d",&M);
        for(int i=0;i<M;i++){
            scanf("%d",&A[i]);
            scanf("%d",&B[i]);
            scanf("%d",&C[i]);
        }
        brute_force();
}
