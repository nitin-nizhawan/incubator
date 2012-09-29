#include<stdio.h>

int getCode(char a){
    if('a'<=a&&a<='z'){
        return a-'a';
    } else if('A'<=a&&a<='Z'){
        return a-'A';
    } else {
        return a;
    }
}
bool isPresent(char * A,char *B,int p){
    int i=0;
    while(A[i]!='\0'){
        int a = getCode(A[i]);
        int b = getCode(B[i+p]);
        if(a!=b){
            return false;
        }
        i++;
    }
    return true;
}
char buff[200][200];
void solve(int R, int C){
    char token[]="spoon\0";
    char buff2[200][200];
    for(int i=0;i<R;i++){
            for(int j=0;j<=(C-5);j++){
                if(isPresent(token,buff[i],j)){
                    printf("There is a spoon!\n");
                    return;
                }
            }
        }
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                buff2[j][i]=buff[i][j];
            }
        }
        for(int i=0;i<C;i++){
            for(int j=0;j<=(R-5);j++){
                if(isPresent(token,buff2[i],j)){
                    printf("There is a spoon!\n");
                    return;
                }
            }
        }
        printf("There is indeed no spoon!\n");

}
int main(){
    int T;
    scanf("%d",&T);
    int R,C;
    while(T--){
        scanf("%d",&R);
        scanf("%d",&C);
        for(int i=0;i<R;i++){
            scanf("%s",buff[i]);
        }
        solve(R,C);
        }
}
