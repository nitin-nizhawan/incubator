#include<cstdio>
#include<cstring>

int main(){
    char a[100],b[100];
    while(scanf("%s %s",a,b)>0){
        int alen = strlen(a);
        int blen = strlen(b);
        int cur=0;
        for(int i=0;i<blen;i++){
            if(cur>=alen) break;
            if(b[i]==a[cur]){
                cur++;
            }
        }    
        if(cur>=alen){
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
}
