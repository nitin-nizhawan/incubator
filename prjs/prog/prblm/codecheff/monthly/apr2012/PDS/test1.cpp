#include<stdio.h>

char numstr[200];
void dfs(long long sum,long long prod, int pos){
    if(pos>10){
        return;
    }
    for(int i=(numstr[pos-1]-'0');i<=9;i++){
        numstr[pos]=i+'0';
        numstr[pos+1]='\0';
        if((prod*i)%(sum+i)==0){
            printf("%s\n",numstr);
        }
        dfs(sum+i,prod*i,pos+1);
    }
}
int main(){
    for(int i=1;i<=9;i++){
        numstr[0]='0'+i;
        dfs(i,i,1);
    }
}
