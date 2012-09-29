#include<stdio.h>



char inp[200000];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s",inp);
        int ans=0;
        int i=0;
        while(inp[i]!='\0'){
            if(inp[i]!='4'&&inp[i]!='7'){
                ans++;
            }
            i++;
        }
        printf("%d\n",ans);
    }
}
