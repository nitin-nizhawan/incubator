#include<stdio.h>
char J[200];
char S[200];
int map[256];
int main(){
    int T;
    scanf("%d",&T);
    int k=1;
    while(T--){
        scanf("%s",J);
        scanf("%s",S);
        int i=0;
        while(J[i]!='\0'){
            map[J[i]]=k;
            i++;
        }
        int ans=0;
        i=0;
        while(S[i]!='\0'){
            if(map[S[i]]==k){
                ans++;
            }
            i++;
        }
        printf("%d\n",ans);
        k++;
    }
}
