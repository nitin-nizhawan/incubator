#include<stdio.h>
int C;
int T;
bool mat[1001][1001];
bool FGAME=true;
bool SGAME=false;
int mx[] = {0,0,1,1,2,2};
int my[] = {1,2,0,1,0,2};
int main(){
    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++){
            bool game = FGAME;
            for(int k=0;k<6;k++){
                if((i-mx[k])>=0&&(j-my[k])>=0){
                    game=(game&&mat[i-mx[k]][j-my[k]]);
                }
            }
            mat[i][j] = !game;
            printf("%s,%s\n",((mat[i][j])?"M":"B"),(((i+j)%3)?"M":"B"));
        }
    }

   
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
